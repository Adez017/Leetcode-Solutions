class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int cnt =0;
            for(int i=0;i<=n-3;i++){
                if(nums[i]==0){
                    
                    nums[i]=1;
                    nums[i+1]=nums[i+1]==0? 1:0;
                    nums[i+2]=nums[i+2]==0? 1:0;
                    cnt++;
                }
            }
            int sum = accumulate(nums.begin(),nums.end(),0);
            if(sum==n) return cnt;
            else return -1;
            
        }
    };