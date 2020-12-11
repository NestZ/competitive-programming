#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, s;cin >> n >> k >> s;
	for(int i = 0;i < n;i++){
		if(i < k)
			cout << s << ' ';
		else{
			if(s + 1 <= 1e9)
				cout << s + 1;
			else cout << s - 1;
			cout << ' ';
		}
	}
	cout << endl;
}
