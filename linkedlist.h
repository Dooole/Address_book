#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#define BUF_SIZE 64

//node in a chain
typedef struct node{
	char name[BUF_SIZE];
	char surname[BUF_SIZE];
	char phone[BUF_SIZE];
	char email[BUF_SIZE];
	struct node* next;
}node_t;

//linked list data structure wich always holds first node in a chain
typedef struct linkedlist{
	int size;
	node_t* head; //head node
}linkedlist_t;


linkedlist_t* CreateLinkedList();

void PrintList(linkedlist_t* list); //Print all nodes in linked list

void Append(linkedlist_t* list, char* name, char* surname, char* phone, char* email); //Add node to the end
	
void Insert(linkedlist_t* list, char* name, char* surname, char* phone, char* email, int pos); //Insert to specific position in linked list

void DeleteNode(linkedlist_t* list, int post); //Delete one node

void DeleteList(linkedlist_t* list); //Delete all nodes in linked list

node_t* FindByIndex(linkedlist_t* list, int pos);

node_t* FindByValue(linkedlist_t* list, char* criteria);

#endif