int solveSpace(vector<int>&heights){
  int had=0,have=0;
  int n=heights.size();
  for(int i=1;i<n;i++){
    int left=have+abs(heights[i]-heights[i-1]);
    int right=INT_MAX;
    if(i>1){
      right=had+abs(heights[i-2]-heights[i]);
    }

    int curr=min(left,right);
    had=have;
    have=curr;

  }
  return had;
}
