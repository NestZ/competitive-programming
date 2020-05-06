#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int T = (1 << 17);
vector<int> tree(2 * T, 0);
int n, m;

void add(int i, int num){
	i += (1 << n);
	tree[i] = num;
	i >>= 1;
	int cnt = 1;
	while(i){
		if(cnt & 1)tree[i] = tree[i * 2] | tree[i * 2 + 1];
		else tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
		i >>= 1;
		cnt++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 0;i < (1 << n);i++){
		int t;cin >> t;
		add(i, t);
	}
	for(int i = 0;i < m;i++){
		int a, b;cin >> a >> b;
		add(a - 1, b);
		cout << tree[1] << endl;
	}
}
