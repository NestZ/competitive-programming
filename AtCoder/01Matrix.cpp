#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int h, w, a, b;
	cin >> h >> w >> a >> b;
	for(int i = 1;i <= h - b;i++){
		for(int j = 1;j <= w;j++){
			if(j <= a)cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	for(int i = 1;i <= b;i++){
		for(int j = 1;j <= w;j++){
			if(j <= a)cout << 0;
			else cout << 1;
		}
		cout << endl;
	}
}
