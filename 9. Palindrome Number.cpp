class Solution {
public:
    bool isPalindrome(int x) {
        int num =x,revnum=0,rem;
        if (num<0) return false;
        while(num!=0)
        {
            rem = num %10;
            num = num/10;
            if (revnum>INT_MAX/10 ||revnum==INT_MAX/10 && rem> 7) return false;
            revnum = revnum*10 + rem;
        }
        if (revnum==x) return true;
        else return false;
    }
};