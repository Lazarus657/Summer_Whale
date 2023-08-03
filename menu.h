//
// Created by lishuainan on 2023/7/28.
//

#ifndef WHALE_MENU_H
#define WHALE_MENU_H

extern const int optionNum[];

///菜单类型
typedef enum{MAIN,ADMIN,USER,BUYER,SELLER,INFO,MODIFY,GOOD} Menu ;
int menu(Menu type);

#endif //WHALE_MENU_H
