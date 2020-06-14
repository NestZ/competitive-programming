#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 3;
	vector<vector<char>> arr(n, vector<char>(n));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	bool flag = true;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(arr[i][j] == 'X' && arr[n - i - 1][n - j - 1] != 'X')flag = false;
		}
	}
	if(flag)cout << "YES";
	else cout << "NO";
}
