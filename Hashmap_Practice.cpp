#include <bits/stdc++.h>
using namespace std;

class Hashmap {
    private:
    string name[10];
    string del;
    public:
    Hashmap() {
        for(int i=0; i<10; ++i) {
            name[i] = "";
        }
        del = "DEL";
    }

    int hashfunc1(string s) {
        int hashvalue = 0;
        for(int i=0; i<s.length(); ++i) {
            hashvalue += (s[i] * (1 + i));
        } 
        return hashvalue % 10;
    }

    int hashfunc2(string s) {
        int hashvalue = 0;
        for(int i=0; i<s.length(); ++i) {
            hashvalue += s[i];
        }
        return 7-(hashvalue % 7);
    }

    void insert(string s) {
       int hash = hashfunc1(s);
       int step_size = hashfunc2(s);
        while(!name[hash].empty() && name[hash] != del) {
            hash = (hash + step_size) % 10;
        }
        name[hash] = s;
    }

    bool search(string s) {
        int hash = hashfunc1(s);
        int step_size = hashfunc2(s);
        while(!name[hash].empty() && name[hash] != del) {
            if(name[hash] == s) {
                return true;
            }
            hash = (hash + step_size) % 10;
        }
        return false;
    }
};