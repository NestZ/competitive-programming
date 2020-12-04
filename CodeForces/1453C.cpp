#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		vector<vector<char>> arr(n, vector<char>(n));
		vector<int> max_row(10, 0);
		vector<int> min_row(10, INT_MAX);
		vector<int> max_col(10, 0);
		vector<int> min_col(10, INT_MAX);
		vector<int> ans(10);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				cin >> arr[i][j];
				int num = arr[i][j] - '0';
				max_row[num] = max(i, max_row[num]);
				min_row[num] = min(i, min_row[num]);
				max_col[num] = max(j, max_col[num]);
				min_col[num] = min(j, min_col[num]);
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int num = arr[i][j] - '0';
				ans[num] = max({ans[num],
						(max(j, n - j - 1) * max(max_row[num] - i, i - min_row[num])),
						(max(i, n - i - 1) * max(max_col[num] - j, j - min_col[num]))});
			}
		}
		for(int i = 0;i < 10;i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}
