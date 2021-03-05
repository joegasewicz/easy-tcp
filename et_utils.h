#include <unistd.h>

#define ET_ARG_SERVER "-server"
#define ET_ARG_CLIENT "-client"
#define ET_OPTION_PORT "--port"
#define ET_OPTION_URL "--url"
#define ET_OPTION_METHOD "--method"
#define ET_OPTION_HEADERS "--headers"
#define ET_OPTION_BODY "--body"


typedef struct Application {
    char name[7]; // server or client
} Application;


int display_help();
Application *create_curr_app(char *app_name);
