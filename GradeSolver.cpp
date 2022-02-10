#include <iostream>

using namespace std;

int main()
{
double prelim, midterm, finals,result=0 ;

cout << "Enter prelim grade: " << endl;
cin >> prelim;
cout << "Enter midterm grade: " << endl;
cin >> midterm;
cout << "Enter endterm grade: " << endl;
cin >> finals;

result= (prelim * 0.20) + (midterm * 0.30) + (finals * 0.50);

cout << "Final Grade: " << result << endl;
return 0;
}