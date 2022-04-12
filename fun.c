#include"head.h"
static st* Malloc(int n) {   //����һ���ڵ�
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
st* csh() {  //��ʼ���ڱ��ڵ�
	st* p=Malloc(0);
	p->next = p;
	p->prve = p;    //�ýڵ��next��prveָ������
	return p;
}
st* find(st* head, int x){   //����
	st* list = head->next;  //�ӵ�һ���ڵ㿪ʼ����
	while (list != head) {
		if (list->n == x) {
			return list;     //���ص�ǰ�ڵ�ĵ�ַ
		}
		list = list->next;
	}
	return NULL;
}
void ListPushBack(st* head, int n) {  //˫�������β��
	st* list = head->prve;   //ѭ���б��У�ͷ�ڵ��ǰ����β�ڵ�
	st* newnode=Malloc(n);
	list->next = newnode;
	newnode->prve = list;
	newnode->next = head;
	head->prve = newnode;
	//��û�нڵ�ʱ��head��ǰ���ͺ�̷ֱ�ָ���������Գ�����
}
void Listheadin(st* head, int n) {  //˫�������ͷ��
	st* list = head->next;
	st* newnode = Malloc(n);
	list->prve = newnode;
	newnode->prve = head;
	newnode->next = list;
	head->next = newnode;
}
void headdate(st* head) {   //ͷɾ
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
void PushBackDate(st* head) { //βɾ
	if (head->prve == head) {   //�������ڱ��ڵ�֮��û�������ڵ�ʱ
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
void suijichar(st* pos,int x) {  //��pos��ַ��֮ǰ����ڵ�
	st* newnode=Malloc(x);
	st* list = pos->prve;
	list->next = newnode;
	newnode->next = pos;
	newnode->prve = list;
	pos->prve = newnode;
}
void suijidate(st* pos) {  //ɾ��pos�ڵ�
	st* node = pos->prve;
	st* node2 = pos->next;
	node->next = node2;
	node2->prve = node;
}
void print(st* head) {  //��ӡ����
	st* list = head->next;
	while (list != head) {
		printf("%d ", list->n);
		list = list->next;
	}
	printf("\n");
}
void Date(st* head) {  //��������
	st* list = head->next;
	while (list != head) {
		st* node = list->next;   //�Ƚ���һ���ڵ�ĵ�ַ����
		free(list);
		list = node;
	}
	free(head);
	head = NULL;
}