#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to find the smallest and largest element in the list
void findMinMax(struct Node* head, int* min, int* max) {
    *min = *max = head->data; // Initialize with first node's data

    while (head != NULL) {
        if (head->data < *min) {
            *min = head->data;
        } else if (head->data > *max) {
            *max = head->data;
        }
        head = head->next;
    }
}

// Function to free the allocated memory for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; // Initially empty list

    int data, choice;

    // Input loop to add integers to the list
    while (1) {
        printf("Enter an integer (0 to quit): ");
        scanf("%d", &data);

        if (data == 0) {
            break;
        }

        insertAtBeginning(&head, data);
    }

    // Find minimum and maximum
    int min, max;
    findMinMax(head, &min, &max);

    printf("Smallest element: %d\n", min);
    printf("Largest element: %d\n", max);

    // Free memory
    freeList(head);

    return 0;
}
