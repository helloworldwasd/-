#include"head.h"
static st* Malloc(int n) {   //开辟一个节点
	st* p =(st*)malloc(sizeof(st));
	if (p == NULL) {
		printf("malloc error\n");
		exit(0);
	}
	else {
		p->n = n;
		p->prve = NULL;
		p->next = NULL;
		return p;
	}
}
st* csh() {  //初始化哨兵节点
	st* p=Malloc(0);
	p->next = p;
	p->prve = p;    //该节点的next与prve指向自身
	return p;
}
st* find(st* head, int x){   //查找
	st* list = head->next;  //从第一个节点开始查找
	while (list != head) {
		if (list->n == x) {
			return list;     //返回当前节点的地址
		}
		list = list->next;
	}
	return NULL;
}
void ListPushBack(st* head, int n) {  //双向链表的尾插
	st* list = head->prve;   //循环列表中，头节点的前驱是尾节点
	st* newnode=Malloc(n);
	list->next = newnode;
	newnode->prve = list;
	newnode->next = head;
	head->prve = newnode;
	//当没有节点时，head的前驱和后继分别指向自身，所以成立。
}
void Listheadin(st* head, int n) {  //双向链表的头插
	st* list = head->next;
	st* newnode = Malloc(n);
	list->prve = newnode;
	newnode->prve = head;
	newnode->next = list;
	head->next = newnode;
}
void headdate(st* head) {   //头删
	if (head->next == head) {
		printf("date error!\n");
		exit(0);
	}
	else {
		st* list = head->next;
		st* node = list->next;
		head->next = list->next;
		node->prve = head;
		free(list);
	}
}
void PushBackDate(st* head) { //尾删
	if (head->prve == head) {   //当除了哨兵节点之外没有其他节点时
		printf("data error!\n");
		exit(0);
	}
	else {
		st* list = head->prve;
		st* node = list->prve;
		node->next = head;
		head->prve = node;
		free(list);
	}
}
void suijichar(st* pos,int x) {  //在pos地址处之前插入节点
	st* newnode=Malloc(x);
	st* list = pos->prve;
	list->next = newnode;
	newnode->next = pos;
	newnode->prve = list;
	pos->prve = newnode;
}
void suijidate(st* pos) {  //删除pos节点
	st* node = pos->prve;
	st* node2 = pos->next;
	node->next = node2;
	node2->prve = node;
}
void print(st* head) {  //打印链表
	st* list = head->next;
	while (list != head) {
		printf("%d ", list->n);
		list = list->next;
	}
	printf("\n");
}
void Date(st* head) {  //销毁链表
	st* list = head->next;
	while (list != head) {
		st* node = list->next;   //先将下一个节点的地址保存
		free(list);
		list = node;
	}
	free(head);
	head = NULL;
}