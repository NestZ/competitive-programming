#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	multiset<int> s;
	for(int i = 0;i < 3;i++){
		multiset<int> ns;
		for(int j = 0;j < n - i;j++){
			int t;cin >> t;
			if(i == 0)s.insert(t);
			else{
				ns.insert(t);
				s.erase(s.find(t));
			}
		}
		if(i != 0){
			cout << *s.begin() << endl;
			s = ns;
		}
	}
}
