#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;cin >> n;
	map<int, int> ma;
	for(int i = 0;i < n;i++){
		int num;cin >> num;
		ma[num]++;
	}
	int m;cin >> m;
	for(int i = 0;i < m;i++){
		int num;cin >> num;
		ma[num]--;
		if(ma[num] < 0)return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;
}
