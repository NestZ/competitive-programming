/*
ID: nestz
LANG: C++14
TASK: transform
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n;

bool check(vector<vector<char>> &a, vector<vector<char>> &b){
	bool res = true;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(a[i][j] != b[i][j])res = false;
		}
	}
	return res;
}

vector<vector<char>> rotate(vector<vector<char>> &a){
	vector<vector<char>> new_arr(n, vector<char>(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			new_arr[j][n - i - 1] = a[i][j];
		}
	}
	return new_arr;
}

vector<vector<char>> reflect(vector<vector<char>> &a){
	vector<vector<char>> new_arr(n, vector<char>(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			new_arr[i][n - j - 1] = a[i][j];
		}
	}
	return new_arr;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("transform.out", "w", stdout);
	freopen("transform.in", "r", stdin);
	
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	vector<vector<char>> res(n, vector<char>(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> res[i][j];
		}
	}
	int ans = INT_MAX;
	vector<vector<char>> curr = rotate(arr);
	for(int i = 0;i < 3;i++){	
		if(check(curr, res))ans = min(i + 1, ans);
		curr = rotate(curr);
	}
	curr = reflect(arr);
	if(check(curr, res))ans = min(ans, 4);
	curr = rotate(curr);
	for(int i = 0;i < 3;i++){
		if(check(curr, res))ans = min(ans, 5);
		curr = rotate(curr);
	}
	if(check(arr, res))ans = min(ans, 6);
	if(ans == INT_MAX)cout << 7;
	else cout << ans;
	cout << endl;
}
