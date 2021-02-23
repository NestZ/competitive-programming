#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mod 1000001
int hashtable[1000001];
int val[100010];
int main(){
		ios::sync_with_stdio(0);
		cin.tie(nullptr);
    int k, m;
		cin>>k>>m;
    memset(hashtable, -1, sizeof(hashtable));
    memset(val, 0, sizeof(val));
    for(int i = 0; i < k; ++i){
            string s;
						cin>>s;
            int num = 0;
            for(int j = 0; j  < m; ++j){
                    num = (num<<1)+(s[j] - '0');
            }
            int hx = num%mod;
            while(hashtable[hx] != -1){
                    hx++;
                    hx%=mod;
            }
            hashtable[hx] = i;
            val[i] = num;
    }
    int t;
		cin>>t;
    bool chk[k+1];
    memset(chk,0,sizeof(chk));
    int work = 0;
    while(t--){
        int l;
        string s;
				cin>>l>>s;
        if(l < m){
						cout<<"OK"<<endl;
            continue;
        }
        int num = 0;
        for(int i = l - m ; i < l; ++i){
            num = (num<<1)+(s[i] - '0');
        }
        for(int i = l - m; i >= 0; --i){
                if(l-m-1 >= i){
                    num += (1<<(m-1))*(s[i] -'0');
                }
                int hx = num%mod;
                while(hashtable[hx] != -1){
                    int j = hashtable[hx];
                    if(val[j] == num){
                        chk[j] = 1;
                        work = 1;
                        break;
                    }
                    hx++;
                    hx%=mod;
                }
                num = (num>>1);
        }
        if(!work){
						cout<<"OK";
        }
        else{
                for(int i = 0; i < k; ++i){
                    if(chk[i]){
												cout<<i+1<<" ";
                        chk[i] = 0;
                    }
                }
                work = 0;
        }
				cout<<'\n';
    }
    return 0;
}
