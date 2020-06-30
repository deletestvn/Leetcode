class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3 || A[1] < A[0]) return false;

        bool foundPeak = false;
        int i = 0;
        while(!foundPeak && i < n - 1){
        	if(A[i] < A[i + 1]) i++;
        	else if(A[i] == A[i + 1]) return false;
        	else{
        		foundPeak = true;
        		break;
        	}
        }

        while(foundPeak && i < n - 1){
        	if(A[i] <= A[i + 1]) return false;
        	else i++;
        }

        return foundPeak;
    }
};