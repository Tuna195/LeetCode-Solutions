class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int current_sub = 0;
        int max_sub = 0;
        int length = s.length();
        int char_arr[127] = {0};
        for(int i = 0; i < length; i++){
            if(char_arr[(int) s[i]] == 0) {
                current_sub++;
                char_arr[(int) s[i]]++;
            }
            else{
                for(int k = i - current_sub; k < i; k++){
                    if(s[k] == s[i]){
                        current_sub = i - k;
                        break;
                    }
                    else{
                        char_arr[(int)s[k]] = 0;
                    }
                }
            }
            if(max_sub < current_sub) max_sub = current_sub;
        }
        return max_sub;
    }
};