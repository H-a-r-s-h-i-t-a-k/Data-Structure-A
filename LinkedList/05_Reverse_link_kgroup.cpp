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