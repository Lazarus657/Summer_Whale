//
// Created by lishuainan on 2023/7/23.
//
#include "info.h"
#include "user.h"
#include <stdio.h>
#include <string.h>
static const char *file_path="src/data/user.txt";

void pullUsers()
{
    totalUser=0;
    FILE *pf = fopen(file_path,"r");
    if(pf)
    {
        while (fscanf(pf, "%s%s%s%s%s%lf", users[totalUser].id, \
                users[totalUser].name, users[totalUser].passwd, users[totalUser].contact, \
                users[totalUser].address, &(users[totalUser].balance)) != EOF) totalUser++;
        fclose(pf);
    }
}

void pushUsers()
{
    FILE *pf= fopen(file_path,"w");
    for (int i=0;i<totalUser;i++)
        fprintf(pf,"%s %s %s %s %s %.1f\n",users[i].id,\
        users[i].name,users[i].passwd,users[i].contact,users[i].address,\
        users[i].balance);
    fclose(pf);
}

void userinfo(int i)
{
    printf("ID:        | %s\n", users[i].id);
    printf("Name:      | %s\n", users[i].name);
    printf("Contact:   | %s\n", users[i].contact);
    printf("Address:   | %s\n", users[i].address);
    printf("Balance:   | %.1f\n", users[i].balance);
}

static int searchUserName(const char *name){
    for (int i=0;i<totalUser;i++)
        if(strcmp(users[i].name,name)==0)
            return i;
    return -1;
}

int addUser(User *u)
{
     /*!
      * @brief 1.已经到达最大的用户数，2.用户已经存在
      */
    if(totalUser=MAX_USER) return 0;
    if(searchUserName(u->name) !=-1) return 0;
    genID(u->id,'U');
    users[totalUser++]= * u;
    //两步操作，1.将用户添加到user数组中
    //2.genID生成唯一id记录
    return 1;
}

/*!
 * @brief 查找指定的ID用户
 * 遍历用户，用strcmp函数判断是否
 */
 static int searchUserID(const char *id)
{
     for(int i=0;i<totalUser;i++)
     {
         if(strcmp(users[i].id,id)==0) return i;
     }
    return -1;
}

/*!
 * @brief 删除指定用户
 * search函数搜索，然后，这里是线性表要怎么操作，后面idex都上移一位
 */
int deleteUser(const char *id,const char* who)
{
    if(who) return 0;
    //如果不是管理员，则不能进行操作
    int idx= searchUserID(id);
    if(idx==-1) return 0;
    for (int j = idx; j <totalUser-1; j++) {
        users[j]=users[j++];
    }
    totalUser--;
    return 1;
}

/*!
 * @brief 打印所有用户信息
 */

static const char * header= "|ID         |Name       |Contact    |Address    |Balance    |";
static const char * divide= "+-----------+-----------+-----------+-----------+-----------+";

static void printUser(int i){
    printf("|%-10s |%-10s |%-10s |%-10s |%-10.1f |\n", users[i].id, users[i].name, users[i].contact,\
    users[i].address,users[i].balance );
}

void printUsers(){
    print_header
    for(int i=0;i<totalUser;i++){
        printUser(i);
        print_divide
    }
}

int checkPass(const char * name,const char * passwd,int * idx)
{
    *idx= searchUserName(name);
    if (*idx==-1) return 0;
    return strcmp(users[*idx].passwd,passwd) == 0;
}

/// 一个函数只能有一个返回值，所以我们通过指针参数确定返回哪个用户成功匹配，也就是*idx

int userTopUp(const char* id, double m) {
    int idx= searchUserID(id);
    if(idx==-1) return 0;
    users[idx].balance+=m;
    return 1;
}