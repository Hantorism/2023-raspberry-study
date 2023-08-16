#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include "lcd.h"

#define LCD_ADDRESS 0x27

#define INTERVAL 3

int main() {
    if (wiringPiSetup () == -1) exit (1);

    int fd = wiringPiI2CSetup(LCD_ADDRESS);

    lcd_init(fd);

    char line1[16] = "Hello, World!";
    char line2[16] = "Have a nice day!";

    char line3[16] = "Hello, Raspberry!";
    char line4[16] = "Welcome to System!";

    int count = 0;

    do {    
        lcd_clear(fd);
        lcd_cursor_move(fd, LCD_CURSOR_LINE1);
        lcd_write_string(fd, line01);
        lcd_cursor_move(fd, LCD_CURSOR_LINE2);
        lcd_write_string(fd, line02);
        lcd_delay(INTERVAL);

        lcd_clear(fd);
        lcd_cursor_move(fd, LCD_CURSOR_LINE1);
        lcd_write_string(fd, line03);
        lcd_cursor_move(fd, LCD_CURSOR_LINE2);
        lcd_write_string(fd, line04);
        lcd_delay(INTERVAL);
    } while (count++ < 10);


    return 0;
}