#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;cin >> t;
	while(t--){
		int n, a, b;cin >> n >> a >> b;
		vector<int> arra(a);
		vector<int> arrb(b);
		for(int i = 0;i < a;i++)cin >> arra[i];
		for(int i = 0;i < b;i++)cin >> arrb[i];
		int mxa = *max_element(arra.begin(), arra.end());
		int mxb = *max_element(arrb.begin(), arrb.end());
		if(mxa > mxb)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
