class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n = nums.size();
            int ans=0;
            int neg = 0;
            int pos =0;
            for(int i=0;i<n;i++){
                if(nums[i]<0){
                    neg++;
                }
                if(nums[i]>0){
                    pos++;
                }
                ans =max(pos,neg);
            }
            return ans;
            
        }
    };