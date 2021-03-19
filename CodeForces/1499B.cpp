#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long int ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;cin >> t;
	while(t--){
		string s;cin >> s;
		int n = s.length();
		int cur0 = 0;
		int cur1 = 0;
		int mx0 = 0;
		int mx1 = 0;
		bool valid = true;
		for(int i = 0;i < n;i++){
			if(s[i] == '1'){
				cur1++;
				mx0 = max(cur0, mx0);
				cur0 = 0;
			}
			else if(s[i] == '0'){
				cur0++;
				if(cur0 >= 2 && mx1 >= 2)valid = false;
				mx1 = max(cur1, mx1);
				cur1 = 0;
			}
		}
		if(valid)cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
