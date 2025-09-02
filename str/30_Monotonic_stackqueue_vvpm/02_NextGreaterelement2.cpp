class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    // app1
    // step1 initialize ans with -1;
    // step2 traverse each i th node and run a loop j=i+1--2n-1 in circular then comapare nums[i] <nums[j%n]
    // stp3 put in ans vector then break
    //  step4 return  ans;
    // int n=nums.size();
    // vector<int> ans(n,-1);

    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<2*n-1;j++){
    //         int index=j%n;
    //         if(nums[i]<nums[index]){
    //             ans[i]=nums[index];
    //             break;
    //         }
    //     }

    // }

    // return ans;

    // App2

    // step1 : initialize vector ans with -1
    // step2 : declare stack  and traverse arr  in order to see virtual double arr 2n-1-----0
    // step3 : fill out or pop out stack element in order to make decreasing fashion
    // step4 : removal while loop to exclude smaller and equal element of curr arr
    // step5 : insert only smaller element then top()  in stack   and update nge vector then return ;

    int n = nums.size();
    vector<int> nge(n, -1);

    stack<int> stk;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
      while (!stk.empty() && nums[i % n] >= stk.top())
      {
        stk.pop();
      }
      int index = i % n;
      if (!stk.empty() && i < n)
        nge[i] = stk.top();
      stk.push(nums[index]);
    }

    return nge;

    //////return
  }
};

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    // step1 initialise stack and nge vector with -1
    // step2 assume virtual circular array  first of  all traverse all element of array
    //       and maintain stack in decreasing order
    // step3 traverse from last element assigning nge =topof stack if stack empty then  store -1
    // step4 run while loop inside reverse traverse for loop for
    //       removal of min and equal elemnt of stack as compare to arr curr element
    // step5 simple return ans vector'
    int n = nums.size();
    stack<int> stk;
    vector<int> nge(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
      while (!stk.empty() && stk.top() <= nums[i % n])
      {
        stk.pop();
      }
      if (i < n)
      {
        nge[i] = stk.empty() ? -1 : stk.top();
        // break;
      }
      stk.push(nums[i % n]);
    }
    return nge;
  }
};