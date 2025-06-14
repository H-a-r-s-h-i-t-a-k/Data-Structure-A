/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  void insertatTail(ListNode *&head, ListNode *&tail, int val)
  {
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }
  ListNode *addList(ListNode *l1, ListNode *l2)
  {
    ListNode *ansH = NULL, *ansT = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
      int a = 0, b = 0;
      if (l1 != NULL)
      {
        a = l1->val;
      }
      if (l2 != NULL)
      {
        b = l2->val;
      }
      int sum = carry + a + b;
      int digit = sum % 10;

      insertatTail(ansH, ansT, digit);
      carry = sum / 10;

      if (l1 != NULL)
      {
        l1 = l1->next;
      }
      if (l2 != NULL)
      {
        l2 = l2->next;
      }
    }
    return ansH;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *ans = addList(l1, l2);

    return ans;
  }
};
