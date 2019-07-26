/*
 * Created by liyechen
 * Time 2019/07/26 17:58
 * Email <gliyechen@hotmail.com>
 */

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> tmp;
		dfs(nums,0,tmp,nums.size());
		return res;
	}

private:
	vector<vector<int>> res;
	void dfs(vector<int> nums,int cur,vector<int> tmp,int nums_size)
	{
		if(cur == nums_size)
		{
			res.push_back(tmp);
			return;
		}
        unordered_set<int> iterNums;
		for(int i = 0; i< nums.size();i++)
		{
			//make
			int tmp_num = nums[i];
            if (iterNums.find(tmp_num) == iterNums.end()) {
                tmp.push_back(tmp_num);
                nums.erase(nums.begin()+i);
                //backtracking
                dfs(nums,cur+1,tmp,nums_size);

                //unmake
                tmp.pop_back();
                nums.insert(nums.begin()+i,tmp_num);
                iterNums.insert(tmp_num);
            }

		}
	}
};
