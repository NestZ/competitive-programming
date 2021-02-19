#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;cin >> n;
	int e = n;
	int o = n;
	int last = -1;
	int cnt = 0;
	for(int i = 0;i < n * 2;i++){
		int a;cin >> a;
		if(a & 1){
			if(last == 1)cnt++;
			else{
				last = 1;
				cnt = 1;
			}
			if(cnt >= 3)e -= 3;
			else e--;
		}
		else{
			if(last == 0)cnt++;
			else{
				last = 0;
				cnt = 1;
			}
			if(cnt >= 3)o -= 3;
			else o--;
		}
		if(e <= 0){
			cout << 1 << endl << a << endl;
			return 0;
		}
		if(o <= 0){
			cout << 0 << endl << a << endl;
			return 0;
		}
	}
}
