#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class AdjList {
public:
    Node* head;
};

class Graph {
private:
    int V;
    AdjList* arr;

public:
    Graph(int V) {
        this->V = V;
        arr = new AdjList[V];
        for (int i = 0; i < V; ++i)
            arr[i].head = NULL;
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = arr[src].head;
        arr[src].head = newNode;

        newNode = new Node;
        newNode->data = src;
        newNode->next = arr[dest].head;
        arr[dest].head = newNode;
    }

    void removeEdge(int src, int dest) {
        Node* temp = arr[src].head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != dest) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            if (prev == NULL) {
                arr[src].head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        }

        temp = arr[dest].head;
        prev = NULL;
        while (temp != NULL && temp->data != src) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            if (prev == NULL) {
                arr[dest].head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        }
    }

    int* getN(int u, int& numNeighbors) {
        Node* tmp = arr[u].head;
        int* neighbors = new int[V];  
        numNeighbors = 0;
        
        while (tmp != NULL) {
            neighbors[numNeighbors++] = tmp->data;
            tmp = tmp->next;
        }
        
        return neighbors;
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            Node* tmp = arr[v].head;
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            while (tmp) {
                cout << "-> " << tmp->data;
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            Node* temp = arr[vertex].head;
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    visited[temp->data] = true;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }

    void DFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) visited[i] = false;

        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;
            }

            Node* temp = arr[vertex].head;
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    s.push(temp->data);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }
};

void measureTime(int V) {
    Graph gh(V);
    for (int i = 0; i < V - 1; ++i) {
        gh.addEdge(i, i + 1);
    }

    auto start = chrono::high_resolution_clock::now();
    gh.BFS(0);
    auto end = chrono::high_resolution_clock::now();
    auto bfs_duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "\nTime taken for BFS with " << V << " vertices: " << bfs_duration << " microseconds" << endl;

    start = chrono::high_resolution_clock::now();
    gh.DFS(0);
    end = chrono::high_resolution_clock::now();
    auto dfs_duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "\nTime taken for DFS with " << V << " vertices: " << dfs_duration << " microseconds" << endl;
    cout<<'\n' <<endl;
}



int main() {
    Graph gh(5);
    gh.addEdge(0, 1);   
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    gh.printGraph();

    cout << "\nRemoving edge between 1 and 4\n";
    gh.removeEdge(1, 4);
    gh.printGraph();
    int numNeighbors = 0;
    int* neighbors = gh.getN(1, numNeighbors);
    cout << "\nNeighbors of vertex 1: ";
    for (int i = 0; i < numNeighbors; ++i) {
        cout << neighbors[i] << " ";
    }
    cout << endl;
    cout << "\nBreadth-First Search starting from vertex 0: ";
    gh.BFS(0);
    cout << endl;
    cout << "\nDepth-First Search starting from vertex 0: ";
    gh.DFS(0);
    cout << endl;

    delete[] neighbors;

    int arr[3]= {100, 500, 1000};

    for (int i=0; i<3; ++i) {
        measureTime(arr[i]);
    }

    return 0;
}
