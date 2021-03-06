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


class ChickenOracle {
public:
	bool check(int n, int tru, int lie, int liar){
		int mn = min(lie,liar);
		foe(y,0,mn){
			int a = lie-y;
			int b = liar-y;
			int c = n-a-b-y;

			if(c+y==tru && a+b==n-tru && c>=0)
				return 1;
		}
		return 0;
	}
	string theTruth(int n, int eggCount, int lieCount, int liarCount) {
		bool egg = check(n,eggCount,lieCount, liarCount);
		bool chic = check(n,n-eggCount, lieCount, liarCount);
		
		if(egg && chic)
			return "Ambiguous";
		else if(egg)
			return "The egg";
		else if(chic)
			return "The chicken";
		else
			return "The oracle is a lie";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	ChickenOracle *obj;
	string answer;
	obj = new ChickenOracle();
	clock_t startTime = clock();
	answer = obj->theTruth(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	string p4;
	
	{
	// ----- test 0 -----
	p0 = 10;
	p1 = 10;
	p2 = 0;
	p3 = 0;
	p4 = "The egg";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 60;
	p1 = 40;
	p2 = 0;
	p3 = 30;
	p4 = "The oracle is a lie";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 60;
	p1 = 20;
	p2 = 5;
	p3 = 25;
	p4 = "The chicken";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1000;
	p1 = 500;
	p2 = 250;
	p3 = 250;
	p4 = "Ambiguous";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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
