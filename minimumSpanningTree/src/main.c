#include <stdio.h>
#include "graph.h"
#include "HeapLib.h"
#include <stdlib.h>

int find(int id, int* parent) {
  if (parent[id] == id) {
    return id;
  }
  return find(parent[id],parent);
}

bool Union(int id1, int id2, int* parent) {
  if (id1 != id2) {
    parent[id2] = id1;
    return true;
  }
  return false;
}

int* safeCalloc (int c, int size) {
  int* arr = calloc(c, size);
  if (arr == NULL) {
    exit(1);
  } else {
    return arr;
  }
}

//Kruskals algorithm to find the MST
int kruskals(Edge* edges, int size, int edgeSize) {

  int* parent = safeCalloc(size+1, sizeof(int));

  for (int i = 1; i < size; i++) {
    parent[i] = i;
  }

  Heap heap = makeHeap();
  for (int i = 0; i < edgeSize; i++) {
    Edge edge = edges[i];
    node n = newNode(edge, edge->weight);
    enqueue(&heap, n);
  }

  int count = 0;
  int weight = 0;

  while (count != size-1) {
    //Use the heap to find the minimal cost edge
    node n = removeMin(&heap);
    Edge minEdge = n.node;

    int uId = minEdge->fromNode->id;
    int vId = minEdge->nextNode->id;
    int u = find(uId, parent);
    int v = find(vId, parent);

    if (Union(u, v, parent)) {
      weight += minEdge->weight;
      count++;
    }
  }

  free(heap.array);
  free(parent);
  return weight;
}



int main() {
  int vertices;
  int edges;
  scanf("%d %d\n", &vertices, &edges);

  if (edges < vertices-1 || vertices == 0 || edges == 0) {
    printf("0\n");
    return 0;
  }
  Node* vertexArray = calloc(vertices, sizeof(struct GraphNode));
  Edge* edgeArray = calloc(edges, sizeof(struct GraphEdge));

  for (int i = 0; i < edges; i++) {
    int fromID, toID, weight;
    scanf("%d %d %d\n", &fromID, &toID, &weight);

    Node fromNode;
    if (vertexArray[fromID] == 0) {
      fromNode = newGraphNode(fromID);
      vertexArray[fromID] = fromNode;
    } else {
      fromNode = vertexArray[fromID];
    }

    Node toNode;
    if (vertexArray[toID] == 0) {
      toNode = newGraphNode(toID);
      vertexArray[toID] = toNode;
    } else {
      toNode = vertexArray[toID];
    }

    edgeArray[i] = newGraphEdge(weight, toNode, fromNode);

  }

  printf("%d\n", kruskals(edgeArray, vertices, edges));

  //Free the memory allocated
  for (int i = 1; i <= vertices; i++) {
    Node vertex = vertexArray[i];
    for (int j = 0; j < vertex->edgeCount; j++) {
      free(vertex->edges[j]);
    }
    free(vertex->edges);
    free(vertex);
  }
  free(vertexArray);

  for (int i = 0; i < edges; i++) {
    free(edgeArray[i]);
  }
  free(edgeArray);

  return 0;
}
