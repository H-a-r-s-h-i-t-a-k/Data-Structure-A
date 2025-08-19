bool palindrome(int n)
{
  int copy = n;
  int rev = 0;
  if (n < 0)
  {
    return false;
  }
  while (n > 0)
  {
    int last = n % 10;
    n /= 10;
    rev = rev * 10 + last;
  }
  // if(rev==copy){
  //     return true;
  // }else{
  //     return false;
  // }
  return rev == copy ? true : false;
  // Write your code here
}