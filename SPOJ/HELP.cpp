#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,m,n) for(int i=m; i<n; i++)
#define repe(i,m,n) for(int i=m; i<=n; i++)
#define repi(it,stl) for(typeof((stl).begin()) it = (stl).begin(); (it)!=stl.end(); ++(it))
#define sz(a) ((int)(a).size())
#define mem(a,n) memset((a), (n), sizeof(a))
#define all(n) (n).begin(),(n).end()
#define rall(n) (n).rbegin(),(n).rend()
#define allarr(n) (n), (n)+( (sizeof (n)) / (sizeof (*n)) )
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n;
ull freq[52];
pii childs[52];

ull DFS(int node){
	if(node < 0)
		return 0;

	ull sum = DFS(childs[node].first) + DFS(childs[node].second);
	freq[node] = sum + 1;
	return 2 * sum + 1;
}

int main() {


	while(scanf("%d",&n) && n){

		bool vis[52]={0};
		rep(i,n){
				scanf("%d%d",&childs[i].first,&childs[i].second);
				--childs[i].first, --childs[i].second;
				vis[childs[i].first]=1;
				vis[childs[i].second]=1;
		}
		int root=0;
		rep(i,n)
			if(!vis[i]){
				root=i;
				break;
			}
		DFS(root);

		rep(i,n){
			if(i)
				cout<<" ";
			cout<<freq[i];
		}
		printf("\n");
	}

	return 0;
}
