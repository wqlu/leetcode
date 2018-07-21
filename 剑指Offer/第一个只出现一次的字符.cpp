class Solution {
  public:
    int FirstNotRepeatingChar(string str) {
            map<char, int> char_map;
            for (int i = 0; i < str.size(); i++) {
                        char_map[str[i]] ++;
                    }
            for (int i = 0; i < str.size(); i++) {
                        if (char_map[str[i]] == 1)
                            return i;
                    }
            return -1;
        }
};
