class Solution {
public:
    int reverseBits(int n) {
        int revnum;
        for(int i=0;i<32;i++)
        {
            int bit =1 & n>>i;
            revnum+= bit<<(31-i);
        }

        return revnum;
    }
};