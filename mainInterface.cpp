//
// Created by lishuainan on 2023/7/31.
//
#include "interface.h"

static void USER_Login()  {};
static void USER_SignUp() {};
static void ADMIN_Login() {};
/// @brief 指针函数
static HANDLER handler[] = {USER_Login,USER_SignUp,ADMIN_Login};
make_interface(M,AIN)

static HANDLER handler1[]={inv,inv,inv,inv,inv,inv};
make_interface(A,DMIN)

static HANDLER handler2[]={BUYER_Interface, SELLER_Interface, INFO_Interface};
make_interface(U,SER)

void inv(){
    invalidMessage();
    failureMessage();
}
