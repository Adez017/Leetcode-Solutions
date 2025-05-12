class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> uniqueNums; // to avoid duplicates
        int n = digits.size();

        // Generate all 3-digit permutations
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    int a = digits[i], b = digits[j], c = digits[k];
                    if (a == 0) continue;      // skip if leading digit is 0
                    if (c % 2 != 0) continue;  // must be even

                    int num = a * 100 + b * 10 + c;
                    uniqueNums.insert(num);
                }
            }
        }

        // Convert set to sorted vector
        return vector<int>(uniqueNums.begin(), uniqueNums.end());
    }
};
