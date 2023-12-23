//7. WAP TO IMPLEMENT A LINKED LIST //

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
void linkedListTraversal(struct Node*ptr){
    while(ptr!= NULL){
        printf("Elements : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    
    head -> data = 7;
    head -> next = second;

    second -> data = 15;
    second -> next = third;

    third -> data = 22;
    third -> next = NULL;

    linkedListTraversal(head);
    return 0;
}