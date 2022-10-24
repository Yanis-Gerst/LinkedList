//
//  linkedList.c
//  Data-Structure
//
//  Created by Yanis Gerst on 22/10/2022.
//

#include "linkedList.h"


LinkedList *initLinkedList(void)
{
    LinkedList *array = malloc(sizeof(LinkedList));
    if (array == NULL )
    {
        printf("Pb malloc enft");
        exit(EXIT_FAILURE);
    }
    array->first = NULL;
    array->length = 0;
    return array;
}

void append(LinkedList *array, int newValue)
{
    array->length++;
    Element *elt = array->first;
    Element *toAppend = malloc(sizeof(Element));
    toAppend->value = newValue;
    toAppend->next = NULL;
    if (elt == NULL)
    {
        array->first = toAppend;
        return;
    }
    while (elt->next != NULL)
    {
        elt = elt->next;
    }
    elt->next = toAppend;
    
}

void printArray(LinkedList *array)
{
    Element *elt = array->first;
    if (elt == NULL)
    {
        printf("[]");
        return;
    }
    while (elt->next != NULL)
    {
        printf("%d \n", elt->value);
        elt = elt->next;
    }
    printf("%d \n", elt->value);
}

void removeElement(LinkedList *array, int toRemove)
{
    Element *elt = array->first;
    
    if (elt->value == toRemove)
    {
        array->first = elt->next;
        free(elt);
        array->length--;
        return;
    }
    
    while (elt->next != NULL && elt->next->value != toRemove)
    {
        elt = elt->next;
    }
    if (elt->next == NULL)
    {
        printf("Pas trouver L'élémént %d \n", toRemove);
        return;
    }
    Element *eltToRemove = elt->next;
    elt->next = elt->next->next;
    free(eltToRemove);
    array->length--;
}

void clearArray(LinkedList *array)
{
    Element *elt = array->first;
    if (elt == NULL)
    {
        return;
    }
    while (elt->next != NULL)
    {
        Element *tempElt = elt;
        elt = elt->next;
        free(tempElt);
    }
    array->first = NULL;
    array->length = 0;
}

void insertArray(LinkedList *array, int index, int newValue)
{
   
    if (index == 0)
    {
        Element *toInsert = malloc(sizeof(Element));
        toInsert->value = newValue;
        toInsert->next = array->first;
        array->first = toInsert;
        array->length++;
        return;
    }
    int counter = 0;
    Element *elt = array->first;
    Element *toInsert = malloc(sizeof(Element));
    toInsert->value = newValue;
    while (elt->next != NULL && counter < index - 1)
    {
        counter++;
        elt = elt->next;
    }
    toInsert->next = elt->next;
    elt->next = toInsert;
    array->length++;
}

int len(LinkedList *array)
{
    return array->length;
}
