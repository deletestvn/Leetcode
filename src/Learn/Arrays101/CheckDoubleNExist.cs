public class Solution {
    public bool CheckIfExist(int[] arr) {
        HashSet<int> lookup = new HashSet<int>();
        foreach(int num in arr){
        	if((num % 2 == 0 && lookup.Contains(num / 2)) || lookup.Contains(2 * num)) return true;
        	else lookup.Add(num);
        }
        return false;
    }
}