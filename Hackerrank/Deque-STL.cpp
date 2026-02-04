#include <iostream>
#include <deque> 
using namespace std;

void pushMax(deque<int> &max, int a) {
    while (!max.empty() && a > max.back()) {
        max.pop_back();
    }
    max.push_back(a);
};

void popMax(deque<int> &max, int a) {
    if (a == max.front()) {
        max.pop_front();
    }
};

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> q;
    deque<int> max;

    for (int i = 0; i < n; i++) {
        if (i >= k) {
            popMax(max, q.front());
            q.pop_front();
        }
        q.push_back(arr[i]);
        pushMax(max, arr[i]);
        if (i == n - 1) {
            cout << max.front() << endl;
        }
        else if (i >= k - 1) {
            cout << max.front() << " ";
        }
    }
};

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
