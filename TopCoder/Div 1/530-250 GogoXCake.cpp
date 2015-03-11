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
#define itr(A,B) typeof(B) A = B

typedef long long ll;
using namespace std;


class GogoXCake {
public:
    string solve(vector <string> cake, vector <string> cutter) {
        int col;
        rep(i,sz(cutter[0]))
                if(cutter[0][i]=='.'){
            col = i;
            break;
        }

        rep(i,sz(cake))
                rep(j,sz(cake[i])){
            if(cake[i][j] == 'X') continue;

            if(col > j || sz(cutter[0])-col > sz(cake[i])-j) return "NO";
            if(i+sz(cutter) > sz(cake)) return "NO";
            int sti = i, stj = j-col;
            rep(ii,sz(cutter))
                    rep(jj,sz(cutter[ii])){
                if(cutter[ii][jj]=='X') continue;
                if(cake[sti+ii][stj+jj] == 'X' && cutter[ii][jj]=='.') return "NO";
                cake[sti+ii][stj+jj] = 'X';
            }


        }

        return "YES";


    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	GogoXCake *obj;
	string answer;
	obj = new GogoXCake();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	vector <string> p0;
	vector <string> p1;
	string p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"X.X","...","...","X.X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".X","..","X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"..XX","...X","X...","XX.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..",".."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...X..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".X.","X.X",".X."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"XXXXXXX","X.....X","X.....X","X.....X","XXXXXXX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".X.","XXX",".X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"..","X.",".X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..",".X","X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"X..",".XX",".XX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".XX",".XX","X.."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	string t0[] = {"..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................",".............................................."
			"....","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","........................................"
			"..........","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................","..................................................",".................................................."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................","............"
			".....................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................","........................."
			"........................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................",".................................................","................................................."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(7, p0, p1, true, p2) && all_right;
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