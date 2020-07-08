class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
        	int currNum = abs(nums[i]);
        	if (nums[currNum - 1] > 0) nums[currNum - 1] *= -1;
        }

        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] > 0) result.push_back(i + 1);
        }
        return result;
    }
};