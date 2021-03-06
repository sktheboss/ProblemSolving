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
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define vi vector<int>
#define vs vector<string>
#define sstr stringstream 
#define fnd(v,x) (find(all((v)),(x))!=(v).end())
typedef long long ll;
using namespace std;


class SentenceDecomposition {
public:
	vs words;
	string str;

	bool isvalid(int pos, int idx){
		if(sz(str)-pos < sz(words[idx])) return 0;
		set<char> s;
		int vis[300]={0},vis2[300]={0};
		reps(i,pos,pos+sz(words[idx]))
			vis[str[i]]++, s.insert(str[i]);
			rep(j,sz(words[idx]))
				vis2[words[idx][j]]++, s.insert(words[idx][j]);
		repi(it, s)
			if(vis[*it] != vis2[*it]) return 0;
		return 1;
	}

	int calc(int pos, int idx){
		int res=0;
		rep(i,sz(words[idx]))
			if(str[pos+i]!=words[idx][i])++res;
		return res;
	}
	int memo[52];
	int DP(int pos){
		if(pos == sz(str)) return 0;
		int& m = memo[pos];
		if(m != -1) return m;

		m = 1<<27;
		rep(i,sz(words)){
			if(isvalid(pos,i))
				m = min(m,DP(pos+sz(words[i])) + calc(pos,i));
		}
		return m;
	}
	int decompose(string sentence, vector <string> validWords) {
		words = validWords;
		str = sentence;
		mem(memo,-1);
		return DP(0)>= 1<<27?-1:DP(0);

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SentenceDecomposition *obj;
	int answer;
	obj = new SentenceDecomposition();
	clock_t startTime = clock();
	answer = obj->decompose(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	vector <string> p1;
	int p2;
	
	{
		// ----- test 0 -----
		p0 = "noonnonnmnnomoonnmooonmnmnnommnomoomommooonommonn";
		string t1[] = {"mmo", "omon", "mmno", "non", "ono", "nono", "n", "mon", "nomn", "ooonomomnmnmmmnmononmoonomnonnoonoonmonnnmonommon", "mnn", "omom", "moo", "nonn", "oono", "ooo"};
				p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 12;
		all_right = KawigiEdit_RunTest(10, p0, p1, true, p2) && all_right;
		// ------------------
		}

	{
	// ----- test 0 -----
	p0 = "neotowheret";
	string t1[] = {"one","two","three","there"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 8;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "abba";
	string t1[] = {"ab","ac","ad"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "thisismeaningless";
	string t1[] = {"this","is","meaningful"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "ommwreehisymkiml";
	string t1[] = {"we","were","here","my","is","mom","here","si","milk","where","si"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "ogodtsneeencs";
	string t1[] = {"go","good","do","sentences","tense","scen"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 8;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "sepawaterords";
	string t1[] = {"separate","words"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
