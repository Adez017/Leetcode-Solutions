#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = nums.size() - (upper_bound(nums.begin(), nums.end(), 0) - nums.begin());  
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();  
        return max(pos, neg);
    }
};
//approach :
// we found the upper bound of zero i.e the first positive number idx  and subtracted it from the size of the array to get the count of positive numbers
// we found the lower bound of zero i.e the first negative number idx  i.e count of negative numbers
//simply return the max of both
//TC: O(NlogN)
//SC: O(1)k