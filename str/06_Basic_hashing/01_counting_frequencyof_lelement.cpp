int maximumFrequency(vector<int> &arr, int n)
{
  int maxi = 0;
  unordered_map<int, int> freq;
  for (int i = n - 1; i >= 0; i--)
  {
    freq[arr[i]]++;
    maxi = max(maxi, freq[arr[i]]);
  }
  int ans = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (maxi == freq[arr[i]])
    {
      ans = arr[i];
      break;
    }
  }
  return ans;
  // Write your code here
}