#include<iostream>
using namespace std;
#define datatype int
struct SeqList {
	int Max;
	int n;
	datatype *ele;
};
typedef SeqList* pl;
pl createNullList(int m) {
	pl pi = (pl)malloc(sizeof(SeqList));
	if (pi != NULL) {
		pi->ele = (datatype*)malloc(m * sizeof(datatype));
		if (pi->ele) {
			pi->Max = m;
			pi->n = 0;
			return pi;
		}
		else {
			free(pi);
		}
	}
	cout << "Out of space!!\n";
	return NULL;
}
bool isNullList(pl pi) {
	return pi->n == 0;
}
int locate(pl pi, datatype x) {
	int ans;
	for (ans = 0; ans < pi->n; ++ans) {
		if (pi->ele[ans] == x)
			return ans;
	}
	return -1;
}
bool insertPre(pl pi, int k, datatype x) {
	int pii;
	if (pi->n == pi->Max) {
		cout << "Out flow!!\n";
		return 0;
	}
	if (k<0 || k>pi->n) {
		cout << "No exist\n";
		return 0;
	}
	for (pii = pi->n - 1; pii >= k; pii--) {
		pi->ele[pii + 1] = pi->ele[pii];
		pi->ele[k] = x;
		pi->n++;
		return 1;
	}
}
void print(pl pi) {
	if (pi->n == 0) {
		cout << "is Null" << '\n';
		return;
	}
	cout << "Seq List is:\n";
	for (int i = 0; i < pi->n-1; i++) {
		cout << pi->ele[i]<<' ';
	}
	cout << pi->ele[pi->n - 1]<<"\nthe end\n";
	return;
}
bool insertPost(pl pi, int p, datatype x) {
	return insertPre(pi, p + 1, x);
}int delete_P(pl pi, int p) {
	int q;
	if (p < 0 || p >= pi->n) {
		cout << "no exist!\n";
		return 0;
	}
	for (q = p; q < pi->n-1; ++q) {
		pi->ele[q] = pi->ele[q + 1];
	}
	pi->n--;
	return 1;
}
bool delete_V(pl pi,datatype x) {
	int position = locate(pi, x);
	if (position == -1) {
		cout << "no exist";
		return 0;
	}
	return delete_P(pi, position);
}
