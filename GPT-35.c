#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to find the smallest number in the linked list
int findSmallest(struct Node* head) {
    int smallest = head->data;
    while (head != NULL) {
        if (head->data < smallest)
            smallest = head->data;
        head = head->next;
    }
    return smallest;
}

// Function to find the largest number in the linked list
int findLargest(struct Node* head) {
    int largest = head->data;
    while (head != NULL) {
        if (head->data > largest)
            largest = head->data;
        head = head->next;
    }
    return largest;
}

// Function to free all the nodes in the linked list
void freeList(struct Node* head) {
    struct Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct Node* head = NULL;
    int num;

    // Input phase
    printf("Enter integers to store in the linked list (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        insert(&head, num);
    }

    // Finding the smallest and largest number
    if (head != NULL) {
        int smallest = findSmallest(head);
        int largest = findLargest(head);
        printf("Smallest number: %d\n", smallest);
        printf("Largest number: %d\n", largest);
    } else {
        printf("The linked list is empty.\n");
    }

    // Freeing allocated memory
    freeList(head);

    return 0;
}