#include"head.h"
int main() {
	st* head = NULL;
	head=csh();
	ListPushBack(head,2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	Listheadin(head, 1);
	headdate(head);
	PushBackDate(head);
	st* t = find(head,3);
	if (t == NULL) {
		printf("Î´ÕÒµ½½Úµã\n");
	}
	else {
		suijichar(t, 2);
		suijidate(t);
	}
	print(head);
}