class Solution {
public:
    string removeDuplicates(string s, int k) {
        int size = s.size();
        vector<pair<char, int>> v; // {value, fre}
        v.reserve(size);
        for(int i = 0; i < size; i++){
            if(v.empty()){
                v.push_back({s[i], 1});
                continue;
            }
            char top = v.back().first;
            if(s[i] == top){
                v.back().second++;
                if(v.back().second == k) v.pop_back();
            }
            else{
                v.push_back({s[i], 1});
            }
        }
        string ans = "";
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].second; j++){
                ans += v[i].first;
            }
        }
        return ans;
    }
};