#include <iostream>
using namespace std;

int main()
{
  // Write your code here
  int num;
  scanf("%d", &num);
  int rev = 0;
  while (num > 0)
  {
    int lastdigit = num % 10;

    rev = rev * 10 + lastdigit;
    num /= 10;
  }
  printf("%d", rev);
  return 0;
}
