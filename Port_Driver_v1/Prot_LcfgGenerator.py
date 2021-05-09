i = 0
port = "PORT_A_"
pin = "PIN_"

f= open("Port_Lcfg.c","w+")

f.write("const Port_ConfigType Port_Config[PORT_PIN_NUMBER] = { \n\n")

while(i< 82):
	if(i< 16):
		port = "PORT_A_"
	elif(i>=16 and i < 32):
		port = "PORT_B_"
	elif(i>=32 and i < 48 ):
		port = "PORT_C_"
	elif(i>= 48 and i < 64 ):
		port = "PORT_D_"
	elif (i >= 64 and i < 80):
		port = "PORT_E_"
	elif (i >= 80 and i < 96):
		port = "PORT_H_"

	f.write("["+port+pin+str(i%16)+"] =\n")
	f.write("				{\n")
	f.write(".PinMode = PORT_AF0 ,\n")			
	f.write(".PinDirection = PORT_PIN_OUT ,\n")
	f.write(".PinLevelInitValue = PORT_PIN_LEVEL_LOW ,\n")
	f.write(".PinInternalPullUp = PORT_PIN_INTERNAL_PULL_DOWN,\n")
	f.write(".PinSpeed  = PORT_PIN_SPEED_V_HIGH,		//Speed_Register\n")
	f.write(".PinOType  = PORT_PIN_OUTPUT_PUSH_PULL ,\n")
	f.write(".PinDirectionChangeableDuringRuntime = STD_ON ,\n")
	f.write(".PortModeChangeableDuringRuntime  = STD_ON\n")
	f.write("			},\n\n")
	i+=1

f.write("};\n\n")

f.close()
