#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		bool p = false;
		bool m = false;
		vector<int> a(n);
		vector<int> b(n);
		bool flag = 1;
		for(int i = 0;i < n;i++)cin >> a[i];
		for(int i = 0;i < n;i++){
			int num;cin >> num;
			if(a[i] < num && !p)flag = false;
			if(a[i] > num && !m)flag = false;
			if(a[i] < 0)m = true;
			else if(a[i] > 0)p = true;
		}
		if(flag)cout << "YES\n";
		else cout << "NO\n";
	}
}
