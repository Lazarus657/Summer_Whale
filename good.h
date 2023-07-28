//
// Created by lishuainan on 2023/7/25.
//
#include "config.h"
#ifndef WHALE_GOOD_H
#define WHALE_GOOD_H
typedef enum {SELLING,SOLD,BANNED} State;
///selling=0,sold=1,banned=2;

typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    State state;
    char date[MAX_LEN];
    char description[MAX_LEN];
}Good;

static Good goods[MAX_GOOD];
static int totalGood=0;

void pullGoods();

void pushGoods();

Good *getGood(int idx);

int addGood(Good *g);

int searchGoodID(const char *id);

int deleteGood(const char * id,const char * who);

int goodInfo(int i);

void printGoods();

void searchGoodName4Buyer(const char * name);

void searchGoodName4Admin(const char * name);

void printGood4Seller(const char * id);

void printGoods4Buyer(const char *id);






#endif //WHALE_GOOD_H
