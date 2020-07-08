class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        if(n <= 1) return 0;

        vector<int> sortedHeights (n, 0);
        int i = 0, j = 0;

        for(auto height : heights) {
        	sortedHeights[i++] = height;
        }

        sort(sortedHeights.begin(), sortedHeights.end());

        i = 0;
        for(auto height : heights) {
        	if(sortedHeights[i++] != height) j++;
        }

        return j;
    }
};