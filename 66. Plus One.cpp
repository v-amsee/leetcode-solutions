class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int digit=(digits[n-1] +1)%10;
        int carry=(digits[n-1]+1)/10;
        int i=n-2;
        int temp;
        vector<int> ans;
        ans.push_back(digit);
        while(i>-1)
        {
            temp=digits[i] + carry;
            digit=(temp)%10;
            ans.push_back(digit);
            carry=temp/10;
            i--;
            
        }
        if(carry!=0)
        {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
   return ans;}
};