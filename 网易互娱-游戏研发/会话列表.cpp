  
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    vector<int> find_index(vector<int> session) {
        vector<int> ans;
        for (int i = session.size()-1; i >=0 ; i--) {
            if (!isIn(session[i], ans)){
                ans.push_back(session[i]);
            }
        }
        return ans;
    }
    bool isIn(const int &temp, vector<int> &vector1 ) {
        for (int i = 0;i < vector1.size(); i++) {
            if (temp == vector1[i])
                return true;
        }
        return false;
    }
};


int main() {
    int test_num;
    vector<vector<int> > ans;
    cin >> test_num;
    Solution solution;
    for (int i = 0; i < test_num; i++) {
        vector<int> temp;
        int vct_num, data;
        cin >> vct_num;
        for (int i = 0; i < vct_num; i++) {
            cin >> data;
            temp.push_back(data);
        }
        ans.push_back(solution.find_index(temp));
    }

    for (int i = 0; i < test_num; i++) {
        for (int j = 0; j < ans[i].size()-1; j++) {
             cout << ans[i][j] << " ";
        }
        cout << ans[i][ans[i].size()-1] << endl;
    }
    return 0;
}
