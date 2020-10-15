#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int w, h, n;cin >> w >> h >> n;
	vector<int> v(w, 0);
	for(int i = 0;i < n;i++){
		int x, a;cin >> x >> a;
		for(int j = x;j < x + a;j++){
			v[j]++;
		}
	}
	int none = 0;
	int some = 0;
	int last = -1;
	int curr = 1;
	for(int i = 0;i < w;i++){
		if(last == -1)last = v[i];
		else{
			if(v[i] != last){
				if(last == 0){
					none += curr * h;
				}
				else if(last == 1){
					some += curr * h;
				}
				last = v[i];
				curr = 1;
			}
			else curr++;
		}
	}
	if(last == 0)none += curr * h;
	else if(last == 1)some += curr * h;
	cout << none << " " << some;
}
