#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

int main() {

  struct node* head = NULL;
  struct node* current = NULL;

  int input;
  printf("Enter integers (0 to quit):\n");

  while(1) {
    scanf("%d", &input);
    if(input == 0) {
      break;
    }
    
    // allocate new node and add to list
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = input;
    new_node->next = NULL;

    if(head == NULL) {
      head = new_node;
    }
    else {
      current->next = new_node;
    }
    current = new_node;
  }

  // find min and max in list
  int min = head->data;
  int max = head->data;
  current = head;
  while(current != NULL) {
    if(current->data < min) {
      min = current->data;
    }
    if(current->data > max) {
      max = current->data;
    }
    current = current->next;
  }

  printf("Min: %d, Max: %d\n", min, max);

  // free list
  current = head;
  while(current != NULL) {
    struct node* temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}