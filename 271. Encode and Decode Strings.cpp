class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
     string ans;
     for(string &s : strs)
     {
        ans+=to_string(s.size()) +"#" + s;
     } 
     return ans;

    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {

        vector<string> ans;
        int i=0;
        while(i < s.size())
        {
            int j=i;
            while(s[j]!='#')
            {
              j++;
            }
            int strsize=stoi(s.substr(i,j-i));
            i=j+1;
            ans.push_back(s.substr(i,strsize));
            i=i+strsize;

        }
        
    return ans;}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));