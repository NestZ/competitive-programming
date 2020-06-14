#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<vector<char>> arr(n, vector<char>(m));
	int srow = -1;
	int scol = INT_MAX;
	int erow = 0;
	int ecol = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
			if(arr[i][j] == '*'){
				if(srow == -1)srow = i;
				scol = min(scol, j);
				erow = max(erow, i);
				ecol = max(ecol, j);
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(i < srow || i > erow)continue;
		for(int j = 0;j < m;j++){
			if(j < scol || j > ecol)continue;
			cout << arr[i][j];
		}
		cout << endl;
	}
}
