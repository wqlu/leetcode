//
// Created by lu on 18-8-9.
// Email: wq.lu@outlook.com
//
/* 
 * 测试用例
1
4
1357xxxxxxx Guang
13680xxxxxx Hang
13799xxxxxx Hang
1379999xxxx Su
5
13579246810
13680222222
13799999999
13799252354
12356556666
*/


#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string find_location(string check_phone, map<string, string> &map_phone) {
    map<string, string>::reverse_iterator it;
    for (it = map_phone.rbegin(); it != map_phone.rend(); it++) {
        bool flag = true;
        for (size_t i = 0; i < (*it).first.size(); i++) {
            if ((*it).first[i] == check_phone[i])
                continue;
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            return (*it).second;
        }
    }
    return "unknown";
}

int main() {
    int num_data;
    cin >> num_data;
    map<string, string> map_phone;
    vector<string> ans;
    for (int i = 0; i < num_data; i++) {
        int rules, handle;
        cin >> rules;
        for (int i = 0; i < rules; i++) {
            string phone, subphone, location;
            unsigned long index = 0;
            cin >> phone >> location;
            // 处理phone
            for (size_t j = 0; j < phone.size(); j++) {
                if (phone[j] == 'x') {
                    index = j;
                    break;
                }
            }
            subphone = phone.substr(0, index);
            map_phone.insert(make_pair(subphone, location));
        }
        cin >> handle;
        for (int i =0; i < handle; i++) {
            string check_phone, ans_string;
            cin >> check_phone;
            ans_string = find_location(check_phone,map_phone);
            ans.push_back(ans_string);
        }
    }

    for (const string &i : ans) {
        cout << i << endl;
    }
    return 0;
}
