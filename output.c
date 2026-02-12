#include<stdlib.h>
#include"project.h"
#include <unistd.h>
#include "joystick.h"
#define RED 0xF800
#define GREEN 0x07E0
#define BLACK 0x0000
pi_framebuffer_t *fb;
sense_fb_bitmap_t *bm;

//Initialize the frame buffer
int open_display(void) {
	if (fb = getFrameBuffer()) {
		bm = fb->bitmap;
		return 1;
	} else { return 0;
}

}

void clear_display(void) {
	clearFrameBuffer(fb, BLACK);
}

void close_display(void) {
	clear_display();
	freeFrameBuffer(fb);
}

void display_dot(int x, int y, int color) {
	x = ((x % 8) + 8 )% 8;
	y = ((y % 8 )+ 8 )% 8;
	bm->pixel[x][y]=color;
}
