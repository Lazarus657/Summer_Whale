#include "hint.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
//
// Created by lishuainan on 2023/7/22.
//
/*!
 * @brief 文件读取方式写GenID函数
 */
static const char *file_path="src/data/id.txt";
void genID(char *dest,char type)
{
    int uid=0,gid=0,oid=0;
    /// @brief 这里读取方式是 file*，还有一种io对象的不知道怎么添加到最后一行
    FILE * pf= fopen(file_path,"r");

    if(pf)
    {

        fscanf(pf,"%d%d%d",&uid,&gid,&oid);
        fclose(pf);
    }
    int id=0;
    /// @brief 打印到屏幕上的id
    switch (type){
        case 'U': id=uid++; break;
        case 'G': id=gid++; break;
        case 'O': id=oid++; break;
    }

    sprintf(dest, "%c%05d", type, id);
    successMessage();
    /// @brief sprintf在这里出错了不知道什么原因
    pf= fopen(file_path,"w");
    fprintf(pf,"%d %d %d",uid,gid,oid);
    fclose(pf);
}
void getDate(char *dest)
{
    time_t  rawtime;
    time(&rawtime);
    struct tm* timeinfo=localtime(&rawtime);
    sprintf(dest,"%d-%d-%d",timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday);
    printf(dest);
}