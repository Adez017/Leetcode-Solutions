class Solution {
    public:
        int numberOfSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int cnt =0;
            
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    int oddcnt =0;
                    for(int k=i;k<=j;k++){
                        if(nums[k]%2==1){
                            oddcnt++;
                        }
                    }
                    if(oddcnt==k){
                        cnt++;
                    }
                }
            }
            return cnt;
            
        }
    };

    //simple Approach:
    //Generate all the subarrays
    //count the number of odd elements in the subarray
    //if the count is equal to k then increment the count
    //return the count
    //Time Complexity: O(n^3)
    //Space Complexity: O(1)
    // GOt TLE