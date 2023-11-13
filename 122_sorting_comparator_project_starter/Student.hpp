/******************************************************
 * CSC 122
 * Sorting and Algorithm Anlaysis
 * StudentList.hpp
 * 
 * STARTER CODE: DO NOT MODIFY
 * ****************************************************
*/
#pragma once
#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <string>
#include <iostream>

using namespace std;

class Student
{
    private:

    int id;
    string name;
    string email;

    public:
    
    Student() {
        id = 0;
        name = "";
        email = "";
    }

    Student(int inId, string inName, string inEmail) {
        id = inId;
        name = inName;
        email = inEmail;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getEmail() {
        return email;
    }

    void print() {
        cout << "Student{" << id << ", " << name;
        cout << ", " << email << "}" << endl;
    }
};

#endif