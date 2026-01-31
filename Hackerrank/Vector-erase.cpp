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
    int position, start, end;
    cin >> position >> start >> end;
    v.erase(v.begin() + position - 1);
    v.erase(v.begin() + start - 1, v.begin() + end - 1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i + 1 < size ? " " : "\n");
    }
    return 0;
}

