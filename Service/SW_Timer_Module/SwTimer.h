/*
 * SwTimer.h
 *
 *  Created on: Mar 12, 2021
 *      Author: Esraa Abdelnaby
 */

#ifndef SWTIMER_H_
#define SWTIMER_H_

#define CBF_MAX 100
#define E_OK 0
#define E_NOK 1

typedef enum{
	SwTimerMode_periodic,
	SwTimerMode_once
}SwTimerMode_t;

typedef void (*SwTimerCbf_t) (void);

typedef struct{
	SwTimerCbf_t func;
	SwTimerMode_t mode;
	u32 timerMs;
	u32 reload;
}cbfList_t;




extern u8 SwTimer_register_cbf(u32 time_ms,SwTimerMode_t mode,SwTimerCbf_t cbf);

extern void SwTimer_init(void);

#endif /* SWTIMER_H_ */
