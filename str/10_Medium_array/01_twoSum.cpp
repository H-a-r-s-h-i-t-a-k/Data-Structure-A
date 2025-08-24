string read(int n, vector<int> book, int target)
{
  // app1:
  // long long t=target;
  // for(int i=0;i<n;i++){
  //     for(int j=i+1;j<n;j++){
  //         long long  sum=book[i];
  //         for(int k=i+1;k<=j;k++){
  //             sum+=book[k];
  //         }
  //        if(sum==t){
  //            return "YES";
  //        }
  //     }
  // }
  // return "NO";

  // appp2

  // for(int i=0;i<n;i++){

  //     for(int j=i+1;j<n;j++){
  //         if(book[i]+book[j]==target){
  //             return"YES";
  //         }
  //     }
  // }
  // return "NO";

  // app3
  sort(book.begin(), book.end());
  int s = 0;
  int e = n - 1;
  while (s < e)
  {
    int sum = book[s] + book[e];
    if (sum == target)
    {
      return "YES";
    }
    else if (sum < target)
    {
      s++;
    }
    else
    {
      e--;
    }
  }
  return "NO";
  // Write your code here.
}