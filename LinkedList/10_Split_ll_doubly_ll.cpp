class Solution
{
public:
  pair<Node *, Node *> splitList(struct Node *head)
  {
    // code here

    Node *slow = head, *fast = head;

    while (fast->next != head)
    {

      fast = fast->next;

      if (fast != head && fast->next != head)
      {
        fast = fast->next;
      }

      else
      {
        break;
      }
      slow = slow->next;
    }

    Node *l2 = slow->next;   // pick secend list
    fast->next = slow->next; // make circular
    slow->next = head;       // first list make circular

    return {head, l2};
  }
};