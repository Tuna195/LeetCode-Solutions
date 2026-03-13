class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int each_letter_counts[26] = {0};
        for(char c : magazine){
            each_letter_counts[c - 'a']++;
        }
        for(char c: ransomNote){
            if(--each_letter_counts[c - 'a'] < 0) return false;
        }
        return true;
    }
};