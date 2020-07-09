class Solution {
public:
	unordered_map<int,int> steps;
    int climbStairs(int n) {
        if(steps.count(n) == 1) return steps.at(n);

        int step;

        if(n <= 2) step = n;
        else step = climbStairs(n - 1) + climbStairs(n - 2);

        steps.insert(pair<int,int>(n, step));
        return step;
    }
};