class Solution {
public:
    int minimumPushes(string word) {
        vector<char> mem;
        int push = 0;
        for(char ch : word){
            
            push += mem.size()/8 +1;
            mem.push_back(ch);
        }
        return push;
    }
};