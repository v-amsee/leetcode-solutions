//Gray Code
class Solution {
public:
    int minimumOneBitOperations(int n) {
         long long ans = 0;
    while (n) {
        ans ^= n;
        n >>= 1;
    }
    return ans;
    }
};

//Math Solution

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)
            return 0;
        int k=1;
        while((k<<1)<=n)
        {
            k=k<<1;
        }
        return (k<<1)-1 - minimumOneBitOperations(k^n);
    }
};
