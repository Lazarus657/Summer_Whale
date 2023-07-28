//
// Created by lishuainan on 2023/7/25.
//
#include "info.h"
#include "good.h"
#include <stdio.h>
#include <string.h>
static const char * file_path="src/data/good.txt";

void pullGoods(){
    totalGood=0;
    FILE *pf = fopen(file_path,"r");
    if(pf)
    {
        while(fscanf(pf,"%s%s%lf%s%u%s%s",goods[totalGood].id,\
        goods[totalGood].name,&goods[totalGood].price,goods[totalGood].seller_id,\
        &goods[totalGood].state,goods[totalGood].date,goods[totalGood].description)!= EOF)totalGood++;
        fclose(pf);
    }
}

void pushGoods(){
    FILE *pf= fopen(file_path,"w");
    for(int i=0;i<totalGood;i++)
    {
        fprintf(pf,"%s %s %lf %s %u %s %s\n",goods[i].id,\
        goods[i].name,goods[i].price,goods[i].seller_id,\
        goods[i].state,goods[i].date,goods[i].description);
    }
    fclose(pf);
}

Good *getGood(int idx){ return goods+idx;}
///这里说明了数组是一串指针，数组名就是首地址，可以通过增加数字方式增加地址

static const char *stateName[]={"Selling","Sold","Banned"};

int goodInfo(int i){
    printf("ID:          | %s \n",goods[i].id);
    printf("Name:        | %s \n",goods[i].name);
    printf("Description: | %s \n",goods[i].description);
    printf("Date         | %s \n",goods[i].date);
    printf("Price;       | %s \n",goods[i].price);
    printf("Seller:      | %s \n",goods[i].seller_id);
    printf("State:       | %s \n",stateName[goods[i].state]);
}

/**
* @brief 查找给定ID的商品
*
* @param id 需要查找的商品ID
* @return int 成功返回下标，失败返回-1
*/

/*!
 * @brief 新增商品的判断，有没有余量
 */
int addGood(Good *g){
    if (totalGood==MAX_GOOD) return 0;
    genID(g->id,'G');
    ///生成一个id并注册这个id，genID是通过地址传递进行操作的
    getDate(g->date);
    /// 将当下时间丢给g->date字符串,getDate也是通过地址进行参数
    g->state=SELLING;

    goods[totalGood++]=* g;
    return 1;
}

int searchGoodID(const char *id){
    for (int i = 0; i < totalGood; i++) {
        if (strcmp(goods[i].id,id)==0)
            return i;
    }
    return -1;
}
/*!
 * @brief 函数考虑的问题 1.who==0是管理员需要判断，2.需要查找id是否存在
 */

int deleteGood(const char *id,const char * who){
    int idx= searchGoodID(id);
    ///如果查找不到的话返回-1
    if(idx == -1) return 0;
    if(who && strcmp(goods->seller_id,who)) return 0;
    goods[idx].state=BANNED;
    ///这里是商品已下架的意思
    return 1;
}

static const char * header ="|ID         |Name       |Price      |Date       |Seller     |State      |";
static const char * divide ="+-----------+-----------+-----------+-----------+-----------+-----------+";

static void printGood(int i){
    printf("|%-10s |%-10s |%-10.1f |%-10s |%-10s |%-10s |\n",goods[i].id,goods[i].name,goods[i].price,\
    goods[i].date,goods[i].seller_id,goods[i].state);
}

void printGoods()
{
    print_divide
    for (int i = 0; i < totalGood; i++) {
        printGood(i);
        print_divide
    }
}
/**
 * @brief 为买家搜索商品-只搜索正在出售中的商品
 *
 * @param name 待搜索商品的名称
 */
void searchGoodName4Buyer(const char* name){
    print_header
    for (int i = 0; i < totalGood; i++) {
        if(goods[i].state == SELLING && strstr(goods[i].name,name)){
            printGood(i);
            print_divide
        }
        ///strstr()字符串匹配，模糊查找
        }
}

void searchGoodName4Admin(const char* name) {
    print_header
    for (int i = 0; i < totalGood; i++)
        if(strstr(goods[i].name,name)){
            printGood(i);
            print_divide
        }
}

void printGoods4Seller(const char* id){
    print_header
    for (int i = 0; i < totalGood; ++i) {
        if (strcmp(goods[i].seller_id,id)==0){
            printGood(i);
            print_divide
        }
    }
}
/*!
 * @brief 管理员可以查看全部的商品（包括已下架的）
 * 买家只能查看正在销售中的商品
 * 卖家只能查看自己出售的商品
 */
void printGoods4Buyer(const char* id) {
    print_header
    for (int i = 0; i < totalGood; i++)
        if (goods[i].state == SELLING) {
            printGood(i);
            print_divide
        }
}