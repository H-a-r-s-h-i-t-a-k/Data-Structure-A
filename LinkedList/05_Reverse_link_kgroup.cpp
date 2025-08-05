class Solution
{
public:
  Node *reverseKGroup(Node *head, int k)
  {
    // code here

    if (head == NULL)
    {
      return head;
    }

    int i = k;

    Node *prev = NULL, *forward = NULL;
    Node *curr = head;
    while (curr != NULL && i > 0)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;

      i--;
    }
    if (forward != NULL)
      head->next = reverseKGroup(forward, k);

    return prev;
  }
};

LinkedListNode<int> *solve(LinkedListNode<int> *&head)
{
  LinkedListNode<int> *prev = NULL;
  LinkedListNode<int> *curr = head;

  while (curr != nullptr)
  {
    LinkedListNode<int> *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
  LinkedListNode<int> *result;
  result = solve(head);

  return result;

  // Write your code here
}
/// @brief ///////////////////////
/// @param head 
/// @param cnt 
/// @return /
Node *reverse(Node *head, int cnt)
{
  Node *prev = NULL;
  Node *curr = head;
  Node *forw = NULL;
  while (cnt >= 0 && curr != NULL)
  {
    forw = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forw;
    cnt--;
  }
  return prev;
}
Node *reverseLL(Node *head, int low, int high)
{
  Node *prev = NULL;
  Node *curr = head;
  Node *next = NULL;
  Node *ptr = NULL;
  int cnt = 1;
  while (curr != NULL)
  {
    if (cnt == low - 1)
      prev = curr;
    if (cnt == high + 1)
      next = curr;
    if (cnt == low)
      ptr = curr;
    curr = curr->next;
    cnt++;
  }

  Node *newNode = reverse(ptr, high - low + 1);
  ptr->next = next;
  if (prev)
  {
    prev->next = newNode;
    return head;
  }
  return newNode;

  // Write your code here.
}