#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

#include "gpio.h"

#define LED_OUT_R 17
#define LED_OUT_G 27
#define LED_OUT_B 27

#define INTERVAL 1

void (*breakCapture)(int);

void signalingHandler(int signo) 
{
    GPIOUnexport(LED_OUT_R);
    GPIOUnexport(LED_OUT_G);
    GPIOUnexport(LED_OUT_B);
    exit(1);
}

int main(int argc, char *argv[]) 
{
    setsid();
    umask(0);

    breakCapture = signal(SIGINT, signalingHandler);

    /*
     * Enable GPIO pins
     */
    if (-1 == GPIOExport(LED_OUT_R) || -1 == GPIOExport(LED_OUT_G) || -1 == GPIOExport(LED_OUT_B)) 
    {
        return (1);
    }

    /*
     * Set GPIO directions
     */
    if (-1 == GPIODirection(LED_OUT_R, OUT) || -1 == GPIODirection(LED_OUT_G, OUT) || -1 == GPIODirection(LED_OUT_B, OUT)) 
    {
        return (2);
    }

    int count = 0;

    do
    {
        if (-1 == GPIOWrite(LED_OUT_R, true))
            return (3);
        
        if (-1 == GPIOWrite(LED_OUT_R, false))
            return (3);

        if (-1 == GPIOWrite(LED_OUT_G, true))
            return (3);

        if (-1 == GPIOWrite(LED_OUT_G, false))
            return (3);

        if (-1 == GPIOWrite(LED_OUT_B, true))
            return (3);

        if (-1 == GPIOWrite(LED_OUT_B, false))
            return (3);
        
        sleep(INTERVAL);
    } while (count++ < 10);

    /*
     * Disable GPIO pins
     */
    if (-1 == GPIOUnexport(LED_OUT_R) || -1 == GPIOUnexport(LED_OUT_G) || -1 == GPIOUnexport(LED_OUT_B)) 
    {
        return (4);
    }

    return (0);
}