/*
 *******************************************************************
 * File Name:    list.h
 * Declaration:  简单列表类型的头文件
 * Author:       jiaga
 * Mail:         jiaga@qq.com
 * Created Time: 2013/12/6 9:53:26
 *******************************************************************
 */

#ifndef LIST_H_
#define LISH_H_
#include <stdbool.h>

/* 特定于程序的声明 */
#define TSIZE 45        /* 存放片名的数组大小 */

struct film {
        char title[TSIZE];
        int rating;
};

/* 一般类型定义 */
typedef struct film Item;

typedef struct node {
        Item item;
        struct node * next;
}Node;

typedef Node * List;

/*
 * 函数原型
 * 操作：       初始化一个列表
 * 操作前：     plist 指向一个列表
 * 操作后:      该列表被初始化为空列表
 */
void InitializeList(List * plist);

/*
 * 操作：       确定列表是否为空列表
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     如果该列表为空则返回true; 否则返回 false
 */
bool ListIsEmpty(const List * plist);

/*
 * 操作：       确定列表是否已满
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     如果该列表已满则返回 true; 否则返回 false
 */
bool ListIsFull(const List *plist);

/*
 * 操作：       确定列表中项目的个数
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     返回该列表中项目的个数
 */
unsigned int ListItemCount(const List *plist);

/*
 * 操作：       在列表尾部添加一个项目
 * 操作前：     item 是要被增加到列表的项目
 *              plist 是指向一个已初始化的新项目
 * 操作后：     如果可能的话，在类表尾部添加一个新项目，
 *              函数返回 true; 否则返回 false
 */
bool AddItem(const Item *pitem, List *plist);

/*
 * 操作：       把一个函数作用域列表中的每个项目
 * 操作前：     plist 指向一个已初始化得列表
 *              pfun 指向一个函数，该函数接受一个 Item 参数并且无返回值
 * 操作后：     pfun 指向的函数被作用到列表中的每个项目一次
 */
void Traverse(const List *plist, void (*pfun)(const Item *pitem));

/*
 * 操作：       释放已分配的内存（如果有）
 * 操作前：     plist 指向一个已初始化的列表
 * 操作后：     为该列表分配的内存已被释放，并且该列表被置为空列表
 */
void EmptyTheList(List *plist);

void showsth(void);

#endif
