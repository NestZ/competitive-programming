#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	for(int i = n + 1;;i++){
		set<int> s;
		int t = i;
		int cnt = 0;
		while(t > 0){
			s.insert(t % 10);
			t /= 10;
			cnt++;
		}
		if(s.size() == cnt)return cout << i, 0; 
	}
}
