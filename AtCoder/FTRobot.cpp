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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;cin >> s;
  int x, y;cin >> x >> y;
  int n = s.length();
  bool cur_x = true;
  vector<int> ax;
  vector<int> ay;
  int cnt = 0;
  for(int i = 0;i < n;i++){
    if(s[i] == 'T'){
      if(cnt){
        if(cur_x)ax.push_back(cnt);
        else ay.push_back(cnt);
      }
      cur_x = !cur_x;
      cnt = 0;
    }
    else cnt++;
  }
  if(cnt){
    if(cur_x)ax.push_back(cnt);
    else ay.push_back(cnt);
  }
  if(s[0] == 'F'){
    x -= ax[0];
    ax.erase(ax.begin());
  }
  vector<vector<bool>> dpx(8010, vector<bool>(8010, false));
  vector<vector<bool>> dpy(8010, vector<bool>(8010, false));
  dpx[0][0] = dpy[0][0] = true;
  for(int i = 0;i < (int)ax.size();i++){
    for(int j = 0;j <= 8000;j++){
      if(!dpx[i][j])continue;
      dpx[i + 1][j + ax[i]] = true;
      dpx[i + 1][abs(j - ax[i])] = true;
    }
  }
  for(int i = 0;i < (int)ay.size();i++){
    for(int j = 0;j <= 8000;j++){
      if(!dpy[i][j])continue;
      dpy[i + 1][j + ay[i]] = true;
      dpy[i + 1][abs(j - ay[i])] = true;
    }
  }
  if(dpx[ax.size()][abs(x)] && dpy[ay.size()][abs(y)])cout << "Yes";
  else cout << "No";
  cout << endl;
}
