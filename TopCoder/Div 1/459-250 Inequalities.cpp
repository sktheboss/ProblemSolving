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
#define find(v,x) (find(all((v)),(x))-(v).begin())
typedef long long ll;
using namespace std;

bool cmp(pii a, pii b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

class Inequalities {
public:


    int maximumSubset(vector <string> inequalities) {
        vector<pii> sm,gr;
        sm.push_back(mp(1000000,1));
        gr.push_back(mp(-1000000,1));
        vi eq;
        rep(i,sz(inequalities)){
            string op;
            char s[5]={0};
            int num;
            sscanf(inequalities[i].c_str(), "X %s %d", s,&num);
            op = s;
            if(op[0] == '>')
                gr.push_back(mp(num, op == ">="));
            else if(op[0] == '<')
                sm.push_back(mp(num, op == "<="));
            else
                eq.push_back(num);

        }
        sort(all(sm));
        sort(all(gr),cmp);
        sort(all(eq));
        int res=0;
        for (int i = sz(gr)-1; i >= 0; --i) {
            int idx = lower_bound(all(sm), gr[i]) - sm.begin();
            here:
            if(idx == sz(sm))
                continue;
            if(sm[idx].first == gr[i].first){
                if(!sm[idx].second  || !gr[i].second){
                    ++idx;
                    goto here;
                }
            }
            int tmp = i + 1 + (sz(sm) - idx);
            rep(j,sz(eq)){
                bool bgr=0,bsm=0;
                if(gr[i].second && eq[j]>= gr[i].first)
                    bgr=1;
                else if(gr[i].second==0 && eq[j]> gr[i].first)
                    bgr=1;
                if(sm[idx].second && eq[j] <= sm[idx].first)
                    bsm=1;
                else if(sm[idx].second==0 && eq[j] < sm[idx].first)
                    bsm=1;
                if(bgr && bsm){
                    ++tmp;
                    break;
                }
            }

            res = max(res, tmp-2 );

        }
        return res;

    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    Inequalities *obj;
    int answer;
    obj = new Inequalities();
    clock_t startTime = clock();
    answer = obj->maximumSubset(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p1;
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
    int p1;

    {
        // ----- test 0 -----
        string t0[] = {"X = 3", "X > 1", "X < 5", "X <= 0", "X > 5", "X = 9", "X <= 6", "X >= 5", "X < 8", "X < 4", "X >= 4", "X <= 1", "X <= 8", "X < 9", "X = 7", "X > 3", "X <= 3", "X > 2", "X <= 7", "X <= 9", "X >= 6", "X >= 0", "X <= 2", "X = 1", "X < 2", "X <= 4", "X < 0", "X > 4", "X <= 5", "X = 4", "X > 0", "X = 5", "X < 7", "X = 0", "X >= 7", "X < 6", "X > 9", "X > 8", "X = 6", "X > 7", "X > 6", "X = 8", "X >= 1", "X >= 3", "X >= 8", "X < 3", "X < 1", "X = 2", "X >= 2", "X >= 9"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 21;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 0 -----
        string t0[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 3;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        string t0[] = {"X < 0","X <= 0"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        string t0[] = {"X = 1","X = 2","X = 3","X > 0"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 2;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        string t0[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 5;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
