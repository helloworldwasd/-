//��ͷ��˫��ѭ������
#pragma once
#include<stdio.h>
#include<stdlib.h>
struct st {
	struct st* prve;     //prve������¼ǰ��
	struct st* next;      //next������¼���
	int n;
};
typedef struct st st;
st* Malloc(int n);   //���ٽڵ�
st* csh(); //��ʼ���ڱ��ڵ�
//˫�������β�� / ˫�������ͷ��
void ListPushBack(st* head, int n); 
void Listheadin(st* head, int n);
//ͷɾ / βɾ
void headdate(st* head);
void PushBackDate(st* head);
//����/���
st* find(st* head, int x);
//�������/ɾ��
void suijichar(st* pos,int x);
void suijidate(st* pos);
//��ӡ / ����
void print(st* head);
void Date(st* head);