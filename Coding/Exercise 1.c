#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a book
typedef struct Book {
    char Reference[40];
    char Title[100];
    float Price;
    int Type; 
} Book;

// Structure for a node in the doubly linked list
typedef struct Noeud {
    Book Data;
    struct Noeud* Next;
    struct Noeud* Prev;
} Noeud;

// Type definition for the list
typedef Noeud* List;

// Function prototypes
List NewElement(Book B);
List AddBeginning(List Head, Book B);
List AddEnd(List Head, Book B);
List AddBook(List Head, Book B);
void Display(List Head);
List DeleteFirst(List Head);
List DeleteLast(List Head);
List DeleteCheap(List Head);
int CountExpensive(List Head);

// Function to create a new node
List NewElement(Book B) {
    List NewE = (List)malloc(sizeof(Noeud));
    if (NewE == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    } else {
        NewE->Data = B;
        NewE->Next = NULL;
        NewE->Prev = NULL;
        return NewE;
    }
}

// Function to add a node at the beginning of the list
List AddBeginning(List Head, Book B) {
    List NewE = NewElement(B);
    if (NewE != NULL) {
        if (Head != NULL) {
            NewE->Next = Head;
            Head->Prev = NewE;
        }
        Head = NewE;
    }
    return Head;
}

// Function to add a node at the end of the list
List AddEnd(List Head, Book B) {
    List NewE = NewElement(B);
    if (NewE != NULL) {
        if (Head == NULL) {
            Head = NewE;
        } else {
            List Temp = Head;
            while (Temp->Next != NULL) {
                Temp = Temp->Next;
            }
            Temp->Next = NewE;
            NewE->Prev = Temp;
        }
    }
    return Head;
}

// Function to add a book based on its type
List AddBook(List Head, Book B) {
    if (B.Type == 0) {
        Head = AddBeginning(Head, B);
    } else {
        Head = AddEnd(Head, B);
    }
    return Head;
}

// Function to display the list
void Display(List Head) {
    if (Head == NULL) {
        printf("The list is empty\n");
    } else {
        List Temp = Head;
        while (Temp != NULL) {
            printf("Reference: %s, Title: %s, Price: %.2f, Type: %d\n", Temp->Data.Reference, Temp->Data.Title, Temp->Data.Price, Temp->Data.Type);
            Temp = Temp->Next;
        }
        printf("\n");
    }
}

// Function to delete the first node in the list
List DeleteFirst(List Head) {
    if (Head != NULL) {
        List Temp = Head;
        Head = Head->Next;
        if (Head != NULL) {
            Head->Prev = NULL;
        }
        free(Temp);
    }
    return Head;
}

// Function to delete the last node in the list
List DeleteLast(List Head) {
    if (Head != NULL) {
        if (Head->Next == NULL) {
            free(Head);
            Head = NULL;
        } else {
            List Temp = Head;
            while (Temp->Next != NULL) {
                Temp = Temp->Next;
            }
            Temp->Prev->Next = NULL;
            free(Temp);
        }
    }
    return Head;
}

// Function to delete all books with a price less than 100Dh
List DeleteCheap(List Head) {
    List Temp = Head;
    while (Temp != NULL) {
        if (Temp->Data.Price < 100) {
            if (Temp->Prev != NULL) {
                Temp->Prev->Next = Temp->Next;
            } else {
                Head = Temp->Next;
            }
            if (Temp->Next != NULL) {
                Temp->Next->Prev = Temp->Prev;
            }
            List ToDelete = Temp;
            Temp = Temp->Next;
            free(ToDelete);
        } else {
            Temp = Temp->Next;
        }
    }
    return Head;
}

// Function to count the number of books with a price exceeding 250Dh
int CountExpensive(List Head) {
    int Count = 0;
    List Temp = Head;
    while (Temp != NULL) {
        if (Temp->Data.Price > 250) {
            Count++;
        }
        Temp = Temp->Next;
    }
    return Count;
}

// Main function to test the different functions
int main() {
    List Head = NULL;
    Book Book1 = {"REF001", "The Little Prince", 150.0, 0};
    Book Book2 = {"REF002", "1984", 300.0, 1};
    Book Book3 = {"REF003", "The Lord of the Rings", 50.0, 0};

    Head = AddBook(Head, Book1);
    Head = AddBook(Head, Book2);
    Head = AddBook(Head, Book3);

    printf("Initial list:\n");
    Display(Head);

    Head = DeleteCheap(Head);
    printf("List after deleting cheap books:\n");
    Display(Head);

    int ExpensiveCount = CountExpensive(Head);
    printf("Number of books with price exceeding 250Dh: %d\n", ExpensiveCount);

    return 0;
}