#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    map<string, int>m;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            string c;
            cin >> c >> b;
            if (m.find(c) == m.end()) {
                m.insert(make_pair(c, b));
            }
            else {
                m[c] += b;
            }
        }
        else if (a == 2) {
            string c;
            cin >> c;
            m.erase(c);
        }
        else if (a == 3) {
            string c;
            cin >> c;
            if (m.find(c) == m.end()) {
                cout << "0" << endl;
            }
            else {
                cout << m[c] << endl;
            }
        }
        else {
            return 1;
        }
        string c;
    }
    return 0;
}




