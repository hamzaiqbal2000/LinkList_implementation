#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct node2{
    int data;
    node2 *next;
    node2 *prev;
    node2 node(int d, node2 *n, node2 *p){
        data = d;next=n;prev=p;
    }
};
class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }
    void add_head(int n){
        if(head==NULL)
        {node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        head = temp;
        tail = temp;
        }else{
            node *temp = new node;
            temp->data = n;
            temp->next = head->next;
            head->next = temp;
        }

    }
    void add_tail(int n)
    {
        int input;
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            find_tail();
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void find_tail(){
        node *temp = new node;
        temp=head;
        while(temp->next)
            temp=temp->next;
        tail = temp;
    }
    void add_node(int n,int m)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        node *traverse = new node;
        traverse = head;
        while(traverse->next) {
            traverse = traverse->next;
            if(traverse->data==n)
                break;
        }
        if (traverse->data == m)
        {
            temp->next = traverse->next;
            traverse->next = temp;
        }else{
            cout<<"Data not found"<<endl;
        }
    }
    void search_node(int n){
        node *temp = new node;
        temp=head;
        while(temp){
            if(temp->data==n)
                break;
            else
                temp=temp->next;
        }
        if(temp->data==n){
            cout<<"Found!"<<endl;
        }else
            cout<<"no record found"<<endl;
    }
    void search_destroy(int n){
        node *temp = new node;
        node *temp2=new node;
        if(head->data==n)
        {
            head=head->next;
        }else
        {
            temp=head;
            temp2=head->next;
            while(temp2){
                if(temp2->data==n){
                    temp->next=temp2->next;
                    break;
                }else{
                    temp=temp2;
                    temp2=temp2->next;
                }
            }
        }
    }
    void reverse(){
        node *current=new node,*prev=new node,*next=new node;
        current=head;
        prev->next=NULL;
        next->next=NULL;
        while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        }
        head=prev;
    }
    void display(){
        node*n;
        n = head;
        while(n) {
            cout << n->data<<endl;
            n=n->next;
        }
    }
};
class double_list{
    node2 *head;node2 *tail;
    double_list(){
        head=NULL;
        tail=NULL;
    }
    void add_head(int n){
        node2 *temp = new node2;
        temp->data = n;
        temp->prev=NULL;
        temp->next=NULL;
        if(head==NULL)
        {
            head==temp;
        }else{
            head->prev = temp;
            temp->next=head;
            head=temp;
            tail=temp;
        }
    }
    void find_tail(){
        node2 *temp = new node2;
        temp=head;
        while(temp->next)
            temp=temp->next;
        tail=temp;
    }
    void add_node(int n,int m){
        node2 *current = new node2;
        current = head;
        while(current->next){
            if(current->data==m)
                break;
        }
        if(current->data = m){
            node2 *temp = new node2;
            temp->node(n,current,current->next);
            current->next=temp;
            temp->next->prev=temp;
        }
    }
    void add_tail(int n){

    }
};
int main()
{
    int input;
    linked_list a;
    a.add_head(1);
    a.add_node(2,1);
    a.add_node(3,2);
    a.add_tail(4);
    //cout<<"Enter number u wish to search!"<<endl;
    //cin>>input;
    //a.search_node(input);
    //cout<<"Enter number u wish to search and delete!"<<endl;
    //cin>>input;
    //a.search_destroy(input);
    a.display();
    a.reverse();
    a.display();
    return 0;
}