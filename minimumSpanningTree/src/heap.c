#include <stdlib.h>
#include <assert.h>
#include "HeapLib.h"

Heap makeHeap() {
  Heap h;
  h.array = malloc(1*sizeof(struct HeapNode));
  assert(h.array != NULL);
  h.front = 1;
  h.size = 1;
  return h;
}

node newNode(Edge edge, int cost) {
  node n;
  n.node = edge;
  n.cost = cost;
  return n;
}

void swap (node *a, node *b) {
  node temp = *a;
  *a = *b;
  *b = temp;
}

void doubleHeapSize (Heap *hp) {
  int newSize = hp->size + 1;
  hp -> array = realloc (hp ->array,newSize * sizeof(struct HeapNode));
  assert (hp -> array != NULL );
  hp -> size = newSize ;
}

void upHeap (Heap *hp, int n) {
  if ( n > 1 && hp->array[n].cost < hp->array[n/2].cost) {
    swap(&(hp->array[n]),&(hp->array[n/2]));
    upHeap(hp, n/2);
  }
}

void downheap(Heap *hp, int n) {
  int front = hp->front;
  int indexMax = n;
  if (front < 2*n+1) {
    return;
  }

  if (hp->array[n].cost > hp->array[2*n].cost ) {
    indexMax = 2*n; //Left Child
  }
  if (front > 2*n+1 && hp->array[indexMax].cost > hp->array[2*n+1].cost) {
    indexMax = 2*n+1; //Right child
  }

  if (indexMax != n) {
    swap(&(hp->array[n]), &(hp->array[indexMax]));
    downheap(hp, indexMax);
  }
}

node removeMin (Heap *hp) {
  node n = hp->array[1];
  hp->front--;
  hp->array[1] = hp->array[hp->front];
  downheap(hp, 1);
  return n;
}

void enqueue(Heap *hp, node n) {
  int front = hp->front;
  if (front == hp->size) {
    doubleHeapSize(hp);
  }
  hp->array[front] = n;
  upHeap(hp, front);
  hp->front = front + 1;
}

void freeHeap(node* heap) {
  free(heap);
}
