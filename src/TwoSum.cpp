// 1. Two Sum
// https://leetcode.com/problems/two-sum/
// Time Complexity: O(n); Space Complexity: O(n)

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

	unordered_map<int, int> candidates;

	for (int i = 0; i < nums.size(); i++) {

		int diff = target - nums[i];

		if (candidates.count(diff)) return { candidates[diff], i };
		
		candidates[nums[i]] = i;
	}

	return {};
}