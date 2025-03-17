class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            // int n = nums.size();
            // sort(nums.begin(),nums.end());
            // for(int i=0;i<n;i+=2){
            //     if(nums[i]!=nums[i+1]){
            //         return false;
            //     }
            // }
            // return true;
            //O(n logn)
            // unordered_map<int,int> mpp;
            // for(auto num:nums){
            //     mpp[num]++;
            // }
            // for(auto it: mpp){
            //     if(it.second%2!=0){
            //         return false;
            //     }
            // }
            // return true; // O(2n) ~~ O(n)
    
            //using the hashset 
            // the idea is if we found a value pair we remove it from the hashset
            unordered_set<int> check;
            for(auto num: nums){
                if(check.count(num)){
                    check.erase(num);
                }
                else{
                    check.insert(num);
                }
            }
            return check.empty();
    
            
        }
    };