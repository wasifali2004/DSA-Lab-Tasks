#include <bits/stdc++.h>
#include <cstring>

#define MAX 56

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
    int stack[MAX];
    int top;

public:
    Graph() : vertexCount(0), top(-1) {
        std::memset(adjMatrix, 0, sizeof(adjMatrix));
    }

    void addVertex(char label) {
        vertices[vertexCount++] = new Vertex(label);
    }

    void addEdge(int start, int end) {
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
    }

    void displayVertex(int vertexIndex) {
        std::cout << vertices[vertexIndex]->label << " ";
    }

    int getAdjUnvisitedVertex(int vertexIndex) {
        for (int i = 0; i < vertexCount; i++) {
            if (adjMatrix[vertexIndex][i] == 1 && !vertices[i]->visited) {
                return i;
            }
        }
        return -1;
    }

    void push(int item) {
        stack[++top] = item;
    }

    int pop() {
        return stack[top--];
    }

    int peek() {
        return stack[top];
    }

    bool isStackEmpty() {
        return top == -1;
    }

    void depthFirstSearch() {
        // Mark the first node as visited
        vertices[0]->visited = true;
        // Display the vertex
        displayVertex(0);
        // Push vertex index in stack
        push(0);

        while (!isStackEmpty()) {
            // Get the unvisited vertex of the vertex at the top of the stack
            int unvisitedVertex = getAdjUnvisitedVertex(peek());
            // No adjacent vertex found
            if (unvisitedVertex == -1) {
                pop();
            } else {
                vertices[unvisitedVertex]->visited = true;
                displayVertex(unvisitedVertex);
                push(unvisitedVertex);
            }
        }

        // Stack is empty, search is complete, reset the visited flag
        for (int i = 0; i < vertexCount; i++) {
            vertices[i]->visited = false;
        }
    }
};

int main() {
    Graph graph;

    graph.addVertex('S'); // 0
    graph.addVertex('A'); // 1
    graph.addVertex('B'); // 2
    graph.addVertex('C'); // 3
    graph.addVertex('D'); // 4

    graph.addEdge(0, 1); // S - A
    graph.addEdge(0, 2); // S - B
    graph.addEdge(0, 3); // S - C
    graph.addEdge(1, 4); // A - D
    graph.addEdge(2, 4); // B - D
    graph.addEdge(3, 4); // C - D

    std::cout << "Depth First Search: ";
    graph.depthFirstSearch();

    return 0;
}
