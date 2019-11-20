#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Heap.h"

#define TRUE 0
#define FALSE 1

//Creating heap
Heap* createHeap(int max)
{
	Heap* pHeap = (Heap*)malloc(sizeof(Heap));
	if (pHeap == NULL)
	{
		return NULL;
	}

	pHeap->heapAry = (Element*)malloc(sizeof(Element));
	pHeap->maxSize = max;
	pHeap->size = 0;

	return pHeap;
}
//Inserting data
void InsertHeap(Heap* pHeap, Element data)
{
	if (heapFull(pHeap))
	{
		printf("Heap is full!");
		return;
	}

	pHeap->heapAry[(pHeap->size)++] = data;
	reHeapUp_recursive(pHeap, (pHeap->size) - 1);
}

//Resorting recursively after inserting data
void reHeapUp_recursive(Heap* pHeap, int index)
{
	int parentIndex = 0;

	if (index <= 0 || index >= pHeap->size)
	{
		return;
	}

	parentIndex = (index - 1) / 2;
	if (pHeap->heapAry[index] > pHeap->heapAry[parentIndex])
	{
		Element temp = pHeap->heapAry[index];
		pHeap->heapAry[index] = pHeap->heapAry[parentIndex];
		pHeap->heapAry[parentIndex] = temp;
		reHeapUp_recursive(pHeap, parentIndex);
	}
}

//Deleting data from heap
int deleteHeap(Heap *pHeap, Element dataBye)
{
	if (heapEmpty(pHeap))
	{
		printf("Heap is empty!\n");
		return FALSE;
	}

	dataBye = pHeap->heapAry[0];
	pHeap->heapAry[0] = pHeap->heapAry[(pHeap->size)--];
	reHeapDown_recursive(pHeap, 0);

	return TRUE;
}

//Resorting datas from Heap after deleting
void reHeapDown_recursive(Heap* pHeap, int index)
{
	if (index < 0 || index >= pHeap->size)
	{
		return;
	}

	if (index * 2 + 1 < pHeap->size)
	{
		int maxChild = index * 2 + 1;
		if (maxChild + 1 < pHeap->size && pHeap->heapAry[maxChild] < pHeap->heapAry[maxChild + 1])
		{
			maxChild++;
		}

		if (pHeap->heapAry[index] < pHeap->heapAry[maxChild])
		{
			Element temp = pHeap->heapAry[index];
			pHeap->heapAry[index] = pHeap->heapAry[maxChild];
			pHeap->heapAry[maxChild] = temp;
			reHeapDown_recursive(pHeap, maxChild);
		}
	}
}

//Creating heap
void buildHeap(Heap* pHeap)
{
	int i;

	for (i = 0; i < pHeap->size; i++)
	{
		reHeapUp_recursive(pHeap, i);
	}
}

//Counting the number of elements in heap
int heapCount(Heap* pHeap)
{
	if (heapEmpty(pHeap))
	{
		return 0;
	}
	else if (heapFull(pHeap))
	{
		return pHeap->maxSize;
	}
	else
		return pHeap->size;
}

//Is Heap Empty?
bool heapEmpty(Heap* pHeap)
{
	if (pHeap->size <= 0)
	{
		return true;
	}
	else
		return false;
}

bool heapFull(Heap* pHeap)
{
	if (pHeap->size == pHeap->maxSize)
	{
		return true;
	}

	return false;
}

bool heapDestroy(Heap* pHeap)
{
	int i = 0;
	
	if (heapEmpty(pHeap))
	{
		free(pHeap);
		return true;
	}

	while (i < pHeap->size)
	{
		free(pHeap->heapAry+i);
	}

	free(pHeap);
	return true;
}