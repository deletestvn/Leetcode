// RecursionL
// Time Complexity: O(N/2); Space Complexity: O(N) to keep recursion stack

public class Solution {
    public void ReverseString(char[] s) {
        recursionHelper(s, 0, s.Length - 1);
    }

    public void recursionHelper(char[] s, int left, int right){
    	if(left >= right) return;
    	char tmp = s[left];
    	s[left++] = s[right];
    	s[right--] = tmp;
    	recursionHelper(s, left, right);
    }
}