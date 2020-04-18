#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n, m;cin >> n >> m;
	vector<bool> row(n, true);
	vector<bool> col(m, true);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			char c;cin >> c;
			if(c == 'S'){
				row[i] = false;
				col[j] = false;
			}
		}
	}
	int r = 0;
	int c = 0;
	for(bool i : row)if(i)r++;
	for(bool i : col)if(i)c++;
	cout << (r * m) - (c * r) + (c * n);
}
