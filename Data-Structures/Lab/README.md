# Δομές Δεδομένων

## <br></br>

## Structs

### Δήλωση δομής

> ```
> struct student {
>    float grade;
>    int semester;
> };
> ```
>
> > _Σε αυτή την περίπτωση η δήλωση ενός αντικειμένου γίνεται:_
> >
> > ```
> > int main () {
> >    struct student std1;
> > }
> > ```

### Ρητή δήλωση δομής

> ```
> typedef struct student {
>    float grade;
>    int semester;
> } student;
> ```
>
> > _Σε αυτή την περίπτωση η δήλωση ενός αντικειμένου γίνεται:_
> >
> > ```
> > int main () {
> >    student std1;
> > }
> > ```

## <br></br>

## Λίστα δομών

- Οι λίστες είναι στόιβες τύπου **_LIFO_**. _Εισάγουμε και εξάγουμε από την κορυφή της στόιβας μόνο_.
- Οι λίστες διακρίνονται σε **_μονοδεσμικές_** και _διπλοδεσμικές_.
- Στις **_μονοδεσμικές_** ή **_απλά συνδεδεμένες_** λίστες κάθε αντικείμενο μιας δομής (struct) έχει έναν Pointer τύπου struct που δείχνει στο επόμενο αντικείμενο

```
struct car {
    char plate[10];
    ...
    struct car *nextCar;
}
```

- Η κορυφή της στοίβας **head** είναι ένας **_struct pointer_** ο οποίος καθορίζει το πρώτο στοιχέιο της λίστας

- **_Προσοχή:_** Στον τελευταίο κόμβο της λίστας, ο next pointer είναι **NULL**. Επομένως με ένα while loop μπορούμε να προσπελάσουμε όλα τα στοιχεία μιας λίστας,

### Εύρεση συγκεκριμένου στοιχείου της λίστας

```
#include <stdio.h>
#include <stdlib.h>

// Ρητή δήλωση δομής τύπου Node
typedef struct Node
{
	int code;
	float grd;
	struct Node *next;
} Node;


// Συνάρτηση εύρεσης ενός στοιχείου της λίστα, με κωδικό code
Node* find(int code);

// Η κεφαλή της λίστας head, δηλώνεται ως global μεταβλητή
Node *head;

int main()
{
	Node *ptr;
	int code;

	printf("\nEnter code to search: ");
	scanf("%d", &code);

	ptr = find(code);
	if(ptr == NULL)
		printf("Code:%d doesn’t exist\n", code);
	else
		printf("Code:%d Grade:%.2f\n", ptr->code, ptr->grd);
	return 0;
}

Node* find(int code)
{
    // Struct Pointer για την προσπέλαση των στοιχείων της λίστας
	Node *ptr;

    // Στην αρχή το πρώτο στοιχείο προς προσπέλαση είναι το εκείνο που δείχνει ο Struct Pointer head.
	ptr = head;
	while(ptr != NULL)
	{
		if(ptr->code == code)
			return ptr;
		else
			ptr = ptr->next;
	}
	return NULL;
}

```

### Εισαγωγή στοιχείου στην λίστα

```
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int code;
	float grd;
	struct Node *next;
} Node;

Node *head;

void add_stack(Node *p);

int main()
{
	int i;
	Node n;

	head = NULL;
	for(i = 0; i < 5; i++)
	{
		printf("\nEnter code: ");
		scanf("%d", &n.code);

		printf("Enter grade: ");
		scanf("%f", &n.grd);

		add_stack(&n);
	}
	return 0;
}
```

> _Επειδή η παράμετρος Node \*p γίνεται override σε κάθε επανάληψη του for loop της main (), δεσμεύεται δυναμικά μνήμη στην συνάρτηση add_stack () για την δημιουργία του νέου στοιχείου._
>
> > ```
> > void add_stack(Node *p)
> > {
> > 	Node *new_node;
> > 	new_node = (Node*) malloc(sizeof(Node));
> > 	if(new_node == NULL)
> > 	{
> > 		printf("Error: No memory");
> > 		exit(1);
> > 	}
> >
> > 	new_node->code = p->code;
> > 	new_node->grd = p->grd;
> >
> > 	new_node->next = head;
> > 	head = new_node;
> > }
> >
> > ```

### Διαγραφή στοιχείου από την λίστα

```
void pop()
{
	Node *p;
	p = head->next;
	printf("\nStudent with code = %d is deleted\n", head->code);
	free(head);
	head = p;
}
```

### Τύπωση στοιχείων λίστας

```
void show_stack()
{
	Node *p;

	p = head;
	while(p != NULL)
	{
		printf("C:%d G:%.2f\n\n", p->code, p->grd);
		p = p->next;
	}
}
```

## <br></br>

## Πίνακας δομών

Έστω ο παρακάτω τύπος δομής:

```
struct mystruct {
    int one;
    float two;
};
```

### Δήλωση πίνακα με 100 δομές mystruct

```
struct mystruct array[100];
```

### Δυναμική δέσμευση πίνακα n θέσεων με δομές mystruct

```
int main () {
    struct mystruct *array;
    int n;
    scanf ("Αριθμός θέσεων πίνακα:", &n);

    array = (struct mystruct*) malloc (n * sizeof (struct mystruct));

    ...

    free (array);
    return 0;
}
```

## <br></br>

## Συναρτήσεις

- Εάν ζητείται **_void συνάρτηση_**, τότε οι επιστρεφόμενες τιμές θα πρέπει να είναι αναγκαστικά **Παράμετροι** και **Pointers**, _π.χ._
  > Συνάρτηση findLast() για την εύρεση του τελευταίου στοιχείου μιας λίστας.
  >
  > > Δέχεται ως παράμετρο την κορυφή της λίστας **head** και έναν Pointer **tail** για την αποθήκευση της διεύθυνσης του τελευταίου στοιχείου.
  > >
  > > ```
  > > void findLast(struct mystruct *head, struct mystruct *tail);
  > > ```
