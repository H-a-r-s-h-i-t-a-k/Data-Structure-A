class Solution
{
public:
  bool hasCycle(ListNode *head)
  {

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
      {
        return true;
      }
    }

    return false;
  }
};