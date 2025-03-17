# Doubly Linked Lists

## Exercise 1:

You are asked to manage a collection of books using a doubly linked list. A book is characterized by its reference, title, price, and type (0 for novel, 1 for others).

1. Define the necessary structures to manage the list of books.
2. Define the function `AddBook` that allows adding a book to the list:
   - If it is a novel, add it at the beginning of the list.
   - Otherwise, add it at the end.
3. Define a function `Display` that allows displaying the list of books.
4. Assume that the list of books is sorted in ascending order by price. Define a function `AddSorted` that allows adding a book to the list while keeping the list sorted.
5. Define a function `DeleteFirst` that allows deleting the first book in the list.
6. Define a function `DeleteLast` that allows deleting the last book in the list.
7. Define a function `DeleteCheap` that allows deleting all books with a price less than 100Dh.
8. Define a function that calculates the number of books with a price exceeding 250Dh.
9. Write the main program to test the different functions.

---

## Exercise 2:

You are asked to manage a collection of students using a doubly linked list. Each student is characterized by their name, CNE (student ID), cycle (P for Preparatory Cycle, I for Engineering Cycle, and A for Others), number of absences, and an array of 5 grades.

1. Define the necessary structures.
2. Define a function `AddEnd` that allows adding a student at the end of the list.
3. Define a function `AddBeginning` that allows adding a student at the beginning of the list.
4. Define a function `AddAfterPrepa` that allows adding a student after the last student in the Preparatory Cycle (see the rules in question 5).
5. Write a function `AddStudent` that allows adding a student to the list while respecting the following rules:
   - If the student belongs to the Preparatory Cycle, insert them at the beginning.
   - If the student belongs to the Engineering Cycle, add them after the last student in the Preparatory Cycle.
   - If the student belongs to Others, insert them at the end of the list.
6. Define a function `Delete` that allows deleting a student identified by their CNE.
7. Write a procedure `Display` that allows displaying the information of students in a given list.
8. Write a function that calculates the total number of absences for the Engineering Cycle.
9. Write a function that allows reversing the elements of the list.
10. Write the `main program` to test the different functions.
