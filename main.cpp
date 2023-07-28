// main.c
#include "color.h" // 包含头文件color.h
#include <stdio.h>
#include "hint.h"
#include "info.h"
const char* hello = "Hello, WinterCode!";
char myid[20];
char mytime[20];
int main() {

    welcomeMessage();
    genID(myid,'U');
    getDate(mytime);
    return 0;
}