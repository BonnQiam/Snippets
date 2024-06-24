#include <stdlib.h>
#include <stdbool.h>

int *array_diff(
    const int *arr1, size_t n1, // n1 is the size of arr1
    const int *arr2, size_t n2, // n2 is the size of arr2
    size_t *z) // z is the pointer to the size of the returned array
               // return the array of the difference between arr1 and arr2
{

    int* diffArr = (int*) malloc(n1 * sizeof(size_t));
    
    *z = 0;
        
    for (size_t i = 0; i < n1; i++) {
        bool inArr2 = false;
        
        // check if arr1[i] is in arr2
        for (size_t j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                inArr2 = true;
                break;
            }
        }
        
        // if arr1[i] is not in arr2, add it to the diffArr
        if (!inArr2) {
            diffArr[*z] = arr1[i];
            *z += 1;
        }
    }


    return diffArr;
}