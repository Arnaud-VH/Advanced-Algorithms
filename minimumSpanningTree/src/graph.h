#ifndef HEAPLIB_H
#define HEAPLIB_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct GraphNode* Node;
typedef struct GraphEdge* Edge;

struct GraphNode {
    int id;
    int edgeCount;
    int maxCapacity;
    Edge* edges;
};

struct GraphEdge {
    int weight;
    Node nextNode;
    Node fromNode;
};

Node createConnection(Node fromNode, int weight, Node toNode);
Node newGraphNode(int id);
Edge newGraphEdge(int weight, Node toNode, Node from);
Node removeConnection(Node start, Node end);

#endif
