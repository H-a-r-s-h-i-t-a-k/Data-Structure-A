int searchInLinkedList(Node<int> *head, int k)
{

  if (head == NULL)
    return 0;
  Node<int> *ptr = head;
  while (ptr != NULL && ptr->data != k)
  {
    ptr = ptr->next;
  }
  if (ptr != NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }

  return 1;

  // Write your code here.
}