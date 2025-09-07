

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
    int id;
    char name[20];
    int age;
    float gpa;
    struct node* next;
};

struct node* head = NULL;

void insertNode(int id, char name[20], int age, float gpa) {
    struct node* newnode;
    struct node* last;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->age = age;
    newnode->gpa = gpa;
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
        newnode->next = NULL;
    }
    printf("student added \n\n");
}

void display(int id) {
    struct node* currentNode = head;
    bool found = false;

    if (head == NULL) {
        printf("no student found \n");
        return;
    }

    while (currentNode != NULL) {
        if (currentNode->id == id) {
            printf("ID: %d  ||  Name: %s  ||  Age: %d  ||  GPA: %.2f \n",
                   currentNode->id, currentNode->name,
                   currentNode->age, currentNode->gpa);
            found = true;
            break;
        }
        currentNode = currentNode->next;
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void search(int ID) {
    struct node* searchID = head;
    while (searchID != NULL) {
        if (ID == searchID->id) {
            printf("ID found\n");
        }
        searchID = searchID->next;
    }
}

void updateByID(int id, char newname[20], int newage, float newgpa) {
    struct node* update;
    update = head;
    while (update != NULL) {
        if (id == update->id) {
            strcpy(update->name, newname);
            update->age = newage;
            update->gpa = newgpa;

            printf("New Name is %s   New Age is %d   New GPA is %.2f \n",
                   newname, newage, newgpa);
        }
        update = update->next;
    }
}

void calcAverageGPA() {
    struct node* average;
    float sum = 0;
    int count = 0;
    float averageGPA;
    average = head;
    while (average != NULL) {
        sum = sum + average->gpa;
        average = average->next;
        count = count + 1;
    }
    if (count > 0) {
        averageGPA = sum / count;
        printf("average gpa = %.2f \n", averageGPA);
    } else {
        printf("No students to calculate average GPA.\n");
    }
}

void HighestGPA() {
    if (head == NULL) {
        printf("No students found.\n");
        return;
    }

    struct node* High = head;
    struct node* Highest = head->next;
    while (Highest != NULL) {
        if (Highest->gpa > High->gpa) {
            High = Highest;
        }
        Highest = Highest->next;
    }
    printf("Highest GPA student = %.2f \n", High->gpa);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    int choice;
    int id;
    char name[20];
    int age;
    float gpa;
    char newname[20];
    int newage;
    float newgpa;

    do {
        printf("To add a new student press 1 \n");
        printf("To search for a student press 2 \n");
        printf("To update student information press 3 \n");
        printf("To display student information by ID press 4 \n");
        printf("To calculate average GPA press 5 \n");
        printf("To display Highest GPA press 6 \n");
        printf("To exit press 0 \n\n");

        scanf("%d", &choice);
        printf("-------------------------------------\n");

        switch (choice) {
            case 1:
                printf("Enter ID: \n");
                scanf("%d", &id);
                printf("Enter Name: \n");
                scanf("%s", name);
                printf("Enter Age :  \n");
                scanf("%d", &age);
                printf("Enter GPA: \n");
                scanf("%f", &gpa);

                insertNode(id, name, age, gpa);
                printf("-------------------------------------\n");
                break;

            case 2:
                printf("Enter ID :  \n");
                scanf("%d", &id);
                search(id);
                printf("-------------------------------------\n");
                break;

            case 3:
                printf("Enter student ID :  \n");
                scanf("%d", &id);
                printf("Enter New Name : \n");
                scanf("%s", newname);
                printf("Enter New Age : \n");
                scanf("%d", &newage);
                printf("Enter New GPA : \n");
                scanf("%f", &newgpa);
                updateByID(id, newname, newage, newgpa);
                printf("-------------------------------------\n");
                break;

            case 4:
                printf("Enter ID of student to display: \n");
                scanf("%d", &id);
                display(id);
                printf("-------------------------------------\n");
                break;

            case 5:
                calcAverageGPA();
                printf("-------------------------------------\n");
                break;

            case 6:
                HighestGPA();
                printf("-------------------------------------\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf(" Invalid \n");
        }
    } while (choice != 0);

    return 0;
}
