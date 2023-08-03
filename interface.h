//
// Created by lishuainan on 2023/7/28.
//

#ifndef WHALE_INTERFACE_H
#define WHALE_INTERFACE_H

#include "hint.h"
#include "menu.h"
#include "user.h"
#include "good.h"
#include "order.h"

#define get_username_passwd \
    char username[MAX_LEN]; \
    char passwd[MAX_LEN];   \
    printf("Username: ");   \
    scanf("%s",username);   \
    printf("Password:");    \
    scanf("%s",passwd);     \

#define make_login(T,YPE,cond) \
static void T#YPE##_login() { \
    get_username_passwd \
    if (cond) {T#YPE##_Interface(); return ;} \
    failureMessage(); \

#define make_interface(T, YPE)\
void T##YPE##_Interface() {\
    successMessage();\
    int op = menu(T##YPE);\
    while (op != optionNum[T##YPE]) {\
        loadingMessage();\
        handler[op - 1]();\
        op = menu(T##YPE);\
    }\
    loadingMessage();\
    successMessage();\
}

typedef void(*HANDLER)(void);

void inv();

void MAIN_Interface();

void ADMIN_Interface();

void USER_Interface();

void BUYER_Interface();

void SELLER_Interface();

void INFO_Interface();

void MODIFY_Interface();


#endif //WHALE_INTERFACE_H
