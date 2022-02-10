/*
 * 3 CS1
 * @Author 
 *      Bueno, Nathanael
 *      Hinggan, Mutya
 *      Paunlagui, John Moises
 *      Tolentino, Charles Justine
 */
#include <iostream>
#include <limits>
using namespace std;

// student Data structure blueprint
class student
{
private:
    string studentName;
    int studentAge;

public:
    string getStudentName()
    {
        return studentName;
    }

    int getStudentAge()
    {
        return studentAge;
    }

    void setStudentName(string name)
    {
        this->studentName = name;
    }

    void setStudentAge(int age)
    {
        this->studentAge = age;
    }
};

// Function declaration
void displayStudent(student students[], int item, int isBefore);
void algoStep(student students[], int items, int index);
void bubbleSortStudentsAccordingToAge(student students[], int item);
void insertionSortStudentsAccordingToAge(student students[], int items);
void mergeStudentsAccordingToAge(student students[], int const left, int const mid, int const right, int items);
void mergeSortStudentsAccordingToAge(student students[], int const begin, int const end, int items);

// Driver code
int main()
{
    /*
     * items handles how many items. 
     * index for indexing            
     * inStudentAge for setting the age
     * optionChosen handles the type of algo to choose                        
     */
    int items, index, inStudentAge, optionChosen;
    // inStudent for setting the name
    string inStudentName;
    // repeat??
    char again;
    // Prompts the user to enter how many elements.
    cout << "Enter the number of students you would like to input? ";
    cin >> items;

    // Sets the array of students on how many items
    student students[items];

    do
    {
        // Getting the names
        cout << "\nPlease state the name of the students\n";
        for (index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "] Name: ";
            cin >> inStudentName;
            students[index].setStudentName(inStudentName);
        }
        // Getting the Age with their names indicated
        cout << "\nPlease state the age of the students\n";
        for (index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "] " << students[index].getStudentName() << "'s age is: ";
            cin >> inStudentAge;
            students[index].setStudentAge(inStudentAge);
        }

        // For Merge Sort
        auto studentsSize = sizeof(students) / sizeof(students[0]);

        /*
         * Ask the user what type of sorting algorithm they want to use to sort 
         * the age of the students from ascending order.                        
         */
        cout << "\nWhat sorting algorithm do you want to use??\n1 for Bubble sort\n2 for Insertion sort\n3 for Merge sort\n";
        cin >> optionChosen;

        // Depends
        switch (optionChosen)
        {
        case 1:
            cout << "Algorithm: Bubble sort\n\nBefore Sorting: \n";
            displayStudent(students, items, 0);
            cout << "\nProcess on each iteration...\n";
            bubbleSortStudentsAccordingToAge(students, items);
            break;
        case 2:
            cout << "Algorithm: Insertion sort\n\nBefore Sorting: \n";
            displayStudent(students, items, 0);
            cout << "\nProcess on each iteration...\n";
            insertionSortStudentsAccordingToAge(students, items);
            break;
        case 3:
            cout << "Algorithm: Merge sort\n\nBefore Sorting: \n";
            displayStudent(students, items, 0);
            cout << "\nProcess on each iteration...\n";
            mergeSortStudentsAccordingToAge(students, 0, studentsSize - 1, items);
            displayStudent(students, studentsSize, 1);
            break;
        default:
            break;
        }

        // To try other sorting algorithm
        cout << "\nDo you want to try other sorting algorithm [Y,N]? ";
        cin >> again;
    } while (again == 'Y' || again == 'y');
    cout << "Program Exited...";
    return 0;
}

/**************************************
 * DISPLAYS UNSORTED AND SORTED ARRAY *
 **************************************/
void displayStudent(student students[], int items, int isBefore)
{
    if (isBefore == 0)
    {
        cout << "\nNo.\t\tAge\t\tName\n";
        for (auto index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "]\t\t" << students[index].getStudentAge() << "\t\t" << students[index].getStudentName() << endl;
        }
    }
    else
    {
        cout << "\nAfter Sorting: \n";
        cout << "\nNo.\t\tAge\t\tName\n";
        for (auto index = 0; index < items; index++)
        {
            cout << "[" << index + 1 << "]\t\t" << students[index].getStudentAge() << "\t\t" << students[index].getStudentName() << endl;
        }
    }
}

/**********************
 * DISPLAYS THE STEPS *
 **********************/
void algoStep(student students[], int items)
{

    for (int j = 0; j < items; j++)
    {
        cout << "[" << students[j].getStudentAge() << "-" << students[j].getStudentName() << "]"
             << "\t";
    }
    cout << endl;
}

/***************
 * BUBBLE SORT *
 ***************/
void bubbleSortStudentsAccordingToAge(student students[], int items)
{
    int index, compareStundents;
    //
    student temp;
    for (index = 0; index < items; index++)
    {
        algoStep(students, items);
        for (compareStundents = 0; compareStundents < items - index - 1; compareStundents++)
        {
            if (students[compareStundents].getStudentAge() > students[compareStundents + 1].getStudentAge())
            {
                // Sets temp to students
                temp = students[compareStundents];
                // students is now the value of students + 1
                students[compareStundents] = students[compareStundents + 1];
                // students + 1 will get the value of the temp
                students[compareStundents + 1] = temp;
            }
        }
    }

    displayStudent(students, items, 1);
}

/******************
 * INSERTION SORT *
 ******************/
void insertionSortStudentsAccordingToAge(student students[], int items)
{
    int index, prevStudentIndex;
    student currentStudent;
    // index is the step to the loop
    for (index = 1; index < items; index++)
    {
        // Gets the 2nd element and stores it separately in temp
        currentStudent = students[index];
        // Previous Index
        prevStudentIndex = index - 1;

        /*
         * Move elements of students[0..i-1], that are       
         * greater than currentStudent, to one position ahead of their
         * currentStudent position                                 
         */
        while (prevStudentIndex >= 0 && students[prevStudentIndex].getStudentAge() > currentStudent.getStudentAge())
        {
            students[prevStudentIndex + 1] = students[prevStudentIndex];
            // Then decrement
            prevStudentIndex--;
        }
        /* 
         * After the while loop, all the greater items have been       
         * shifted to the right, finally we can store the current item 
         * at index prevStudentIndex + 1 equals current                               
         */
        students[prevStudentIndex + 1] = currentStudent;
        algoStep(students, items);
    }
    displayStudent(students, items, 1);
}

/**************
 * MERGE SORT *
 **************/
// Merges two subarrays of students[].
// First subarray is students[begin..mid]
// Second subarray is students[mid+1..end]
void mergeStudentsAccordingToAge(student students[], int const left, int const mid, int const right, int items)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    student leftArray[subArrayOne],
        rightArray[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = students[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = students[mid + 1 + j];

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne].getStudentAge() <= rightArray[indexOfSubArrayTwo].getStudentAge())
        {
            students[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            students[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
        algoStep(students, items);
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        students[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        algoStep(students, items);
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        students[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        algoStep(students, items);
    }
}

// begin is for left index and end is
// right index of the sub-array
// of students to be sorted */
void mergeSortStudentsAccordingToAge(student students[], int const begin, int const end, int items)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSortStudentsAccordingToAge(students, begin, mid, items);
    mergeSortStudentsAccordingToAge(students, mid + 1, end, items);
    mergeStudentsAccordingToAge(students, begin, mid, end, items);
}

/************
 * END LINE *
 ************/