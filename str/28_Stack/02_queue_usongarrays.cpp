#include<iostream>
#include<stack>
using namespace std;
class Queue{

  int capacity ;
  int sizeq;
  stack<int> stk1,stk2;

  public:
  Queue(int capacity){
    this->capacity=capacity;
    sizeq=0;

  }
 bool isEmpty(){
    return sizeq==0;
  }


  int top(){
    if(stk2.empty()){
     while(!stk1.empty()){
       stk2.push(stk1.top());stk1.pop();
    }
  }
    return stk2.top();
  }



  void push(int value){
    if(sizeq==capacity){
      printf("\n queue Overflow");
      return ;
    }

    if(stk1.size()==capacity/2){
      while(!stk1.empty()){
        stk2.push(stk1.top());stk1.pop();
        

      }
    }

    stk1.push(value);
    sizeq++;
  }
  void pop(){
    if(sizeq==0){
      printf("\n queue empyt queue Underlfow ");
      return;
    }
    if(stk2.empty()){
      while(!stk1.empty()){
        stk2.push(stk1.top());stk1.pop();
      }
    }
    stk2.pop();
    sizeq--;

  }

  void traverse(){
    if(sizeq==0){
      printf("\n Queue empty ");
      return ;
    }

   int top2=stk2.top();
      while(top2!=-1){

        cout<<stk2.top()<<"\t";
        top2--;
      } 
      stack<int>temp;
      int top1=stk1.top();
      while(top1!=-1){
        temp.push(stk1.top());top1--;

      }
      while(!temp.empty()){
        cout<<temp.top()<<" \t";
      temp.pop();
      }

    

  }

};


using namespace std;
int main(){
//   1 2 3 4 5 stack 1

//   5 4 3 2 1 stack 2



  int capacity;
  cin>>capacity;
Queue queue(capacity);

  while(1){

    printf("\nChoose an option :\n1.push\n2.pop\n3.isempty\n4.top\n5.traversal\n6.exit");
    int ch=0;
    cin>>ch;
    switch(ch){
      case 1://push
      int val;
      cin>>val;
      queue.push(val);
      queue.traverse();
      break;
      case 2://pop
      queue.pop();
      queue.traverse();
      break;
      case 3://isEmpty
      if(queue.isEmpty()){
        cout<<" yes"<<endl;
      }else{
        cout<<" No"<<endl;
      }
      break;
      case 4://top
       cout<<queue.top()<<endl;
      break;
      case 5://traversal
      queue.traverse();
      break;
      case 6:
      // exit
      return 0;

      default: 
      cout<<" oops wrong option \n ";
      // return 0;
    }
  }
  return 0;
}

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
  int capacity;
  int sizeq;
  stack<int> stk1, stk2;

public:
  Queue(int capacity)
  {
    this->capacity = capacity;
    sizeq = 0;
  }

  bool isEmpty()
  {
    return sizeq == 0;
  }

  int top()
  {
    if (isEmpty())
    {
      cout << "Queue is empty\n";
      return -1;
    }
    if (stk2.empty())
    {
      while (!stk1.empty())
      {
        stk2.push(stk1.top());
        stk1.pop();
      }
    }
    return stk2.top();
  }

  void push(int value)
  {
    if (sizeq == capacity)
    {
      cout << "Queue Overflow\n";
      return;
    }
    stk1.push(value);
    sizeq++;
  }

  void pop()
  {
    if (isEmpty())
    {
      cout << "Queue Underflow\n";
      return;
    }
    if (stk2.empty())
    {
      while (!stk1.empty())
      {
        stk2.push(stk1.top());
        stk1.pop();
      }
    }
    stk2.pop();
    sizeq--;
  }

  void traverse()
  {
    if (isEmpty())
    {
      cout << "Queue is empty\n";
      return;
    }

    // Copy stacks into temporary stacks for safe traversal
    stack<int> temp1 = stk1;
    stack<int> temp2 = stk2;

    // First print stk2 (already in correct queue order)
    stack<int> rev;
    while (!temp2.empty())
    {
      rev.push(temp2.top());
      temp2.pop();
    }
    while (!rev.empty())
    {
      cout << rev.top() << "\t";
      rev.pop();
    }

    // Then print stk1 (reverse needed because new elements go on top)
    stack<int> tempStk;
    while (!temp1.empty())
    {
      tempStk.push(temp1.top());
      temp1.pop();
    }
    while (!tempStk.empty())
    {
      cout << tempStk.top() << "\t";
      tempStk.pop();
    }
    cout << "\n";
  }
};

int main()
{
  int capacity;
  cout << "Enter queue capacity: ";
  cin >> capacity;
  Queue queue(capacity);

  while (true)
  {
    cout << "\nChoose an option:\n"
         << "1. Push\n2. Pop\n3. IsEmpty\n4. Top\n5. Traverse\n6. Exit\n";
    int ch;
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
      int val;
      cout << "Enter value: ";
      cin >> val;
      queue.push(val);
      queue.traverse();
      break;
    }
    case 2:
      queue.pop();
      queue.traverse();
      break;
    case 3:
      cout << (queue.isEmpty() ? "Yes" : "No") << endl;
      break;
    case 4:
      cout << "Front: " << queue.top() << endl;
      break;
    case 5:
      queue.traverse();
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid option\n";
    }
  }
  return 0;
}
