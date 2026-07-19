class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26,0);
        for ( int i = 0 ; i < s.length() ; i ++){
            lastIndex[s[i]-'a']=i;
        }

        vector<bool> vis(26,false);
        string ans = "";

        for(int i = 0 ; i < s.length(); i++){
            char c = s[i];
            if(vis[c-'a']){
                continue;
            }

            while (!ans.empty() && ans.back()>c && lastIndex[ans.back()-'a']>i){
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }

            ans.push_back(c);
            vis[c-'a']=true;

        }
        return ans;
    }
};