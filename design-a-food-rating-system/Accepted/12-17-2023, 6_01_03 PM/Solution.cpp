// https://leetcode.com/problems/design-a-food-rating-system

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> rated;
    unordered_map<string, pair<int, string>> mp; 
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        size_t n = foods.size();
        for(size_t i{};i<n;i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            mp[food] = {-rating, cuisine};
            rated[cuisine].insert({-rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = mp[food].second;
        int inverseRating = mp[food].first;
        rated[cuisine].erase({inverseRating, food});
        rated[cuisine].insert({-newRating, food});
        mp[food] = {-newRating, cuisine};

        
    }
    
    string highestRated(string cuisine) {
        return rated[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */