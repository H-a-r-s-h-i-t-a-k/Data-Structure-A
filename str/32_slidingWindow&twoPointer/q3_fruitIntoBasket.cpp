q4class Solution{
  public :
      int totalFruit(vector<int> & fruits){
          // brute force

          // int ans=0,n=fruits.size(),k=2;
          //    set<int>st;
          // for(int i=0;i<=n-1;i++){
          //     st.clear();
          //     for(int j=i;j<n;j++){
          //         if(st.size()>k){
          //             break;
          //         }
          //         st.insert(fruits[j]);
          //         ans=max(ans,j-i+1);

          //     }
          // }

          // better

          //     int l=0,r=0,n=fruits.size();
          //     unordered_map<int,int> mp;
          // int k=2,ans=0;
          //     for(r=0;r<n;r++){
          //         mp[fruits[r]]+=1;
          //         while(mp.size()>k){
          //             mp[fruits[l]]--;
          //             if(mp[fruits[l]]==0){
          //                 mp.erase(fruits[l]);
          //             }
          //             l++;
          //         }

          //         ans=max(ans,r-l+1);
          //     }
          //     return ans;
          //     }

          ////optimise
          int l = 0, r = 0, n = fruits.size();
unordered_map<int, int> mp;
int k = 2, ans = 0;
for (r = 0; r < n; r++)
{
  mp[fruits[r]]++;
  if (mp.size() > k)
  {
    mp[fruits[l]]--;
    if (mp[fruits[l]] == 0)
    {
      mp.erase(fruits[l]);
    }
    l++;
  }

  ans = max(ans, r - l + 1);
}
return ans;
}
}
;
