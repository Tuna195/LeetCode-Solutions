class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size, 0);
        vector<int>st; // {index}
        st.reserve(size);

        for(int i = 0; i < size; i++){
            
            while(!st.empty() && temperatures[st.back()] < temperatures[i]){
               ans[st.back()] = i - st.back();
               st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};