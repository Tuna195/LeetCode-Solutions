class Solution {
public:
    bool checkCloseChar(char c){
        if(c == '}' || c == ']' || c == ')') return true;
        return false;
    }
    bool checkValid(char a, char b){
        if(a == '(' && b == ')') return true;
        if(a == '[' && b == ']') return true;
        if(a == '{' && b == '}') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        if(s[0] == ')' || s[0] == '}' || s[0] == ']'){
            return false;
        }
        st.push(s[0]);
        int k = 1;
        while(k < s.size()){
            st.push(s[k]);
            k++;
            if(checkCloseChar(st.top()) && st.size() > 1){
                char b = st.top(); st.pop();
                char a = st.top(); st.pop();
                if(!checkValid(a, b)) return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};