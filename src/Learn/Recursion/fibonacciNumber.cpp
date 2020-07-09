class Solution {
public:
	unordered_map<int,int> fibs;
    int fib(int N) {
        if(fibs.count(N) == 1) return fibs.at(N);

        int result;

        if(N <= 1) result = N;
        else result = fib(N - 1) + fib(N - 2);

        fibs.insert(pair<int,int>(N, result));
        return result;
    }
};