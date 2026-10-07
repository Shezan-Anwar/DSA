class Solution {
public:
    bool isValid(string s){
        int bal = 0 ;
        for(char ch : s){
            if(ch=='('){
                bal++;
            }else if (ch==')'){
                bal --;
                if(bal<0) return false;
            }
        }
        return bal==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < curr.length(); ++i) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string nextState = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(nextState) == visited.end()) {
                    visited.insert(nextState);
                    q.push(nextState);
                }
            }
        }

        return result;
    }
};