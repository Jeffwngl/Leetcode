#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start_time;
    int duration;
    int end_time;
    Workshop() {
        start_time = -1;
        end_time = -1;
        duration = -1;
    }
};

struct Available_Workshops {
    int n;
    vector<Workshop>v;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* a = new Available_Workshops(); // needed for a to persist after the function code
    a->n = n;
    for (int i = 0; i < n; i++) {
        Workshop b;
        b.start_time = start_time[i];
        b.duration = duration[i];
        b.end_time = start_time[i] + duration[i];
        a->v.push_back(b);
    }
    return a;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    vector<Workshop> v = ptr->v;
    
    sort(v.begin(), v.end(), [](const Workshop& a, const Workshop& b) {
        return a.end_time < b.end_time;
    });
    
    int cnt = 0;
    Workshop curr_smallest;
    for (int i = 0; i < ptr->n; i++) {
        if (v[i].start_time < curr_smallest.end_time) { // overlap
            // cout << i << endl;
            // cout << ptr->v[i].start_time << "<=" << curr_smallest.end_time << endl;
            cnt++;
            continue;
        }
        curr_smallest = v[i];
    }
    return ptr->n - cnt;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

