

#ifndef adt_classInfo
#define adt_classInfo

#include <fstream>
#include <iostream>
#include <map>
using namespace std;



// grade structure
struct grades{
    int grade;
    string topic;
    string assesmentType;

    grades(int grade0, string topic0, string assesmentType0) : grade(grade0), topic(topic0), assesmentType(assesmentType0){};
};


// Node struct
struct Node {
    grades _grade;
    Node* _next;
    Node(grades grade0) : _grade(grade0), _next(nullptr) {};
};


// dll structure
class dll{

private:
    Node* _head;
    int _size;

public:
    dll() : _head(nullptr), _size(0) {};

    bool insert(grades grade0){

        Node* newGrade = new Node(grade0);
        if (_size==0)
        {
            _head = newGrade;
            _size ++;
            return true;
        }

        Node* tempNode = _head;

        while (tempNode->_next != nullptr){
            tempNode = tempNode->_next;
        }

        tempNode->_next = newGrade;
        _size ++;
        return true;
    }

    grades* getGrade(int idx){
        if (idx >= _size){
            return new grades(0, 0, 0);
        }
        Node* temp = _head;
        for (int i=0; i < idx; ++i)
        {
            temp = temp->_next;
        }
        grades* tempGrade = &temp->_grade;
        return tempGrade;
    }

    int getSize()
    {
        return _size;
    }

};


// class Data
class classData{

private:

    dll _grades;
    string _topics[4] = {"C++ Review", "ADT", "Recursion + Big O", "Linked Lists"};
    string _assessmentType[2] = {"CS", "Lab"};

public:

    classData();
    void printGrades();

};

classData::classData()
{
    ifstream fin ("/home/alex/Desktop/Cpp-Mark-analysis/src/Data.txt");
    int grade, topic, assesstype;

    _grades= dll();

    while (fin >> grade >> topic >> assesstype)
    {
        grades newGrade = grades(grade,_topics[topic],_assessmentType[assesstype]);
        _grades.insert(newGrade);
    }

}

void classData::printGrades() {
    int tempSizeVar = _grades.getSize();

    for (int i = 0; i < tempSizeVar; ++i)
    {
        grades* tempGrade = _grades.getGrade(i);
        cout << "Assesment Type: " << tempGrade->assesmentType << "   ";
        cout << "Topic: " << tempGrade->topic << "   ";
        cout << "Grade: " << tempGrade->grade << endl;
    }
}




#endif