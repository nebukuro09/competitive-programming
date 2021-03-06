#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP2(i,m,n) for (int i=m;i<(n);i++)
typedef long long ll;

int deg[1010];
int pr[1010];

class MakingRegularGraph {
    public:
    vector<int> addEdges(int n, vector<int> x, vector<int> y) {
        REP(i, n) deg[i] = 0;
        REP(i, n) pr[i] = i;
        int m = x.size();

        REP(i, m) {
            if (deg[x[i]] >= 2 || deg[y[i]] >= 2)
                return vector<int>{-1};
            if (pr[x[i]] == y[i] && pr[y[i]] == x[i] && (m != n || i != m-1))
                return vector<int>{-1};
            deg[x[i]] += 1;
            deg[y[i]] += 1;
            int old_prx = pr[x[i]];
            int old_pry = pr[y[i]];
            pr[old_prx] = old_pry;
            pr[old_pry] = old_prx;
        }


        vector<bool> used = vector<bool>(n);
        priority_queue<pair<int, int> > pq;
        REP(i, n) if (deg[i] < 2 && !used[i]) {
            pq.push(make_pair(-i, -pr[i]));
            used[i] = used[pr[i]] = true;
        }

        vector<int> ans;

        while (!pq.empty()) {
            if (pq.size() == 1) {
                ans.push_back(-pq.top().first);
                ans.push_back(-pq.top().second);
                break;
            }
            pair<int, int> p1 = pq.top();
            pq.pop();
            pair<int, int> p2 = pq.top();
            pq.pop();
            int u = -p1.first;
            int v = -p2.first;
            int uu = -p1.second;
            int vv = -p2.second;
            ans.push_back(u);
            ans.push_back(v);
            if (uu > vv) swap(uu, vv);
            pq.push(make_pair(-uu, -vv));
        }

        return ans;
    }
};

// CUT begin
ifstream data("MakingRegularGraph.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(int n, vector<int> x, vector<int> y, vector<int> __expected) {
    time_t startClock = clock();
    MakingRegularGraph *instance = new MakingRegularGraph();
    vector<int> __result = instance->addEdges(n, x, y);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int n;
        from_stream(n);
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, x, y, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1527955882;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "MakingRegularGraph (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
