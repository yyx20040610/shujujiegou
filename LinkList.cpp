#include<iostream>
#define datatype int
using namespace std;
struct node;
typedef node *pn;
struct node {
	datatype val;
	pn link;
};
typedef struct node* LinkList;
LinkList createNullList(void) {
	LinkList p = (LinkList)malloc(sizeof(node));
	if (p == NULL) {
		cout << "fail to malloc new space for you\n";
	}
	else {
		p->link = NULL;
	}
	return p;
}
bool isNull(pn p) {
	return (p->link == 0);

}
pn locate_val(LinkList ph, datatype x) {
	pn p;
	if (isNull == 0) {
		cout << "no exist\n"; return NULL;
	}
	p = ph->link;
	while (p->link != NULL && p->val != x) {
		p = p->link;
	}
	if (p == NULL) {
		cout << "no exist\n"; return NULL;
	}
	else {
		return p;
	}
}
bool insertPost_Link(LinkList list, pn p, datatype x) {
	pn new_p = (pn)malloc(sizeof(node));
	if (new_p == NULL) {
		cout << "Out of space!!\n";
		return 0;
	}
	else {
		new_p->link = p->link;
		new_p->val = x;
		p->link = new_p;
		return 1;
	}
}
pn find_seq(LinkList list, int num) {
	pn point = list->link; int i = 0;
	while (point != NULL) {
		if (i != num) {
			++i; point = point->link;
		}
		else {
			return point;
		}
	}
	cout << "no exist\n";
	return NULL;
}
pn locatePre_link(LinkList list, pn p) {
	pn pre;
	if (list == NULL)return NULL;
	pre = list;
	while (pre!=NULL&&pre->link != p) {
		pre = pre->link;
	}
	return pre;
}
bool deleteV_link(LinkList list, datatype x) {
	pn p, q;
	if (p == NULL)return 0;
	while (p->link != NULL && p->link->val != x) {
		p = p->link;
	}
	if(p->link==NULL){
		cout<<"no exist\n";
		return 0;
	}
	else{
		q=p->link;
		p->link=q->link;
		free(q);
		return 1;
	}
}
