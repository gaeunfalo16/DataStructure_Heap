#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;

// Making heap with array
typedef struct Heap
{
	Element *heapAry;
	int maxSize;
	int size;
} Heap;

Heap* createHeap(int);
void InsertHeap(Heap*, Element);
void reHeapUp_recursive(Heap*, int);
int deleteHeap(Heap*, Element);
void reHeapDown_recursive(Heap*, int);
void buildHeap(Heap*);
int heapCount(Heap*);
bool heapDestroy(Heap*);
bool heapEmpty(Heap*);
bool heapFull(Heap*);

