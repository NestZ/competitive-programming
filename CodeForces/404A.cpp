#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	set<char> s;
	int cnt = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> arr[i][j];
			s.insert(arr[i][j]);
			if(arr[i][j] == arr[0][0])cnt++;
		}
	}
	for(int i = 0;i < n;i++){
		if(arr[i][i] != arr[0][0] || arr[i][n - i - 1] != arr[0][0])return cout << "NO", 0;
	}
	if(cnt != n * 2 - 1 || s.size() > 2)cout << "NO";
	else cout << "YES";
}
