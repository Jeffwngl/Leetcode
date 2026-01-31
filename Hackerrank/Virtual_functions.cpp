#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <numeric>

class Person {
    public:
        string name;
        int age;
        
        virtual void getdata() {};
        virtual void putdata() {};
        virtual ~Person() {};
};

class Professor : public Person {
    private:
        int publications;
        int cur_id;
        static int cnt;
    public:
        Professor() {
            cur_id = cnt++;
        }
        void getdata() override {
            cin >> name >> age >> publications;
        }
        void putdata() override {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;        
        }
};

class Student : public Person {
    private:
        int marks[6];
        int cur_id;
        static int cnt;
    public:
        Student() {
            cur_id = cnt++;
        }
        void getdata() override {
            cin >> name >> age;
            
            for (int i = 0; i < 6; i++) {
                cin >> marks[i];
            }
        }
        void putdata() override {
            int total = accumulate(begin(marks), end(marks), 0);
            cout << name << " " << age << " " << total << " " << cur_id << endl;
        }
};

int Professor::cnt = 1;
int Student::cnt = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

