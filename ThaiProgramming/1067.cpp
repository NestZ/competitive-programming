#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;cin >> m >> n >> k;
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	for(int i = 0;i < k;i++){
		int col, row;cin >> col >> row;
		col--;
		row--;
		char dir = 'N';
		bool flag = true;
		set<pair<int, int>> s;
		s.insert(make_pair(col, row));
		while(true){
			if(arr[row][col] == 1){
				row--;
				dir = 'N';
			}
			else if(arr[row][col] == 2){
				col++;
				dir = 'E';
			}
			else if(arr[row][col] == 3){
				row++;
				dir = 'S';
			}
			else{
				col--;
				dir = 'W';
			}
			if(col < 0 || row < 0 || col >= m || row >= n)break;
			if(s.count(make_pair(col, row)) > 0){
				flag = false;
				break;
			}
			else s.insert(make_pair(col, row));
		}
		if(flag == false)cout << "NO";
		else cout << dir;
		cout << endl;
	}
}
