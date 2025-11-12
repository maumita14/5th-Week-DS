// Program to check whether a linked list is sorted(ascending order)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *head = NULL;

static Node *new_node(int v) {
    Node *n = malloc(sizeof *n);
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = v; n->next = NULL;
    return n;
}

void insert_at_end(int v) {
    Node *n = new_node(v);
    if (!head) { head = n; return; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

int is_sorted(void) {
    if (!head || !head->next) return 1;
    for (Node *p = head; p->next; p = p->next) {
        if (p->data > p->next->data) return 0;
    }
    return 1;
}

void display(void) {
    if (!head) { puts("List is empty"); return; }
    printf("List: ");
    for (Node *p = head; p; p = p->next)
        printf("%d%s", p->data, p->next ? " -> " : "\n");
}

void free_list(void) {
    Node *p = head;
    while (p) {
        Node *t = p;
        p = p->next;
        free(t);
    }
    head = NULL;
}

int main(void) {
    insert_at_end(11);
    insert_at_end(25);
    insert_at_end(56);
    insert_at_end(59);
    insert_at_end(88);
    display();
    printf("Sorted? %s\n", is_sorted() ? "Yes" : "No");
    free_list();
    return 0;
}
