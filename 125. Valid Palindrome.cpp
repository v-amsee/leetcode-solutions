class Solution {
public:
    bool isPalindrome(string s) {
        int j=0;
        string str=s;
        for (int i=0;i<str.size();i++)
        {
            if((str[i]>='a' && str[i]<='z')||
                (str[i]>='A' && str[i]<='Z')||
                (str[i]>='0' && str[i]<='9'))
                {str[j++]=tolower(s[i]);}
        }
        str.resize(j);

    int left=0,right=str.size()-1;
    while(left<=right)
    {
        if(str[left]!=str[right]) return false;
        left++;
        right--;
    }
    return true;
    }
};