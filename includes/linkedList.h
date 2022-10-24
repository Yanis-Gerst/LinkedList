//
//  linkedList.h
//  Data-Structure
//
//  Created by Yanis Gerst on 22/10/2022.
//

#ifndef linkedList_h
#define linkedList_h

#include <stdio.h>
#include <stdlib.h>


typedef struct Element Element;
struct Element
{
    int value;
    Element *next;
};

typedef struct LinkedList LinkedList;
struct LinkedList
{
    int length;
    Element *first;
};

void append(LinkedList *array, int value);
void printArray(LinkedList *array);
LinkedList *initLinkedList(void);
void removeElement(LinkedList *array, int toRemove);
void clearArray(LinkedList *array);
void insertArray(LinkedList *array, int index, int newValue);
int len(LinkedList *array);
#endif /* linkedList_h */
