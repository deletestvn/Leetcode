// Time Complexity: O(n); Space Complexity: O(1)
public class Solution {
    public void DuplicateZeros(int[] arr) {
        int possibleDups = 0;
        int end = arr.Length - 1;

        for (int i = 0; i <= end - possibleDups; i++) {
        	if (arr[i] == 0) {
                if (i == end - possibleDups) {
                    arr[end] = 0;
                    end--;
                    break;
                }
                possibleDups++;
            }
        }

        end -= possibleDups;

        for (int i = end; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + possibleDups] = 0;
                possibleDups--;
                arr[i + possibleDups] = 0;
            }
            else {
                arr[i + possibleDups] = arr[i];
            }
        }
    }
}