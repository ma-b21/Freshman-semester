#pragma once

#include "CP_Student.h"
#include <cstddef>

class CP_ChainDoubleLink
{
public:
    CP_Student m_data;
    CP_ChainDoubleLink* m_previous; // ָ��ǰһ����㡣
    CP_ChainDoubleLink* m_next;     // ָ���һ����㡣

public:
    CP_ChainDoubleLink() : m_previous( NULL ), m_next(NULL) { }
    ~CP_ChainDoubleLink();
    CP_ChainDoubleLink* mb_createNode();
    void mb_deleteNode(CP_ChainDoubleLink* p);
    CP_ChainDoubleLink* mb_findNodeById(int id);
    int  mb_getNodeNumber();
    void mb_sortById();
    void mb_sortByScore();
}; // ��CP_ChainDoubleLink�������

