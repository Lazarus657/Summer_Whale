//
// Created by lishuainan on 2023/7/28.
//
#include "hint.h"
#include "config.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

static const char * menuPrompts[MENU_NUM]= {"\
+==============+================+===============+========+\n\
| 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |\n\
+==============+================+===============+========+\n", \
"\
+=========+==========+==========+=========+==========+=======+========+\n\
| 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |\n\
+=========+==========+==========+=========+==========+=======+========+\n ", \
"\
+=========+==========+==============+========+\n\
| 1.Buyer | 2.Seller | 3.Infomation | 4.Back |\n\
+=========+==========+==============+========+\n", \
"\
+=========+=======+==========+=========+===============+========+\n\
| 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Information | 6.Back |\n\
+=========+=======+==========+=========+===============+========+\n", \
"\
+========+=========+==========+=======+=========+========+\n\
| 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |\n\
+========+=========+==========+=======+=========+========+\n", \
"\
+===============+==========+==========+========+\n\
| 1.Information | 2.Modify | 3.Top Up | 4.Back |\n\
+===============+==========+==========+========+\n", \
"\
+============+===========+===========+========+\n\
| 1.Password | 2.Contact | 3.Address | 4.Back |\n\
+============+===========+===========+========+\n", \
"\
+========+=========+===============+========+\n\
| 1.Name | 2.Price | 3.Description | 4.Back |\n\
+========+=========+===============+========+\n"};

static const char *menuNames[MENU_NUM]={"Main","Admin","User","Buyer","Seller","Information","Modify"};
const int optionNum[MENU_NUM]={4,7,4,6,6,4,4,4};
///optionNum不是一个静态局部变量，可以被其他文件引用！

static void promptMessage(Menu type)
{
    printf("\t\t\t%s%s Menu%\n",menuNames[type]);
    printf("%s\nPlease choose operation: ",menuPrompts[type]);
}

/**
 * @brief 菜单的作用是给出提示信息并获取用户输入
 *
 * @param type 菜单类型
 * @return int 用户的有效输入
 */

int menu(Menu type){
    promptMessage(type);
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

