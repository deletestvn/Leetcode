public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
    	int maxResult = 0;
    	int currResult = 0;
        foreach(int num in nums){
        	if(num == 1){
        		currResult++;
        		maxResult = Math.Max(maxResult, currResult);
        	}
        	else{
        		maxResult = Math.Max(maxResult, currResult);
        		currResult = 0;
        	}
        	
        }
        return maxResult;
    }
}