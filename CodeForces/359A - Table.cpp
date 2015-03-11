#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,a,b,d) for(int i=a; i<=b; i+=d)
#define repd(i,a,b,d) for(int i=a; i>=b; i-=d)
#define repi(it,stl) for(auto it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream
#define indexof(v,x) (find(all((v)),(x))-(v).begin())

typedef long long ll;
using namespace std;

bool g[52][52];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("main.txt","rt",stdin);
    //  freopen("out.txt","wt",stdout);
#endif

    int n,m;
    cin >> n >> m;
    rep(i,n) rep(j,m) cin >> g[i][j];
    if(g[0][0] || g[0][m-1] || g[n-1][0] || g[n-1][m-1]){
        cout << 1;
        return 0;
    }
    rep(i,n) if(g[i][0] || g[i][m-1]){cout << 2; return 0;}
    rep(j,m) if(g[0][j] || g[n-1][j]){cout << 2; return 0;}
    cout << 4;
    return 0;
}
