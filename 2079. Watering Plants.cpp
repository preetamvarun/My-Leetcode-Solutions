class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, i = 0, maxCapacity = capacity;
        while(i < plants.size()){
            if(capacity >= plants[i]){
                capacity -= plants[i];
                i++;
                steps++;
            }
            else if(capacity < plants[i]){
                capacity = maxCapacity;
                steps += i * 2 + 1;
                capacity -= plants[i];
                i++;
            }
        }
        return steps;
    }
};
