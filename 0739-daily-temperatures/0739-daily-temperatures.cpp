class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st; // {index}
        int size = temperatures.size();
        vector<int> ans(size, 0);
        for(int i = 0; i < size; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            while(temperatures[st.top()] < temperatures[i]){
                int top_value = temperatures[st.top()];
                ans[st.top()] = i - st.top();
                st.pop();
                if(st.empty()) break;
            }
            st.push(i);
        }
        return ans;
    }
};