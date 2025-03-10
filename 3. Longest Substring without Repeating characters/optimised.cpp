class Solution {
    public:
    //s = 'abcabcbb'
      //keeping a window of l and r
            //if we get a repeating character then we will move the left pointer to the next of the repeating character
            //and update the length
            //this way we will get the maximum length of the substring without repeating characters
            //Time Complexity: O(n) 
            //Space Complexity: O(1)
            //This is a optimised approach as we are using a map to store the index of the characters
            
    
        int lengthOfLongestSubstring(string s) {
            vector<int> map(256,-1);
            int n = s.length();
            int l =0;
            int r = 0;
            int length = 0;
          
            while(r<n){
                if(map[s[r]]!=-1){
                    l = max(map[s[r]]+1,l);
                }
                map[s[r]] = r;
                length = max(length,r-l+1);
                r++;
            }
            return length;
        }
    };