// TC: 447-D2-1		Points= 194.94 of 250
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

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

class ImportantTasks {
public:
	int maximalCost(vector<int> complexity, vector<int> computers) {
		int lim = 1000000;
		int max = -1, index = -1;
		int count = 0;
		for (int i = 0; i < computers.size(); i++) {

			for (int j = 0; j < complexity.size(); j++) {
				if (computers[i] >= complexity[j]) {
					if (max < complexity[j]) {
						max = complexity[j];
						index = j;
					}

				}
			}

			if (max > -1) {
				count++;
				max = -1;

				computers[i] = lim;
				complexity[index] = lim;
			}

		}

		return count;

	}

	// BEGIN CUT HERE
	void __test() {
		// END CUT HERE

		// BEGIN CUT HERE
		static bool s_FirstTime = true;
		if (s_FirstTime) {
			s_FirstTime = false;
			run_test(-1);
		}
		// END CUT HERE

		// BEGIN CUT HERE
	}
	// END CUT HERE

	// BEGIN CUT HERE
public:
	void run_test(int Case) {
		if ((Case == -1) || (Case == 0))
			test_case_0();
		if ((Case == -1) || (Case == 1))
			test_case_1();
		if ((Case == -1) || (Case == 2))
			test_case_2();
		if ((Case == -1) || (Case == 3))
			test_case_3();
		if ((Case == -1) || (Case == 4))
			test_case_4();
	}
private:
	template<typename T> string print_array(const vector<T> &V) {
		ostringstream os;
		os << "{ ";
		for (typename vector<T>::const_iterator iter = V.begin(); iter
				!= V.end(); ++iter)
			os << '\"' << *iter << "\",";
		os << " }";
		return os.str();
	}
	void verify_case(int Case, const int &Expected, const int &Received) {
		cerr << "Test Case #" << Case << "...";
		if (Expected == Received)
			cerr << "PASSED" << endl;
		else {
			cerr << "FAILED" << endl;
			cerr << "\tExpected: \"" << Expected << '\"' << endl;
			cerr << "\tReceived: \"" << Received << '\"' << endl;
		}
	}
	void test_case_0() {
		int Arr0[] = { 1, 2, 3 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arr1[] = { 2, 2, 2 };
		vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 2;
		verify_case(0, Arg2, maximalCost(Arg0, Arg1));
	}
	void test_case_1() {
		int Arr0[] = { 1, 2, 3 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arr1[] = { 3 };
		vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 1;
		verify_case(1, Arg2, maximalCost(Arg0, Arg1));
	}
	void test_case_2() {
		int Arr0[] = { 3, 5, 1, 7 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arr1[] = { 9, 4, 1, 1, 1 };
		vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 3;
		verify_case(2, Arg2, maximalCost(Arg0, Arg1));
	}
	void test_case_3() {
		int Arr0[] = { 5, 2, 7, 8, 6, 4, 2, 10, 2, 3 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arr1[] = { 4, 1, 3, 6, 2, 10, 11, 1, 1, 3, 4, 2 };
		vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 8;
		verify_case(3, Arg2, maximalCost(Arg0, Arg1));
	}
	void test_case_4() {
		int Arr0[] = { 100 };
		vector<int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0])));
		int Arr1[] = { 100, 100 };
		vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 1;
		verify_case(4, Arg2, maximalCost(Arg0, Arg1));
	}

	// END CUT HERE

};
// BEGIN CUT HERE
int main() {
	ImportantTasks c;
	c.__test();
	return 0;
}
// END CUT HERE
