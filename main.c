#include <stdio.h>
#include "project.h"
#include <unistd.h>
#include "joystick.h"
// #include "input.c"
#include <sense.h>
#include <math.h>
#include <stdlib.h>
// #include "output.c"
#include <signal.h>
#define SHAKE_THRESHOLD
int run=1;
int num1 = 0;
int num2 = 0;

int color = WHITE;
void interrupt_handler(int sig){
    run=0;
}

int main(){
	
	open_input();
	open_display();

	clear_display();

    float threshold=1;
    pi_i2c_t* device;
    coordinate_t data;
    signal(SIGINT, interrupt_handler);
    device=geti2cDevice();
    if (device){
        configureAccelGyro(device);
        /*
        printf("Please leave the Pi flat on the table for calibration\n");
        while(run && getAccelData(device,&data) && data.x!=0.0) {
            usleep(100);
        }
        printf("You may pick up the pi.\n");
        */
        float x=0, y=0,z=0;
        float maxx=0,maxy=0,maxz=0;
        while (run && getAccelData(device,&data)){
		if (num1 > 7) x = 0;
        	if (num1 < 0) x = 7;
        	if (num2 > 7) y = 0;
        	if (num2 < 0) y = 7;

		display_dot(num1, num2, color);

		check_input(handler, 1);
	

            float dx=data.x-x,dy=data.y-y,dz=data.z-z;
            if(dx>maxx) maxx=dx;
            if(dy>maxy) maxy=dy;
            if(dz>maxz) maxz=dz;
            if(dx*dx+dy*dy+dz*dz > threshold) {
                clear_display();
            }
            x=data.x; y=data.y; z=data.z;
        }
    }
	closed_input();
	return 0;
}

//Handler for color changing the etch a sketch game
void handler(unsigned int code) {
	if (code == KEY_LEFT) {
		num2--;
	}
	if (code == KEY_RIGHT) {
		num2++;
	}
	if (code == KEY_DOWN) {
		num1++;
	}
	if (code == KEY_UP) {
		num1--;
	}
	if (code == KEY_ENTER) {
		if (color == WHITE) {
			color = RED;
		} else if (color == RED) {
			color = GREEN;
		} else if (color == GREEN) {
			color = BLUE;
		} else if (color == BLUE) {
			color = BLACK;
		} else {
			color = WHITE;
		}
	}

}
