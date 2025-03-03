class Solution {
    public:

    //Bruteforce approach
    //key observation a bar can only make rectangle with the bars of same or greater height
    //so we can iterate over the array and for each bar we can find the left and right boundary of the rectangle
    //and calculate the area
    //Time complexity: O(n)
    //Space complexity: O(n)
        vector<int> pse(vector<int>&nums){
            int n = nums.size();
            stack<int> st;
            vector<int> pse(n);
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.top()] > nums[i]){
                    st.pop();
                }
                pse[i]=st.empty()?-1:st.top();
                st.push(i);
            }
            return pse;
        }
    
        vector<int>nse(vector<int>&nums){
            stack<int> st;
            int n = nums.size();
            vector<int> nse(n);
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
                nse[i]=st.empty()? n:st.top();
                st.push(i);
            }
            return nse;
        }
    
        int largestRectangleArea(vector<int>& heights) {
            vector<int> nsel = nse(heights);
            vector<int> psel = pse(heights);
            int maxarea = 0;
            int n = heights.size();
            for(int i=0;i<n;i++){
                int area = heights[i]*(nsel[i]-psel[i]-1);
                maxarea = max(area,maxarea);
            }
            return maxarea;
        }
    };