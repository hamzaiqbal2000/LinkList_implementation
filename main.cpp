#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
struct node2 {
	int data;
	node2* next;
	node2* prev;
	node2 node(int d, node2* n, node2* p) {
		data = d; next = n; prev = p;
	}
};
class linked_list
{
private:
	node* head, * tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	void add_head(int n) {
		if (head == NULL)
		{
			node* temp = new node;
			temp->data = n;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else {
			node* temp = new node;
			temp->data = n;
			temp->next = head->next;
			head->next = temp;
		}

	}
	void add_tail(int n)
	{
		int input;
		node* tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
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
	void find_tail() {
		node* temp = new node;
		temp = head;
		while (temp->next)
			temp = temp->next;
		tail = temp;
	}
	void add_node(int n, int m)
	{
		node* temp = new node;
		temp->data = n;
		temp->next = NULL;
		node* traverse = new node;
		traverse = head;
		while (traverse->next) {
			traverse = traverse->next;
			if (traverse->data == n)
				break;
		}
		if (traverse->data == m)
		{
			temp->next = traverse->next;
			traverse->next = temp;
		}
		else {
			cout << "Data not found" << endl;
		}
	}
	void search_node(int n) {
		node* temp = new node;
		temp = head;
		while (temp) {
			if (temp->data == n)
				break;
			else
				temp = temp->next;
		}
		if (temp->data == n) {
			cout << "Found!" << endl;
		}
		else
			cout << "no record found" << endl;
	}
	void search_destroy(int n) {
		node* temp = new node;
		node* temp2 = new node;
		if (head->data == n)
		{
			head = head->next;
		}
		else
		{
			temp = head;
			temp2 = head->next;
			while (temp2) {
				if (temp2->data == n) {
					temp->next = temp2->next;
					break;
				}
				else {
					temp = temp2;
					temp2 = temp2->next;
				}
			}
		}
	}
	void reverse() {
		node* current = new node, * prev = new node, * next = new node;
		current = head;
		prev->next = NULL;
		next->next = NULL;
		while (current) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void display() {
		node* n;
		n = head;
		while (n) {
			cout << n->data << endl;
			n = n->next;
		}
	}

	/*CIRCULAR LINKLIST*/
	/*CIRCULAR LINKLIST*/
	/*CIRCULAR LINKLIST*/

	//function for inserting data into dircular linked list
	void Insert_circular(int pos, int data) {//takes two arguments first=position at which data should be
											 //inserted and second=takes data
		node* p, * t;
		int i;
		//code for inserting a node at 0th position
		if (pos == 0) {
			t = new node;
			t->data = data;
			if (head == NULL) {
				head = t;
				head->next = head;
			}
			else {
				p = head;
				while (p->next != head) {
					p = p->next;
				}
				p->next = t;
				t->next = head;
				head = t;
			}
		}
		//code for inserting a node other than 0th position
		else {
			p = head;
			for (i = 0; i < pos - 1; i++) {
				p = p->next;
			}
			t = new node;
			t->data = data;
			t->next = p->next;
			p->next = t;

		}
	}

	//function for deleting a node
	void delete_circular(int pos) {
		node* p = head;
		node* q = NULL;
		int j=0;
		do{//while loop for counting the length of linkedlist
			j++;
			p = p->next;
		} while (p != head);
		p = head;
		//for deleting node at position 1
		if (pos == 1) {
			while (p->next != head) {
				p = p->next;
			}
			p->next = head->next;
			q = head;
			head = p->next;
			q->next = NULL;
			delete q;
		}
		
		//prints error message if the position is greater than length of list
		else if (j <= pos - 1) {
			cout << "Error: position greater than length of list"<<endl;
		}
		//deletes the node other than at 0th position
		else {
			for (int i = 0; i < pos - 1; i++) {
				q = p;
				p = p->next;
			}
			q->next = p->next;
			p->next = NULL;
			delete p;
		}
	}
	//prints the circular linkedlist
	void Print_circular() {
		node* temp = head;
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}

};
class double_list {
	node2* head; node2* tail;
	double_list() {
		head = NULL;
		tail = NULL;
	}
	void add_head(int n) {
		node2* temp = new node2;
		temp->data = n;
		temp->prev = NULL;
		temp->next = NULL;
		if (head == NULL)
		{
			head == temp;
		}
		else {
			head->prev = temp;
			temp->next = head;
			head = temp;
			tail = temp;
		}
	}
	void find_tail() {
		node2* temp = new node2;
		temp = head;
		while (temp->next)
			temp = temp->next;
		tail = temp;
	}
	void add_node(int n, int m) {
		node2* current = new node2;
		current = head;
		while (current->next) {
			if (current->data == m)
				break;
		}
		if (current->data = m) {
			node2* temp = new node2;
			temp->node(n, current, current->next);
			current->next = temp;
			temp->next->prev = temp;
		}
	}
	void add_tail(int n) {

	}

	

};
int main()
{
	//int input;
	linked_list a;
	//Inserting data into circular linkedlist at specfic position
	a.Insert_circular(0, 2);//pos1
	a.Insert_circular(1, 5);//pos2
	a.Insert_circular(2, 3);//pos3
	a.Insert_circular(3, 7);//pos4
	a.Insert_circular(4, 9);//pos5
	a.Print_circular();//printing circular linkedlist
	a.delete_circular(5);//deleting circular linkedlist
	a.Print_circular();//printing circular linkedlist
	//prints error message because linkedlist length is 5 only
	a.delete_circular(6);//deleting circular linkedlist
	a.Print_circular();//printing circular linkedlist

	/*a.add_head(1);
	a.add_node(2, 1);
	a.add_node(3, 2);
	a.add_tail(4);
	//cout<<"Enter number u wish to search!"<<endl;
	//cin>>input;
	//a.search_node(input);
	//cout<<"Enter number u wish to search and delete!"<<endl;
	//cin>>input;
	//a.search_destroy(input);
	a.display();
	a.reverse();
	a.display();*/
	
	return 0;
}
