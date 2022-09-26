#include<stdio.h>
#include "linkedlist.h"
#include <stdlib.h>
#define BUF_SIZE 64

int main(){
    char name[BUF_SIZE];
    char surname[BUF_SIZE];
    char phone[BUF_SIZE];
    char email [BUF_SIZE];
    char criteria[BUF_SIZE];

    node_t* node = NULL;

    linkedlist_t* newList = CreateLinkedList();

	Append(newList, "Tadas","Tadelis","+37061233333","tadzius@gmail.com");
    Append(newList, "Vilius","Dunduliukas","+37012321532","vil@hotmail.com");
    Append(newList, "Tomas","Tomelis","+37012321533","tom@hotmail.com");
    Append(newList, "Kasparas","Kasparelis","+37012321534","kasp@hotmail.com");
    Append(newList, "Arturas","Arturelis","+37012321535","art@hotmail.com");
    Append(newList, "Ignas","Ignelis","+37012321730","ign@hotmail.com");
    Append(newList, "Ramas","Ramiakas","+37012321930","rim@hotmail.com");
    Append(newList, "Rimas","Rimukas","+37012320530","rim2@hotmail.com");
    Append(newList, "Jonas","Jonelis","+37012321930","jon@hotmail.com");
    Append(newList, "Jurgis","Jurgelis","+37012320530","paul@hotmail.com");

    int exit = 0;
    int choose, pos;
    while(!exit)
    {
        printf("1 Print\n2 Append\n3 Add\n4 Delete\n5 Delete All\n6 Find index\n7 Find\n0 Exit\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
        {
            PrintList(newList);
            printf("----------------\n");
            break;
        }
        case 2:
        {
            printf("Enter name: ");
            scanf("%s",name);
            printf("Enter surname: ");
            scanf("%s",surname);
            printf("Enter phone number: ");
            scanf("%s",phone);
            printf("Enter email: ");
            scanf("%s",email);
            Append(newList,name,surname,phone,email);
            printf("----------------\n");
            break;
        }

        case 3:
        {
            printf("POSITION: ");
            scanf("%d", &pos);
            if (pos < 0 || pos > (newList->size)) {
                printf("OUT OF RANGE!\n");
                break;
            }
            printf("Enter name: ");
            scanf("%s",name);
            printf("Enter surname: ");
            scanf("%s",surname);
            printf("Enter phone number: ");
            scanf("%s",phone);
            printf("Enter email: ");
            scanf("%s",email);
            Insert(newList,name,surname,phone,email, pos);
            printf("----------------\n");
            break;
        }

        case 4:
        {
            printf("Position: ");
            scanf("%d",&pos);
            if (pos < 0 || pos > (newList->size)) {
                printf("OUT OF RANGE!\n");
                break;
            }
            DeleteNode(newList, pos);
            printf("----------------\n");
            break;
        }  

        case 5:
        {

            DeleteList(newList);
            newList = CreateLinkedList();
            printf("----------------\n");
            break;
        }

        case 6:
        {
            printf("Position: ");
            scanf("%d",&pos);
            if (pos < 0 || pos > (newList->size)) {
                printf("OUT OF RANGE!\n");
                break;
            }

            node = FindByIndex(newList, pos);
            if (node) {
                printf("Results:\n");
                printf("%s\n %s\n %s\n %s\n ************\n", node->name, node->surname, node->phone, node->email);

            } else {
                printf("NOT FOUND!\n");
            }
            printf("----------------\n");
            break;
        } 

        case 7:
        {
            printf("Criteria: ");
            scanf("%s",criteria);

            node = FindByValue(newList, criteria);
            if (node) {
                printf("Results:\n");
                printf("%s\n %s\n %s\n %s\n ************\n", node->name, node->surname, node->phone, node->email);
            } else {
                printf("NOT FOUND!\n");
            }
            printf("----------------\n");
            break;
        }       

        case 0:
        {
            printf("----------------\n");
            exit = 1;
            break;
        }
        }
    }

    printf("Exiting\n");
    if (newList) {
        DeleteList(newList);
    }
	return 0;

}
