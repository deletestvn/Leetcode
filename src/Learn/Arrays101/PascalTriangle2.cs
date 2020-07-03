public class Solution {
    public IList<int> GetRow(int rowIndex) {
        List<int> result = new List<int>();
        return helper(rowIndex + 1, result);
    }

    public List<int> helper(int n, List<int> result) {
    	if(result.Count == n) return result;
    	else if(result.Count <= 1) {
    		result.Add(1);
    	}
    	else{
    		result.Add(1);
    		for(int i = result.Count - 2; i >= 1; i--)
    			result[i] = result[i] + result[i - 1];
    	}
    	return helper(n, result);
    }
}