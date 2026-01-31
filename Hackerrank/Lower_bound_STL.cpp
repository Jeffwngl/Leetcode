#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
    cin >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++) {
        cin >> v[i];
    }
    int queries;
    cin >> queries;
    int cnt = 0;
    while (cnt < queries) {
        int num;
        cin >> num;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), num);
        int index = (low - v.begin());
        cout << (v[index] == num ? "Yes" : "No") << " " << index + 1 << endl;
        cnt++;
    }
    return 0;
}

