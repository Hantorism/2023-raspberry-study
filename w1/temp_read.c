#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define INTERVAL 1

int main() {
    while (1) {
        int fd = open("/sys/bus/w1/devices/28-0416b05be4ff/w1_slave", O_RDONLY);
        char buf[256];

        read(fd, buf, 256);

        int i = 0;
        for (i = 0; i < 256; i++) {
            if (buf[i] == 't' && buf[i + 1] == '=') {
                break;
            }
        }

        char *temp = (char *)malloc(sizeof(char) * 6);
        strncpy(temp, buf + i + 2, 5);
        temp[5] = '\0';

        printf("Temp: %.3lfc\n", atoi(temp) / 1000.0);

        close(fd);

        sleep(INTERVAL);
    }

    return 0;
}