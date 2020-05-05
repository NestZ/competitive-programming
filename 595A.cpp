#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	int ans = 0;
	vector<vector<int>> arr(n, vector<int>(2 * m));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 2 * m;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 2 * m;j+=2){
			if(arr[i][j] == 0 && arr[i][j + 1] == 0)ans++;
		}
	}
	cout << n * m - ans;
}
