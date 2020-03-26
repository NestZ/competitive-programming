#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;cin >> t;
	while(t--){
		int n;cin >> n;
		string s;cin >> s;
		vector<char> a(n, '0');
		vector<char> b(n, '0');
		a[0] = '1';
		b[0] = '1';
		bool flag = false;
		for(int i = 1;i < n;i++){
			if(s[i] == '2'){
				if(flag){
					a[i] = '0';
					b[i] = '2';
				}
				else{
					a[i] = '1';
					b[i] = '1';
				}
			}
			else if(s[i] == '1'){
				if(!flag){
					a[i] = '1';
					b[i] = '0';
				}
				else{
					a[i] = '0';
					b[i] = '1';
				}
				flag = true;
			}
		}
		cout << string(a.begin(), a.end()) << endl;
		cout << string(b.begin(), b.end()) << endl;
	}
}
