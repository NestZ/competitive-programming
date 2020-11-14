#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int mxN = 1005;
vector<vector<bool>> arr(mxN, vector<bool>(mxN, false));

bool valid(int cur_x, int cur_y){
	if(cur_x < 0 || cur_y < 0 || cur_x >= mxN || cur_y >= mxN)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	for(int i = 0;i < n;i++){
		int col, row;cin >> col >> row;
		arr[row][col] = true;
	}
	for(int i = 0;i < m;i++){
		int col, row, r;cin >> col >> row >> r;
		int start_col = col - r;
		int start_row = row - r;
		int end_col = col + r;
		int end_row = row + r;
		int cnt = 0;
		for(int j = start_row;j <= end_row;j++){
			for(int k = start_col;k <= end_col;k++){
				if(!valid(j, k))continue;
				if(arr[j][k]){
					cnt++;	
					arr[j][k] = false;
				}
			}
		}
		cout << cnt << endl;
	}
}
