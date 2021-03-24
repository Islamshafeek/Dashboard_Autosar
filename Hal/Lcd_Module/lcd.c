/*
 * lcd.c
 *
 *  Created on: Mar 20, 2021
 *      Author: bibom
 */

#include "Std_Types.h"
#include "Bit_Mask.h"
#include "Bit_Math.h"
#include "status.h"
#include "Dio_int.h"
#include "swTimer.h"
#include "lcd.h"
#include "lcd_cfg.h"


#define	LCD_u8CLEAR_SCREEN_CMD										((u8)0x01U)
#define	LCD_u8RETURN_HOME_CMD										((u8)0x02U)
#define	LCD_u8ENTRY_MODE_SET_INC_SHIFT_CMD							((u8)0x07U)
#define	LCD_u8ENTRY_MODE_SET_INC_NO_SHIFT_CMD						((u8)0x06U)
#define	LCD_u8ENTRY_MODE_SET_DEC_SHIFT_CMD							((u8)0x05U)
#define	LCD_u8ENTRY_MODE_SET_DEC_NO_SHIFT_CMD						((u8)0x04U)
#define LCD_u8DISPLAY_ON_OFF_CONTORL_DISP_OFF_CURSOR_OFF			((u8)0x08U)
#define LCD_u8DISPLAY_ON_OFF_CONTORL_DISP_ON_CURSOR_OFF				((u8)0x0CU)
#define LCD_u8DISPLAY_ON_OFF_CONTORL_DISP_ON_CURSOR_ON_NO_BLINK		((u8)0x0EU)
#define LCD_u8DISPLAY_ON_OFF_CONTORL_DISP_ON_CURSOR_ON_BLINK		((u8)0x0FU)
#define LCD_u8DISPLAY_SHIFT_RIGHT									((u8)0x1CU)
#define LCD_u8DISPLAY_SHIFT_LEFT									((u8)0x18U)
#define	LCD_u8CURSOR_SHIFT_RIGHT									((u8)0x14U)
#define	LCD_u8CURSOR_SHIFT_LEFT										((u8)0x10U)
#define	LCD_u8FUNCTION_SET_8BITS_2LINES_5X7_DOTS					((u8)0x38U)
#define	LCD_u8FUNCTION_SET_8BITS_1LINE_5X7_DOTS						((u8)0x34U)
#define	LCD_u8FUNCTION_SET_8BITS_1LINE_5X10_DOTS					((u8)0x34U)
#define	LCD_u8FUNCTION_SET_4BITS_2LINE_5X7_DOTS						((u8)0x28U)
#define	LCD_u8FUNCTION_SET_4BITS_1LINE_5X7_DOTS						((u8)0x24U)
#define	LCD_u8FUNCTION_SET_4BITS_1LINE_5X10_DOTS					((u8)0x20U)
#define LCD_u8CGRAM_SET_ADDRESS										((u8)0x40U)
#define LCD_u8DDRAM_SET_ADDRESS										((u8)0x80U)


#define LCD_PACKET_COMMAND	(0)
#define LCD_PACKET_DATA	 	(1)

typedef enum
{
	lcdState_idle,
	lcdState_writeData,
	lcdState_writeCommand,
	_lcdState_len_
}lcdState_t;

typedef enum
{
	lcdStateMachine_initialWait,
	lcdStateMachine_functionSet,
	lcdStateMachine_displayControl,
	lcdStateMachine_displayClear,
	lcdStateMachine_entryModeSet,
	lcdStateMachine_ready,
	_lcdStateMachine_len_
}lcdStateMachine_t;

extern const u8 lcdCfg[PIN_NUM];
static lcdStateMachine_t lcdStateMachine = lcdStateMachine_initialWait;
static lcdState_t lcdState = lcdState_idle;
static u8 lcdBuffer[33];
static u8 lcdBufferInd = 0;
static u8 isReady = 0;

static void init_stateMachine(void);
static void process(void);
static status_RT lcd_sendPacket(u8 packet,u8 LCD_PACKET_type);
static void lcd_handler(void);

status_RT lcd_init(void)
{
	status_RT status = E_OK;
	for(u8 i=0;i<PIN_NUM;i++)
	{
		Dio_vidSetPinVal(lcdCfg[i],DIO_u8LOW);
	}
	SwTimer_register_cbf(2,SwTimerMode_periodic,lcd_handler);
	return status;
}


static void lcd_handler(void)
{
	if(isReady)
	{
		process();
	}
	else
	{
		init_stateMachine();
	}
}

static void init_stateMachine(void)
{
	status_RT status;
	static u8 counter = 0;
	switch(lcdStateMachine)
	{
	case lcdStateMachine_initialWait:
		if(counter == 30)
		{
			status = lcd_sendPacket(LCD_u8FUNCTION_SET_8BITS_2LINES_5X7_DOTS,LCD_PACKET_COMMAND);
			if(status == E_OK)
			{
				lcdStateMachine = lcdStateMachine_functionSet;
				counter = 0;
			}
		}
		else
		{
			counter++;
		}
		break;
	case lcdStateMachine_functionSet:
		status = lcd_sendPacket(LCD_u8DISPLAY_ON_OFF_CONTORL_DISP_ON_CURSOR_OFF,LCD_PACKET_COMMAND);
		if(status == E_OK)
		{
			lcdStateMachine = lcdStateMachine_displayControl;
			counter = 0;
		}
		break;
	case lcdStateMachine_displayControl:
		status = lcd_sendPacket(LCD_u8CLEAR_SCREEN_CMD,LCD_PACKET_COMMAND);
		if(status == E_OK)
		{
			lcdStateMachine = lcdStateMachine_displayClear;
			counter = 0;
		}
		break;
	case lcdStateMachine_displayClear:
		if(counter == 1)
		{
			status = lcd_sendPacket(LCD_u8ENTRY_MODE_SET_INC_NO_SHIFT_CMD,LCD_PACKET_COMMAND);
			if(status == E_OK)
			{
				lcdStateMachine = lcdStateMachine_entryModeSet;
				counter = 0;
			}
		}
		else
		{
			counter++;
		}
		break;
	case lcdStateMachine_entryModeSet:
		lcdStateMachine = lcdStateMachine_ready;
		isReady = 1;
		break;
	case lcdStateMachine_ready:
		break;
	}
}

static void process(void)
{
	status_RT status;
	if(lcdState == lcdState_writeData)
	{
		if(lcdBuffer[lcdBufferInd])
		{
			status = lcd_sendPacket(lcdBuffer[lcdBufferInd],LCD_PACKET_DATA);
			if(status == E_OK)
			{
				lcdBufferInd++;
			}
		}
		else
		{
			lcdBufferInd = 0;
			lcdState = lcdState_idle;
		}
	}
	else if(lcdState == lcdState_writeCommand)
	{
		status = lcd_sendPacket(lcdBuffer[0],LCD_PACKET_COMMAND);
		if(status == E_OK)
		{
			lcdState = lcdState_idle;
		}
	}
}

static status_RT lcd_sendPacket(u8 packet,u8 LCD_PACKET_type)
{
	status_RT status = E_OK;
	static u8 state = 0;
	if(state == 0)
	{
		if(LCD_PACKET_type == LCD_PACKET_COMMAND)
		{
			Dio_vidSetPinVal(lcdCfg[RS],DIO_u8LOW);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[RS],DIO_u8HIGH);
		}
		Dio_vidSetPinVal(lcdCfg[EN],DIO_u8HIGH);
		if((packet >> 7) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D7],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D7],DIO_u8LOW);
		}
		if((packet >> 6) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D6],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D6],DIO_u8LOW);
		}
		if((packet >> 5) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D5],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D5],DIO_u8LOW);
		}
		if((packet >> 4) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D4],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D4],DIO_u8LOW);
		}
		if((packet >> 3) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D3],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D3],DIO_u8LOW);
		}
		if((packet >> 2) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D2],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D2],DIO_u8LOW);
		}
		if((packet >> 1) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D1],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D1],DIO_u8LOW);
		}
		if((packet >> 0) & 1)
		{
			Dio_vidSetPinVal(lcdCfg[D0],DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(lcdCfg[D0],DIO_u8LOW);
		}
		state = 1;
		status = RT_PENDING;
	}
	else if(state == 1)
	{
		Dio_vidSetPinVal(lcdCfg[EN],DIO_u8LOW);
		status = RT_BUSY;
		state++;
	}
	else if(state==2)
	{
		//trace_printf("%x\n",packet);
		state = 0;
		status = E_OK;
	}
	return status;
}

status_RT lcd_clear(void)
{
	status_RT status = E_OK;
	if(isReady)
	{
		if(lcdState == lcdState_idle)
		{
			lcdState = lcdState_writeCommand;
			lcdBuffer[0] = LCD_u8CLEAR_SCREEN_CMD;
		}
		else
		{
			status = RT_BUSY;
		}
	}
	else
	{
		status = E_NOK;
	}
	return status;
}

status_RT lcd_writeString(const u8* const str)
{
	status_RT status = E_OK;
	u8 i = 0;
	if(isReady)
	{
		if(lcdState == lcdState_idle)
		{
			lcdState = lcdState_writeData;
			for(i=0;str[i];i++)
			{
				lcdBuffer[i] = str[i];
			}
			lcdBuffer[i] = '\0';
		}
		else
		{
			status = RT_BUSY;
		}
	}
	else
	{
		status = E_NOK;
	}
	return status;
}
