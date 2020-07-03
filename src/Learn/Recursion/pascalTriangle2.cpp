class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> result;
    	return recursionHelper(result, rowIndex + 1);
    }

    vector<int> mathHelper(int n) {
    	vector<int> result(n, 1);
    	for(int k = 1; k <= (n - 1) / 2; k++) {
    		// kth element of nth row is: n!/(k!*(n-k)!)
    		result[k] = (long)result[k - 1] * (long)(n - k) / k;
    		result[n - k - 1] = result[k];
    	}
    	return result;
    }

    vector<int> iterationHelper(int n) {
    	vector<int> result;
    	for(int i = 0; i < n; i++) {
    		result.push_back(1);
    		for(int j = i - 1; j >= 1; j--)
    			result[j] = result[j] + result[j - 1];
    	}
    	return result;
    }

    vector<int> recursionHelper(vector<int> result, int n) {
    	if(result.size() == n) return result;
    	else if(result.size() <= 1) {
    		result.push_back(1);
    	}
    	else{
    		result.push_back(1);
    		for(int i = result.size() - 2; i >= 1; i--)
    			result[i] = result[i] + result[i - 1];
    	}
    	return recursionHelper(result, n);
    } 
};