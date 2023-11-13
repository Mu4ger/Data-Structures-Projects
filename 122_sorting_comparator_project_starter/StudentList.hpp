/******************************************************
 * CSC 122
 * Sorting and Algorithm Anlaysis
 * StudentList.hpp
 * 
 * Team Name:
 * Team Members:
 * ****************************************************
*/
#pragma once
#ifndef __STUDENTLIST_HPP__
#define __STUDENTLIST_HPP__

#include <fstream>
#include <cstdlib>
#include "Student.hpp"
#include "Comparer.hpp"

class StudentList {
private:
  Student** students;
  int size;
  int capacity;

public:
  StudentList() {
    capacity = 10;
    students = new Student*[capacity];
    size = 0;
  }

  StudentList(string filepath) {
    // open the file stream
    ifstream inStream = ifstream(filepath);
    // total number of students is the first value.
    int startCapacity;
    inStream >> startCapacity;

    // initialize the capacity, array, and size
    capacity = startCapacity;
    students = new Student*[capacity];
    size = 0;

    // loop through student data and insert it into the list.
    for (int i = 0; i < startCapacity; i++) {
      int id;
      string name;
      string email; // read data for one student and insert it.
      inStream >> id >> name >> email;
      insert(id, name, email); // use our nice insert function.
    }
  }

  ~StudentList() {
    for(int i = 0; i < size; i++)
    {
      Student* current = students[i];
      delete current;
    }
    delete[] students;
  }

  int getSize() { return size; }

  bool isFull() { return size == capacity; }

  bool insert(int id, string name, string email) {
    if (isFull()) {
      return false;
    }

    Student* student = new Student(id, name, email);
    students[size] = student;
    size++;
    return true;
  }

  void printAll() {
    cout << "StudentList with ";
    cout << size << "/" << capacity << " students" << endl;
    for (int i = 0; i < size; i++) {
      students[i]->print();
    }
  }

  void exchange(int i, int j) {
    if(i == j){ return; }
    Student *temp = students[i];
    students[i] = students[j];
    students[j] = temp;
  }
  int partition (int start, int end, Comparer &comp)
  {
    Student* pivot = students [start];
    int smallIndex = start;
    for (int index = start+1; index <= end; index++)
      {
        if (comp.compare(students[index], pivot) < 0)
        {
          smallIndex++;
          exchange(smallIndex, index);
        }
      }
      exchange (start, smallIndex);
      return smallIndex;
  }
  void quicksort(int start, int end, Comparer &comp)
  {
    if (start < end)
    {
      int pivotIndex = partition(start,end,comp);
      quicksort(start,pivotIndex - 1, comp);
      quicksort(pivotIndex+1, end, comp);
    }
  }
  void quicksort(Comparer &comp) 
  { 
    quicksort(0,size - 1, comp);
  }

  int findMinIndex(int start, Comparer& comp) 
  {
        int minIndex = start;
        for (int i = start; i < size; i++)
        {
            if (comp.compare(students[i], students[minIndex]) < 0) 
            {
                minIndex = i;
            }
        }
        return minIndex;
    }

  void selectionSort(Comparer &comp) 
  {
    for (int i = 0; i < size; i++) 
    {
            int minIndex = findMinIndex(i, comp);
            if (minIndex != i) 
            {
                exchange(i, minIndex);
            }
        }
  }

  void insertionSort(Comparer &comp) 
  {
    for (int i = 1; i < size; i++) 
    {
      Student* key = students[i];
      int j = i - 1;
        while (j >= 0 && comp.compare(students[j], key) > 0) 
        {
        students[j + 1] = students[j];
        j--;
        }
        students[j + 1] = key;
    }
  }

  bool isSorted(Comparer &comp) 
  { 
    for (int i = 0; i < size - 1; i++) 
    {
            if (comp.compare(students[i], students[i + 1]) > 0) 
            {
                return false;
            }
        }
        return true;
  }

  void randomize()
  {
    for (int i = 0; i < size / 2; i++) 
    {
      int index1 = rand() % size;
      int index2 = rand() % size;
      exchange(index1, index2);
    }
  }
};

#endif