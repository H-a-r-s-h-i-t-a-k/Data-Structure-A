class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *temp = head;
    ListNode *res = head;

    while (temp && temp->next != nullptr)
    {

      if (temp->val == temp->next->val)
      {
        temp->next = temp->next->next;
      }
      else
      {
        temp = temp->next;
      }
    }

    return res;
  }
};