// Time Complexity: O(n); Space Complexity: O(1)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int possibleDups = 0;
    	int end = arr.size() - 1;
    	
        // Find the number of zeros to be duplicated
        for (int i = 0; i <= end - possibleDups; i++) {
        	if (arr[i] == 0) {
        		// Edge case
        		if (i == end - possibleDups) {
        			arr[end] = 0;
        			end -= 1;
        			break;
        		}
        		possibleDups++;
        	}
        }
        
        end -= possibleDups;

        // Duplicate
        for (int i = end; i >= 0; i--) {
        	if (arr[i] == 0 && possibleDups != 0) {
        		arr[i + possibleDups] = 0;
                possibleDups--;
        		arr[i + possibleDups] = 0;
        	}
        	else {
        		arr[i + possibleDups] = arr[i];
        	}
        }
    }
};