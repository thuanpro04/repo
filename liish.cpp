#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
typedef struct Node node;
struct List
{
    /* data */
    node *first;
    node *last;
};
typedef struct List list;
// Khởi tạo 2 con trỏ đầu cuối
void Khoi_tao (list &l)
{
    l.first= l.last= NULL;
}
node* GetNode(int x)
{
    node *p= new node;
    if(p==NULL)
    {
        cout<<"Ko du bo nho. ";
        return NULL;
    }
    p->data=x;
    p->next=NULL;
    return p;
}
void InsertFirst_element(list &l, node *p)
{
    if(l.first==NULL) // danh sách rỗng
    {
        l.first= l.last= p;
    }
    else
    {
        p->next=l.first;
        l.first=p;
    }
}
void InsertLast_element(list &l, node *p)
{
    if(l.first==NULL) // danh sách rỗng
    {
        l.first= l.last= p;
    }
    else
    {
        l.last->next=p;
        l.last=p;
    }
}
void Input(list &l)
{
    int n;
    cout<<"Nhap so luong Node: ";
    cin>>n;
    Khoi_tao(l);
    for(int i=1; i<=n; i++)
    {
        int x;
        cout<<"Nhap data: ";
        cin>>x;
        node *p= GetNode(x);
        InsertLast_element(l, p);
    }
}
void OutPut(list l)
{
    for(node *p= l.first; p!=NULL ; p=p->next )
    {
        cout<<p->data <<" " << p->next<<endl;
    }
}
void Delete_First(list &l)
{
    if(l.first == NULL)
    {
        return;
    }
    node *p= l.first;
    l.first= l.first->next;
    delete p;
    OutPut(l);
}
void Delete_Last(list &l)
{
    node *p;
    node *temp=l.first;
    while (temp->next!=NULL)
    {
        p=temp;
        temp=temp->next;
    }
    l.last=p;
    if(l.last!=NULL)
    {
        l.last->next=NULL;
    }
    delete p;
    OutPut(l); 
}
int main()
{
    list l;
    node x;
    Input(l);
    //Delete_Last(l);
    OutPut(l);
    delete x.next;
    delete l.first;
    delete l.last;
    return 0;
}