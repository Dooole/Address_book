#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>

linkedlist_t* CreateLinkedList(){
	linkedlist_t* newList = (linkedlist_t*)malloc(sizeof(linkedlist_t));
	if (!newList)
		return NULL;

	newList->head = NULL;
	newList->size = 0;
	return newList;
}

void PrintList(linkedlist_t* list){
	int pos = 0;
	node_t* temp = list->head;
	while (temp !=NULL){
		printf("%d: %s\n %s\n %s\n %s\n ************\n", pos, temp->name, temp->surname, temp->phone, temp->email);
		temp=temp->next;
		pos++;
	}
} 

void Append(linkedlist_t* list, char* name, char* surname, char* phone, char* email){
	//list is empty
	if (list->head == NULL){
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		if (!newNode)
			return;
		memset(newNode, 0, sizeof(node_t));
		strncpy(newNode->name, name, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	    strncpy(newNode->surname, surname, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	    strncpy(newNode->phone, phone, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	    strncpy(newNode->email, email, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
		newNode->next = NULL;
		list->head = newNode;
	}else{
		node_t* temp = list->head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		if (!newNode)
			return;
		memset(newNode, 0, sizeof(node_t));
		strncpy(newNode->name, name, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	    strncpy(newNode->surname, surname, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	    strncpy(newNode->phone, phone, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	    strncpy(newNode->email, email, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
		newNode->next = NULL;
		temp->next = newNode;
	}
	list->size++;
}

void Insert(linkedlist_t* list, char* email, char* phone, char* surname, char* name, int pos){
	int cur_pos = 0; 
	if (pos < 0 || pos > (list->size - 1))
		return;
	node_t* prev = NULL;
	node_t* current = list->head;
	while(current->next != NULL && cur_pos != pos){
		prev = current;
		current=current->next;
		cur_pos++;
	}
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (!newNode)
		return;
	memset(newNode, 0, sizeof(node_t));
	strncpy(newNode->name, name, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
    strncpy(newNode->surname, surname, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
    strncpy(newNode->phone, phone, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
    strncpy(newNode->email, email, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	prev->next = newNode;
	newNode->next = current;
	list->size++;
}

void DeleteNode(linkedlist_t* list, int pos){
	int cur_pos = 0;

	if (pos < 0 || pos > (list->size - 1))
		return;

	node_t* prev = NULL;
	node_t* current = list->head;
	while(current->next != NULL && cur_pos != pos){
		prev = current;
		current=current->next;
		cur_pos++;
	}

	prev->next = current->next;
	free(current);
	list->size--;
}

void DeleteList(linkedlist_t* list){
	node_t* current = list->head; //points to current node
	if (current == NULL){
		free(list);
		return;
	}

	node_t* next;

	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	free(list);
}


node_t* FindByIndex(linkedlist_t* list, int pos){
	int cur_pos = 0;

	if (pos < 0 || pos > (list->size - 1))
		return NULL;

	node_t* current = list->head;
	while (current->next != NULL && cur_pos != pos){
		current=current->next;
		cur_pos++;
	}

	return current;
}

node_t* FindByValue(linkedlist_t* list, char* criteria) {
	int found = 0;

	node_t* current = list->head;
	while(current->next != NULL){

		if (!strcmp(current->name, criteria) ||
			!strcmp(current->surname, criteria) ||
			!strcmp(current->phone, criteria) ||
			!strcmp(current->email, criteria)) {
			found = 1;
			break;
		}

		current=current->next;
	}

	if (!found)
		return NULL;

	return current;
}
