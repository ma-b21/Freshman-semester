#pragma once
#include "CP_Student.h"

class CP_Student
{
public:
    int m_ID;
    int m_score;
public:
    CP_Student(int id = 0, int score = 100)
        :m_ID(id), m_score(score) { }
}; 

extern void gb_swapStudent(CP_Student& a, CP_Student& b);

