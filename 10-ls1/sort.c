#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// an example of using qsort with strings
// also see https://man7.org/linux/man-pages/man3/qsort.3.html

// a comparison function that will be used by qsort()
int myStringCompare(const void *a, const void *b) {
    // The actual arguments to this function are "pointers to pointers to char", 
    // but strcmp() arguments are "pointers to char", 
    // which requires the following typecasting followed by dereferencing 
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;
    return strcmp(pa,pb);
}

int main() {
    char *words[] = {"orange", "apple", "table", "chair", "cable", "TV", "1234"};
    int wordCount = sizeof(words)/sizeof(char*);    // number of elements in the array

    qsort(words, wordCount, sizeof(char*), myStringCompare);

    for(int i; i < wordCount; i++)      // verify the correctness of sorting
        printf("%d: %s\n", i, words[i]);
}