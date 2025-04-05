#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL, prev = NULL;
    }
};

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
void insertAtHead(Node *&head, int data)
{
    Node *node = new Node(data);
    node->next = head;
    head->prev = node;
    head = node;
}
void insertAtTail(Node *&tail, int data)
{
    Node *node = new Node(data);
    node->prev = tail;
    tail->next = node;
    tail = node;
}
void insertAtLoc(Node *&head, Node *&tail, int loc, int data)
{
    if (loc == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < loc)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *node = new Node(data);

    node->next = temp->next;
    node->prev = temp->next->prev;
    temp->next = node;
}
void deleteAtHead(Node *&head)
{
    Node *node = head;
    head->next->prev = NULL;
    head = head->next;
    delete node;
}
void deleteAtTail(Node *&tail)
{
    Node *node = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
}
void deleteAtLoc(Node *&head, Node *&tail, int loc)
{
    if(loc == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < loc )
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        deleteAtTail(tail);
    }
    Node *node = temp;
    cout<<temp->data<<endl;
    cout << temp->prev->data << endl;
    cout << temp->next->data << endl;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

int main()
{
    Node *head = NULL;
    Node *node = new Node(87);
    Node *tail = node;
    head = node;

    insertAtHead(head, 565);
    insertAtHead(head, 24);
    insertAtHead(head, 5);
    traverse(head);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    traverse(head);
    insertAtLoc(head, tail, 2, 765657);
    deleteAtHead(head);
    deleteAtTail(tail);
    traverse(head);
    deleteAtLoc(head, tail, 3);
    traverse(head);
    return 0;
}