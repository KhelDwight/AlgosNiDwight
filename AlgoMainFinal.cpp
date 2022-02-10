//For input and output
#include <iostream>

//For other string libraries
#include <string.h>

using namespace std;

//GROUP OF DATA ELEMENTS THAT IS UNDER ONE NAME
struct student
{
    string StudentName;
    int StudentAge;
} list, tempBubble, currentInsertion, tempMerge;

//TO DISPLAY THE UNSORTED AND SORTED STUDENTS BY THEIR AGE.
void display(int element, student list[])
{
    cout << "\nID_No.\t\tAge\t\tName\n";
    for (auto ind = 0; ind < element; ind++)
    {
        cout << "|" << ind + 1 << "|\t\t" << list[ind].StudentAge << "\t\t" << list[ind].StudentName << "\n";
    }
}
//**********SORTING ALGORITHM**********//

//**********BUBBLE SORTING**********//
void BubbleSorting(int element, student list[])
{
    int ind, StdntInd;
    for (ind = 0; ind < element - 1; ind++)
    {
        for (StdntInd = 0; StdntInd < element - ind - 1; StdntInd++)
        {
            if (list[StdntInd].StudentAge > list[StdntInd + 1].StudentAge)
            {
                // Sets temp to list
                tempBubble = list[StdntInd];

                // list is now the value of list + 1
                list[StdntInd] = list[StdntInd + 1];

                // list + 1 will get the value of the temp
                list[StdntInd + 1] = tempBubble;
            }
        }
    }
    display(element, list);
}
//**********INSERTION SORTING**********//
void InsertionSorting(int element, student list[])
{
    int ind, prevStdntInd;

    // ind is the step to the loop
    for (ind = 1; ind < element; ind++)
    {
        // Gets the 2nd element and stores it separately in temp
        currentInsertion = list[ind];
        //Previous Student Index
        prevStdntInd = ind - 1;

        //Move elements of arrarys[0..i-1], that are      |
        //greater than key, to one position ahead of their|
        //current position.                               |

        while (prevStdntInd >= 0 && list[prevStdntInd].StudentAge > currentInsertion.StudentAge)
        {
            list[prevStdntInd + 1] = list[prevStdntInd];

            // Then decrement
            prevStdntInd--;
        }

        //After the while loop, all the higher items have been       |
        //shifted to the right, finally we can store the present item|
        //at index j + 1 equals present.                             |

        list[prevStdntInd + 1] = currentInsertion;
    }
    display(element, list);
}
//**********MERGE SORTING**********//
// Merges two subarrays of students[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void Merging(student list[], int const start, int const mid, int const endpoint, int element)
{
    int left_index = start;
    int right_index = mid + 1;
    int combined_index = start;
    student tempMerge[element];

    while (left_index <= mid && right_index <= endpoint)
    {
        if (list[left_index].StudentAge <= list[right_index].StudentAge)
        {
            tempMerge[combined_index++] = list[left_index++];
        }
        else
        {
            tempMerge[combined_index++] = list[right_index++];
        }
    }

    if (left_index == mid + 1)
    {
        while (right_index <= endpoint)
        {
            tempMerge[combined_index++] = list[right_index++];
        }
    }
    else
    {
        while (left_index <= mid)
        {
            tempMerge[combined_index++] = list[left_index++];
        }
    }

    for (int index = start; index <= endpoint; index++)
    {
        list[index] = tempMerge[index];
    }
}

void MergeSorting(student list[], int const start, int const endpoint, int element)
{
    if (start >= endpoint)
        return; // Returns recursively

    auto mid = (start + endpoint) / 2;
    MergeSorting(list, start, mid, element);
    MergeSorting(list, mid + 1, endpoint, element);
    Merging(list, start, mid, endpoint, element);
}

//MAIN CLASS
int main()
{

    // * elements handles how many will you input.                |
    // * choices handles the type of sorting that you will chose. |
    // * ind is for the index                                     |

    int elements, choices, ind, low = 0, high = 0;
    char again;

    // Prompts the user to enter how many elements.
    cout << "Enter the number of students: ";
    cin >> elements;
    student list[elements];

    // Getting your names and ages that you will input.
    cout << "Input the names and age of the students\n";

    for (ind = 0; ind < elements; ind++)
    {
        cout << "Name: ";
        cin >> list[ind].StudentName;
    }
    for (ind = 0; ind < elements; ind++)
    {
        cout << list[ind].StudentName << "'s age: ";
        cin >> list[ind].StudentAge;
    }
    //For Merge Sorting
    auto arr_size = sizeof(list) / sizeof(list[0]);
    do
    {
        //Ask the user what type of sorting algorithm that they want  |
        //to use to sort the age of the students from ascending order.|
        cout << "\nChoose your Sorting Algorithm:\n1 for Bubble sort\n2 for Insertion sort\n3 for Merge sort\n";
        cin >> choices;

        switch (choices)
        {
        case 1:
            cout << "You chose Bubble Sorting\n";
            printf("\nBubble Sort: \n");
            BubbleSorting(elements, list);
            break;
        case 2:
            cout << "You chose Insertion Sorting\n";
            printf("\nInsertion Sort: \n");
            InsertionSorting(elements, list);
            break;
        case 3:
            cout << "You chose Merge Sorting\n";
            printf("\nMerge Sort: \n");
            MergeSorting(list, 0, arr_size - 1, elements);
            display(arr_size, list);
            break;
        default:
            cout << "You're not the chose one!";
            break;
        }   cout << "Do you want use other type of Sorting Algorithm? (Y/N)\n";
            cin >> again;
    } while (toupper(again) == 'Y'); 
}
// THE END!