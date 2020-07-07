public class Solution {
    public int[] ReplaceElements(int[] arr) {
        int maxElement = -1;
        int currElement;
        for(int i = arr.Length - 1; i >= 0; i--) {
        	currElement = arr[i];
        	arr[i] = maxElement;
        	if (currElement > maxElement) maxElement = currElement;
        }
        return arr;
    }
}