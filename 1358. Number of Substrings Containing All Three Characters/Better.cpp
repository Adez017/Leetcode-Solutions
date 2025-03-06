class Solution {
    public:
    //idea is if we had a valid subaaray till j that simply means that no 
    //matter what comes next it would be valid subarray
    //so we can simply add n-j to the cnt
    //Time Complexity: O(n^2) worst case ? then why better beacuse it would somwwhat be less than n^2
    // exmaple a , a, b,c, a, b 
        //     0    1  2 3 4  5   at 3 we got valid then the remainig subarrays will be valid we dont need
        //    to check them so we can simply add n-j to the cnt
            //Space Complexity: O(1)
        int numberOfSubstrings(string s) {
            int n = s.length();
            int cnt =0;
            for(int i=0;i<n;i++){
                int acnt =0,bcnt =0,ccnt=0;
                for(int j=i;j<n;j++){
                    if(s[j]=='a') acnt++;
                    else if(s[j]=='b') bcnt++;
                    else{
                        ccnt++;
                    }
                    if(acnt>=1 && bcnt>=1 && ccnt>=1){
                        cnt = cnt+(n-j);
                        break;
                    
                    
                    }
                }
                
            }
            return cnt;
            
        }
    };