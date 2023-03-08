#include<iostream>
using namespace std;
struct str{
    int n;
    int Max;
    char* s;
};
typedef str* pstr;
pstr createNullStr(int m){
    pstr p=(pstr)malloc(sizeof(str));
    if(p!=NULL){
        p->s=(char*)malloc(sizeof(char)*m);
        if(p->s!=NULL){
            p->Max=m;
            p->n=0;
            return p;
        }
        else free(p);
    }
    cout<<"out of space";
    return NULL;
}