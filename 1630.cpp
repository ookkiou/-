#include <iostream>
using namespace std;
int del(int *arr,int n,int &len){
    int a=arr[n];
    for(int i=n;i<len;i++){
        arr[i]=arr[i+1];
    }
    len=len-1;
    return a;
}

void JosephRing(int *arr,int n,int *m,int chushi){
    int x=0;
    int len=n;
    int i=chushi;
    while(len>1){
        x=(x+m[i]-1)%len;
        int a = del(arr,x,len);
        cout<<a<<" ";
        i=a-1;
    }
    cout<<arr[0]<<endl;
}

int main(){
    cout<<"entet people count"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    int m[n];
    int chushi;
    cout<<"enter initial password"<<endl;
    cin>>chushi;
    cout<<"enter everyones password"<<endl;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    cout<<"this is"<<endl;
    JosephRing(arr,n,m,chushi);
    return 0;
}
