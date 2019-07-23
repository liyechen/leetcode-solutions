class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSumFromIndex(candidates, target, 0);
    }
    
private:
    vector<vector<int>> combinationSumFromIndex(const vector<int>& candidates, int target, int index) {
        vector<vector<int>> combinations;
        if (index == candidates.size()) return combinations;
        for (unsigned int i = index; i < candidates.size(); i++) {
            int candidate = candidates[i];
            if (target - candidate > 0) {
                vector<vector<int>> nextCombinations = combinationSumFromIndex(candidates, target - candidate, i);
                for (const vector<int>& combination: nextCombinations) {
                    vector<int> comb;
                    comb.push_back(candidate);
                    comb.insert(comb.end(), combination.begin(), combination.end());
                    combinations.push_back(comb);
                }
            } else if (target == candidate) {
                vector<int> comb;
                comb.push_back(candidate);
                combinations.push_back(comb);
            }
        }
        return combinations;
    }
};
