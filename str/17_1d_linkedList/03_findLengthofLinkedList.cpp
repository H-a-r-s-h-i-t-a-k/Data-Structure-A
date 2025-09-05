int length(Node *head)
{
  int cnt = 0;
  Node *ptr = head;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    cnt++;
  }
  return cnt;
  // Write your code here
}
