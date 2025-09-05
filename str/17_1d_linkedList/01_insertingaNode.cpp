Node *insert(Node *head, int n, int pos, int val)
{
  int cnt = 0;
  Node *ptr = head;
  Node *newNode = new Node(val);

  if (pos == 0)
  {
    newNode->next = head;
    head = newNode;
    return head;
  }
  while (cnt < pos - 1)
  {
    ptr = ptr->next;
    cnt++;
  }
  newNode->next = ptr->next;
  ptr->next = newNode;
  return head;
  // Write your code here
}
