class Solution {
public:
    bool check(char a, char b){
        if(islower(a) && isupper(b)){
            if(tolower(a) == tolower(b)) return false;
        }
        else if(isupper(a) && islower(b)){
            if(tolower(a) == tolower(b)) return false;
        }
        return true;
    }
    string makeGood(string s) {
        stack<char> st;
        int size = s.length();
        st.push(s[0]);
        for(int i = 1; i < size; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            char top = st.top();
            if(!check(top, s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            char c = st.top(); st.pop();
            ans += c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};