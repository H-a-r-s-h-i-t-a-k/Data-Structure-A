class twoStacks
{
public:
  int arr[100];
  int top1, top2;
  twoStacks()
  {

    top1 = -1, top2 = 100;
  }

  bool isEmpty(int l)
  {
    return (l == 1 && top1 == -1) || (l == 2 && top2 == 100);
  }
  // Function to push an integer into the stack1.
  void push1(int x)
  {
    // code here
    if (top1 < top2 - 1)
      arr[++top1] = x;
  }

  // Function to push an integer into the stack2.
  void push2(int x)
  {
    if (top1 < top2 - 1)
      arr[--top2] = x;

    // code here
  }

  // Function to remove an element from top of the stack1.

  int pop1()
  {
    if (isEmpty(1))
    {
      return -1;
    }
    int var = arr[top1--];
    // code here
    return var;
  }

  // Function to remove an element from top of the stack2.
  int pop2()
  {
    if (isEmpty(2))
    {
      return -1;
    }
    int var = arr[top2++];
    // code here
    return var;
    // code here
  }
};