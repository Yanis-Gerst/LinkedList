//
//  main.c
//  Data-Structure
//
//  Created by Yanis Gerst on 22/10/2022.
//

#include <stdio.h>
#include "linkedList.h"

int main(int argc, const char * argv[]) {
    
    LinkedList *array = initLinkedList();
    
    for (int i = 0; i < 10; i++)
    {
        append(array, i);
    }
    clearArray(array);
    
    printArray(array);
    int n = len(array);
    printf("La Longeur est de %d \n", n);
   
    return 0;
}
