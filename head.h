//带头的双向循环链表
#pragma once
#include<stdio.h>
#include<stdlib.h>
struct st {
	struct st* prve;     //prve用来记录前驱
	struct st* next;      //next用来记录后继
	int n;
};
typedef struct st st;
st* Malloc(int n);   //开辟节点
st* csh(); //初始化哨兵节点
//双向链表的尾插 / 双向链表的头插
void ListPushBack(st* head, int n); 
void Listheadin(st* head, int n);
//头删 / 尾删
void headdate(st* head);
void PushBackDate(st* head);
//查找/查改
st* find(st* head, int x);
//随机插入/删除
void suijichar(st* pos,int x);
void suijidate(st* pos);
//打印 / 销毁
void print(st* head);
void Date(st* head);