#include <stdio.h>
#include <string.h>

struct student {
    int mo;
    char name[15];
};

int main () {
    // system ("chcp 65001");
    int i;
    struct student s1, s2, s3;
    struct student *classroom [3];

// Το classroom είναι πίνακας με pointers που δείχνουν σε struct αντικείμενα
    classroom [0] = &s1;
    classroom [1] = &s2;
    classroom [2] = &s3;

// Απόδοση τιμών στα struct αντικείμενα, χρησιμοποιώντας τους pointers 
    classroom [0] -> mo = 5;
    strcpy (classroom [0] -> name, "Dimitris");

    classroom [1]->mo = 7;
    strcpy (classroom [1] -> name, "Giannis");

    classroom [2] -> mo = 9;
    strcpy (classroom [2] -> name, "Kostas");

// Τύπωμα τιμών 
    for (i=0; i<3; i++) {
        printf ("Student %d: [%s, %d]\n", i, classroom [i] -> name, classroom [i] -> mo);
    }
}