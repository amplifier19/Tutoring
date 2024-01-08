#include <stdio.h>

int main () {
    // system ("chscp 65001");
    int var;
    int *ptr;

    var = 30;
    ptr = &var;

    printf ("Pointer address: %d", &ptr);
    printf ("\nPointer points: %d", ptr);
    printf ("\nVar address: %d", &var);
    printf ("\nContent in pointed address: %d\n", *ptr);
}