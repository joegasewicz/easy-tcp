#include <stdio.h>


int display_help()
{
    printf("Usage easy-tcp [option] [arguments] :\n");
    printf("Options:\n");
    printf("\t-server\t\tStart the TCP server\n");
    printf("\t-client\t\tStart the client\n");
    return 0;
}