class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return arr;

        int maxElement = -1;
        int currElement;

        for(int i = n - 1; i >= 0; i--) {
        	currElement = arr[i];
        	arr[i] = maxElement;
        	if(currElement > maxElement) maxElement = currElement;
        }

        return arr;
    }
};