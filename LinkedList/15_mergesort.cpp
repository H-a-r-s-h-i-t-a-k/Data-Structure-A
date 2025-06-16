class Solution
{
public:
  Node *findmid(Node *head)
  {
    // step 1 make two pointer
    Node *slow = head;
    Node *fast = head->next;

    // step 2 slow one step and fast two step if possible
    while (fast != NULL && fast->next != NULL)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    // step 3 fast== nullptr then return slow is mid
    return slow;
  }
  Node *merge(Node *first, Node *second)
  {
    // step 1 check if one of two empty then return head non empty
    if (first == NULL)
      return second;
    if (second == NULL)
      return first;

    // step 2 make ans Node with dummy value and temp pointer
    Node *ans = new Node(-1);
    Node *temp = ans;
    // step 3 iterate compare each other and link temp pointer
    while (first != NULL && second != NULL)
    {
      if (first->data <= second->data)
      {
        temp->next = first;
        temp = first;

        first = first->next;
      }
      else
      {
        temp->next = second;
        temp = second;
        second = second->next;
      }
    }

    // step 4 points remaining list to temp

    while (first != NULL)
    {
      temp->next = first;
      temp = first;
      first = first->next;
    }
    while (second != NULL)
    {
      temp->next = second;
      temp = second;
      second = second->next;
    }

    // step 5 return list ans
    return ans->next;
  }

  // Function to sort the given linked list using Merge Sort.
  Node *mergeSort(Node *head)
  {
    // your code here
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    // step 1 find mid

    Node *mid = findmid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    // step 2 mergesort (left ) right

    left = mergeSort(left);
    right = mergeSort(right);

    // step 3 merge them and return ;

    Node *ans = merge(left, right);

    return ans;
  }
};