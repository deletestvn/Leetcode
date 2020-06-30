class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0;
        int currNum;
        for(auto num : nums){
        	if(num == currNum) continue;
        	else{
        		currNum = num;
        		nums[length++] = currNum;
        	}
        }
        return length;
    }
};