class Solution {
    public:
    // approach:
    //The question state that we can take k cards from the start or end of the array
    //So we can take k cards from the start and from the end or vice versa
    //we had to find the maximum sum of the cards we can take


    //solution:
    //for taking k cards from the start we can take the sum of the first k cards
    //if we take k cards from the start then Maxsum = sum of the first k cards i.e lsum
    //then we can take the remaining cards from the end of the array and substitute the cards from the start
    //one by one and check if the sum is greater than the maxsum
    //if it is greater then update the maxsum
    //return the maxsum
    //Time Complexity: O(n)
    //Space Complexity: O(1)
        int maxScore(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
            int lsum =0;
            int rsum =0;
            int maxsum =0;
            for(int i=0;i<k;i++){
                lsum+=cardPoints[i];
            }
            maxsum = lsum;
            int ridx = n-1;
            for(int i=k-1;i>=0;i--){
                lsum-=cardPoints[i];
                rsum +=cardPoints[ridx];
                ridx--;
    
                maxsum = max(maxsum,lsum+rsum);
                
            }
            return maxsum;
    
            
        }
    };