#include<iostream>
using namespace std;
typedef struct node{
	int data;
	struct node* next;
}Node;

Node* CreatList(int n)//创建循环链表
{
	Node* head=(Node*)malloc(sizeof(Node));
	Node* newnode;
	Node* tail=head;
	for (int i=1;i<=n;i++)
	{
		newnode=(Node*)malloc(sizeof(Node));
		newnode->data =i;
		tail->next =newnode;
		newnode->next =NULL;
		tail=newnode;
	}
	tail->next =head->next ; 
	return head;
}

void JosephRing(Node* head,int num[],int kaishi)
{
	Node* aim;
	Node* move=head->next;
    int k=kaishi;
	while (move->next!=move)  
	{
		for (int i=1;i<num[k]-1;i++) 
		{
			move=move->next ;
		} 
		aim=move->next;      
		cout<<aim->data<<" ";
		move->next =aim->next;
		move=move->next ;
		k=(aim->data)-1;
		free(aim);            
		aim=NULL;
	}
	cout<<move->data;//最后一个数
} 

int main(void)
{
	Node* bb;
	int n;  
	int kaishi;

	cout<<"people"<<endl;
	cin>>n;
	int num[n]; 
	cout<<"kaishi"<<endl;
	cin>>kaishi;
	cout<<"mima"<<endl;
    for(int i=0;i<n;i++)
	{cin>>num[i];}
	Node* a=CreatList(n);
	Node* move=a->next;
	for(int j=0;j<4;j++){
		move=move->next;
	}
	cout<<move->data;
	bb=CreatList(n);
	cout<<"this"<<endl;	
	JosephRing(bb,num,kaishi);


	return 0;
}