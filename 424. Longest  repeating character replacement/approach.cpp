class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n = s.length();
            int l = 0;
            int maxFreq = 0;  // Track the max frequency of a character in the window
            unordered_map<char, int> mpp;
            int maxLength = 0;
    
            for (int r = 0; r < n; r++) {
                mpp[s[r]]++;
                maxFreq = max(maxFreq, mpp[s[r]]);  // Keep track of the max occurring character
    
                // If window is invalid, shrink from left
                //windowsize-maxfreq = remainig characters count or remaining
                while ((r - l + 1) - maxFreq > k) {
                    mpp[s[l]]--;
                    l++;
                }
    
                maxLength = max(maxLength, r - l + 1);
            }
    
            return maxLength;
        }
    };
    