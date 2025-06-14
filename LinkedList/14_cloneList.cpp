
class Solution
{
public:
  void insertatTail(Node *&head, Node *&tail, int data)
  {
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }
  Node *solve(Node *head)
  {
    Node *cloneH = nullptr, *cloneT = nullptr;
    // step1 clone link list
    Node *oldH = head;
    while (oldH != nullptr)
    {
      insertatTail(cloneH, cloneT, oldH->val);
      oldH = oldH->next;
    }
    // stp2 make map  old with new
    oldH = head;
    Node *newH = cloneH;

    unordered_map<Node *, Node *> mp;
    while (oldH != nullptr)
    {
      mp[oldH] = newH;
      oldH = oldH->next;
      newH = newH->next;
    }

    // step3 pick and map random pionter to new
    oldH = head;
    newH = cloneH;
    while (oldH != nullptr)
    {
      newH->random = mp[oldH->random];
      oldH = oldH->next;
      newH = newH->next;
    }
    return cloneH;
  }

  Node *copyRandomList(Node *head)
  {
    if (head == nullptr)
      return head;
    return solve(head);
  }
};