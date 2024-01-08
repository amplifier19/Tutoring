#include <stdio.h>

struct student {
    int code;
    float grade;
};

struct student* normalize (struct student pass[], struct student fail[], int *p, int *f);

int main () {
    struct student pass[100];
    struct student fail[100];
    int code, i, p, f;
    float grade;
    struct student *ptr;

    p = 0;
    f = 0;
    for (i=0; i<100; i++) {
        printf ("Code: ");
        scanf ("%d", &code);
        printf ("Grade: ");
        scanf ("%f", &grade);
        printf ("\n");
        if (grade >= 5) {
            p++;
            pass[p].code=code;
            pass[p].grade=grade;
        }
        else {
            f++;
            fail[f].code=code;
            fail[f].grade=grade;
        }
    }

    ptr = normalize (pass, fail, &p, &f);
    if (ptr != NULL) {
        printf ("Excellent Student: [Code: %d] [Grade: %f]\n", ptr->code, ptr->grade);
    }
}

struct student* normalize (struct student pass[], struct student fail[], int *p, int *f) {
    int i;
    int fnew;
    
    fnew = (*f);
    for (i=0; i<(*f); i++) {
        if (fail[i].grade >=4 && fail[i].grade < 5) {
            pass[*p].code = fail[i].code;
            pass[*p].grade = 5.0;
            printf ("Passed: [Code: %d] [Grade: %f]\n", pass[(*p)].code, pass[(*p)].grade);
            *p = (*p) + 1;
            fnew--;
        }
    }

    *f = fnew;
    float percentage = (*p) * 100 / ((*p) + (*f));   // π.χ. 25 / 50 = 0.5*100 = 50%
    if (percentage < 70) {
        return NULL;
    }
    for (i=0; i<(*p); i++) {
        if (pass[i].grade == 10.0) {
            return &pass[i];
        }
    }
    return NULL;
}
