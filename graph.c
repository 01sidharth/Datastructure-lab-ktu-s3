#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

void push(struct ListNode *head, int item) {
    struct ListNode *ptr, *new;

    new = malloc(sizeof(struct ListNode));

    new->data = item;
    new->next = NULL;

    ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new;
}

int pop(struct ListNode *head) {
    if(head->next == NULL) {
        printf("stack empty");
        return -1;
    }

    struct ListNode *ptr, *parent;

    ptr = head->next;
    parent = head;

    while(ptr->next != NULL) {
        parent = ptr;
        ptr = ptr->next;
    }

    parent->next = NULL;

    return ptr->data;
}

void print(struct ListNode *head) {
    struct ListNode *ptr;

    ptr = head->next;

    printf("\nPrinting list\n");
    while(ptr != NULL) {
        printf("\t%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\nPrinting list done!\n");
}

void queue(struct ListNode *head, int item) {
    struct ListNode *ptr, *new;

    new = malloc(sizeof(struct ListNode));

    new->data = item;
    new->next = NULL;

    ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = new;
}

int dequeue(struct ListNode *head) {
    if(head->next == NULL) {
        printf("queue empty");
        return -1;
    }
    
    int temp = head->next->data;

    head->next = head->next->next;

    return temp;
}

int isEmpty(struct ListNode *head) {
    if(head->next == NULL)
        return 1;
    
    return 0;
}

int search(struct ListNode *head, int item) {
    struct ListNode *ptr;

    ptr = head->next;

    while(ptr != NULL) {
        if(ptr->data == item)
            return 1;
        
        ptr = ptr->next;
    }

    return 0;
}

int main() {
    int size, i, j, choice;
    struct ListNode *stack_list, *visited_stack_list, *queue_list, *visited_queue_list;

    printf("\nEnter size: ");
    scanf("%d", &size);
    
    int adj_mat[size][size];

    printf("\nEnter adjacency matrix data :-\n");
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &adj_mat[i][j]);
        }

    do {
        printf("\n\n1. Perform DFS\n2. Perform BFS\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                stack_list = malloc(sizeof(struct ListNode));
                visited_stack_list = malloc(sizeof(struct ListNode));
                push(stack_list, 1);
                push(visited_stack_list, 1);

                printf("\n\nDFS Traversal :-\n");
                while(isEmpty(stack_list) != 1) {
                    i = pop(stack_list);
                    printf("%d\t", i);

                    for(j = 0; j < size; j++)
                        if(adj_mat[i - 1][j] == 1)
                            if(search(visited_stack_list, j + 1) != 1) {
                                push(stack_list, j + 1);
                                push(visited_stack_list, j + 1);
                            }
                }
                break;
            
            case 2:
                queue_list = malloc(sizeof(struct ListNode));
                visited_queue_list = malloc(sizeof(struct ListNode));
                queue(queue_list, 1);
                queue(visited_queue_list, 1);

                printf("\n\nBFS Traversal :-\n");
                while(isEmpty(queue_list) != 1) {
                    i = dequeue(queue_list);
                    printf("%d\t", i);

                    for(j = 0; j < size; j++)
                        if(adj_mat[i - 1][j] == 1)
                            if(search(visited_queue_list, j + 1) != 1) {
                                queue(queue_list, j + 1);
                                queue(visited_queue_list, j + 1);
                            }
                }
                break;
            
            case 3:
                printf("\nExiting...");
                break;
            
            default:
                printf("\nInvalid!");
        }
    } while(choice != 3);

    return 0;
}