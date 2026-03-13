class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for(int c : candies){
            if(c > max) max = c;
        }
        int n = candies.size();
        vector<bool> result(n);
        for(int i = 0; i < n; i++){
            if(candies[i] + extraCandies >= max) result[i] = true;
            else result[i] = false;
        }
        return result;
    }

};