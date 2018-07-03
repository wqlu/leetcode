class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return IsBST(sequence, 0, sequence.size()-1);
    }

    bool IsBST(vector<int>& sequence, int begin, int end) {
        if (begin >= end)
            return true;
        int temp = end;
        // find the index of boundary
        while(sequence[temp-1] > sequence[end]) {
            temp --;
        }
        // check the left sequence
        for (int i = 0; i < temp; ++i) {
            if (sequence[i] > sequence[end])
                return false;
        }
        return IsBST(sequence, begin, temp-1) && IsBST(sequence, temp, end-1);
    }
};
