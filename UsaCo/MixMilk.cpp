/*
ID: nestz
LANG: C++14
TASK: mixmilk
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("mixmilk.out", "w", stdout);
	freopen("mixmilk.in", "r", stdin);

	int s1, c1, s2, c2, s3, c3;
	cin >> s1 >> c1 >> s2 >> c2 >> s3 >> c3;
	for(int i = 0;i < 100;i++){
		if(i % 3 == 0){
			int mn = min(c1, s2 - c2);
			c1 -= mn;
			c2 += mn;
		}
		else if(i % 3 == 1){
			int mn = min(c2, s3 - c3);
			c2 -= mn;
			c3 += mn;
		}
		else{
			int mn = min(c3, s1 - c1);
			c3 -= mn;
			c1 += mn;
		}
	}
	cout << c1 << endl << c2 << endl << c3 << endl;
}
