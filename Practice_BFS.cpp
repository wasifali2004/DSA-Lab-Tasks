#include <bits/stdc++.h>
using namespace std;

class vertex {
    public:
    char label;
    bool visit;
    vertex(char lab): label(lab),visit(false){}
};

class BFS {
    private:
    vertex* arr[10];
    int matrix[10][10];
    int vertices;
    int front;
    int rear;
    int queue[10];
    int queue_ele;
    public:
    BFS() {
        vertices = 0;
        front = 0;
        rear = -1;
        for(int i=0; i<10; ++i) {
            for(int j=0; j<10; ++j) {
                matrix[i][j] = 0;
            }
        }
        queue_ele = 0;
    }

    void insert_vertex(char c) {
        arr[vertices++] = new vertex(c);
    }

    void insert_edge(int s, int e) {
        matrix[s][e] = 1;
        matrix[e][s] = 1;
    }

    void display(int idx) {
        cout<< arr[idx] -> label <<" ";
    }

    int adjacent_vertice(int idx) {
        for(int i=0; i<10; ++i) {
            if(matrix[idx][i] == 1 && ! arr[i] -> visit) {
                return i;
            }
        }
        return -1;
    }

    void insert_queue(int x) {
        queue[++rear] = x;
        queue_ele++;
    }

    int remove_queue() {
        queue_ele--;
        return queue[front++];
    }

    bool isEmpty() {
        return queue_ele == 0;
    }

    bool isFull() {
        return queue_ele == 10;
    }

    void Breadth_First_Search() {
        arr[0] -> visit = true;
        display(0);
        insert_queue(0);
        while(!isEmpty()) {
            int temp = remove_queue();
            int unvisited;
            while( (unvisited = adjacent_vertice(temp) ) != -1) {
                arr[unvisited] -> visit = true;
                insert_queue(unvisited);
                display(unvisited);
            }
        }

        for (int i = 0; i < 10; i++) {
            arr[i]->visit = false;
        }
    }

};

int main() {
    BFS graph;
    graph.insert_vertex('Z');
    graph.insert_vertex('A');
    graph.insert_vertex('B');
    graph.insert_vertex('C');
    graph.insert_vertex('Y');

    graph.insert_edge(0,1);
    graph.insert_edge(0,2);
    graph.insert_edge(0,3);
    graph.insert_edge(1,4);
    graph.insert_edge(2,4);
    graph.insert_edge(3,4);
    graph.Breadth_First_Search();
}