class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int r =0;
            int l =0;
            int zerocnt =0;
            int maxi =0;
            //example of dynamic window maintaining
            for(int i=0;i<n;i++){
                //keeping the track of the zero's
                if(nums[r]==0){
                    zerocnt++;
                }
                //while zero's>k we check that if the left pointer is on 0 if 
                //it is so then we move left pointer next to zero+1 to eliminate 0
                while(zerocnt>k){
                    if(nums[l]==0){
                        zerocnt--;
                    }
                    l++;
    
                }
                //this way we are mainatining the fliping of the zeros 
                maxi = max(maxi,r-l+1); //window size;
                r++;
            }
            return maxi;
            //TC = O(N);
            //SC = O(1)
            
        }
    };