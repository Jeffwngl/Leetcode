#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a, b;
    cin >> a >> b;
    
    cin.ignore();
    
    vector<string> tagStack;
    map<string, string> tagMap;
    
    for (int i = 0; i < a; i++) {
        string l;
        getline(cin, l);
        
        if (l.substr(0, 2) == "</") {
            tagStack.pop_back();
            continue;
        }
        
        l.erase(0, 1);
        l.pop_back();
        
        stringstream ss(l);
        string tag, key, eq, value;
        ss >> tag;
        
        tagStack.push_back(tag);
        
        while (ss >> key >> eq >> value) {
            value = value.substr(1, value.length() - 2);
            
            string tagKey;
            for (int j = 0; j < tagStack.size(); j++) {
                if (j > 0) {
                    tagKey += ".";
                }
                tagKey += tagStack[j];
            }
            tagMap[tagKey + "~" + key] = value;
        }
    }
    
    for (int i = 0; i < b; i++) {
        string q;
        getline(cin, q);
        if (!tagMap.count(q)) {
            cout << "Not Found!" << endl;
        }
        else {
           cout << tagMap[q] << endl; 
        }  
    }
    return 0;
}

