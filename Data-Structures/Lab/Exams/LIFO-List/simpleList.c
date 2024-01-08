/*
Να ορίσετε μία δομή Node με πεδία: αριθμός μητρώου και βαθμός. 
Να γραφεί ένα πρόγραμμα το οποίο να δημιουργεί μία LIFO στοίβα της οποίας κάθε κόμβος να είναι μία τέτοια δομή. 
Συγκεκριμένα, να υλοποίησετε την συνάρτηση add_stack(), 
η οποία να αποθηκεύει τα στοιχεία ενός φοιτητή στην στοίβα (κάθε φοιτητής αντιστοιχεί σε έναν κόμβο).

Κάθε αποθήκευση πρέπει να γίνεται σε έναν νέο κόμβο,
ο οποίος θα αποτελεί την νέα κεφαλή της στοίβας. 
Να αποθηκεύσετε στη στοίβα τα στοιχεία 5 φοιτητών.

Στην συνέχεια να υλοποιήσεται τις συναρτήσεις για την αφαίρεση ενός στοιχείου από την στοίβα, 
για την τύπωση των στοιχείων της στοίβας και για την απαλευθέρωση της μνήμης που δεσμέυτηκε για την στοίβα

- add_stack ()
- pop ()
- display ()
- free_stack ()

head ---> s1 ---> s2 ---> s3 ---> NULL
     next    next    next
     
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
     int am;
     float grade;
     struct node *next;
};


void add_stack(struct node n);
void pop ();
void display ();
void free_stack ();

struct node *head;

int main () {
     system ("chcp 1253");

     struct node n;
     int i;

     head = NULL;
     for (i=0;i<5;i++)
     {
          printf("Δώσε AM του %d φοιτητή: ", i);
          scanf("%d",&n.am);
          printf("Δώσε τον βαθμό του %d φοιτητή: ", i);
          scanf("%f",&n.grade);
          add_stack (n);  // Προσθέτω έναν φοιτητή στη λίστα.
     }

     pop (); // Διαγραφή του πρώτου φοιτητή της λίστας
     display (); // Τύπωση όλων των φοιτητών της λίστας
     free_stack (); // Αποδέσμευση μνήμης της λίστας
}

void add_stack(struct node n)
{
     struct node *new; // Δημιουργία νεου φοιτητή με δυναμικό τρόπο.
     new = (struct node*) malloc(sizeof(struct node)); //  -//-  
     
     new->am = n.am; // Βελάκι επειδη ο new είναι pointer, που δείχνει στην μνήμη που δεσμεύτηκε με την malloc.
     new->grade = n.grade;


     new->next = head;   
     /*            100 300    
          200 100  head--> 300
          new ---> s1 ---> s2 ---> s3 ---> NULL
              next    next    next
     */

     head = new;
     /*   200 100      
          head---> 100
          new ---> s1 ---> s2 ---> s3 ---> NULL
              next    next    next
     */
     
          
}

void display () { 
     struct node *p;
     p = head; // Για να προσπελάσουμε όλους τους φοιτητές (s1,s2,s3).
     printf ("\n");
     while (p!= NULL) {
          printf ("AM: %d, Βαθμό: %f\n", p->am, p->grade);
          p = p->next;
     }
}

void pop () {
     struct node *p;
     p = head->next;
     free (head);
     head = p;
}

void free_stack () {
     struct node *n;
     struct node *p;
     p = head;
     while (p != NULL) {
          n = p->next;
          free (p);
          p = n;
     }
}