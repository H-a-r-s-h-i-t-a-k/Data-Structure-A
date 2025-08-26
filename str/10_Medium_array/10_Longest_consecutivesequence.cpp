#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
  // unordered_set<int>st;

  //     for(auto item:arr){
  //         st.insert(item);
  //     }
  //     int maxcount=1;
  //     for(auto item:arr){
  //         int search=1;
  //         int num=item;
  //         int cnt=1;
  //         while(search){
  //             if(st.find(num-1)!=st.end()){
  //                 cnt++;
  //                 num--;
  //             }else{
  //                 search=0;
  //             }
  //         }
  //         search=1;
  //         num=item;
  //         while(search){
  //             if(st.find(num+1)!=st.end()){
  //                 cnt++;
  //                 num++;
  //             }else{
  //                 search=0;
  //             }
  //         }
  //         maxcount=max(maxcount,cnt);
  //     }
  //        return maxcount;

  //        app2

  if (arr.size() == 0)
  {
    return 0;
  }
  sort(arr.begin(), arr.end());
  int cnt = 0;
  int longest = 1;
  int recentsmall = INT_MIN;
  for (int i = 0; i <= n - 1; i++)
  {
    if (recentsmall == arr[i] - 1)
    {
      cnt++;
      recentsmall = arr[i];
    }
    else if (recentsmall != arr[i])
    {
      cnt = 1;
      recentsmall = arr[i];
    }

    longest = max(longest, cnt);
  }

  return longest;

  // Write your code here.
}