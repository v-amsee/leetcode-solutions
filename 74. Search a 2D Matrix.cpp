class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows=matrix.size();
        int cols=matrix[0].size();

        int high=rows-1,low=0,row;
        while(low <=high)
        {
            row= (high - low)/2 + low;
            if(target < matrix[row][0])
            {
                high=row-1;
            }
            else if (target > matrix[row][cols-1])
            {
                low=row +1;
            }
            else
                break;
        }
        if(!(low<=high)) 
            return false;

        int l=0,h=cols-1;
        while(l<=h)
        {
            int col=(h-l)/2 +l;
            if(matrix[row][col]==target)
                return true;
            else if (matrix[row][col]<target)
                l=col+1;
            else
                h=col-1;
        }
    return false;
    }
};