class Solution {
    public:
    //instead of using two arrays to store the left and right boundary of the rectangle
    //we can use a stack to store the index of the bars
    //this way we can find the left and right boundary of the rectangle for each bar in O(1) time
    //Time complexity: O(n)
    //Space complexity: O(n)
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int> st;
            int maxa = 0;
            for(int i=0;i<n;i++){
                //if the current bar is smaller than the bar at the top of the stack
                //then we can find the nse boundary of the rectangle
                //and calculate the area
                while(!st.empty() && heights[st.top()]>heights[i]){
                    int el = st.top() ;
                    st.pop();
                    int nse = i;
                    int pse = st.empty()? -1:st.top();
                    maxa = max(maxa,(heights[el]*(nse-pse-1)));
                }
                st.push(i);
            }
            while(!st.empty()){
                int ele = st.top(); st.pop();
                int nse = n;
                int pse = st.empty()?-1: st.top();
                maxa = max(maxa,(heights[ele]*(nse-pse-1)));
            
            }
            return maxa;
    
            
        }
    };

    //Time complexity: O(n)
    //Space complexity: O(n)
    //Optimised approach
    //key observation a bar can only make rectangle with the bars of same or greater height
    //so we can iterate over the array and for each bar we can find the left and right boundary of the rectangle
    //and calculate the area