#include "sense.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <linux/input.h>
#define WHITE 0xFFFF
#define BLACK 0x0000
#define RED 0xF800
#define BLUE 0x001F
#define GREEN 0x07E0

int open_display(void);

void close_display(void);

void display_dot(int, int, int);

void clear_display(void);

void open_input(void);

void closed_input(void);

void check_input(void (*callback)(unsigned int), int);

void handler(unsigned int);

int main(void);
