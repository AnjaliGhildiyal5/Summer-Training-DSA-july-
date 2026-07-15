#include <stdio.h>

//input marks
void inputMarks(int marks[], int n)
{
    int i;

    printf("\nEnter marks of %d students:\n", n);
    for(i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

//display all marks
void displayMarks(int marks[], int n)
{
    int i;

    printf("\n--- Marks of All Students ---\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d : %d\n", i + 1, marks[i]);
    }
}

//lowest mark
int lowestMark(int marks[], int n)
{
    int i, lowest = marks[0];

    for(i = 1; i < n; i++)
    {
        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

//highest mark
int highestMark(int marks[], int n)
{
    int i, highest = marks[0];

    for(i = 1; i < n; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

//calc average
float averageMarks(int marks[], int n)
{
    int i, sum = 0;

    for(i = 0; i < n; i++)
    {
        sum += marks[i];
    }

    return (float)sum / n;
}

int main()
{
    int marks[100];
    int n, choice;

    do
    {
        printf("Enter the number of students (1-100): ");
        scanf("%d", &n);
        printf("\n--------------------------------------\n");

        if(n < 1 || n > 100)
        {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
        }

    } while(n < 1 || n > 100);

    // Input 
    inputMarks(marks, n);

    do
    {
        printf("\n--------- Student Marks Management System ---------\n");
        printf("1. Display All Marks\n");
        printf("2. Display Lowest Mark\n");
        printf("3. Display Highest Mark\n");
        printf("4. Display Average Marks\n");
        printf("5. Exit\n");
        printf("\n----------------------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                displayMarks(marks, n);
                break;

            case 2:
                printf("Lowest Mark = %d\n", lowestMark(marks, n));
                break;

            case 3:
                printf("Highest Mark = %d\n", highestMark(marks, n));
                break;

            case 4:
                printf("Average Marks = %.2f\n", averageMarks(marks, n));
                break;

            case 5:
                printf("The End\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}