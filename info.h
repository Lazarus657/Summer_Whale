//
// Created by lishuainan on 2023/7/22.
//

#ifndef WHALE_INFO_H
#define WHALE_INFO_H

#define print_header \
     printf("%s\n",divide); \
     printf("%s\n",header); \
     printf("%s\n",divide);

#define print_divide \
    printf("%s\n",divide);
void genID(char *dest,char type);
/*!
 * @brief 生成一个给定的Id
 */
/// @param dest 目标的字符串
/// @param type 一共有三种类型 U-用户，G-商品，O-订单
void getDate(char *dest);
/*!
 * @brief 获得当前的日期
 */
 /// @param dest 储存日期的目标字符串


#endif //WHALE_INFO_H
