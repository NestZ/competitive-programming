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
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int cnt = 0;
			for(int k = 0;k < 4;k++){
				int c = j + dx[k];
				int r = i + dy[k];
				if(c >= n || c < 0 || r >= n || r < 0)continue;
				if(arr[r][c] == 'o')cnt++;
			}
			if(cnt & 1)return cout << "NO", 0;
		}
	}
	cout << "YES";
}
