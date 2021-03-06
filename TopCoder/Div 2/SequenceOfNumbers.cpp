#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#define fo(i,n) for(int i=0;i<(n);++i)
#define foo(i,m,n) for(int i=(m);i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;

class SequenceOfNumbers {
public:
vector <string> rearrange(vector <string> sequence)
{

	vs res(sequence.size());
	vi ii(sequence.size());
	fo(i,sequence.size()){
		stringstream ss(sequence[i]);
		ss>>ii[i];
	}

	sort(ii.begin(),ii.end());

	fo(i,sequence.size()){
		stringstream ss;
		ss<<ii[i];
		ss>>res[i];
	}
	return res;
}



// BEGIN CUT HERE
void __test()
{
// END CUT HERE

// BEGIN CUT HERE
		static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
// END CUT HERE

// BEGIN CUT HERE
}
// END CUT HERE

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1","174","23","578","71","9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1", "9", "23", "71", "174", "578" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, rearrange(Arg0)); }
	void test_case_1() { string Arr0[] = {"172","172","172","23","23"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"23", "23", "172", "172", "172" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, rearrange(Arg0)); }
	void test_case_2() { string Arr0[] = {"183","2","357","38","446","46","628","734","741","838"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2", "38", "46", "183", "357", "446", "628", "734", "741", "838" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, rearrange(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
SequenceOfNumbers c;
c.__test();
return 0;
}
// END CUT HERE
