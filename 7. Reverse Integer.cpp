class Solution {
public:
    int reverse(int x) {
        int revnum = 0,rem,num = x;

        while(num!=0)
        {
            rem = num%10;
            num=num/10;
            if (revnum > INT_MAX/10 || revnum==INT_MAX/10 &&  rem>7) return 0;
            if (revnum <INT_MIN/10 || revnum ==INT_MIN/10 && rem<-8) return 0;
            revnum = revnum*10 + rem;
            
        }
     return revnum;}
};