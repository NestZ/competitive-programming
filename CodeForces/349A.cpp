#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	int a = 0, b = 0;
	while(n--){
		int t;cin >> t;
		if(t == 25)a++;
		else if(t == 50){
			if(a > 0){
				a--;
				b++;
			}
			else return cout << "NO", 0;
		}
		else{
			if(b > 0 && a > 0){
				b--;
				a--;
			}
			else if(b == 0 && a > 2){
				a -= 3;
			}
			else return cout << "NO", 0;
		}
	}
	cout << "YES";
}
