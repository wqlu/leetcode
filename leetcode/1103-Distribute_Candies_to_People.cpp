class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int candie = 1, index = 1;
        int total = candies;
        while (total > candie) {
            index = (candie - 1) % num_people;
            ans[index] += candie;
            total -= candie;
            candie++;
        }
        index = (candie - 1) % num_people;
        ans[index] += total;

        return ans;
    }
};
