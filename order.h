//
// Created by lishuainan on 2023/7/28.
//

#ifndef WHALE_ORDER_H
#define WHALE_ORDER_H

#include "config.h"

typedef struct {
    char id[MAX_LEN];
    char good_id[MAX_LEN];
    double price;
    char date[MAX_LEN];
    char seller_id[MAX_LEN];
    char buyer_id[MAX_LEN];
}Order;

void pullOrders();

/// @brief pull all order information from external file

void pushOrders();

/// @brief push all order information into external file

int addOrder(Order* o);

/*!
 * @brief  param o order to added
 * @return int 0 if failed else 1
 */

void printOrders();

/// @brief print all order's information

void printOrdersSeller(const char  *id);

void printOrdersBuyer(const char *id);


#endif //WHALE_ORDER_H
