public class Solution {
    public int[] SortArrayByParity(int[] A) {
        int n = A.Length;
        int j = -1;
        for(int i = 0; i < n; i++) {
        	if(A[i] % 2 != 0 & j == -1) j = i;
        	else if(A[i] % 2 == 0 & j != -1) {
        		int currOdd = A[j];
        		A[j] = A[i];
        		A[i] = currOdd;
        		j++;
        	}
        }
        return A;
    }
}