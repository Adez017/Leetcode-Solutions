class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // set<int> uniqueNums; // to avoid duplicates
        // int n = digits.size();

        // // Generate all 3-digit permutations
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (j == i) continue;
        //         for (int k = 0; k < n; k++) {
        //             if (k == i || k == j) continue;

        //             int a = digits[i], b = digits[j], c = digits[k];
        //             if (a == 0) continue;      // skip if leading digit is 0
        //             if (c % 2 != 0) continue;  // must be even

        //             int num = a * 100 + b * 10 + c;
        //             uniqueNums.insert(num);
        //         }
        //     }
        // }

        // // Convert set to sorted vector
        // return vector<int>(uniqueNums.begin(), uniqueNums.end());

        //better approach 
        //instead of making every pair manualy taking O(n^3)
        //will count or store the frequency map that take every frequency 
        //as given the number will be in between 100 to 999 so we iterate thourh them and when we are iteraitng we are going to update the frequesnciues and add to result till it is greater then 0
        unordered_map<int,int>mpp;
        vector<int> res;
        for(auto m: digits){
            mpp[m]++;
        }
        for(int i=100;i<=999;i+=2){ //+2 so we take even only
            int a = i/100 ; //100 place 
            int b = (i/10)%10 ; //10 place
            int c = i%10; //1 place
            unordered_map<int,int>mp1 = mpp;
            if(--mp1[a]>=0 && --mp1[b]>=0 && --mp1[c]>=0){
                res.push_back(a*100+b*10+c);
            }
        }
        return res;
    }
};
