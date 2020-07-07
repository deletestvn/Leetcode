class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int oddNum;
        for(int i = 0, j = -1; i < n; i++) {
        	if(A[i] % 2 != 0 && j == -1) j = i;
        	if(A[i] % 2 == 0 && j != -1) {
        		oddNum = A[j];
        		A[j++] = A[i];
        		A[i] = oddNum;
        	}
        }
        return A;
    }
};