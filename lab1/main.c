#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#include "record.h"
#include "node.h"
 
int main(void) {
    // 1. Arrays
    int arr[] = {2, 5, 7, 8, 21, 11};
    size_t count = sizeof arr / sizeof arr[0];
    int total = sum_array(arr,count);

    printf("Sum of array: %d\n", total);

    //2. Record Struct Construction
    Record rec1 = {
        .id = 1,
        .value = 360
    };

    //Record Pointer
    Record *rec1_ptr = &rec1;
    rec1_ptr->id = 2;

    printf("Record: id = %d value = %.0f\n", rec1_ptr->id, rec1_ptr->value);

    //3. Dynamic Record
    Record *rec2 = malloc(sizeof *rec2);

    //Allocation Check
    if(rec2 == nullptr) {
        fputs("memory allocation failed\n",stderr);
        return EXIT_FAILURE;
    }

    //Use of dynamic record
    rec2->id = 3;
    rec2->value = 321;

    printf("Dynamic record: id = %d value = %.0f\n", rec2->id, rec2->value);

    //Freeing of memory
    free(rec2);

    Node *node = malloc(sizeof *node);

    if(node == nullptr) {
        fputs("memory allocation failed\n",stderr);
        return EXIT_FAILURE;
    }

    //Use of dynamic node
    node->value = 100;
    node->next = nullptr;

    printf("Value: %d, Next: %p\n", node->value, (void *)node->next);

    //Freeing of memory
    free(node);

    return EXIT_SUCCESS;
}
