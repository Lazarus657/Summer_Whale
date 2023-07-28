//
// Created by lishuainan on 2023/7/22.
//
#include "config.h"
#ifndef WHALE_USER_H
#define WHALE_USER_H

typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    char address[MAX_LEN];
    char contact[MAX_LEN];
    char passwd[MAX_LEN];
    double balance;
    /// @brief balance什么意思
}User;

static User users[MAX_USER];
static int totalUser=0;

/// @brief 在静态区域存放全局数组和变量，原因有两个，静态区生命周期与程序相同，静态区内存比较大
void pullUsers();
void pushUsers();
User *getUser( int idex);
/*!
 * @brief 获取用户信息
 */
void userinfo(int i);
/*!
 * @brief 打印用户信息
 */
int addUser(User *u);

int deleteUser(const char *id,const char* who);
/*!
 * @brief 删除指定id
 * @param id 待删除用户id
 * @param who 执行者，管理员为null
 * @return int success 1 fail 0
 */
void printUsers();

int checkPass(const char * name,const char * passwd,int * idx);
/*!
 * @brief 检查用户密码是否匹配
 * @param name 用户名
 * @param passwd 密码
 * @param idx 如果成功，返回指针
 * @return int success 1 fail 0
 */

int userTopUp(const char *id,double m);
/*!
 * @brief 用户充值
 * @param double 充值额度
 */
#endif //WHALE_USER_H
