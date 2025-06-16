
class Solution
{
public:
  ListNode *solve(ListNode *first, ListNode *second)
  {
    if (first->next == NULL)
    {
      first->next = second;
      return first;
    }
    ListNode *currF = first;
    ListNode *nextF = first->next;
    ListNode *currS = second;
    ListNode *nextS = NULL;

    while (currF != NULL && nextF != NULL && currS != NULL)
    {
      int data = currS->val;
      if (data >= currF->val && data <= nextF->val)
      {
        currF->next = currS;
        nextS = currS->next;
        currS->next = nextF;

        currF = currS;
        currS = nextS;
      }
      else
      {
        currF = nextF;
        nextF = nextF->next;
        if (nextF == nullptr)
        {
          currF->next = currS;
          return first;
        }
      }
    }

    return first;
  }

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *ans = NULL;
    if (list1 == NULL)
      return list2;
    if (list2 == NULL)
      return list1;

    if (list1->val <= list2->val)
    {
      return solve(list1, list2);
    }
    else
    {
      return solve(list2, list1);
    }
    return ans;
  }
};
