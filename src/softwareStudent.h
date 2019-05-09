//
//  softwareStudent.h
//  C867-ClassRoster-AustinWise
//
//  Created by Austin Wise on 3/26/19.
//  Copyright © 2019 Austin Wise. All rights reserved.
//

#pragma once
#include "student.h"

class SoftwareStudent : public Student {
using Student::Student;
    public:
        Degree getDegreeProgram();
        //void print();
        
        //SoftwareStudent();
        //SoftwareStudent(string, string, string, string, int, int*, Degree);
        //~SoftwareStudent();
    private:
        Degree DegreeProgram = SOFTWARE;
};
