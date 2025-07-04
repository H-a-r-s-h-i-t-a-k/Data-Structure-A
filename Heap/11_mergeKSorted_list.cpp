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
class compare
{
public:
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val;
  }
};
class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, compare> minheap;
    int k = lists.size();
    if (k == 0)
      return nullptr;
    for (int i = 0; i < k; i++)
    {
      if (lists[i] != nullptr)
      {
        minheap.push(lists[i]);
      }
    }
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (!minheap.empty())
    {
      ListNode *top = minheap.top();
      minheap.pop();
      if (top->next)
      {
        minheap.push(top->next);
      }
      if (head == NULL)
      {
        head = top;
        tail = top;
      }
      else
      {
        tail->next = top;
        tail = top;
      }
    }

    return head;
  }
};