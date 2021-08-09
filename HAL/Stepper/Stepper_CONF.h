#ifndef STEPPER_CONF_H_
#define STEPPER_CONF_H_

#include "../../MCAL/GPIO/GPIO_CONFIG.h"



#define MOTOR_PORT				PORT_D
#define WINDING_A					0
#define WINDING_B					1
#define WINDING_C					2
#define WINDING_D					3
#define PIN4					4
#define PIN5					5


#define MOTOR_TYPE				BIPOLAR
#define STEP_SEQUENCE_TYPE 		NORMAL_STEP_SEQUENCE_4
#define MOTOR_DIRECTION 		CLOCKWISE
#define STEPS_PER_REVOLUTION  48 // resolution of the stepper motor



/*************************************************************/
#define UNIPOLAR	1
#define BIPOLAR 	2
#define UNIVERSAL 	3


#define NORMAL_STEP_SEQUENCE_4 	0
#define HALF_STEP_SEQUENCE_8 	1
#define WAVE_STEP_SEQUENCE_4	2


#define CLOCKWISE 			0
#define COUNTER_CLOCKWISE 		1


#endif /* STEPPER_CONF_H_ */