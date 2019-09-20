//
// Created by Abdullah Khurram on 14/09/2019.
//

#ifndef LINKED_LIST_MAIN2_H
#define LINKED_LIST_MAIN2_H

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
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

    void add_node(int n)
    {
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
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display(){
        node*n = new node;
        n = head;
        while(n->next) {
            cout << n->data<<endl;
            n=n->next;
        }
        getchar();
    }
};

int main2()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.display();
    return 0;
}



#endif //LINKED_LIST_MAIN2_H
