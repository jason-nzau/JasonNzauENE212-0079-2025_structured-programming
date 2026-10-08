#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    int marks;
    int reg_no;
    char name[50];
    char grade;
    printf("Enter the number of students, N: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        printf("\n===Enter the details of the student %d===\n", i);
        printf("Registration Number: ");
        scanf("%d", &reg_no);
        printf("Name: ");
        scanf("%s", name);
        printf("Marks(0-100): ");
        scanf("%d", &marks);
        if(marks >= 70 && marks <= 100){
            grade = 'A';
        }
        else if(marks >= 60 && marks < 70){
            grade = 'B';
        }
        else if(marks >=50 && marks < 60){
            grade = 'C';
        }
        else if(marks >= 40 && marks < 50){
            grade = 'D';
        }
        else{
            grade = 'F';
        }
        printf("\n------------------------------\n");
        printf("        STUDENT INFORMATION\n");
        printf("\n------------------------------\n");
        printf("Registration No: %d\n", reg_no);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);
        if (marks >= 40){
            printf("Status: Passed\n");
        }
        else{
            printf("Status: Failed\n");
        }
        printf("\n------------------------------\n");

    }


    return 0;
}
