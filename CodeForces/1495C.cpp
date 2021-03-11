#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		int n, m;cin >> n >> m;
		vector<vector<char>> arr(n, vector<char>(m));
		vector<vector<char>> ans(n, vector<char>(m, '.'));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cin >> arr[i][j];
				if(arr[i][j] == 'X')
					ans[i][j] = 'X';
			}
		}
		for(int i = 1;i < m;i += 3)
			for(int j = 0;j < n;j++)
				ans[j][i] = 'X';
		for(int j = 2;j < m - 1;j += 3){
			bool filled = false;
			if(j + 2 == m && m % 3 == 1)break;
			for(int i = 0;i < n;i++){
				if(arr[i][j + 1] == 'X' && arr[i][j] == 'X')
					filled = true;
			}
			if(filled)continue;
			for(int i = 0;i < n;i++){
				if(arr[i][j + 1] == 'X' || arr[i][j] == 'X'){
					ans[i][j + 1] = ans[i][j] = 'X';
					filled = true;
					break;
				}
			}
			if(!filled)ans[0][j] = ans[0][j + 1] = 'X';
		}
		if(m % 3 == 1){
			if(m == 1){
				for(int i = 0;i < n;i++){
					ans[i][0] = 'X';
				}
			}
			else{
				for(int i = 0;i < n;i++){
					if(arr[i][m - 1] == 'X')
						ans[i][m - 2] = 'X';
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
}
