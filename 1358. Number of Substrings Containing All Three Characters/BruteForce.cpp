class Solution {
    //Approach :
    //Iterate Through all the substrings and keep a track of the cnt 0f a,b,c
    //at any point cnt of a,b,c >=1 then increment the cnt
    //return the cnt
    //Time Complexity: O(n^2)
    //Space Complexity: O(1)
    //Got TLE After 48/54 test cases
    public:
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
                    cnt++;
                    
                    }
                }
                
            }
            return cnt;
            
        }
    };