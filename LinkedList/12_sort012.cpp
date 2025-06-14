/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
void insertatTail(Node *&head, Node *&tail, int data)
{
  Node *newNode = new Node(data);
  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
    return;
  }
  tail->next = newNode;
  tail = newNode;
}
Node *sortList(Node *head)
{
  // Write your code here.

  Node *zeroH = new Node(-1);
  Node *zeroT = zeroH;
  Node *oneH = new Node(-1);
  Node *oneT = oneH;
  Node *twoH = new Node(-1);
  Node *twoT = twoH;

  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == 0)
    {
      insertatTail(zeroH, zeroT, 0);
    }
    else if (temp->data == 1)
    {
      insertatTail(oneH, oneT, 1);
    }
    else
    {
      insertatTail(twoH, twoT, 2);
    }
    temp = temp->next;
  }

  if (oneH->next != NULL)
  {
    zeroT->next = oneH->next;
  }
  if (twoH->next != NULL)
  {
    oneT->next = twoH->next;
  }
  head = zeroH->next;
  delete zeroH;
  delete oneH;
  delete twoH;

  return head;
}