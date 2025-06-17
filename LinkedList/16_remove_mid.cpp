class Solution
{
public:
  ListNode *deleteMiddle(ListNode *head)
  {
    if (!head || !head->next)
      return head;
    ListNode *slow = head;
    ListNode *follow = nullptr;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      follow = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    // cout<<slow->val<<e??ndl;
    if (follow)
      follow->next = slow->next;

    delete slow;
    return head;
  }
};