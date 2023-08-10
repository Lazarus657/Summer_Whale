你好旧时光

## 2023-07-22

工作记录：

主要工作，配置环境，写了info函数，hint函数，color函数

遇到的问题，终端无法输出彩色字符，查阅是终端无法转义ANSI字符，在win出现，没有解决方法

info函数中

```c
sprintf（dest，“%c%05d”，type，id）
```

有问题，还没解决，推测是dest的定义问题

time函数![image-20230722220513786](C:\Users\lishuainan\AppData\Roaming\Typora\typora-user-images\image-20230722220513786.png)

## 2023-07-23

一些编写代码的规范

- 在导入头文件的时候，先包含用户自带的头文件，在包含系统头文件
- static关键字和const关键字，例如在user

昨天的工作

- user函数，主要是与txt文件的交互，还有逻辑的判断，

## 2023-07-24

```c
printf("%-10s")；
//左对齐并占用宽度为 10 的字符串
```

```c
#define printf_header printf("%s\n",header);
#define printf_divide printf("%s\n",divide);
//两个宏定义，定义在info.h函数之中
//并且在good，user，order中都有局部变量的定义
```

## 2023-07-27

- [ ] 在c++中双引号和单引号区别

```c
"abc"//表示的是一个string字符串
'abc'//表示的是一个char型字符
```

- [ ] `strstr()`的使用

- 描述

  **char \*strstr(const char \*haystack, const char \*needle)** 在字符串 **haystack** 中查找第一次出现字符串 **needle** 的位置，不包含终止符 '\0'。

- 举例

  ```c
  #include <stdio.h>
  #include <string.h>
   
  int main()
  {
     const char haystack[20] = "RUNOOB";
     const char needle[10] = "NOOB";
     char *ret;
   
     ret = strstr(haystack, needle);
   
     printf("子字符串是： %s\n", ret);
     
     return(0);
  }
  ```

  ​	执行结果

  ```c
  子字符串是： NOOB
  ```

  7.28

  问题描述：在新建一个git仓库时，遇到了master和main不能合并的问题，解决办法如下：

  ```c
  # 切换分支至master
  git checkout master
  # 强制重命名master分支为main分支
  git branch main master -f
  # 切换分支至main
  git checkout main
  # 强制推送本地main分支至远程库，并覆盖远程main分支内容
  git push origin main -f
  ```

  另外一些基础的git命令

  ```c
  git init #初始化仓库
  git add . #添加所有文件到暂存区
  git commit -m "commit" #添加上传标题
  git remote add origin ssh #链接目标地址
  git rm remote #清除远端地址
  git push origin master #上传文件
  ```

  封装设计各个界面的菜单
  
  主要有两个问题
  
  - 程序的健壮性，如果有非法的输入怎么办
  - 类似菜单怎么样更合理的编写，因为重复的菜单很多
  
   
  
  突然有一个问题就是子程序定义的全局变量是会调用如果被其他头文件引用，和一个静态局部变量被其他一个头文件引用
  
  extern 关键字怎么使用，就是全局搜索
  
  ## 7.30
  
  ### menu.c的实现（封装各个界面）
  
  ![](C:\Users\lishuainan\AppData\Roaming\Typora\typora-user-images\image-20230730230524102.png)

利用数组建立枚举类型和字符串之间的映射关系 `Menu：typedef enum{ }Menu`

通过哈希表建立枚举数据和表之间的映射关系

通过数组建立枚举类型和选择项目数量之间的关系，

```c
const int optionNum[MENU_NUM] = {4, 7, 4, 6, 6, 4, 4, 4};
```



###  interface界面

一共要实现八个菜单界面，需要设计前端和后端（类似于）

1. 交互界面的功能是什么

   - 显示菜单
   - 获取用户的输入，处理用户的输入
   - 重复上述步骤，知道用户退出界面

2. 前端界面的实现，为了不适用大量的if-else结构，使用了枚举类型结构，建立整数和函数之间的映射关系

   > `optionNum`在menu.c中

```c
typedef void (*HANDLER)(void);
static HANDLER handler[] = {USER_Login, USER_SignUp, ADMIN_Login};
```

```c
void MAIN_Interface() {
    successMessage();
    int op = menu(MAIN);
    while (op != optionNum[MAIN]) {
        loadingMessage();
        handler[op - 1]();
        op = menu(MAIN); 
    }
    loadingMessage();
    successMessage();
}
```







