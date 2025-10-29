class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> rect;
        int maxarea=0;
        for (int i=0;i<heights.size();i++)
        {
            int start =i;
            while(!rect.empty() && heights[i]<rect.top().second)
            {
                maxarea=max(maxarea,rect.top().second*(i - rect.top().first));
                start =rect.top().first;
                rect.pop();
            }
            rect.push({start,heights[i]});
        }
        while(!rect.empty())
        {
        maxarea=max(maxarea,rect.top().second*static_cast<int>(heights.size() - rect.top().first));
        rect.pop();
        }
    return maxarea;
    }
};