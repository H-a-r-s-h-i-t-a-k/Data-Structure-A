class Solution
{
public:
  ListNode *solve(ListNode *head, int k, int ind)
  {

    if (head == NULL)
    {
      return head;
    }
    // kelement exixts or not
    ListNode *temp = head;
    int ele = 0;
    while (ele < k)
    {
      if (temp == NULL)
        return head;
      ele++;
      temp = temp->next;
    }

    int i = 0;

    ListNode *prev = NULL, *forward = NULL;
    ListNode *curr = head;

    while (curr != NULL && i < k)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;

      i++;
    }

    if (forward != NULL)
      head->next = solve(forward, k, ind + 5);

    return prev;
  }

  ListNode *reverseKGroup(ListNode *head, int k)
  {

    return solve(head, k, 0);
  }
};