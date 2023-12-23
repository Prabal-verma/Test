// 8 A) WAP TO INSERT A NODE IN LINKED LIST

#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node * add_beg(struct Node *head, int d){
    struct Node * ptr = malloc(sizeof(struct Node));
    ptr ->data = d;
    ptr -> link = NULL;

    ptr -> link = head;
    head = ptr;
    return head;
}

int main(){
    struct Node * head = malloc(sizeof(struct Node));
    head -> data = 36;
    head -> link = NULL;

    struct Node * ptr = malloc(sizeof(struct Node));
    ptr -> data = 67;
    ptr -> link = NULL;

    head ->link = ptr;

    int data = 3;

    head = add_beg(head,data);
    ptr = head;
    while(ptr != NULL){
        printf(" %d ", ptr -> data);
        ptr = ptr ->link;
    }

return 0;
}