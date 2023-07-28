//
// Created by lishuainan on 2023/7/22.
//
#include <iostream>
#include "hint.h"
#include "color.h"
static const char *BANNER="\
\t__          ___           _          __  __            _        _       _\n\
\t\\ \\        / / |         | |        |  \\/  |          | |      | |     | |\n\
\t \\ \\  /\\  / /| |__   __ _| | ___    | \\  / | __ _ _ __| | _____| |_    | |\n\
\t  \\ \\/  \\/ / | '_ \\ / _` | |/ _ \\   | |\\/| |/ _` | '__| |/ / _ \\ __|   | |\n\
\t   \\  /\\  /  | | | | (_| | |  __/   | |  | | (_| | |  |   <  __/ |_    |_|\n\
\t    \\/  \\/   |_| |_|\\__,_|_|\\___|   |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|   (_)\n\
";
static const char* SUCCESS = "\t\t*** Operation Successful! ***";
static const char* FAILURE = "\t\t*** Operation Failed! ***";
static const char* ILLEGAL = "\t\t*** Illegal Input! ***";
static const char* LOADING = "\t\t*** Loading ... ***";
static const char* EXITING = "\t\t*** Exiting ... ***";
static const char* INVALID = "\
\t  _____                           _   _       _   _\n\
\t |_   _|                         | | (_)     | | | |\n\
\t   | |    _ __   __   __   __ _  | |  _    __| | | |\n\
\t   | |   | '_ \\  \\ \\ / /  / _` | | | | |  / _` | | |\n\
\t  _| |_  | | | |  \\ V /  | (_| | | | | | | (_| | |_|\n\
\t |_____| |_| |_|   \\_/    \\__,_| |_| |_|  \\__,_| (_)\n\
";
void welcomeMessage()
{
    printf("\nWelcome to\n");
    printf("%s",BANNER);
    printf("This is a SunnerCode Project for C-beginner\n");
}
void successMessage() { printf("\n%s\n",SUCCESS); }
void failureMessage() { printf("\n%s\n",FAILURE); }
void illegalMessage() { printf("\n%s\n",ILLEGAL); }
void loadingMessage() { printf("\n%s\n",LOADING); }
void exitingMessage() { printf("\n%s\n",EXITING); }
void invalidMessage() {
    printf("\n%s\n",INVALID);
    printf("\nThis function is Waiting For you to Implement...\n\n");
}