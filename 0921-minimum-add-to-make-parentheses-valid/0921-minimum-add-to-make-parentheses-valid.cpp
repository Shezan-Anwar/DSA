class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(st.size()==0){
                st.push(ch);
            }else if(ch == ')' && st.top()=='('){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.size();
    }
};