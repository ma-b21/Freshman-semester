#pragma once
#include "CP_ChainDoubleLink.h"

class CP_StudentSystem
{
public:
    CP_ChainDoubleLink* m_head;
public:
    CP_StudentSystem() : m_head(NULL) { }
    ~CP_StudentSystem() { delete m_head; }

    void mb_printAllStudent();
    void mb_printMainMenu();
    void mb_findIdbyScore(int Score);
    void mb_deletebyScore(int Score);
    void mb_run();
};
