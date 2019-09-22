#include <bits/stdc++.h>

using namespace std;

/**
 * Welcome to vivo !
 */
 
int solution(int a[], int N)
{
    if (N == 1) return 0;
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= a[i]; ++j) {
            if (i+j < N)
                dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    if (dp[N-1] == INT_MAX) return -1;
    return dp[N-1];
}

int main()
{
	string str("");
	getline(cin, str);
	int a[2000];
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
		if(i >= 2000)
			break;
	}

	int num = solution(a, count);
	cout << num << endl;
	return 0;
}
