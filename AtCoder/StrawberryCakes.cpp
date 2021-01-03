#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, k;cin >> h >> w >> k;
	vector<vector<char>> arr(h, vector<char>(w));
	vector<vector<int>> ans(h, vector<int>(w));
	vector<bool> have(h, false);
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cin >> arr[i][j];
			if(arr[i][j] == '#')have[i] = true;
		}
	}
	int cnt = 0;
	for(int i = 0;i < h;i++){
		if(!have[i])continue;
		cnt++;
		bool seen = false;
		for(int j = 0;j < w;j++){
			if(arr[i][j] == '#'){
				if(seen)cnt++;
				else seen = true;
			}
			ans[i][j] = cnt;
		}
	}
	vector<int> last(w, 0);
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			if(ans[i][j] == 0 && last[j] != 0)
				ans[i][j] = last[j];
			last[j] = ans[i][j];
		}
	}
	last = vector<int>(w, 0);
	for(int i = h - 1;i >= 0;i--){
		for(int j = 0;j < w;j++){
			if(ans[i][j] == 0 && last[j] != 0)
				ans[i][j] = last[j];
			last[j] = ans[i][j];
		}
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
}
