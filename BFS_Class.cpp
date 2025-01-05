#include <iostream>
#include <queue>
#include <cstring>

#define MAX 5

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
    int queue[MAX];
    int rear;
    int front;
    int queueItemCount;

public:
    Graph() : vertexCount(0), rear(-1), front(0), queueItemCount(0) {
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

    void insertQueue(int data) {
        queue[++rear] = data;
        queueItemCount++;
    }

    int removeQueue() {
        queueItemCount--;
        return queue[front++];
    }

    bool isQueueEmpty() {
        return queueItemCount == 0;
    }

    void breadthFirstSearch() {
        // Mark first node as visited
        vertices[0]->visited = true;
        // Display the vertex
        displayVertex(0);
        // Insert vertex index in queue
        insertQueue(0);

        while (!isQueueEmpty()) {
            // Get the unvisited vertex of vertex which is at front of the queue
            int tempVertex = removeQueue();
            int unvisitedVertex;

            // No adjacent vertex found
            while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
                vertices[unvisitedVertex]->visited = true;
                displayVertex(unvisitedVertex);
                insertQueue(unvisitedVertex);
            }
        }

        // Queue is empty, search is complete, reset the visited flag
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

    std::cout << "\nBreadth First Search: ";
    graph.breadthFirstSearch();

    return 0;
}
