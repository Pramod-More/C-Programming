#include <stdio.h>
#include <string.h>

// Define a structure for a book
struct Book {
    int bookID;
    char bookName[100];
    char authorName[100];
    float price;
    float rating;
};
void addBook();
void removeBook(int);
void searchBookByID(int);
void searchBookByName(char*);
void updateBook(int);
void displayTop3ByPrice();
void displayTop3ByRating();
void displayAllBooks();
// Maximum number of books
#define MAX_BOOKS 100

// Global array to store books
struct Book library[MAX_BOOKS];

// Number of books currently in the library
int numBooks = 3;
int main() {
   int choice, bookID;
   char bookName[100];
   struct Book s1;
   struct Book s2;
   struct Book s3;
   
   strcpy(s1.authorName,"rohit");
   s1.bookID=1;
   strcpy(s1.bookName,"history");
   s1.price=89;
   s1.rating=5;
   
    strcpy(s2.authorName,"mohit");
   s2.bookID=2;
   strcpy(s2.bookName,"geography");
   s2.price=90;
   s2.rating=4;
   
   
   strcpy(s3.authorName,"shamit");
   s3.bookID=3;
   strcpy(s3.bookName,"civics");
   s3.price=48;
   s3.rating=3;
   
   library[0]=s1;
   library[1]=s2;
   library[2]=s3;
   
   
   
    while (1) {
        printf("\nBook Management System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Search Book by Book Name\n");
        printf("5. Show Author's Books\n");
        printf("6. Update Book Data\n");
        printf("7. Display Top 3 Books by Price\n");
        printf("8. Display Top 3 Books by Rating\n");
        printf("9. Display All Books\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                printf("Enter Book ID to remove: ");
                scanf("%d", &bookID);
                removeBook(bookID);
                break;
            case 3:
                printf("Enter Book ID to search: ");
                scanf("%d", &bookID);
                searchBookByID(bookID);
                break;
            case 4:
                printf("Enter Book Name to search: ");
                scanf(" %s", bookName);
                searchBookByName(bookName);
                break;
            case 5:
                printf("Enter Author Name to search: ");
                scanf(" %s", bookName);
                // Function to show author's books
                break;
            case 6:
                printf("Enter Book ID to update: ");
                scanf("%d", &bookID);
                updateBook(bookID);
                break;
            case 7:
                displayTop3ByPrice();
                break;
            case 8:
                displayTop3ByRating();
                break;
            case 9:
                displayAllBooks();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}
// Function to add a new book to the library
void addBook() {
    if (numBooks < MAX_BOOKS) {
        struct Book newBook;

        printf("Enter Book ID: ");
        scanf("%d", &newBook.bookID);
        printf("Enter Book Name: ");
        scanf(" %s", newBook.bookName);
        printf("Enter Author Name: ");
        scanf(" %s", newBook.authorName);
        printf("Enter Price: ");
        scanf("%f", &newBook.price);
        printf("Enter Rating: ");
        scanf("%f", &newBook.rating);

        library[numBooks] = newBook;
        numBooks++;

        printf("Book added successfully!\n");
    } else {
        printf("The library is full. Cannot add more books.\n");
    }
}

// Function to remove a book by Book ID
void removeBook(int bookID) {
    int found = 0;
    
    for (int i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            // Move the last book to the position of the removed book and decrease the count
            library[i] = library[numBooks - 1];
            numBooks--;
            found = 1;
            printf("Book removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Book with Book ID %d not found in the library.\n", bookID);
    }
}

// Function to search a book by Book ID
void searchBookByID(int bookID) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            printf("Book Details:\n");
            printf("Book ID: %d\n", library[i].bookID);
            printf("Book Name: %s\n", library[i].bookName);
            printf("Author Name: %s\n", library[i].authorName);
            printf("Price: %.2f\n", library[i].price);
            printf("Rating: %.2f\n", library[i].rating);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with Book ID %d not found in the library.\n", bookID);
    }
}

// Function to search a book by Book Name
void searchBookByName(char bookName[]) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].bookName, bookName) == 0) {
            printf("Book Details:\n");
            printf("Book ID: %d\n", library[i].bookID);
            printf("Book Name: %s\n", library[i].bookName);
            printf("Author Name: %s\n", library[i].authorName);
            printf("Price: %.2f\n", library[i].price);
            printf("Rating: %.2f\n", library[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("Book with the name '%s' not found in the library.\n", bookName);
    }
}

// Function to update book data (price and rating) by Book ID
void updateBook(int bookID) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (library[i].bookID == bookID) {
            printf("Enter updated Price: ");
            scanf("%f", &library[i].price);
            printf("Enter updated Rating: ");
            scanf("%f", &library[i].rating);
            printf("Book data updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with Book ID %d not found in the library. Update failed.\n", bookID);
    }
}

// Function to display the top 3 books based on price
void displayTop3ByPrice() {
    // Sort the library array by price (descending order)
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - i - 1; j++) {
            if (library[j].price < library[j + 1].price) {
                struct Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }

    printf("Top 3 Books by Price:\n");
    for (int i = 0; i < 3 && i < numBooks; i++) {
        printf("Book Name: %s, Price: %.2f\n", library[i].bookName, library[i].price);
    }
}

// Function to display the top 3 books based on rating
void displayTop3ByRating() {
    // Sort the library array by rating (descending order)
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - i - 1; j++) {
            if (library[j].rating < library[j + 1].rating) {
                struct Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }

    printf("Top 3 Books by Rating:\n");
    for (int i = 0; i < 3 && i < numBooks; i++) {
        printf("Book Name: %s, Rating: %.2f\n", library[i].bookName, library[i].rating);
    }
}

// Function to display details of all books in the library
void displayAllBooks() {
    printf("Details of All Books in the Library:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book ID: %d\n", library[i].bookID);
        printf("Book Name: %s\n", library[i].bookName);
        printf("Author Name: %s\n", library[i].authorName);
        printf("Price: %.2f\n", library[i].price);
        printf("Rating: %.2f\n", library[i].rating);
        printf("\n");
    }
}