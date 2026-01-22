class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        int i=0;
        stack<char> st;
        while(i<n){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
            else{
                if(st.empty()) return false;
                else if(s[i]==')' && st.top()=='(') st.pop();
                else if(s[i]=='}' && st.top()=='{') st.pop();
                else if(s[i]==']' && st.top()=='[') st.pop();
                else return false;
            }
            i++;
        }
        if(!st.empty()) return false;
        return true;
    }
};