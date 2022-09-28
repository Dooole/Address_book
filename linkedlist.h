#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#define BUF_SIZE 64

typedef struct node {
	char name[BUF_SIZE];
	char surname[BUF_SIZE];
	char phone[BUF_SIZE];
	char email[BUF_SIZE];
	struct node* next;
} node_t;

node_t* CreateNode(char* name, char* surname, char* phone, char* email);

void PrintList(node_t* list); //Print all nodes in linked list

void Append(node_t** list, node_t* newNode); //Add node to the end
	
void Insert(node_t** list, node_t* newNode, int pos); //Insert to specific position in linked list

void DeleteNode(node_t* list, int post); //Delete one node

void DeleteList(node_t** list); //Delete all nodes in linked list

node_t* FindByIndex(node_t* list, int pos);

node_t* FindByValue(node_t* list, char* criteria);

void PrintNode(node_t* node);

int GetSize(node_t* node);

#endif
