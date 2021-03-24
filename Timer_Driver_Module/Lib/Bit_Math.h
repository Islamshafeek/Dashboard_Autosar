
#ifndef _BIT_MATH_H
#define BIT_MATH_H
  			
#define SET_BIT(Reg,Bit)					( (Reg) |=  ( (1) << (Bit) )  )
#define CLR_BIT(Reg,Bit)                 	( (Reg) &= ~( (1) << (Bit) )  )
#define TGL_BIT(Reg,Bit)                 	( (Reg) ^=  ( (1) << (Bit) )  )

#define GET_BIT(Reg,Bit)					( ( (Reg) >> (Bit) ) & (1) )

#define ASSIGN_REG(Reg,Value)				(Reg) = (Value)
#define ASSIGN_NIB_HIGH(Reg,Value)			(Reg) = ( (Value)&(0xf0) )|( (Reg)&(0x0f) )
#define ASSIGN_NIB_LOW(Reg,Value)			(Reg) = ( (Value)&(0x0f) )|( (Reg)&(0xf0) )

#define SET_REG(Reg)						(Reg) = ( (Reg) | (0xff) )
#define RST_REG(Reg)						(Reg) = ( (Reg) & (0x00) )

#define SET_NIB_HIGH(Reg)					(Reg) = ( (Reg)&(0xf0) ) | ( (Reg)&(0x0f) )
#define SET_NIB_LOW(Reg)					(Reg) = ( (Reg)&(0x0f) ) | ( (Reg)&(0xf0) )
												    
#define RST_NIB_HIGH(Reg)					(Reg) = ( (Reg)&(0x0f) )
#define RST_NIB_LOW(Reg)					(Reg) = ( (Reg)&(0xf0) )

#define GET_NIB_HIGH(Reg)					( ( (Reg)>>4 ) & (0x0f) )
#define GET_NIB_LOW(Reg)					( (Reg) & (0x0f) )

#define ROT_REG_RIGHT(Reg,Step)				(Reg)=( ( (Reg) >> Step) | ( (Reg) << (8-Step) ) )
#define ROT_REG_LEFT(Reg,Step)				(Reg)=( ( (Reg) << Step) | ( (Reg) >> (8-Step) ) )
 
/* 
	Concatination macro
*/
#define CONC2(s,t,u,v,w,x,y,z)				0b##s##t##u##v##w##x##y##z
#define CONC(s,t,u,v,w,x,y,z)				CONC2(s,t,u,v,w,x,y,z)

#endif /* _BIT_MATH_H */
