/********************************************************
 * CSC 122
 * Sorting and Algorithm Anlaysis
 * main.cpp
 * 
 * Team Name:
 * Team Members:
 * ******************************************************
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Student.hpp"
#include "StudentList.hpp"
#include "Comparer.hpp"

using namespace std;

/**
 * ----------------------------------------------------
 * forward declaration of test and helper functions
 * ----------------------------------------------------
*/
void testSelectionSort(Comparer &comp);
void testInsertionSort(Comparer &comp);
void testQuickSort(Comparer &comp);

void testSelectionSort(string field);
void testInsertionSort(string field);
void testQuickSort(string field);

void testSelectionSortAverage();
void testInsertionSortAverage();
void testQuickSortAverage();

void printHeader(string message);
void printFooter();
void printCompareSummary(Comparer &comp);
void confirmSorted(StudentList &list, Comparer &comp);
void printBreak(string message);

/**
 * ----------------------------------------------------
 * Average functions
 * COMPLETE THESE FUNCTIONS
 * ----------------------------------------------------
*/
double averageSelectionSort(int n) 
{
        StudentList list = StudentList("student_data.txt");
        Comparer comp = Comparer();
        int count = 0;
       
        for (int i = 0; i<n; i++)
        {
            list.selectionSort(comp);
            count += comp.getCompares();
            comp.reset();
            list.randomize(); 
        }
        double countDouble = static_cast<double>(count);
        return countDouble / n;
}

double averageInsertionSort(int n) 
{
    StudentList list = StudentList("student_data.txt");
        Comparer comp = Comparer();
        int count = 0;
       
        for (int i = 0; i<n; i++)
        {
            list.insertionSort(comp);
            count += comp.getCompares();
            comp.reset();
            list.randomize(); 
        }
        double countDouble = static_cast<double>(count);
        return countDouble / n;
}

double averageQuickSort(int n) 
{
    StudentList list = StudentList("student_data.txt");
        Comparer comp = Comparer();
        int count = 0;
       
        for (int i = 0; i<n; i++)
        {
            list.quicksort(comp);
            count += comp.getCompares();
            comp.reset();
            list.randomize(); 
        }
        double countDouble = static_cast<double>(count);
        return countDouble / n;
}
/**
 * ----------------------------------------------------
 * Main, this drives the test code.
 * ----------------------------------------------------
*/
int main()
{
    // initialize random number generator.
    srand(time(0));

    //################################################
    // Sort testing
    printBreak("Id Sorting");
    testSelectionSort("id");
    testInsertionSort("id");
    testQuickSort("id");
    
    printBreak("Name Sorting");
    testSelectionSort("name");
    testInsertionSort("name");
    testQuickSort("name");

    printBreak("Email Sorting");
    testSelectionSort("email");
    testInsertionSort("email");
    testQuickSort("email");

    /**
     * Some code to test your average functions.
    */
    // double average = averageSelectionSort(10000);
    // cout << "Selection Sort: " << average << endl;
    // average = averageInsertionSort(10000);
    // cout << "Insertion Sort:" << average << endl;
    // average = averageQuickSort(10000);
    // cout << "Quick Sort:" << average << endl;

    //################################################
    // Average testing
    printBreak("Average Compares Testing");
    testSelectionSortAverage();
    testInsertionSortAverage();
    testQuickSortAverage();
    
    // end program
    return 0;
}


/**
 * ----------------------------------------------------
 * ################## Helpers ##################
 * DO NOT MODIFY
 * ----------------------------------------------------
*/
void printHeader(string message){
    cout << "===== ";
    cout << message;
    cout << " =====" << endl;
}

void printFooter()
{
    cout << "----------" << endl;
    cout << endl;
}

void printCompareSummary(Comparer &comp)
{
    int compareCount = comp.getCompares();
    cout << "comparing by: " << comp.getField() << endl;
    cout << "compares: " << compareCount << endl;
}

void confirmSorted(StudentList &list, Comparer &comp)
{
    cout << "isSorted reports:";
    if(list.isSorted(comp)){
        cout << "Sorted!";
    } else {
        cout << "Not Sorted";
    }
    cout << endl;
}

void printBreak(string message){
    cout << "#####|========== ";
    cout << message;
    cout << " ==========|#####" << endl;
}

/**
 * ----------------------------------------------------
 * ################     TESTS    ####################
 * DO NOT MODIFY
 * ----------------------------------------------------
*/
void testSelectionSort(Comparer &comp) {
    printHeader("Selection Sort");
    //----------------------------
    
    StudentList list = StudentList("student_data.txt");
    // algorithm:
        list.selectionSort(comp);

    printCompareSummary(comp);

    //----------------------------
    confirmSorted(list,comp);
    printFooter();
}

void testInsertionSort(Comparer &comp) {
    printHeader("Insertion Sort");
    //----------------------------
    
    StudentList list = StudentList("student_data.txt");
    // algorithm:
        list.insertionSort(comp);
        
    printCompareSummary(comp);

    //----------------------------
    confirmSorted(list,comp);
    printFooter();
}

void testQuickSort(Comparer &comp) {
    printHeader("Quick Sort");
    //----------------------------
    
    StudentList list = StudentList("student_data.txt");
    // algorithm:
        list.quicksort(comp);
        
    printCompareSummary(comp);

    //----------------------------
    confirmSorted(list,comp);
    printFooter();
}

void testSelectionSort(string field) {
    Comparer comp;
    if(field == "id" || field == "name" || field == "email") {
        comp.setField(field);
        testSelectionSort(comp);
    } else {
        cout << "ERROR: no such field for sorting" << endl;
    }
}

void testInsertionSort(string field) {
    Comparer comp;
    if(field == "id" || field == "name" || field == "email") {
        comp.setField(field);
        testInsertionSort(comp);
    } else {
        cout << "ERROR: no such field for sorting" << endl;
    }
}

void testQuickSort(string field) {
    Comparer comp;
    if(field == "id" || field == "name" || field == "email") {
        comp.setField(field);
        testQuickSort(comp);
    } else {
        cout << "ERROR: no such field for sorting" << endl;
    }
}

void testSelectionSortAverage() {
    printHeader("Selection Sort average");
    const double drBible_estimate = 528.00;
    double average = averageSelectionSort(10000);
    if(average > drBible_estimate - 5 && average < drBible_estimate + 5 )
    {
        cout << "Average Test Passed: Estimate in valid range" << endl;
    }
    else
    {
        cout << "Average Test Failed: Estimate NOT in valid range" << endl;
    }
}

void testInsertionSortAverage() {
    printHeader("Insertion Sort average");
    const double drBible_estimate = 206.832;
    double average = averageInsertionSort(10000);
    if(average > drBible_estimate - 5 && average < drBible_estimate + 5 )
    {
        cout << "Average Test Passed: Estimate in valid range" << endl;
    }
    else
    {
        cout << "Average Test Failed: Estimate NOT in valid range" << endl;
    }
}

void testQuickSortAverage() {
    printHeader("Quicksort average");
    const double drBible_estimate = 168.102;
    double average = averageQuickSort(10000);
    if(average > drBible_estimate - 5 && average < drBible_estimate + 5 )
    {
        cout << "Average Test Passed: Estimate in valid range" << endl;
    }
    else
    {
        cout << "Average Test Failed: Estimate NOT in valid range" << endl;
    }
}



