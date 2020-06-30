public class Solution {
    public int[] SortedSquares(int[] A) {
    	int n = A.Length;
        int[] squares = new int[n];

        for(int i = 0; i < n; i++){
        	squares[i] = A[i] * A[i];
        }

        return Array.Sort(squares);
    }
}