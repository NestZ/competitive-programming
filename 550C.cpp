#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	string s;cin >> s;
	int n = s.length();
	for(int i = 0;i < n;i++){
		if((s[i] - '0') % 8 == 0){
			cout << "YES" << endl << s[i];
			return 0;
		}
	}
	for(int i = 0;i < n - 1;i++){
		for(int j = i + 1;j < n;j++){
			int num = (s[i] - '0') * 10 + (s[j] - '0');
			if(num % 8 == 0){
				cout << "YES" << endl << num;
				return 0;
			}
		}
	}
	for(int i = 0;i < n - 2;i++){
		for(int j = i + 1;j < n - 1;j++){
			for(int k = j + 1;k < n;k++){
				int num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
				if(num % 8 == 0){
					cout << "YES" << endl << num;
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
