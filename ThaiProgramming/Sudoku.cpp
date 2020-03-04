#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int start[10][10];
	vector<int> ans;
	for(int i = 0;i < 9;i++)
		for(int j = 0;j < 9;j++)
			cin >> start[i][j];
	for(int i = 0;i < n;i++){
		int curr[10][10];
		bool flag = true;
		for(int j = 0;j < 9;j++){
			for(int k = 0;k < 9;k++){
				cin >> curr[j][k];
				if(start[j][k] != 0 && (curr[j][k] != start[j][k]))flag = false;
				if(curr[j][k] == 0 || curr[j][k] > 9)flag = false;
			}
		}
		if(!flag)continue;
		set<int> s[9];
		set<int> col[9];
		for(int j = 0;j < 9;j++){
			set<int> row[9];
			for(int k = 0;k < 9;k++){
				s[(j / 3) * 3 + k / 3].insert(curr[j][k]);
				row[j].insert(curr[j][k]);
				col[k].insert(curr[j][k]);
			}
			if(row[j].size() != 9)flag = false;
		}
		for(int j = 0;j < 9;j++){
			if(s[j].size() != 9 || col[j].size() != 9)flag = false;
		}
		if(!flag)continue;
		ans.push_back(i + 1);
	}		
	for(int i : ans)cout << i << endl;
	cout << "END";
}
