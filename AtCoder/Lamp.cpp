#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w;cin >> h >> w;
	vector<vector<char>> arr(h, vector<char>(w));
	vector<vector<int>> up(h, vector<int>(w));
	vector<vector<int>> down(h, vector<int>(w));
	vector<vector<int>> left(h, vector<int>(w));
	vector<vector<int>> right(h, vector<int>(w));
	for(int i = 0;i < h;i++)
		for(int j = 0;j < w;j++)
			cin >> arr[i][j];
	for(int i = 0;i < h;i++){
		int cur = 0;
		for(int j = 0;j < w;j++){
			left[i][j] = cur;
			if(arr[i][j] == '.')cur++;
			else cur = 0;
		}
		cur = 0;
		for(int j = w - 1;j >= 0;j--){
			right[i][j] = cur;
			if(arr[i][j] == '.')cur++;
			else cur = 0;
		}
	}
	for(int i = 0;i < w;i++){
		int cur = 0;
		for(int j = 0;j < h;j++){
			up[j][i] = cur;
			if(arr[j][i] == '.')cur++;
			else cur = 0;
		}
		cur = 0;
		for(int j = h - 1;j >= 0;j--){
			down[j][i] = cur;
			if(arr[j][i] == '.')cur++;
			else cur = 0;
		}
	}
	int ans = 0;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(arr[i][j] == '#')continue;
			ans = max(ans, up[i][j] + left[i][j] + down[i][j] + right[i][j] + 1);
		}
	}
	cout << ans << endl;
}
