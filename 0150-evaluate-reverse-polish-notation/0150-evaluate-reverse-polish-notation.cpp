class Solution {
public:
    int calculate(int x, int y, string oprt){
        if(oprt == "+") return x + y;
        else if(oprt == "-") return y - x;
        else if(oprt == "*") return y * x;
        else return y / x;
    }
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        vector<int> v;
        v.reserve(size);
        for(int i = 0; i < size; i++){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])) v.push_back(stoi(tokens[i]));
            else{
                int a = v.back(); v.pop_back();
                int b = v.back(); v.pop_back();
                int c = calculate(a, b, tokens[i]);
                v.push_back(c);
            }
        }
        return v[0];
    }
};