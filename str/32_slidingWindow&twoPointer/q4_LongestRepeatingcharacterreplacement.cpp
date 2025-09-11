// 424. Longest Repeating Character Replacement
//     Attempted
//         Medium
//             Topics
//                 premium lock icon
//                     Companies
//                         You are given a string s and an integer k.You can choose any character of the string and change it to any other uppercase English character.You can perform this operation at most k times.

//     Return the length of the longest substring containing the same letter you can get after performing the above operations.


#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

// int characterReplacement(string s,int k){
//   int maxlen=0;
//   int n=s.size();
//   for(int i=0;i<n;i++){
//     unordered_map<int,int>mp;
//     int maxfreq=0;
//     for(int j=i;j<n;j++){
//       char ch=s[j]-'A';
//       mp[ch]++;
//       maxfreq=max(maxfreq,mp[ch]);
//       int len=j-i+1;
//       int rem=len-maxfreq;
//       if(rem<=k){
//         maxlen=max(maxlen,len);
//       }
//     }
//   }
//   return maxlen;
// }
// int characterReplacement(string s,int k){
//   int maxlen=0,n=s.size();
//   int l=0,r=0;
//   unordered_map<int,int>mp;
// int maxfreq=0,maxele=0;
//   for(r=0;r<n;r++){
//     char ch=s[r]-'A';
//     mp[ch]++;
//     if(maxfreq<mp[ch]){
//       maxfreq=mp[ch];
//       maxele=mp[ch];
//     }
//     maxfreq=max(maxfreq,mp[ch]);
//     int len=r-l+1;
//     int rem=len-maxfreq;
while ((r - l + 1) - maxfreq > k)
{
  ch = s[l] - 'A';
  mp[ch]--;
  maxfreq = max(maxfreq, mp[ch]);

  l++;
}

//     }
//     if(rem<=k){
//       maxlen=max(maxlen,r-l+1);
//     }




//   }
//   return maxlen;
// }

int characterReplacement(string s, int k)
{
  int maxlen = 0, n = s.size();
  int l = 0, r = 0;
  unordered_map<int, int> mp;
  int maxfreq = 0, maxele = 0;
  for (r = 0; r < n; r++)
  {
    char ch = s[r] - 'A';
    mp[ch]++;
    if (maxfreq < mp[ch])
    {
      maxfreq = mp[ch];
      maxele = mp[ch];
    }
    maxfreq = max(maxfreq, mp[ch]);
    int len = r - l + 1;
    int rem = len - maxfreq;

    while ((r - l + 1) - maxfreq > k)
    {
      ch = s[l] - 'A';
      mp[ch]--;
      maxfreq = max(maxfreq, mp[ch]);

      l++;
    }
    if (rem <= k)
    {
      maxlen = max(maxlen, r - l + 1);
    }
  }
  return maxlen;
}

int main(){
  char arrchar[100000];
  int k;
  scanf("%s",arrchar);

  scanf("%d",&k);
  string s(arrchar);
  printf("%d",characterReplacement(s,k));


  return 0;

}

