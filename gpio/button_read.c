#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

#include "gpio.h"

#define BUTTON_IN 16 

#define INTERVAL 1

void (*breakCapture)(int);

void signalingHandler(int signo) 
{
    GPIOUnexport(BUTTON_IN);
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
    if (-1 == GPIOExport(BUTTON_IN)) 
    {
        return (1);
    }

    /*
     * Set GPIO directions
     */
    if  (-1 == GPIODirection(BUTTON_IN, IN)) 
    {
        return (2);
    }

    int count = 0;

    do
    {
        int button_status = GPIORead(BUTTON_IN);

        printf("Button : %d from pin %d\n", button_status, BUTTON_IN);

        sleep(INTERVAL);
    } while (count++ < 10);

    /*
     * Disable GPIO pins
     */
    if (-1 == GPIOUnexport(BUTTON_IN)) 
    {
        return (4);
    }

    return (0);
}