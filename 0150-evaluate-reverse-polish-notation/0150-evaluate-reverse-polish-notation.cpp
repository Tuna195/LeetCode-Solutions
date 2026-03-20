class Solution {
public:
    int calculate(string a, string b, string oprt){
        int x = stoi(a);
        int y = stoi(b);
        if(oprt == "+") return x + y;
        else if(oprt == "-") return y - x;
        else if(oprt == "*") return y * x;
        else return y / x;
    }
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        vector<string> v;
        v.reserve(size);
        for(int i = 0; i < size; i++){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])) v.push_back(tokens[i]);
            else{
                string a = v.back(); v.pop_back();
                string b = v.back(); v.pop_back();
                int c = calculate(a, b, tokens[i]);
                v.push_back(to_string(c));
            }
        }
        return stoi(v[0]);
    }
};