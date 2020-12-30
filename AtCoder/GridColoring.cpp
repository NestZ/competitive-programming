#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h, w;cin >> h >> w;
	int n;cin >> n;
	vector<vector<int>> arr(h, vector<int>(w));
	vector<int> cnt(n);
	for(int i = 0;i < n;i++)cin >> cnt[i];
	bool r = true;
	int ptr = 0;
	for(int i = 0;i < h;i++){
		if(r){
			for(int j = 0;j < w;j++){
				arr[i][j] = ptr + 1;
				cnt[ptr]--;
				if(cnt[ptr] == 0)ptr++;
			}
		}
		else{
			for(int j = w - 1;j >= 0;j--){
				arr[i][j] = ptr + 1;
				cnt[ptr]--;
				if(cnt[ptr] == 0)ptr++;
			}
		}
		r = !r;
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
