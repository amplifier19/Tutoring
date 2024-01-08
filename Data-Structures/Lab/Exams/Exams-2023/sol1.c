#include <stdio.h>
#include <stdlib.h>

struct student {
    int  code;
    float grade;
};

struct student* normalize (struct student pass[], struct student fail[], int *p, int *f);

int main () {
    struct student pass[4];
    struct student fail[4];
    int i, f, p, code;
    float grade;

    p = 0;
    f = 0;
    for (i=0; i<4; i++) {
        printf ("Code: ");
        scanf ("%d", &code);
        printf ("Grade: ");
        scanf ("%f", &grade);
        printf ("\n");
        if (grade < 5) {
            fail[f].code = code;
            fail[f].grade = grade;
            f++;
        }
        else {
            pass[p].code = code;
            pass[p].grade = grade;
            p++;
        }
    }

    struct student *ptr;
    ptr = normalize (pass, fail, &p, &f);
    printf ("Excellent Student: [Code: %d] [Grade: %f]\n", ptr->code, ptr->grade);
}

struct student* normalize (struct student pass[], struct student fail[], int *p, int *f) {
    int i;
    float p_percent;
    int f_new = *f;
    for (i=0; i<(*f); i++) {
        if (fail[i].grade<5 && fail[i].grade>=4) {
            pass[(*p)].code = fail[i].code;
            pass[(*p)].grade = 5;
            printf ("Passed: [Code: %d] [Grade: %f]\n", pass[(*p)].code, pass[(*p)].grade);
            f_new --;
            *p = (*p) + 1;
        }
    }
    *f = f_new;
    p_percent = (*p) * 100 / ((*p)+(*f));
    if (p_percent < 70) {
        return NULL;
    }
    for (i=0; i<(*p); i++) {
        if (pass[i].grade == 10.0) {
            return &pass[i];
        }
    }
    return NULL;
}