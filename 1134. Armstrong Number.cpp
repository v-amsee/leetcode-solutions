class Solution {
public:
    bool isArmstrong(int n) {
    int num=n,count=0,sum=0,rem;

    while(num!=0)
    {num=num/10;count++;}
    num=n;
    while(num!=0)
    {
        rem=num%10;
		num=num/10;
        sum+=pow(rem,count);
    }
    if(sum==n) return true;
    else return false;    
     }
};