#ifndef GRAPH_H
#define GRAPH_H
#include "graph.h"

typedef struct HeapNode {
    Edge node;
    int cost;
}node;

typedef struct HeapArray {
    node* array;
    int front;
    int size;
}Heap;

Heap makeHeap();
node newNode(Edge node, int cost);
void swap(node *a, node *b);
void doubleHeapSize (Heap *hp);
void upHeap (Heap *hp, int n);
void downheap(Heap *hp, int n);
node removeMin(Heap *hp);
void enqueue(Heap *hp, node n);
void freeHeap(node* hp);

#endif
