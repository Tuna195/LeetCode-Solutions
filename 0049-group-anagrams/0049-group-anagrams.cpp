class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> uo_mp;
        vector<vector<string>> ans;
        for(string s : strs){
            string ss = s;
            sort(s.begin(), s.end());
            if(uo_mp.find(s) == uo_mp.end()){
                uo_mp[s] = {ss};
            }
            else{
                uo_mp[s].push_back(ss);
            }
        }
        for(auto it = uo_mp.begin(); it != uo_mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};