#include <bits/stdc++.h>
using namespace std;

typedef struct _node
{
    int num;
    struct _node * next;
}node;

void solution(int N, int M) {

    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= N; ++i) q.push(i);
    while (!q.empty()) {
        for (int i = 1; i < M; ++i) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        int k = q.front();
        ans.push_back(k);
        q.pop();
    }

    for (auto iter : ans) {
        cout << iter << " ";
    }
    cout << endl;
}

int main()
{
	int N;
	int M;
	
	string str("");
	getline(cin, str);
	
	char *p;
	const char* strs = str.c_str();
	
	p = strtok((char *)strs, " ");
	N = atoi(p);

	p = strtok(NULL, " ");
	M = atoi(p);
	
	solution(N, M);
	
	return 0;
}
