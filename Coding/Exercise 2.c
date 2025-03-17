#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct Student {
    char Name[100];
    char CNE[20];
    char Cycle; // P, I, or A
    int Absences;
    float Grades[5];
} Student;

// Structure for a node in the doubly linked list
typedef struct Noeud {
    Student Data;
    struct Noeud* Next;
    struct Noeud* Prev;
} Noeud;

// Type definition for the list
typedef Noeud* List;

// Function to create a new node
List NewElement(Student S) {
    List NewE = (List)malloc(sizeof(Noeud));
    if (NewE == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    } else {
        NewE->Data = S;
        NewE->Next = NULL;
        NewE->Prev = NULL;
        return NewE;
    }
}

// Function to add a student at the end of the list
List AddEnd(List Head, Student S) {
    List NewE = NewElement(S);
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

// Function to add a student at the beginning of the list
List AddBeginning(List Head, Student S) {
    List NewE = NewElement(S);
    if (NewE != NULL) {
        if (Head != NULL) {
            NewE->Next = Head;
            Head->Prev = NewE;
        }
        Head = NewE;
    }
    return Head;
}

// Function to add a student after the last Preparatory Cycle student
List AddAfterPrepa(List Head, Student S) {
    if (Head == NULL) {
        return AddBeginning(Head, S);
    }

    List Temp = Head;
    while (Temp->Next != NULL && Temp->Data.Cycle != 'P') {
        Temp = Temp->Next;
    }

    List NewE = NewElement(S);
    if (NewE != NULL) {
        NewE->Next = Temp->Next;
        NewE->Prev = Temp;
        if (Temp->Next != NULL) {
            Temp->Next->Prev = NewE;
        }
        Temp->Next = NewE;
    }
    return Head;
}

// Function to add a student based on their cycle
List AddStudent(List Head, Student S) {
    if (S.Cycle == 'P') {
        Head = AddBeginning(Head, S);
    } else if (S.Cycle == 'I') {
        Head = AddAfterPrepa(Head, S);
    } else {
        Head = AddEnd(Head, S);
    }
    return Head;
}

// Function to delete a student by CNE
List Delete(List Head, char* CNE) {
    List Temp = Head;
    while (Temp != NULL) {
        if (strcmp(Temp->Data.CNE, CNE) == 0) {
            if (Temp->Prev != NULL) {
                Temp->Prev->Next = Temp->Next;
            } else {
                Head = Temp->Next;
            }
            if (Temp->Next != NULL) {
                Temp->Next->Prev = Temp->Prev;
            }
            free(Temp);
            break;
        }
        Temp = Temp->Next;
    }
    return Head;
}

// Function to display the list of students
void Display(List Head) {
    if (Head == NULL) {
        printf("The list is empty\n");
    } else {
        List Temp = Head;
        while (Temp != NULL) {
            printf("Name: %s, CNE: %s, Cycle: %c, Absences: %d\n", Temp->Data.Name, Temp->Data.CNE, Temp->Data.Cycle, Temp->Data.Absences);
            Temp = Temp->Next;
        }
        printf("\n");
    }
}

// Function to calculate total absences for the Engineering Cycle
int TotalAbsencesEngineering(List Head) {
    int Total = 0;
    List Temp = Head;
    while (Temp != NULL) {
        if (Temp->Data.Cycle == 'I') {
            Total += Temp->Data.Absences;
        }
        Temp = Temp->Next;
    }
    return Total;
}

// Function to reverse the list
List ReverseList(List Head) {
    List Temp = NULL;
    List Current = Head;
    while (Current != NULL) {
        Temp = Current->Prev;
        Current->Prev = Current->Next;
        Current->Next = Temp;
        Current = Current->Prev;
    }
    if (Temp != NULL) {
        Head = Temp->Prev;
    }
    return Head;
}

// Main function to test the different functions
int main() {
    List Head = NULL;

    Student Student1 = {"Alice", "CNE001", 'P', 2, {12, 14, 15, 10, 13}};
    Student Student2 = {"Bob", "CNE002", 'I', 3, {16, 18, 17, 15, 14}};
    Student Student3 = {"Charlie", "CNE003", 'A', 1, {10, 12, 11, 9, 8}};

    Head = AddStudent(Head, Student1);
    Head = AddStudent(Head, Student2);
    Head = AddStudent(Head, Student3);

    printf("Initial list:\n");
    Display(Head);

    Head = Delete(Head, "CNE002");
    printf("List after deleting Bob:\n");
    Display(Head);

    int Absences = TotalAbsencesEngineering(Head);
    printf("Total absences for Engineering Cycle: %d\n", Absences);

    Head = ReverseList(Head);
    printf("List after reversing:\n");
    Display(Head);

    return 0;
}