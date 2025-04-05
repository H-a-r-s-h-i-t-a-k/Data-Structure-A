#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void insert_atHead(Node *&head, int d)
{
    Node *node = new Node(d);
    node->next = head;
    head = node;
}
void insert_atTail(Node *&tail, int d)
{
    Node *node = new Node(d);
    tail->next = node;
    tail = node;
}
void insertAtLoc(Node *&head, Node *&tail, int loc, int data)
{
    if (loc == 1)
    {
        insert_atHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 2;
    while (cnt < loc)
    {
        temp = temp->next;
        cnt++;
    }
    // last element
    if (temp->next == NULL)
    {

        insert_atTail(tail, data);
        return;
    }
    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
}
void traverse(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
void deleteAtHead(Node *&head)
{
    Node *node = head;
    head = head->next;
    delete node;
}
void deleteAtTail(Node *&tail, Node *head)
{
    Node *node = tail;
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;
    delete node;
}
void deleteAtLoc(Node *&head, Node *&tail, int loc)
{
    if (loc == 1)
    {
        deleteAtHead(head);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < loc - 1)
    {
        temp = temp->next;
        cnt++;
    }
    temp->next = temp->next->next;
    tail = temp;
}

int main()
{
    Node *head = NULL;
    Node *node = new Node(89);
    Node *tail = node;
    head = node;
    insert_atHead(head, 78);
    insert_atHead(head, 756);
    insert_atHead(head, 23);
    insert_atHead(head, 67);
    insert_atHead(head, 98);
    insert_atHead(head, 67);
    traverse(head);
    insert_atTail(tail, 45498);
    insert_atTail(tail, 8);
    insert_atTail(tail, 1);
    insert_atTail(tail, 4);
    traverse(head);
    insertAtLoc(head, tail, 3, 3487584);
    insertAtLoc(head, tail, 1, 3487584);
    insertAtLoc(head, tail, 14, 3487584);
    traverse(head);
    // deleteAtTail(tail, head);
    // deleteAtTail(tail, head);
    // deleteAtTail(tail, head);
    // deleteAtTail(tail, head);
    deleteAtLoc(head, tail, 14);
    deleteAtLoc(head, tail, 1);
    deleteAtLoc(head, tail, 5);
    traverse(head);
    return 0;
}