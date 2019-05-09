//
//  student.h
//  C867-ClassRoster-AustinWise
//
//  Created by Austin Wise on 3/26/19.
//  Copyright © 2019 Austin Wise. All rights reserved.
//

#pragma once

#include "degree.h"

#include <string>
#include <vector>

using namespace std;

class Student {
public:
    //accessors
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToCompletion();
    //Degree getDegreeType();
    
    //mutators
    void setStudentId(string);
    void setFirstName(string);
    void setLastName(string);
    void setEmailAddress(string);
    void setAge(int);
    void setDaysToCompletion(int*);
    void setDegreeProgram(Degree);
    
    //constructor
    //Student();
    Student(string, string, string, string, int, int completedDays[3], Degree);
    
    //virtual print
    virtual void print();
    
    //destructor
    ~Student();
    
    //virtual getDegreeProgram();
    virtual Degree getDegreeProgram();
    
private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToCompletion[3];
    Degree degreeProgram;
};
