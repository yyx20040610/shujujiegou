#include<iostream>
using namespace std;
#include<string>
int* createNext(string m){
    int *a;
    a[0]=-1;
    int i=0,k=-1;
    while(i<m.size()-1){
        while(k>=0&&m[i]!=m[k]){
            k=a[k];
        }
        i++;k++;
        if(m[i]==m[k])a[i]=a[k];
        else a[i]=k;
    }
    return a;
}
int find(string o,string m){
    int* next=createNext(m);
    int i,j;
    i=0,j=0;
    while(i<m.size()&&j<o.size()){
        if(i==1||m[i]==o[i]){
            i++;j++;
        }
        else i=next[i];
        if(i>=m.size()) return(j-m.size()+1);
        else return -1;
    }
}

int main(){
    cout<<"hello world\n";
    string O,M;
    cin>>O>>M;
    printf("%d",find(O,M));

}