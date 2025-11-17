class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n<=2) return 1;
        int thirdlast=0,seclast=1,last=1,ans;
        for(int i=3;i<=n;i++)
        {
            ans=thirdlast + seclast + last;
            thirdlast=seclast;
            seclast=last;
            last=ans;
        }
        return ans;
    }
};