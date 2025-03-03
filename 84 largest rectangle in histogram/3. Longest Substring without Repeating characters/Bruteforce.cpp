class Solution {
    public:
    //use of Frequency array to keep track of the characters without repeating
        int lengthOfLongestSubstring(string s) {
            int n = s.length();
            int max_length = 0;
    
            for (int i = 0; i < n; i++) {  // Left pointer (start of substring)
                int freq[256] = {0};  // Array to track character frequency
    
                for (int j = i; j < n; j++) {  // Right pointer (end of substring)
                    if (freq[s[j]] > 0) break;  // If character repeats, stop expanding
    
                    freq[s[j]]++;  // Mark character as seen
                    max_length = max(max_length, j - i + 1);
                }
            }
    
            return max_length;
        }
    };
    //TC = O(n^2)
    //SC = O(1)    