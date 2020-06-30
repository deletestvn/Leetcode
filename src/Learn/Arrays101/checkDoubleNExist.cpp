class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n - 1; i++){
        	for(int j = i + 1; j < n; j++){
        		if(2 * arr[i] == arr[j] || 2 * arr[j] == arr[i]) return true;
        	}
        }
        return false;
    }
};