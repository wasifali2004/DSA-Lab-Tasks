#include <iostream>
#include <string>
using namespace std;

class HashmapDouble {
private:
    string hashTable[10];
    string deletedMarker;

public:
    HashmapDouble() : deletedMarker("#DEL#") {
        for (int i = 0; i < 10; ++i) {
            hashTable[i] = "";
        }
    }

    int hashFunc(const string &key) {
        int hashValue = 0;
        for (size_t i = 0; i < key.length(); ++i) {
            hashValue += (key[i] * (i + 1));
        }
        return hashValue % 2069 % 10;
    }

    int hashFunc2(const string &key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return 7 - (hashValue % 7);
    }

    void insert(const string &key) {
        int hashKey = hashFunc(key);
        int stepSize = hashFunc2(key);
        while (!hashTable[hashKey].empty() && hashTable[hashKey] != deletedMarker) {
            hashKey = (hashKey + stepSize) % 10;
        }
        hashTable[hashKey] = key;
    }

    bool search(const string &key) {
        int hashKey = hashFunc(key);
        int stepSize = hashFunc2(key);
        while (!hashTable[hashKey].empty()) {
            if (hashTable[hashKey] == key) {
                return true;
            }
            hashKey = (hashKey + stepSize) % 10;
        }
        return false;
    }

    void deleted(const string &key) {
        int hashKey = hashFunc(key);
        int stepSize = hashFunc2(key);
        while (!hashTable[hashKey].empty()) {
            if (hashTable[hashKey] == key) {
                hashTable[hashKey] = deletedMarker;
                return;
            }
            hashKey = (hashKey + stepSize) % 10;
        }
    }

    void display() {
        for (int i = 0; i < 10; ++i) {
            if (hashTable[i].empty()) {
                cout << "__ ";
            } else if (hashTable[i] == deletedMarker) {
                cout << "DEL ";
            } else {
                cout << hashTable[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    HashmapDouble hashTable;

    hashTable.insert("abcdef");
    hashTable.insert("bcdefa");
    hashTable.insert("cherry");
    hashTable.insert("date");
    hashTable.insert("fig");

    hashTable.display();

    cout << (hashTable.search("bcdefa") ? "Found" : "Not Found") << endl;
    cout << (hashTable.search("grape") ? "Found" : "Not Found") << endl;

    hashTable.deleted("bcdefa");
    hashTable.display();

    return 0;
}
