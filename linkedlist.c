#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>


node_t* CreateNode(char* name, char* surname, char* phone, char* email){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	if (newNode == NULL){
		return NULL;}

	memset(newNode, 0, sizeof(node_t));
	strncpy(newNode->name, name, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	strncpy(newNode->surname, surname, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	strncpy(newNode->phone, phone, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi
	strncpy(newNode->email, email, BUF_SIZE - 1); //tikrinti kopijuojamo stringo ilgi

	return newNode;
}

void PrintList(node_t* list){
	int pos = 0;
	node_t* temp = list;
	while (temp !=NULL){
		printf("%d: %s\n %s\n %s\n %s\n ************\n", pos, temp->name, temp->surname, temp->phone, temp->email);
		temp=temp->next;
		pos++;
	}
} 

void Append(node_t** list, node_t* newNode){
	node_t* temp = *list;
	if (temp == NULL){
		*list = newNode;
		return;
	}

	while(temp->next != NULL){
		temp=temp->next;
	}

	temp->next = newNode;
	
	if (!newNode)
		return;
}

void Insert(node_t** list, node_t* newNode, int pos){
	int cur_pos = 0; 
	node_t* prev = NULL;
	node_t* current = *list;
	if (!current && pos == 0) {
		*list = newNode;
		return;
	}

	while(current->next != NULL && cur_pos != pos){
		prev = current;
		current=current->next;
		cur_pos++;
	}

	prev->next = newNode;
	newNode->next = current;
}

void DeleteNode(node_t* list, int pos){
	int cur_pos = 0;
	node_t* prev = NULL;
	node_t* current = list;
	while(current->next != NULL && cur_pos != pos){
		prev = current;
		current=current->next;
		cur_pos++;
	}

	prev->next = current->next;
	free(current);
}

void DeleteList(node_t** list){
	node_t* current = *list; //points to current node
	if (current == NULL){
		//free(list);
		return;
	}

	node_t* next;

	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	//free(list);
	*list = NULL;
}


node_t* FindByIndex(node_t* list, int pos){
	int cur_pos = 0;
	node_t* current = list;
	while (current->next != NULL && cur_pos != pos){
		current=current->next;
		cur_pos++;
	}

	return current;
}

node_t* FindByValue(node_t* list, char* criteria) {
	int found = 0;
	node_t* current = list;
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

int GetSize(node_t* list) {
	int size = 0;
	node_t* current = list;
	if (!current) {
		return size;
	}

	while (current->next != NULL){
		current=current->next;
		size++;
	}

	return size;
}

void PrintNode(node_t* newNode) {
	 printf("%s\n %s\n %s\n %s\n\n",newNode->name,newNode->surname,newNode->phone,newNode->email);
}
