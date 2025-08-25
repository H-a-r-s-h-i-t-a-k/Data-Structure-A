class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {

    // vector<int>even;
    // vector<int>odd;
    // int n=nums.size();
    // vector<int>ans(n);
    // for(int i=0;i<n;i++){
    //     if(nums[i]<0){
    //         //odd
    //         odd.push_back(nums[i]);
    //     }else{
    //         even.push_back(nums[i]);
    //     }
    // }
    // int ind=0;
    // int e=even.size()-1;
    // while(2*ind<n){
    //     ans[2*ind]=even[ind];
    //     ind++;
    // }
    // ind=0;
    // int o=odd.size()-1;
    // while((2*ind+1)<n){
    //     ans[2*ind+1]=odd[ind];
    //     ind++;
    // }
    // return ans;

    // app2

    int p = 0, n = 1;
    int size = nums.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
      if (nums[i] > 0)
      {
        ans[p] = nums[i];
        p += 2;
      }
      else
      {
        ans[n] = nums[i];
        n += 2;
      }
    }
    return ans;
  }
};