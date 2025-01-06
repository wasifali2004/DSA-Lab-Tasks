#include <iostream>
#include <queue>
#include <stack>
#include <chrono>
using namespace std;

#define MAX 700

class Vertex {
public:
    char label;
    bool visited;

    Vertex(char lab) : label(lab), visited(false) {}
};

class Graph {
private:
    Vertex* vertices[MAX];
    int adjMatrix[MAX][MAX];
    int vertexCount;
    int front, rear;
    int queue[MAX];
    int queue_ele;
    int stack[MAX];
    int top;

public:
    Graph() : vertexCount(0), front(0), rear(-1), queue_ele(0), top(-1) {
        for(int i=0; i<MAX; ++i) {
            for(int j=0; j<MAX; ++j) {
                adjMatrix[i][j] = -1;
            }
        }
    }

    void add_vertex(char label) {
        vertices[vertexCount++] = new Vertex(label);
    }

    void add_edge(int start, int end) {
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
    }

    void remove_edge(int start, int end) {
        adjMatrix[start][end] = 0;
        adjMatrix[end][start] = 0;
    }

    void get_neighbors(int vertexIndex, int neighbors[], int &neighborCount) {
        neighborCount = 0;
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[vertexIndex][i] == 1) {
                neighbors[neighborCount++] = i;
            }
        }
    }

    void display_graph() {
        for (int i = 0; i < vertexCount; i++) {
            cout << vertices[i]->label << " -> ";
            for (int j = 0; j < vertexCount; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << vertices[j]->label << " ";
                }
            }
            cout << endl;
        }
    }

    void display(int idx) {
        cout << vertices[idx]->label << " ";
    }

    int adjacent_vertice(int idx) {
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[idx][i] == 1 && !vertices[i]->visited) {
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

    bool is_queue_empty() {
        return queue_ele == 0;
    }

    bool is_queue_full() {
        return queue_ele == MAX;
    }

    void Breadth_First_Search() {
        vertices[0]->visited = true;
        display(0);
        insert_queue(0);
        while (!is_queue_empty()) {
            int temp = remove_queue();
            int unvisited;
            while ((unvisited = adjacent_vertice(temp)) != -1) {
                vertices[unvisited]->visited = true;
                insert_queue(unvisited);
                display(unvisited);
            }
        }

        for (int i = 0; i < vertexCount; i++) {
            vertices[i]->visited = false;
        }
    }

    void push_stack(int item) {
        stack[++top] = item;
    }

    int pop_stack() {
        return stack[top--];
    }

    int peek_stack() {
        return stack[top];
    }

    bool is_stack_empty() {
        return top == -1;
    }

    void depthFirstSearch() {
        vertices[0]->visited = true;
        display(0);
        push_stack(0);

        while (!is_stack_empty()) {
            int unvisitedVertex = adjacent_vertice(peek_stack());
            if (unvisitedVertex == -1) {
                pop_stack();
            } else {
                vertices[unvisitedVertex]->visited = true;
                display(unvisitedVertex);
                push_stack(unvisitedVertex);
            }
        }

        for (int i = 0; i < vertexCount; i++) {
            vertices[i]->visited = false;
        }
    }

    void measure_bfs() {
        auto start = std::chrono::high_resolution_clock::now();
        Breadth_First_Search();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "\nBFS execution time: " << duration.count() << " seconds" << std::endl;
    }

    void measure_dfs() {
        auto start = std::chrono::high_resolution_clock::now();
        depthFirstSearch();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        cout << "\nDFS execution time: " << duration.count() << " seconds" << std::endl;
    }
};

int main() {
    Graph graph;

    for (int i = 0; i < 700; ++i) {
        graph.add_vertex('A' + (i % 26)); 
    }

    for (int i = 0; i < 699; ++i) {
        graph.add_edge(i, (i+1) % 7000);
    }

    cout << "\nMeasuring BFS on 1000 vertices: " << endl;
    graph.measure_bfs();

    cout << "\nMeasuring DFS on 1000 vertices: " << endl;
    graph.measure_dfs();

    return 0;
}
