public class Solution {
    public bool ValidMountainArray(int[] A) {
        int N = A.Length;
        int i = 0;
        // walk up
        while(i + 1 < N && A[i] < A[i + 1]) i++;

        // edge case: peak cannot be first or last element
        if(i == 0 || i == N - 1) return false;

        // walk down
        while(i + 1 < N && A[i] > A[i + 1]) i++;

        return i == N - 1;
    }
}