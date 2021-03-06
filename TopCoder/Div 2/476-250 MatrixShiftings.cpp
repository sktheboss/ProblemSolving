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

#define fo(i,n) for(int i=0; i<n; i++)
#define foo(i,m,n) for(int i=m; i<n; i++)
#define foe(i,m,n) for(int i=m; i<=n; i++)
#define be(n) n.begin(),n.end()
#define rbe(n) n.rbegin(),n.rend()
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
using namespace std;

int min(int x, size_t t) {
	return min(x, (int) t);
}

int calc(int r, int c, vector<string>& m) {
	int res = r + c;
	res = min(res, c + m.size() - r);
	res = min(res, m[0].size() - c + r);
	res = min(res, m.size() - r + m[0].size() - c);
	return res;
}

class MatrixShiftings {
public:
	int minimumShifts(vector<string> m, int v) {
		int r = -1, c = -1, res = 1e9;
		fo(i,m.size()) {
			int pos = 0;
			while (1) {
				pos = m[i].find(v + '0', pos);
				if (pos == -1)
					break;
				r = i, c = pos;
				res = min(res, calc(r, c, m));
				pos++;
			}

		}
		return (res == 1e9) ? -1 : res;

	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector<string> p0, int p1, bool hasAnswer,
		int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	MatrixShiftings *obj;
	int answer;
	obj = new MatrixShiftings();
	clock_t startTime = clock();
	answer = obj->minimumShifts(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
			<< " seconds" << endl;
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

	vector<string> p0;
	int p1;
	int p2;

	{
		// ----- test 0 -----
		string t0[] = { "136", "427", "568", "309" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 2;
		p2 = 2;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "0000", "0000", "0099" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 9;
		p2 = 2;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "0123456789" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 7;
		p2 = 3;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = { "555", "555" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		p2 = -1;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		string t0[] = { "12417727123", "65125691886", "55524912622",
				"12261288888" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 9;
		p2 = 6;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
