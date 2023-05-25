#include <stdio.h>
#include <string.h>


struct Teacher {
    char username[50];
    char password[50];
};

struct Student {
    char name[50];
    int roll;
    int account;
    int c_programming;
    int english;
    int project;
    int maths;
    int electronic;
};

int main() {
    FILE *file;
    struct Teacher teacher;
    struct Student student;
    int choice;
    char loginChoice;

    printf("\t\t\t\t\t Are you a Student (S) or a Teacher (T)? ");
    scanf(" %c", &loginChoice);

    if (loginChoice == 'S' || loginChoice == 's') {
        int rollNo;
        printf("Enter your Roll No: ");
        scanf("%d", &rollNo);

        file = fopen("students.txt", "r");
        if (file == NULL) {
            printf("Error opening the file.\n");
            return 1;
        }

         while (fscanf(file,"Name: %s\n Roll: %d\n account: %d\n c_programming: %d\n english: %d\n project: %d\n maths: %d\n electronic: %d\n",
                      student.name, &student.roll, &student.account, &student.c_programming, &student.english,
                      &student.project, &student.maths, &student.electronic) != EOF) {
            if (student.roll == rollNo) {
                printf("Student Details \n");
                printf("Name: %s\n", student.name);
                printf("Roll No: %d\n", student.roll);
                printf("Account Marks: %d\n", student.account);
                printf("C Programming Marks: %d\n", student.c_programming);
                printf("English Marks: %d\n", student.english);
                printf("Project Marks: %d\n", student.project);
                printf("Maths Marks: %d\n", student.maths);
                printf("Electronic Marks: %d\n", student.electronic);
                break;
            
            }
        }
        
printf("\n \n You can see your result");
        fclose(file);
       
    } else if (loginChoice == 'T' || loginChoice == 't') {
        char username[50];
        char password[50];
        int loggedIn = 0;
        int registerChoice;

        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        file = fopen("teachers.txt", "r");
        if (file == NULL) {
            printf("Error opening the file.\n");
            return 0;
        }

        while (fscanf(file, "Username: %s\n Password: %s\n", teacher.username, teacher.password) != EOF) {
            if (strcmp(teacher.username, username) == 0 && strcmp(teacher.password, password) == 0) {
                loggedIn = 1;
                break;
            }
        }

        fclose(file);

        if (!loggedIn) {
            printf("Invalid username or password.\n");

            printf("Do you want to register a new teacher? (1 for Yes / 0 for No): ");
            scanf("%d", &registerChoice);

            if (registerChoice == 1) {
                printf("Register a New Teacher\n");
                file = fopen("teachers.txt", "w");
                if (file == NULL) {
                    printf("Error opening the file.\n");
                    return 1;
                }

                printf("Enter a new username: ");
                scanf("%s", teacher.username);
                printf("Enter a new password: ");
                scanf("%s", teacher.password);

                fprintf(file, "Username: %s\nPassword: %s\n", teacher.username, teacher.password);

                fclose(file);

                printf("Teacher registered successfully.\n");
            }
        }

        printf("<********RESULT MANAGEMENT SYSTEM********>\n\n");
        printf("\t\tWelcome, %s\n\n", username);

        do {
            printf("Menu:\n");
            printf("1. Add new student\n");
            printf("2. search \n");
            printf("3. modify \n");
            printf("4. Display all students\n");
            printf("5. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    file = fopen("students.txt", "a");
                    if (file == NULL) {
                        printf("Error opening the file.\n");
                        return 1;
                    }

                    printf("Add New Student\n");
                    printf("Enter the name: ");
                    scanf("%s", student.name);
                    printf("Enter the roll number: ");
                    scanf("%d", &student.roll);
                    printf("Enter the account marks: ");
                    scanf("%d", &student.account);
                    printf("Enter the C Programming marks: ");
                    scanf("%d", &student.c_programming);
                    printf("Enter the English marks: ");
                    scanf("%d", &student.english);
                    printf("Enter the Project marks: ");
                    scanf("%d", &student.project);
                    printf("Enter the Maths marks: ");
                    scanf("%d", &student.maths);
                    printf("Enter the Electronic marks: ");
                    scanf("%d", &student.electronic);

                    fprintf(file, "Name: %s\n Roll: %d\n account: %d\n c_programming: %d\n english: %d\n project: %d\n maths: %d\n electronic: %d\n",
                            student.name, student.roll, student.account, student.c_programming, student.english,
                            student.project, student.maths, student.electronic);

                    fclose(file);

                    printf("New student added successfully.\n");
                    break;
               
            
                case 2:
                    file = fopen("students.txt", "r");
                    if (file == NULL) {
                        printf("Error opening the file.\n");
                        return 1;
                    }

                    printf("All Students \n");
                    while (fscanf(file, "Name: %s\n Roll: %d\n account: %d\n c_programming: %d\n english: %d\n project: %d\n maths: %d\n electronic: %d\n",
                                  student.name, &student.roll, &student.account, &student.c_programming, &student.english,
                                  &student.project, &student.maths, &student.electronic) != EOF) {
                        printf("Student Details\n");
                        printf("Name: %s\n", student.name);
                        printf("Roll No: %d\n", student.roll);
                        printf("Account Marks: %d\n", student.account);
                        printf("C Programming Marks: %d\n", student.c_programming);
                        printf("English Marks: %d\n", student.english);
                        printf("Project Marks: %d\n", student.project);
                        printf("Maths Marks: %d\n", student.maths);
                        printf("Electronic Marks: %d\n", student.electronic);
                    }

                    fclose(file);
                    break;

                case 3:
                    printf("Logged out successfully.\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
            }

        } while (choice != 5);
    } else {
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}

