#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

void Insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void Print(struct Node* p) {
    if (p == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    Print(p->next);
}

void Reverse(struct Node* p)
{
    if(p->next ==NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main() {
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Print(head);
    Reverse(head);
    Print(head);

    return 0;
}
