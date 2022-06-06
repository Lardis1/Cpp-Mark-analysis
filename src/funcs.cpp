//
// Created by alex on 05/06/22.
//
#include "storeData.h"

// cpp file used to manip data and get stats

double getAvg(classData cd)
{
    dll listGrades = cd.retGradesList();
    int sizeTemp = listGrades.getSize();

    double total;

    for (int i=0; i < sizeTemp; ++i){
        grades* currentGradeS = listGrades.getGrade(i);
        total+=currentGradeS->grade;
    }
    return total/sizeTemp;
}

string bestTopic(classData cd)
{
    dll listGrades = cd.retGradesList();
    int sizeTemp = listGrades.getSize();

    string bT="";
    int tempGrade=0;
    int hG=0;

    for (int i=0; i < sizeTemp; ++i){
        grades* currentGradeS = listGrades.getGrade(i);
        tempGrade = currentGradeS->grade;
        if (tempGrade > hG)
        {
            bT = currentGradeS->topic;
            hG = tempGrade;
        }
    }
    return bT;

}

string worstTopic(classData cd)
{
    dll listGrades = cd.retGradesList();
    int sizeTemp = listGrades.getSize();

    string wT="";
    int tempGrade=0;

    int lG=100;

    for (int i=0; i < sizeTemp; ++i){
        grades* currentGradeS = listGrades.getGrade(i);
        tempGrade = currentGradeS->grade;
        if (tempGrade < lG)
        {
            wT = currentGradeS->topic;
            lG = tempGrade;
        }

    }
    return wT;
}

string bestAssessmentType(classData cd)
{
    dll listGrades = cd.retGradesList();
    int sizeTemp = listGrades.getSize();

    string bA="";
    int tempGrade=0;

    int hG=0;

    for (int i=0; i < sizeTemp; ++i){
        grades* currentGradeS = listGrades.getGrade(i);
        tempGrade = currentGradeS->grade;
        if (tempGrade > hG)
        {
            bA = currentGradeS->assesmentType;
            hG = tempGrade;
        }
    }
    return bA;
}

string worstAssessmentType(classData cd)
{
    dll listGrades = cd.retGradesList();
    int sizeTemp = listGrades.getSize();

    string wA="";
    int tempGrade=0;
    int lG=100;

    for (int i=0; i < sizeTemp; ++i){
        grades* currentGradeS = listGrades.getGrade(i);
        tempGrade = currentGradeS->grade;
        if (tempGrade < lG)
        {
            wA = currentGradeS->assesmentType;
            lG=tempGrade;
        }
    }
    return wA;
}
