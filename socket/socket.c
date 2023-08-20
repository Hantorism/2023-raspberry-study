#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <curl/curl.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "../include/socket.h"

#define SENDER_PORT 10000

#define RECEIVER_PORT 10000
#define RECEIVER_ADDRESS "192.168.0.1"

#define INTERVAL 3 

char send_packet[8] = "NONE";
char **recv_packet = NULL;

int *random_number = 0;

void *socket_sender_thd() {
    socket_sender_info *sender_args = (socket_sender_info *)malloc(sizeof(socket_sender_info));

    sender_args->port = SENDER_PORT;
    sender_args->packet = send_packet;
    
    socket_sender(sender_args, INTERVAL);

    return 0;
}

void *socket_receiver_thd(void *receiver_args) {
    socket_receiver_info *receiver_info = (socket_receiver_info *)receiver_args;

    receiver_info->address = RECEIVER_ADDRESS;
    receiver_info->port = RECEIVER_PORT;
    receiver_info->packet = NULL;
    
    recv_packet = &receiver_info->packet;

    socket_receiver(receiver_info, INTERVAL);

    return 0;
}

void status_thd() {
    srand(time(NULL));

    while (1) {
        int random_number = rand() % 10;

        sprintf(send_packet, "%d", random_number);

        if (recv_packet != NULL) {
            printf("%s\n", *recv_packet);
        }
    }
}

int main() {
    signal(SIGPIPE, SIG_IGN);

    pthread_t p_thread[3];

    socket_receiver_info *receiver_args = (socket_receiver_info *)malloc(sizeof(socket_receiver_info));

    int status;

    thread_creater(&p_thread[0], status_thd, NULL);
    thread_creater(&p_thread[1], socket_sender_thd, NULL);
    thread_creater(&p_thread[2], socket_receiver_thd, (void *)receiver_args);

    thread_joiner(p_thread, (void **)&status, sizeof(p_thread) / sizeof(pthread_t));

    return 0;
}