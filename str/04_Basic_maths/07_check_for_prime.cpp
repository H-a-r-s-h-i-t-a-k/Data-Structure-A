#include <iostream>
using namespace std;

int main()
{
  // Write your code here
  int num;
  scanf("%d", &num);

  int c = 0;
  // if(num<=2){
  // 	cout<<"true";
  // 	return 0;
  // }
  for (int i = 1; i <= i * i; i++)
  {
    if ((num % i) == 0)
    {
      c++;
    }
  }
  if (c == 2)
    cout << "true";
  else
  {
    cout << "false";
  }
  return 0;
}
