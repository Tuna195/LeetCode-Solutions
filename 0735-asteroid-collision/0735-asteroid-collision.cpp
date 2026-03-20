class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int size = asteroids.size();
        vector<int> v;
        v.reserve(size);
        for(int i = 0; i < size; i++){
            if(asteroids[i] > 0) v.push_back(asteroids[i]);
            else{
                while(!v.empty() && v.back() > 0){
                    if(abs(asteroids[i]) == v.back()){
                        v.pop_back();
                        asteroids[i] = 0;
                        break;
                    }
                    else if(abs(asteroids[i]) > v.back()) v.pop_back();
                    else break;
                }
                if((v.empty() || (!v.empty() && v.back() < 0)) && asteroids[i]) v.push_back(asteroids[i]);         
            }
        }
        return v;
    }
};