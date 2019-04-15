//
//  student.cpp
//  C867-ClassRoster-AustinWise
//
//  Created by Austin Wise on 3/26/19.
//  Copyright © 2019 Austin Wise. All rights reserved.
//

//#include "pch.h"

#include "student.h"
#include <iostream>
#include <string>

using namespace std;

//Accessor Methods
string Student::getStudentId(){       return studentId; };
string Student::getFirstName(){       return firstName; };
string Student::getLastName(){        return lastName; };
string Student::getEmailAddress(){    return emailAddress; };
int Student::getAge(){                return age; };
int * Student::getDaysToCompletion(){ return daysToCompletion; };
Degree Student::getDegreeProgram(){      return degreeProgram; };


//Mutator Methods
void Student::setStudentId(string studentId){       this->studentId = studentId; };
void Student::setFirstName(string firstName){       this->firstName = firstName; };
void Student::setLastName(string lastName){         this->lastName = lastName; };
void Student::setEmailAddress(string emailAddress){ this->emailAddress = emailAddress; };
void Student::setAge(int age){                      this->age = age; };

void Student::setDaysToCompletion (int* daysToCompletion){
    for(int i = 0; i < 3; i++){
        this->daysToCompletion[i] = daysToCompletion[i];
    }
};

void Student::setDegreeProgram(Degree degreeProgram){ this->degreeProgram = degreeProgram; };

//Constructor
//Student::Student(){}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompletion[3], Degree degreeProgram){
    setStudentId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
    setEmailAddress(emailAddress);
    setAge(age);
    setDaysToCompletion(daysToCompletion);
    setDegreeProgram(degreeProgram);
};

//print
void Student::print(){
    string degree;
    
    if(getDegreeProgram() == 0)
        degree = "SECURITY";
    else if(getDegreeProgram() == 1)
        degree = "NETWORK";
    else if (getDegreeProgram() == 2)
        degree = "SOFTWARE";
    else {
        degree = "OTHER";
    }
    
    cout << getStudentId() << "\n"
    "First Name: " << getFirstName() << "\n"
    "Last Name: " << getLastName() << "\n"
    "Email Address: " << getEmailAddress() << "\n"
    "Age: " << getAge() << "\n"
    "Days to Completion: " << getDaysToCompletion()[0] << ", " << getDaysToCompletion()[1] << ", " << getDaysToCompletion() [2] << "\n"
    "Degree Type: " << degree << endl;
}

//virtual getDegreeProgram
/*
Degree Student::getDegreeProgram(){
    return OTHER;
};
*/

//Destructor
Student::~Student(){};
