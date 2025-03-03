class Solution {
    public:
    //the idea is simple we have to find  cnt of the Binary subarray with sum = goal
    //we can find the cnt of the Binary subarray with sum <= goal
    //and cnt of the Binary subarray with sum <= goal-1 
    //and the difference between them will be the cnt of the Binary subarray with sum = goal
        int lessthengoal(vector<int>&nums,int goal){
            if(goal<0) return 0;
            int l = 0;
            int r = 0;
            int n = nums.size();
            int cnt =0;
            int sum =0;
            while(r<n){
                sum+=nums[r];
                while(sum>goal){
                    sum-=nums[l];
                    l++;
                }
                cnt+=(r-l+1);
                r++;   
    
            }
            return cnt;
        }
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return lessthengoal(nums,goal)-lessthengoal(nums,goal-1);
            
        }
    };