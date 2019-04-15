//
//  networkStudent.h
//  C867-ClassRoster-AustinWise
//
//  Created by Austin Wise on 3/26/19.
//  Copyright © 2019 Austin Wise. All rights reserved.
//

#pragma once
#include "student.h"

class NetworkStudent : public Student {
using Student::Student;
    public:
        virtual Degree getDegreeProgram();
        //void print();
    
        //NetworkStudent();
        //NetworkStudent(string, string, string, string, int, int*, Degree);
        //~NetworkStudent();
    private:
        Degree degreeProgram = NETWORK;
};
