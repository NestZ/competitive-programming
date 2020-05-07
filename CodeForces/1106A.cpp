#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	int ans = 0;
	for(int i = 1;i < n - 1;i++)
		for(int j = 1;j < n - 1;j++){
			if(arr[i][j] == 'X' && arr[i + 1][j + 1] == 'X'
				&& arr[i - 1][j - 1] == 'X' && arr[i + 1][j - 1] == 'X'
				&& arr[i - 1][j + 1] == 'X')
				ans++;
		}
	cout << ans;
}
