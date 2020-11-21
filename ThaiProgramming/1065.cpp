#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

typedef struct rect {
	int x1, x2, y1, y2;
}rect;

bool overlap(rect &r1, rect &r2){
	int top = min(r1.x2, r2.x2) - max(r1.x1, r2.x1);
	int side = min(r1.y1, r2.y1) - max(r1.y2, r2.y2);
	if(top <= 0 || side <= 0)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;cin >> n >> m;
	vector<rect> arr;
	for(int i = 0;i < n;i++){
		rect rec;
		cin >> rec.x1 >> rec.y1 >> rec.x2 >> rec.y2;
		arr.push_back(rec);
	}
	for(int i = 0;i < m;i++){
		int ans = 0;
		rect rec;
		cin >> rec.x1 >> rec.y1 >> rec.x2 >> rec.y2;
		for(int j = 0;j < n;j++){
			if(overlap(arr[j], rec))ans++;
		}
		cout << ans << endl;
	}
}
