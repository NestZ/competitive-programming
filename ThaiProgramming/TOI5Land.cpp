#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;
int n, m;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int cur_i, int cur_j){
	if(cur_i < 0 || cur_j < 0 || cur_i >= n || cur_j >= m)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	double ans = 0;
	vector<vector<double>> arr(n, vector<double>(m));
	vector<int> perm(n * m);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> arr[i][j];
	for(int i = 0;i < n * m;i++)perm[i] = i;
	do{
		double sum = 0;
		vector<vector<double>> cur(n, vector<double>(m));
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				cur[i][j] = arr[i][j];
		for(int i = 0;i < n * m;i++){
			int buy = perm[i];
			int r = buy / m;
			int c = buy % m;
			double diff = cur[r][c] * 0.1;
			sum += cur[r][c];
			for(int j = 0;j < 8;j++){
				if(valid(r + x[j], c + y[j]))
					cur[r + x[j]][c + y[j]] += diff;
			}
		}
		if(ans == 0)ans = sum;
		else ans = min(ans, sum);
	}
	while(next_permutation(perm.begin(), perm.end()));
	printf("%.2lf\n", ans);
}
