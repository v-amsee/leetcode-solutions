class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    
    int n=nums.size(),count=0,start=0;
    k=k%n;
    while(count < n)
    {
        int prev=nums[start],temp,curr=start;
        
        do{
            int next = (curr +k)%n;
            temp=nums[next];
            nums[next]=prev;
            prev=temp;
            curr=next;
            count++;
        }while(curr!=start);
        start++;
    }
    }

};