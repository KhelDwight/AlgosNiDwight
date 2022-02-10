#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int age;
    char name[30];
} student[10], tempAgeName, tempAgeName2;

int main()
{
    int age[10], loop = 0, n = 10, opt = 0, a = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, t = 0, flag, swapAge;
    char swapName[n][10];

    printf("Sorting Algorithm\n");

    //Input Name and Age
    printf("Enter Name:\n");
    for (loop = 0; loop < 10; loop++)
    {
        scanf("%s", student[loop].name);
    }
    for (loop = 0; loop < 10; loop++)
    {
        printf("Enter %s Age:\n", student[loop].name);
        scanf("%d", &student[loop].age);
    }

    //Sorting Option
    printf("\nChoose your Sorting Option:\n");
    printf("\nType 1 (for Bubble Sort), 2 (for Insertion Sort), 3 (for Merge Sort)\n");
    scanf("%d", &opt);

    //Sorting Implementation
    switch (opt)
    {
        //--------------------------------------------------------------------------------//
    case 1: // Bubble Sort
        for (c = 0; c < n - 1; c++)
        {
            for (d = 0; d < n - c - 1; d++)
            {
                if (student[d].age > student[d + 1].age)
                {
                    tempAgeName = student[d];
                    student[d] = student[d + 1];
                    student[d + 1] = tempAgeName;
                }
            }
        }
        printf("\nSorted List of Age in Ascending Order\n");
        for (a = 0; a < 10; a++)
        {
            printf("%s\t%d\n", student[a].name, student[a].age);
        }
        break;
        //---------------------------------------------------------------------------------
    case 2: // Insertion Sort
        for (h = 1; h <= n - 1; h++)
        {
            tempAgeName2 = student[h];
            for (i = h - 1; i >= 0; i--)
            {
                if (student[i].age > tempAgeName2.age)
                {
                    student[i + 1] = student[i];
                    flag = 1;
                }
                else
                    break;
            }
            if (flag)
            {
                student[i + 1] = tempAgeName2;
            }
        }
        printf("\nSorted List of Age in Ascending Order\n");
        for (i = 0; i < 10; i++)
        {
            printf("%s\t%d\n", student[i].name, student[i].age);
        }
        break;
        //---------------------------------------------------------------------------------
    case 3: // Merge Sort

        break;
        //---------------------------------------------------------------------------------
    default:
        printf("\nInvalid Input!");
        break;
    }
    //---------------------------------------------------------------------------------
    return 0;
}