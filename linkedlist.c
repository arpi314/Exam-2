#include<stdio.h>
#include<stdlib.h>

//Stores the data itself and links that data to the other nodes via pointers
struct myNode{
    int value;
    struct myNode *next;
};
typedef struct myNode myNode;

//The linked list itself
struct SLList{
    myNode *head;
    myNode *tail;
    int size;
};
typedef struct SLList SLList;

void initList(SLList *list);
myNode *getNode(SLList *list, int index);
myNode *createNode(int x);
void insertItem(SLList *list, int index, int item);
void empty(SLList *list);

int main(){

    SLList list;
    initList(&list);

    insertItem(&list, list.size, 0);
    insertItem(&list, list.size, 6);
    insertItem(&list, list.size, 9);
    insertItem(&list, list.size, 0);

    empty(&list);

    return 0;
}

//Initialize the list to null
void initList(SLList *list){
    list->head = 0;
    list->tail = 0;
    list->size = 0;
}

//Retrives an item from the list
myNode *getNode(SLList *list, int index){
    myNode *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current;
}


myNode *createNode(int x){
    myNode *a = (myNode*)malloc(sizeof(myNode));
    a->value = x;
    a->next = 0;
    return a;
}

//Inserts item to the list 
void insertItem(SLList *list, int index, int item){
    if(index >= 0 && index <= list->size){

        myNode *toInsert = createNode(item); //This creates the node with a value of item

        if (index == 0){ //Inserting at the beginning of the list. 
            toInsert->next = list->head;
            list->head = toInsert;
        }
        if(index == list->size){ //Inserting at the tail 
            if(list->tail != 0){
                list->tail->next = toInsert;
            }
            list->tail = toInsert;
        }
        if(index > 0 && index < list->size){ //Inserting somewhere in the middle of the list
            myNode *previous = getNode(list,index-1);
            toInsert->next = previous->next;
            previous->next = toInsert;
        }
        list->size++; 
    }
}

void empty(SLList *list)
{
    myNode *n;
    myNode *temp;
    n = list->head;

    while(n){
        temp = n->next;
        free(n);
        n = temp;
        list->size--;
    }  
}

