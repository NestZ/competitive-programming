#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	bool flag = true;
	for(int i = 0;i < n;i++){
		for(int j = 1;j < m;j++){
			if(arr[i][j] != arr[i][j - 1])flag = false;
		}
	}
	for(int i = 1;i < n;i++)
		if(arr[i][0] == arr[i - 1][0])flag = false;
	if(flag)cout << "YES";
	else cout << "NO";
}
