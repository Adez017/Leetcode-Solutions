class Solution {
    public:
    
    
    //Approach:
    //The idea is simple we have to find the cnt of the subarray with atmost k odd elements
    //and cnt of the subarray with atmost k-1 odd elements
    //and the difference between them will be the cnt of the subarray with exactly k odd elements

    //Idea is simple we have to find the cnt of the subarray with atmost k odd elements
    //and cnt of the subarray with atmost k-1 odd elements
    //and the difference between them will be the cnt of the subarray with exactly k odd elements//

    //we use the Sliding window approach where we keep track of the number of odd elements in the subarray
    //if the number of odd elements in the subarray is greater than k then we move the left pointer to the right
    //and if the number of odd elements in the subarray is less than or equal to k then we move the right pointer to the right
    //and we keep track of the cnt of the subarray with atmost k odd elements
    //and cnt of the subarray with atmost k-1 odd elements
    //this way we can find the cnt of the subarray with exactly k odd elements
    //Time Complexity: O(n)
    //Space Complexity: O(1)
        int sub(vector<int>&nums,int goal){
            int r =0, l =0;
            int n = nums.size();
            int cnt =0;
            int ans=0;
            while(r<n){
                if(nums[r]%2) cnt++;
                while(l<=r && cnt>goal){
                    if(nums[l]%2) cnt--;
                    l++;
                }
                r++;
                ans+=r-l+1;
                
    
            }
            return ans;
    
        }
        int numberOfSubarrays(vector<int>& nums, int k) {
            return sub(nums,k) - sub(nums,k-1);
            
        }
    };