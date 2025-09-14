#include<iostream>
#include<vector>
using namespace std;
class stack{
int capacity;
int size;
int top;
int* arr;
public:
stack(int capacity){
  this->capacity=capacity;
  size=0;
  top=-1;
  arr=new int[capacity];





}
~stack(){
  delete[] arr;
}
void push(int value){
  if(size==capacity){
    printf("OverFlow\n");
    return;
  }
    top++;size++;
    arr[top]=value;

}
void pop(){
  if(size==0){
    printf("UnderFlow\n");
    return;
  }
  top--;
  size--;
  

}
// int top(){
//   return top;
// }
// int size(){
// return size;
// }
bool isempty(){
  return (size==0);
}
void traverse(){
  if (size == 0)
  {
    printf("UnderFlow\n");
    return;
  }
  for(int i=0;i<size;i++){
    int ele=arr[i];
    printf("%d\t",ele);
  }
  printf("\n");
}




};
int main(){
  int n;
  scanf("%d",&n);

stack stk(n);

  int operations;
  scanf("%d",&operations);

  while(operations--){
    
    printf("\n choose operation on stack: \n1.push\n2.pop\n3.top\n4.size\n5.isempty\n6.traverse\n");
    int opt=0;
    scanf("%d", &opt);

    switch(opt){
      case 1://push
      int value;
      cin>>value;
            stk.push(value);
            stk.traverse();
      break;
      case 2://pop
      stk.pop();stk.traverse();
      break;
      // case 3://top
      // stk.top();
      // break;
      // case 4://size
      // stk.size();
      // break;
      case 5://isempty
      if(stk.isempty()){
      cout<<"yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
      break;
      case 6://traverse
      stk.traverse();
      break;

      default:
      printf("\n ooops you choose wrong \n");
    }
  }

  return 0;
}