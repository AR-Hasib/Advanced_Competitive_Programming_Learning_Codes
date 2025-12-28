/* https://leetcode.com/problems/maximum-population-year/ */

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>population(101, 0);
        for(auto it:logs){
            population[it[0]-1950]++;
            population[it[1]-1950]--;
        }

        int ans=0, mx=population[0];
        for(int i=1; i<=100; i++){
            population[i]+=population[i-1];
            if(population[i]>mx){
                mx=population[i];
                ans=i;
            }
        }
        return ans+1950;
    }
};

