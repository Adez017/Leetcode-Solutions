class Solution {
    public:
        vector<int> decrypt(vector<int>& code, int k) {
            int n = code.size();
            vector<int> result(n,0);
            //if k is 0 then return the result as it is i.e [0] array
            if (k==0) return result;
            for(int i=0;i<n;i++){
                if(k>0){
                    //compute the sum of the next k elements
                    for(int j=i+1;j<i+k+1;j++){
                        result[i]+=code[j%n];
                    }
                }
                else{
                    //compute the sum of the previous k elements
                    //if j is negative then add n to it to get the positive index
                    for(int j=i+k;j<i;j++){
                        result[i]+=code[(j+n)%n];
                    }
                }
            }
            return result;
            
        }
    };