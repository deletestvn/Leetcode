class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
    	int N = A.size();
        vector<int> squares(N, 0);
        for(int i = 0; i < N; i++){
        	squares[i] = A[i] * A[i];
        }
        sort(squares.begin(), squares.end());
        return squares;
    }
};