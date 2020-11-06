/*
ID: nestz
LANG: C++14
TASK: holstein
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("holstein.out", "w", stdout);
	freopen("holstein.in", "r", stdin);
	
	int n;cin >> n;
	//store wanted vitamin
	vector<int> want(n);
	for(int i = 0;i < n;i++)cin >> want[i];
	int scp_cnt;cin >> scp_cnt;
	//store vitamin info
	vector<vector<int>> arr(scp_cnt, vector<int>(n));
	for(int i = 0;i < scp_cnt;i++)
		for(int j = 0;j < n;j++)
			cin >> arr[i][j];
	//store minumun scoop require
	int mn_scp = INT_MAX;
	//store ans scoop list
	vector<vector<int>> possible;
	//try every possible combination
	for(int i = 1;i < (1 << scp_cnt);i++){
		vector<int> cur_choose;
		vector<int> cur_vitamin(n, 0);
		//store all choosen scoop
		for(int choose = 0;choose < scp_cnt;choose++){
			if(i & (1 << choose)){
				cur_choose.push_back(choose);
			}
		}
		//cal recieved vitamin
		int choose_cnt = cur_choose.size();
		for(int j = 0;j < choose_cnt;j++){
			vector<int> choosen = arr[cur_choose[j]];
			for(int k = 0;k < n;k++){
				cur_vitamin[k] += choosen[k];
			}
		}
		//check if vitamin is sufficient
		int suf_cnt = 0;
		for(int j = 0;j < n;j++){
			if(cur_vitamin[j] >= want[j])suf_cnt++;
		}
		if(suf_cnt == n){
			possible.push_back(cur_choose);
			mn_scp = min(mn_scp, (int)cur_choose.size());
		}
	}
	int smallest_feed = INT_MAX;
	int pos_cnt = possible.size();
	vector<int> ans;
	for(int i = 0;i < pos_cnt;i++){
		vector<int> cur_pos = possible[i];
		if(cur_pos.size() == mn_scp){
			if(cur_pos[0] < smallest_feed){
				ans = cur_pos;
				smallest_feed = cur_pos[0];
			}
		}
	}
	cout << ans.size() << ' ';
	for(int i = 0;i < ans.size();i++){
		cout << ans[i] + 1;
		if(i != ans.size() - 1)cout << ' ';
	}
	cout << endl;
}
