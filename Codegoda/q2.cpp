#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int Y = 9999, M = 12, D = 31;
vector<int> ncnt(Y * M * D + Y);

int offset(int y, int m, int d){
  return D * M * y + D * m + d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin >> n;
  for(int i = 0;i < n;i++){
    string start, end;cin >> start >> end;
    int sy = stoi(start.substr(0, 4));
    int sm = stoi(start.substr(5, 2));
    int sd = stoi(start.substr(8, 2));
    int ey = stoi(end.substr(0, 4));
    int em = stoi(end.substr(5, 2));
    int ed = stoi(end.substr(8, 2));
    ncnt[offset(sy, sm, sd)]++;
    ncnt[offset(ey, em, ed)]--;
  }
  int mx = 0, cur = 0;
  int my = 0, mm = 0, md = 0;
  for(int i = 1;i <= Y;i++){
    for(int j = 1;j <= M;j++){
      for(int k = 1;k <= D;k++){
        cur += ncnt[offset(i, j, k)];
        if(cur > mx){
          mx = cur;
          my = i;
          mm = j;
          md = k;
        }
      }
    }
  }
  string ans_y = to_string(my);
  string ans_m = to_string(mm);
  string ans_d = to_string(md);
  while(ans_y.length() < 4)ans_y = "0" + ans_y;
  while(ans_m.length() < 2)ans_m = "0" + ans_m;
  while(ans_d.length() < 2)ans_d = "0" + ans_d;
  cout << ans_y << '-' << ans_m << '-' << ans_d << endl;
}
