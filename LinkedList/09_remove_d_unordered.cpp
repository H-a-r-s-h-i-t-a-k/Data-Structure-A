class Solution
{
public:
  Node *removeDuplicates(Node *head)
  {
    unordered_set<int> st;
    Node *temp = head, *prev = NULL;

    while (temp != NULL)
    {
      if (st.find(temp->data) != st.end())
      {
        prev->next = temp->next;

        Node *rem = temp;

        temp = temp->next;
        delete rem;
      }

      else
      {
        st.insert(temp->data);
        prev = temp;
        temp = temp->next;
      }
    }

    return head;
  }
};