class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

     int l=1;
     int r=*max_element(piles.begin(),piles.end());
     int ans=r,k;

     while(l<=r)
     {
        k=(r-l)/2 +l;
        long long time=0;
        for(auto p:piles)
        {
            time+=ceil(static_cast<double>(p)/k);
        }
        if(time<=h)
        {
            ans=k;
            r=k-1;
        }
        else
        {
            l=k+1;
        }
       }   
    return ans;
    }
};