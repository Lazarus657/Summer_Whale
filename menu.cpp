//
// Created by lishuainan on 2023/7/28.
//
#include "hint.h"
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
int mainMenu(){
    printf("\
\t\t\tMain Menu\n\
+==============+================+===============+========+\n\
| 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |\n\
+==============+================+===============+========+\n");
    printf("Please choose operation:");
    char buffer[MAX_LEN];
    int res;
    scanf("%s",buffer);
    ///数组名其实就是一个指针
    res=atoi(buffer);
    ///aoti的作用是将任意的输入的字符串转换为整形；转换失败和转换长度高都是非法的
    while(1){
        if(res >= 1 && res <= 4) break;
        illegalMessage();
        printf("Please try again: ");
        scanf("%s",buffer);
        res= atoi(buffer);
    }
    return res;
}
