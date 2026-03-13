class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
	for(const auto &str : strs){
		string s = str;
		sort(s.begin(), s.end());
		mp[s].push_back(str);
	}
	int n = mp.size();
	vector<vector<string>> v(n);
	int i = 0;
	for(const auto &pair : mp){
		v[i] = pair.second;
        i++;
	}
	return v;
    }
};