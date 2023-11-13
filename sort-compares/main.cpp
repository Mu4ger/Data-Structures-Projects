#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Student.hpp"
#include "StudentList.hpp"

using namespace std;

int main()
{
    // initialize random number generator.
    srand(time(0));

    StudentList selectionList = StudentList("student_data.txt");
    StudentList quickList = StudentList("student_data.txt");
    StudentList insertionList = StudentList("student_data.txt");

    // selection sort
    selectionList.printAll();
    cout << "-----" << endl;
    selectionList.selectionSort();
    selectionList.printAll();

    //quick sort

    // insertion sort
    
    return 0;
}




