#include<iostream>
#include<bits/stdc++.h>


using namespace std;


void mergesort(vector<int>& nums,vector<int>& nums2){
  int n=nums.size();
  int m=nums2.size();
  int total=n+m;
  vector<int>ans(total);
   int i=0,j=0;
   int ind=0;
   while(i<n&&j<m){
      if(nums[i]<nums2[j]){
        ans[ind]=nums[i];
        i++;ind++;
      }
      else if (nums[i]>nums2[j]){
        ans[ind]=nums2[j];
        j++;ind++;
      }
      else{
        ans[ind]==nums[j];
        ind++;i++;j++;
      }
   }

   while(i<n){
    ans[ind++]=nums[i++];
   }
   while(j<m){
    ans[ind++]=nums2[j++];
   }











   i=0,j=0;
   for(auto& ele:ans){
    if(i<n){
      nums[i]=ele;
      i++;
    }else{
      nums2[j]=ele;
      j++;
    }
   }

}
void mergesortBetter(vector<int>&nums,vector<int>& nums2){
  int n=nums.size();
  int m=nums2.size();

  int l=n-1,r=0;

  while(l>=0&& r<=m-1){
    if(nums[l]>nums[r]){
      swap(nums[l],nums2[r]);
      l--;r++;
    }
    else{
      break;
    }
  }
  sort(nums.begin(),nums.end());
  sort(nums2.begin(),nums2.end());

  


}

void swapIfGreater(vector<int>&nums,vector<int>&nums2,int i ,int j){
  if(nums[i]>nums2[j]){
    swap(nums[i],nums2[j]);
  }
}
void mergesortOptimal(vector<int>& nums,vector<int>& nums2){
      int n=nums.size()+nums2.size();
int first=nums.size(),second=nums2.size();
      int gap=(n/2)+(n%2);

      while(gap>0){
        int left=0;
        int right=left+gap;

        while(right<n){
          //first second
          if(left<first && right>=first){
            swapIfGreater(nums,nums2,left,right-first);
          }
          // second second
          else if(left>=first){
            swapIfGreater(nums,nums2,left-first,right-first);
          }// first fist
          else{
            swapIfGreater(nums, nums2, left, right);
          }

          left++;right++;
        }


        if(gap==1)break;
        gap=(gap/2)+(gap%2);
      }
     
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  vector<int>nums2(m);
  

  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  for(int i=0;i<m;i++){
    cin>>nums2[i];
  }

  // mergesort(nums,nums2);
  // mergesortBetter(nums,nums2);
  mergesortOptimal(nums,nums2);
 for(int i=0;i<n;i++){
  cout<<nums[i]<<" ";
 }
 for(int i=0;i<m;i++){
  cout<<nums2[i]<<" ";
 }




  return 0;
}