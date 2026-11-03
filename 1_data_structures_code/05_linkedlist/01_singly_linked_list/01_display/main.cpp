#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node create(int *A, int n);
void display(Node* p);

int main(){
    int A[] = {3, 5, 7, 8, 10};
    Node head = create(A, 5);
    display(&head);
    return 0;
}

Node create(int *A, int n)
{
    Node *first = new Node;
    first->next = NULL;
    first->data = A[0];
    
    Node* last = first;

    for(int i = 1; i < n; ++i)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    return *first;
}

void display(Node* p)
{
    Node* t = p;
    while(t)
    {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}