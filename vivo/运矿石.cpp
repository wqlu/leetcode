#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 101

int dp[10005];

int solution(int n, int weight[]) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += weight[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = sum / 2; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j-weight[i]] + weight[i]);
        }
    }
    return sum - dp[sum/2]*2;
}

int main()
{    
	string str("");
	getline(cin, str);
	int a[MAX_NUM];
	int i = 0;
	char *p;
	int count = 0;
	
	const char* strs = str.c_str();
	p = strtok((char *)strs, " ");
	while(p)
	{
		a[i] = atoi(p);
		count++;
		p = strtok(NULL, " ");
		i++;
		if(i >= MAX_NUM)
			break;
	}
	
	int result = solution(count, a);
	cout << result << endl;
	return 0;
}
