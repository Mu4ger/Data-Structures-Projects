/********************************************************
 * CSC 122
 * Sorting and Algorithm Anlaysis
 * Comparer.hpp
 * 
 * Team Name:
 * Team Members:
 * ******************************************************
*/
#pragma once
#ifndef __COMPARER_HPP__
#define __COMPARER_HPP__

#include <string>
#include "Student.hpp"

class Comparer {
private:
    int compares;
    std::string field;
public:
    Comparer()
    {
        compares = 0;
        field = "id";
    }
    int compare(Student *s1, Student *s2) 
    {
        if (field == "name")
            {
                return compareName (s1,s2);
            }
        else if (field == "id")
            {
                return compareid (s1,s2);
            }      
        else if (field == "email")
            {
                return compareEmail (s1,s2);
            }
        else return 0;
    }

    int getCompares() { 
        return compares;
    }

    void reset() {
        compares = 0;
    }

    void setField(std::string sortField)
    {
        if (sortField == "email" || sortField == "name")
        {
            field = sortField;
        }
        else
        {
            field = "id";
        }
    }

    std::string getField(){
        return field;
    }
    int compareid (Student *s1, Student *s2)
    {
        compares++;
        if (s1->getId() < s2-> getId())
        {
            return -1;
        }
        else if(s1->getId() > s2-> getId())
        {
            return 1;
        }
        else return 0; 
    }
    int compareName(Student *s1, Student *s2)
    {
        compares++;
        if (s1->getName() < s2-> getName())
        {
            return -1;
        }
        else if(s1->getName() > s2-> getName())
        {
            return 1;
        }
        else return 0; 
    }
    int compareEmail(Student *s1, Student *s2)
    {
        compares++;
        if (s1->getEmail() < s2-> getEmail())
        {
            return -1;
        }
        else if(s1->getEmail() > s2-> getEmail())
        {
            return 1;
        }
        else return 0; 
    }
};

#endif 