#include <stdio.h>
#include <stdlib.h>

void insertionSort(int v[], int s)
{
    for (int j = 1; j < s; j++) {
        int key = v[j];
        int i = j - 1;
        
        while (i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }

        v[i + 1] = key;
    }
}

void get(int v[], int s) {
    for (int i = 0; i < s; i++) {
        printf((i == s - 1) ? "%d\n" : "%d, ", v[i]);
    }
}

void main()
{
    int v[] = {4, 3, 5, 2};
    int s = sizeof(v) / sizeof(*v);
    
    get(v, s);
    insertionSort(v, s);
    get(v, s);
}