//
//  roster.h
//  C867-ClassRoster-AustinWise
//
//  Created by Austin Wise on 3/26/19.
//  Copyright © 2019 Austin Wise. All rights reserved.
//

#pragma once

#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"


class Roster {
    public:
        Roster();
        void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
        void remove(string studentId);
        void printAll();
        void printDaysInCourse(string studentId);
        void printInvalidEmails();
        void printByDegreeProgram(Degree degreeProgram);
        ~Roster();
        Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    
    private:
    
};
