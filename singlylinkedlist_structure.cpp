#include <iostream>
using namespace std;

struct node
{

    int data;
    struct node *nxt_ptr;
};

void firstapppend(struct node **head, int x)
{
    struct node *n1 = new struct node();
    n1->data = x;
    n1->nxt_ptr = NULL;
    *head = n1;
}

void preappend(struct node **head, int x)
{
    struct node *n1 = new struct node();
    struct node *temp = *head;
    n1->nxt_ptr = temp;
    *head = n1;
    n1->data = x;
}

void append(struct node **head, int x)
{
    struct node *temp = *head;
    struct node *n2 = new struct node();

    while (temp->nxt_ptr != NULL)
    {
        temp = temp->nxt_ptr;
    }
    temp->nxt_ptr = n2;
    n2->data = x;
    n2->nxt_ptr = NULL;
}

void display(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->nxt_ptr;
    }
}

int main()
{

    struct node *head = new struct node();
    head->nxt_ptr = NULL;

    firstapppend(&head, 8);
    preappend(&head, 0);
    append(&head, 10);

    display(&head);
}