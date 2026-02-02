#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    set<int>s;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            s.insert(b);
        }
        else if (a == 2) {
            s.erase(b);
        }
        else if (a == 3) {
            set<int>::iterator isValid = s.find(b);
            if (isValid == s.end()) {
                cout << "No" << endl;
            }
            else {
                cout << "Yes" << endl;
            }
        }
    }   
    return 0;
}


