#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	vector<int> v(260, 0);
	for(int i = 0;i < n;i++){
		int l, h, r;cin >> l >> h >> r;
		for(int j = l;j < r;j++){
			v[j] = max(v[j], h);
		}
	}
	int last = 0;
	for(int i = 1;i < 260;i++){
		if(v[i] != last){
			cout << i << " " << v[i] << " ";
			last = v[i];
		}
	}
}
