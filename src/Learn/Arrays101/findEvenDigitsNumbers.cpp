class Solution {
public:
    int findNumbers(vector<int>& nums) {
		int count = 0;
		for(auto num : nums){
			count += hasEvenDigits(num);
		}   
		return count;
    }

    int hasEvenDigits(int num) { 
    	int count = 0;
    	while(num) {
    		num /= 10;
    		count++;
    	}
    	return count % 2 == 0 ? 1 : 0;
    }
};