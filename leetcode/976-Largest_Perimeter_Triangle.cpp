class Solution {
public:
    int largestPerimeter(vector<int> &A) {
        if (A.size() < 3) return 0;
        int ans = 0;
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; --i) {
            if (isTriangle(A, i)) {
                ans = A[i] + A[i - 1] + A[i - 2];
                break;
            }
        }
        return ans;
    }

    bool isTriangle(vector<int> &A, int index) {
        return (A[index] + A[index - 1] > A[index - 2]) &&
            (A[index - 1] + A[index - 2] > A[index]) &&
            (A[index - 2] + A[index] > A[index - 1]);
    }
};