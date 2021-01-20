#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	bool odd = false;
	for(int i = 0;i < n;i++){
		int t;cin >> t;
		if(t & 1)odd = true;
	}
	if(odd)cout << "first";
	else cout << "second";
	cout << endl;
}
