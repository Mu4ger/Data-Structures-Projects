#pragma once
#ifndef __STUDENTLIST_HPP__
#define __STUDENTLIST_HPP__

#include <fstream>
#include "Student.hpp"

class StudentList {
private:
  Student **students;
  int size;
  int capacity;
  int compares;

public:
  StudentList() {
    capacity = 10;
    students = new Student *[capacity];
    size = 0;
    compares = 0;
  }

  StudentList(string filepath) {
    // open the file stream
    ifstream inStream = ifstream(filepath);
    // total number of students is the first value.
    int startCapacity;
    inStream >> startCapacity;

    // initialize the capacity, array, and size
    capacity = startCapacity;
    students = new Student *[capacity];
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
    // ??
  }

  int getSize() { return size; }

  int getComapres() { return compares; }

  void resetCompares() { compares = 0; }

  bool isFull() { return size == capacity; }

  bool insert(int id, string name, string email) {
    if (isFull()) {
      return false;
    }

    Student *student = new Student(id, name, email);
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

  int compare(Student *s1, Student *s2) {
    if (s1->getId() < s2->getId()) {
      return -1;
    } else if (s1->getId() > s2->getId()) {
      return 1;
    } else {
      return 0;
    }
    compares++; 
  }

  void exchange(int i, int j) {
    Student *temp = students[i];
    students[i] = students[j];
    students[j] = temp;
  }

  int partition(int start, int end) {
    // your code here ...
    Student *pivot = students[start];
    int smallIndex = start;
    for (int index = start + 1; index <= end; index++) {
      if (compare(students[index], pivot) < 0) {
        smallIndex++;
        exchange(smallIndex, index);
      }
    }
    exchange(start, smallIndex);
    return smallIndex;
  }

  void quicksort(int start, int end) {
    // cout << start << " " << end << endl;
    if (start < end) {
      int pivotIndex = partition(start, end);
      quicksort(start, pivotIndex - 1);
      quicksort(pivotIndex + 1, end);
    }
  }

  void sort() { quicksort(0, size - 1); }

  int findMin(int start) {
    int minIndex = start;
    for (int i = start; i < size; i++) {
      if (compare(students[minIndex], students[i]) < 0) {
        minIndex = i;
      }
    }
    return minIndex;
  }

  void selectionSort() {
    for (int i = 0; i < size; i++) {
      int index = findMin(i);
      exchange(index, i);
    }
  }
  void insertionSort()
  {
    if (size==1)
    {
      return;
    }
    int endSorted = 1;
      while( endSorted < size )
      {
        int index = endSorted;
        Student* currentStudent = students[index];
        while ( index > 0 &&compare(currentStudent, students [index-1]) == -1 )
          {
            students[index] = students [index -1];
            index--;
          }
        students[index] = currentStudent;
        endSorted++;
      } 
  }
};

#endif