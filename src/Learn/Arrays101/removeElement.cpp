class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0;
        for(auto num : nums)
            if(num != val) length++;
        int i = 0, j = 0;
        while(i < length){
            if(nums[i + j] == val) j++;
            else{
                nums[i] = nums[i + j];
                i++;
            }
        }
        return length;
    }
};