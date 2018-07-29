class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> vector1{1};
        int max = vector1[0];
        int index_2 = 0;
        int index_3 = 0;
        int index_5 = 0;
        while (vector1.size() < index) {
            int mut_2 = vector1[index_2]*2;
            int mut_3 = vector1[index_3]*3;
            int mut_5 = vector1[index_5]*5;
            if (mut_2 <= mut_3 && mut_2 <= mut_5) {
                index_2 ++;
                max = mut_2;
            }
            if (mut_3 <= mut_2 && mut_3 <= mut_5) {
                index_3 ++;
                max = mut_3;
            }
            if (mut_5 <= mut_2 && mut_5 <= mut_3) {
                index_5 ++;
                max = mut_5;
            }
            vector1.push_back(max);
        }
        return vector1[index-1];
    }
};


