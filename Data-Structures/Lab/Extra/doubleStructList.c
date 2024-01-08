#include <stdio.h>

struct element {
    int info;
    struct element *prev;
    struct element *next;
};

int main () {
    // system ("chscp 65001");
    struct element el1, el2, el3;
    struct element *ptr1, *ptr2, *ptr3;

// Οι pointers δείχνουν στις διευθύνσεις μνήμης των αντικειμένων 
    ptr1 = &el1;
    ptr2 = &el2;
    ptr3 = &el3;

// Απόδοση τιμών στα struct αντικείμενα, χρησιμοποιώντας τους pointers
    ptr1->info = 1;
    ptr1->prev = NULL;
    ptr1->next = &el2;

    ptr2->info = 2;
    ptr2->prev = &el1;
    ptr2->next = &el3;

    ptr3->info = 3;
    ptr3->prev = &el2;
    ptr3->next = NULL;

    printf ("\nElement 2 info: %d\n", ptr1->next->info);
// ptr1->next->info είναι το ίδιο με (*ptr1).(*next).info 
     
}