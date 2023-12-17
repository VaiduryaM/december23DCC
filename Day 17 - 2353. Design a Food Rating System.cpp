//Day 17 - 2353. Design a Food Rating System

class FoodRatings {
private:
    unordered_map<string, int> itemsToRatingMap;
    unordered_map<string, string> itemsToCuisineMap;
    unordered_map<string, set<pair<int, string>>> cuisineItemMap;

public:
    //what on earth
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            itemsToRatingMap[foods[i]] = ratings[i];
            itemsToCuisineMap[foods[i]] = cuisines[i];
            cuisineItemMap[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {

        auto name = itemsToCuisineMap[food];
        auto old = cuisineItemMap[name].find({-itemsToRatingMap[food], food});
        cuisineItemMap[name].erase(old);

        itemsToRatingMap[food] = newRating;
        cuisineItemMap[name].insert({-newRating, food});
        
    }
    
    string highestRated(string cuisine) {
        auto high = *cuisineItemMap[cuisine].begin();

        return high.second;
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */