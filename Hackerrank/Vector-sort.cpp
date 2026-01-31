int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int>v;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            cout << v[i] << endl;
            break;
        }
        cout << v[i] << " ";
    }
    return 0;
}

// Better version

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
    sort(v.begin(), v.end());
    for (int i = 0; i < size; i++) {
        cout << v[i] << (i + 1 < size ? ' ' : '\n');
    }
    return 0;
}

