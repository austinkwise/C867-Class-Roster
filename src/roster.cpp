//
//  roster.cpp
//  C867-ClassRoster-AustinWise
//
//  Created by Austin Wise on 3/26/19.
//  Copyright © 2019 Austin Wise. All rights reserved.
//

#include "roster.h"
//#include "pch.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Austin,Wise,awise38@wgu.edu,24,14,38,22,SOFTWARE"
};

int main(){
    cout<<"========Student Info========= \n";
    cout << "C867 Scripting and Programming - Applications \n";
    cout << "Language Used: C++ \n";
    cout << "Student ID: 001083734 \n";
    cout << "Name: Austin Wise \n";
    
    cout << "\n";
    
    Roster classRoster;
    Degree degreeProgram;
    
    //Insert student data into class roster array
    for (int i = 0; i < sizeof(studentData)/sizeof(studentData[i]); i++){
        string dataInsert;
        string arrayLine[9];
        string indString = studentData[i];
        istringstream studentString(indString);
        
        int z = 0;
        while (getline(studentString, dataInsert, ',')){
            arrayLine[z] = dataInsert;
            z++;
        }
        
        if(arrayLine[8] == "SECURITY")
            degreeProgram = SECURITY;
        else if(arrayLine[8] == "SOFTWARE")
            degreeProgram = SOFTWARE;
        else if(arrayLine[8] == "NETWORK")
            degreeProgram = NETWORK;
        else{
            degreeProgram = OTHER;
        }
        
        classRoster.add(arrayLine[0], arrayLine[1], arrayLine[2], arrayLine[3], stoi(arrayLine[4]), stoi(arrayLine[5]), stoi(arrayLine[6]), stoi(arrayLine[7]), degreeProgram);
    }
    
    //methods for rubric
    classRoster.printAll();
    
    cout << "\n";
    
    classRoster.printInvalidEmails();
    
    cout << "\n";
    
    for (int i = 0; i < sizeof(classRoster.classRosterArray)/sizeof(classRoster.classRosterArray[i]); i++){
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    cout << "\n";
    
    classRoster.remove("A3");
    
    cout << "\n";
    
    classRoster.remove("A3");
    
    cout << "\n";
    
    classRoster.~Roster();
    
    return 0;
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysToCompletion1, int daysToCompletion2, int daysToCompletion3, Degree degreeProgram) {
    
    int completedDays[3] = {daysToCompletion1, daysToCompletion2, daysToCompletion3};
    
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++){
        if(classRosterArray[i] == nullptr){
            switch (degreeProgram){
                case NETWORK:
                    classRosterArray[i] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, completedDays, degreeProgram);
                    break;
                case SECURITY:
                    classRosterArray[i] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, completedDays, degreeProgram);
                    break;
                case SOFTWARE:
                    classRosterArray[i] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, completedDays, degreeProgram);
                    break;
                default:
                    break;
            
            }
            break;
        }
    }
};

Roster::Roster(){};
Roster::~Roster(){};

void Roster::printAll(){
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++){
        if (classRosterArray[i] != nullptr){
            classRosterArray[i]->print();
        }
        
    }
}


bool validEmail (string studentEmail){
    if (studentEmail.find("@") != string::npos
        &&
        studentEmail.find(".") != string::npos
        &&
        studentEmail.find(" ") == string::npos){
        return true;
    }
    else{
        return false;
    }
}

void Roster::printInvalidEmails(){
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++){
        if((classRosterArray[i] != nullptr) && (!validEmail(classRosterArray[i]->getEmailAddress()))){
            cout << classRosterArray[i]->getStudentId()
            << " " << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
}

void Roster::printDaysInCourse(string studentId){
    float avg = 0;
    int z = 3;
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
        if((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentId() == studentId)) {
            int *daysInCourse = classRosterArray[i]->getDaysToCompletion();
            for (int x = 0; x < z; x++) {
                avg += daysInCourse[x];
            }
            
            cout << "Student Id: " << classRosterArray[i]->getStudentId() << endl;
            cout << "Average days in courses: " << (avg / z) << "\n";
            break;
        }
    }
}

void Roster::printByDegreeProgram(Degree degreeProgram){
    for(int i = 0; i < 5; i++){
        if(classRosterArray[i]->getDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
}

void Roster::remove(string studentId){
    bool removeStudent = false;
    for (int i = 0; i < sizeof(classRosterArray)/sizeof(classRosterArray[i]); i++){
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentId() == studentId)){
            classRosterArray[i] = nullptr;
            removeStudent = true;
            break;
        }
    }
        if (removeStudent == false){
            cout << "No Student ID for: " << studentId << endl;
        }
        else{
            cout << "Removing student ID for: " << studentId << endl;
        }
    }
