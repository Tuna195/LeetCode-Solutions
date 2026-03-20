class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        vector<int> v;
        v.reserve(size);
        for(int i = 0; i < size; i++){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])) v.push_back(stoi(tokens[i]));
            else{
                int right = v.back(); v.pop_back();
                int left = v.back(); v.pop_back();
                string oprt = tokens[i];
                if (oprt == "+") v.push_back(left + right);
                else if (oprt == "-") v.push_back(left - right);
                else if (oprt == "*") v.push_back(left * right);
                else if (oprt == "/") v.push_back(left / right);
            }
        }
        return v.back();
    }
};