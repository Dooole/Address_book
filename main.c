#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int InitialData(node_t** list) {
    node_t *node;

    node = CreateNode("Tadas","Tadelis","+37061233333","tadzius@gmail.com");

    Append(list, node);

    node = CreateNode("Vilius","Dunduliukas","+37012321532","vil@hotmail.com");
    
    Append(list, node);

    node = CreateNode("Tomas","Tomelis","+37012321533","tom@hotmail.com");
   
    Append(list, node);

     node = CreateNode("Kasparas","Kasparelis","+37012321534","kasp@hotmail.com");

    Append(list, node);

    node = CreateNode("Arturas","Arturelis","+37012321535","art@hotmail.com");

    Append(list, node);

    node = CreateNode("Ignas","Ignelis","+37012321730","ign@hotmail.com");
 
    Append(list, node);

    node = CreateNode("Ramas","Ramiakas","+37012321930","rim@hotmail.com");

    Append(list, node);

    node = CreateNode("Jonas","Jonelis","+37012321930","jon@hotmail.com");
   
    Append(list, node);

    node = CreateNode("Jurgis","Jurgelis","+37012320530","paul@hotmail.com");
    Append(list, node);

    return 0;
}

node_t *ParseData() {
    char name[BUF_SIZE];
    char surname[BUF_SIZE];
    char phone[BUF_SIZE];
    char email [BUF_SIZE];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter surname: ");
    scanf("%s", surname);
    printf("Enter phone number: ");
    scanf("%s", phone);
    printf("Enter email: ");
    scanf("%s", email);

    return CreateNode(name, surname, phone, email);
}

int ParseIndex(node_t* list) {
    int index, size;

    size = GetSize(list);

    printf("Enter index: ");
    if (scanf("%d", &index) != 1) {
        printf("invalid index format: valid 0 - %d\n", size);
        return -1;
    }

    if (size == 0) {
        if (index != 0) {
            printf("invalid index: valid 0\n");
            return -1;
        }
        return index;
    }

    if (index < 0 || index > (size - 1)) {
        printf("invalid index: valid 0 - %d\n", size);
        return -1;
    }

    return index;
}

int main() {
    char criteria[BUF_SIZE];
    node_t *list = NULL, *node = NULL;

    if (InitialData(&list)) {
        printf("Failed to add initial data\n");
        DeleteList(&list);
        exit(1);
    }

    int finish = 0;
    int choose, pos;

    while(!finish)
    {
        printf("1 Print\n2 Append\n3 Add\n4 Delete\n5 Delete All\n6 Find index\n7 Find\n0 Exit\n");

        choose = -1;
        if (scanf("%d", &choose) != 1 || choose < 0 || choose > 7) {
            printf("Invalid option\n");
            continue;
        }

        switch(choose)
        {
            case 1:
            {
                PrintList(list);
                break;
            }
            case 2:
            {
                node = ParseData();
                if (!node) {
                    printf("Failed to parse input\n");
                    break;
                }

                Append(&list, node);
                break;
            }

            case 3:
            {

                pos = ParseIndex(list);
                if (pos < 0) {
                    printf("Failed to parse index\n");
                    break;
                }
                
                node = ParseData();
                if (!node) {
                    printf("Failed to parse input\n");
                    break;
                }
  
                Insert(&list, node, pos);
                break;
            }

            case 4:
            {
                pos = ParseIndex(list);
                if (pos < 0) {
                    printf("Failed to parse index\n");
                    break;
                }

                DeleteNode(list, pos);
                break;
            }  

            case 5:
            {

                DeleteList(&list);
                break;
            }

            case 6:
            {
                pos = ParseIndex(list);
                if (pos < 0) {
                    printf("Failed to parse index\n");
                    break;
                }

                node = FindByIndex(list, pos);
                if (node) {
                    PrintNode(node);
                }
                break;
            } 

            case 7:
            {
                printf("Criteria: ");
                scanf("%s", criteria);

                node = FindByValue(list, criteria);
                if (node) {
                    PrintNode(node);
                }
                break;
            }       

            case 0:
            {
                finish = 1;
                break;
            }
        }
    }

    printf("Exiting\n");

    if (list) {
        DeleteList(&list);
    }

    return 0;
}