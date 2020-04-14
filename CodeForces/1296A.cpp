#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		int odd = 0;
		int even = 0;
		for(int i = 0;i < n;i++){
			int k;cin >> k;
			if(k & 1)odd++;
			else even++;
		}
		if(even == n || (odd == n && !(odd & 1)))cout << "NO";
		else cout << "YES";
		cout << endl;
	}
}
