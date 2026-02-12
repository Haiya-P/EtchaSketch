#include "project.h"


pi_joystick_t* joystick;

void open_input(void){
	joystick = getJoystickDevice();
}

void closed_input(void) {
	freeJoystick(joystick);
}

void check_input(void (*callback)(unsigned int code), int delay) {
	pollJoystick(joystick, callback, delay);
}
