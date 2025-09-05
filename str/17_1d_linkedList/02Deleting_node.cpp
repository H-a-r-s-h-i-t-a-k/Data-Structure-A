
Node *deleteLast(Node *list)
{

  Node *ptr = list;
  if (ptr == NULL || ptr->next == NULL)
  {
    return NULL;
  }
  while (ptr->next != NULL && ptr->next->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = ptr->next->next;
  return list;
  // Write your code here
}