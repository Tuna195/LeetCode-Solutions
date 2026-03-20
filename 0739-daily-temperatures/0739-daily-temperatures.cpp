class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>st; // {index, value}
        int size = temperatures.size();
        vector<int> ans(size, 0);
        for(int i = 0; i < size; i++){
            if(st.empty()){
                st.push({i, temperatures[i]});
                continue;
            }
            while(st.top().second < temperatures[i]){
                int top_value = st.top().second;
                int top_index = st.top().first;
                ans[top_index] = i - top_index;
                st.pop();
                if(st.empty()) break;
            }
            st.push({i, temperatures[i]});
        }
        return ans;
    }
};