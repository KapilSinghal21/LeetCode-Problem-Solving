class FoodRatings {
    unordered_map<string,string> foodToCuisine;                 // food -> cuisine
    unordered_map<string,int>    foodToRating;                  // food -> current rating
    unordered_map<string,set<pair<int,string>>> cuisineFoods;    // cuisine -> set of (-rating, name)

public:
    FoodRatings(vector<string>& foods,
                vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]]  = ratings[i];
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string c = foodToCuisine[food];
        int old  = foodToRating[food];
        cuisineFoods[c].erase({-old, food});          // remove old entry
        cuisineFoods[c].insert({-newRating, food});   // insert updated entry
        foodToRating[food] = newRating;
    }

    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second; // best rating, tie-break by name
    }
};
