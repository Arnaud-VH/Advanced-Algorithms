#include "graph.h"
#include <stdio.h>
#include <stdbool.h>

#define MAXCONNECTIONS 10


Node newGraphNode(int id) {
  Node n = malloc(sizeof(struct GraphNode));
  n->id = id;
  n->edgeCount = 0;
  n->maxCapacity = MAXCONNECTIONS;
  n->edges = malloc(sizeof(struct GraphEdge) * n->maxCapacity);
  return n;
}

Edge newGraphEdge(int weight, Node toNode, Node fromNode) {
  Edge edge = malloc(sizeof(struct GraphEdge));
  edge->weight = weight;
  edge->nextNode = toNode;
  edge->fromNode = fromNode;
  return edge;
}

Node createConnection(Node fromNode, int weight, Node toNode) {
  int index = fromNode->edgeCount;
  if (index >= fromNode->maxCapacity) {
    fromNode->maxCapacity *=2;
    fromNode->edges = realloc(fromNode->edges, sizeof(struct GraphEdge)*fromNode->maxCapacity);
  }
  Edge edge = newGraphEdge(weight, toNode, fromNode);
  fromNode->edges[index] = edge;
  return fromNode;
}

Node removeConnection(Node start, Node end) {
  int endID = end->id;
  Edge* newStartEdge = malloc(sizeof(struct GraphEdge)*start->edgeCount-1);
  int index = 0;
  for (int i = 0; i < start->edgeCount; i++) {
    if (endID != start->edges[i]->nextNode->id) {
      newStartEdge[index] = start->edges[i];
      index++;
    } else {
      free(start->edges[i]);
    }
  }
  start->edgeCount--;
  free(start->edges);
  start->edges = newStartEdge;
  return start;
}
