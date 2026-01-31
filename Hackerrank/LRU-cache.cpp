#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    private:
        void removeNode(Node* node) {
            if (!node) {
                return;
            }
            
            if (node->prev) {
                node->prev->next = node->next;
            }
            else { // is head
                head = node->next;
            }
            
            if (node->next) {
                node->next->prev = node->prev;
            }
            else {
                tail = node->prev;
            }
        }
        
        void insertNode(Node* node) {        
            node->prev = nullptr;
            node->next = head;
            if (head) {
                head->prev = node;
            }
            if (!tail) {
                tail = node;
            }
            head = node;
        }
        
        void removeTail() {
            if (!tail) {
                return;
            }
            
            Node* tmp = tail;
            mp.erase(tmp->key);
            removeNode(tmp);
            delete tmp;
        }
        
    public:
        LRUCache() {
            cp = 0;
            head = nullptr;
            tail = nullptr;
        }
        LRUCache(int capacity) {
            cp = capacity;
            head = nullptr;
            tail = nullptr;
        }
        
        void set(int key, int value) override {
            if (cp == 0) {
                return;
            }
            // find if key exists and set
            if (mp.find(key) != mp.end()) {
                Node* node = mp[key];
                node->value = value;
                removeNode(node);
                insertNode(node);
            }
            else { // append new key
                Node* newNode = new Node(key, value);
                if (mp.size() >= cp) {
                    removeTail();
                }
                insertNode(newNode);
                mp[key] = newNode;
            }
        }
        
        int get(int key) override {
            // find key in cache
            if (mp.find(key) != mp.end()) {
                Node* recentlyUsed = mp[key];
                removeNode(recentlyUsed);
                insertNode(recentlyUsed);
                return recentlyUsed->value;
            }
            // return -1 if not found
            else {
                return -1;
            }
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

