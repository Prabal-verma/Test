// 8. WAP TO INSERT A NODE AND DELETE A NODE IN A LINKED LIST

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at a specified position in the list
void insertAtPosition(struct Node** head, int newData, int position) {
    // Check if the specified position is valid
    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }

    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Set the data for the new node
    newNode->data = newData;

    // If inserting at the beginning (position = 1), update the head
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Find the node at the (position - 1)th position
        struct Node* previous = *head;
        for (int i = 1; i < position - 1 && previous != NULL; i++) {
            previous = previous->next;
        }

        // Check if the position is valid
        if (previous == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            return;
        }

        // Insert the new node after the (position - 1)th node
        newNode->next = previous->next;
        previous->next = newNode;
    }
}

// Function to delete a node with a given value from the list
void deleteNode(struct Node** head, int key) {
    // Initialize two pointers, one to the current node and one to the previous node
    struct Node* current = *head;
    struct Node* previous = NULL;

    // Traverse the list to find the node with the given value
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If the node with the given value is not found, return
    if (current == NULL) {
        printf("Node with value %d not found in the list.\n", key);
        return;
    }

    // If the node to be deleted is the first node, update the head
    if (previous == NULL) {
        *head = current->next;
    } else {
        // Otherwise, update the next of the previous node
        previous->next = current->next;
    }

    // Free the memory of the deleted node
    free(current);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    printf("Linked List: ");

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some elements at the beginning
    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);

    // Print the linked list
    printList(head);

    // Insert a node at a specified position (e.g., 25 at position 2)
    insertAtPosition(&head, 25, 2);

    // Print the updated linked list
    printList(head);

    // Delete a node with a given value (e.g., delete node with value 20)
    deleteNode(&head, 20);

    // Print the linked list after deletion
    printList(head);

    return 0;
}
