class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans = combinationSumFromIndex(candidates, target, 0);
        return ans;
    }
    
private:
    vector<vector<int>> combinationSumFromIndex(const vector<int>& candidates, int target, int index) {
        vector<vector<int>> combinations;
        if (index == candidates.size()) return combinations;
        for (unsigned int i = index; i < candidates.size(); i++) {
            if (i != index && candidates[i] == candidates[i - 1]) continue;
            int candidate = candidates[i];
            if (target - candidate > 0) {
                vector<vector<int>> nextCombinations = combinationSumFromIndex(candidates, target - candidate, i + 1);
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
