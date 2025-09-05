
Node *insert(int k, int val, Node *head)
{
  Node *newNode = new Node(val);
  if (k == 0)
  {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
  }
  Node *ptr = head;
  int cnt = 0;
  while (cnt < k - 1)
  {
    ptr = ptr->next;
    cnt++;
  }
  if (ptr->next == NULL)
  {
    newNode->next = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    return head;
  }

  newNode->next = ptr->next;
  ptr->next->prev = newNode;
  ptr->next = newNode;
  newNode->prev = ptr;

  return head;

  // Write Your Code Here.
}
