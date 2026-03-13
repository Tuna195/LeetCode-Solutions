class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(char c : s) result = result ^ c;
        for(char c : t) result = result ^ c;
        return result;
    }
};