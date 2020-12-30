int singleNumber(const vector<int> &A) {
    int n = A.size();
    int ones = 0, twos = 0, threes = 0;
    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }
    return ones;
}

// Approach 2
class Solution {
public:
    int singleNumber(const vector<int> &A) {
            int n = A.size();
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }
};

/// Approach 3
int Solution::singleNumber(const vector<int> &A) {
    int seen_once = 0, seen_twice = 0;
    for (int num: A) {
        seen_once = ~seen_twice & (seen_once ^ num);
        seen_twice = ~seen_once & (seen_twice ^ num);
    }
    return seen_once;
}