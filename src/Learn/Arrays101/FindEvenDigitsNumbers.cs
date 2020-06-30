public class Solution {
    public int FindNumbers(int[] nums) {
    	int count = 0;
        foreach(int num in nums){
        	count += hasEvenDigits(num);
        }
        return count;
    }

    private int hasEvenDigits(int num){
    	int digits = 0;
    	while(num != 0){
    		digits++;
    		num /= 10;
    	}
		return digits % 2 == 0 ? 1 : 0;
    }
}