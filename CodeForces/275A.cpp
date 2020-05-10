#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<bool>> arr(3, vector<bool>(3, true));
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			int t;cin >> t;
			if(t & 1 ^ 1)continue;
			arr[i][j] = !arr[i][j];
			for(int k = 0;k < 4;k++){
				int r = i + dy[k];
				int c = j + dx[k];
				if(r < 0 || r > 2 || c < 0 || c > 2)continue;
				arr[r][c] = !arr[r][c];
			}
		}
	}
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(arr[i][j])cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
}
