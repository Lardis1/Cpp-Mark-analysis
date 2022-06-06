

#ifndef adt_classInfo
#define adt_classInfo

#include <fstream>
#include <iostream>
#include <map>
using namespace std;


// grade structure

struct grades{
    int grade; // stores int grade value
    string topic; // stores string of what topic it covers
    string assesmentType; // stores the type of assesment

    grades(int grade0, string topic0, string assesmentType0) : grade(grade0), topic(topic0), assesmentType(assesmentType0){};
    // assigns all values through input
};


// Node struct

struct Node {
    grades _grade; // stores a grade block
    Node* _next; // pointer to next node with next grade values
    Node(grades grade0) : _grade(grade0), _next(nullptr) {}; // constructor requires a grade entry, default points to nothing
};


// dll structure
// stores a list of all grade structures, each grade structure has 3 vals

class dll{

private:
    Node* _head; // head pointer node
    int _size; // size of list

public:
    dll() : _head(nullptr), _size(0) {}; // constructor

    bool insert(grades grade0){

        Node* newGrade = new Node(grade0);
        if (_size==0)
        {
            _head = newGrade;
            _size ++;
            return true; // returns true if inserted
        }

        Node* tempNode = _head; // sets a temporary node for iterating equal to head


        // iterates until the temporary node is not pointing to anything
        while (tempNode->_next != nullptr){
            tempNode = tempNode->_next;
        }
        // temporary node is now the last element in the list

        tempNode->_next = newGrade; // set the new last node to the new inserted grade
        _size ++;
        return true;
    }

    // method that will return pointer to a specific grade at an index
    grades* getGrade(int idx){
        // if the index is invalid, return null
        if (idx >= _size){
            return nullptr;
        }

        // if not:
        Node* temp = _head; // temporary pointer, set to head
        for (int i=0; i < idx; ++i)
        {
            temp = temp->_next; // iterate to the correct index
        }

        // temp is now equal to a pointer that points to the proper grade structure
        grades* tempGrade = &temp->_grade; // create a new pointer to a node
        //                  ^ address of grade struct
        // clarity- tempGrade is a pointer to target grade structure
        return tempGrade; // return the pointer to the specific grade structure

    }

    // Accessor
    const int getSize()
    {
        return _size;
    }

};


// class Data

class classData{

private:

    dll _grades; // list of grades
    string _topics[4] = {"C++ Review", "ADT", "Recursion + Big O", "Linked Lists"}; // list of topics
    string _assessmentType[2] = {"CS", "Lab"}; // list of assessment types

public:

    classData(); // constructor
    void printGrades(); // print function for debug
    dll retGradesList();

};

classData::classData()
{

    ifstream fin ("/home/alex/Desktop/Cpp-Mark-analysis/src/Data.txt"); // reads Data file
    int grade, topic, assesstype; // inits temp assignment vars

    _grades=dll(); //  initializes list, defaults to empty list

    while (fin >> grade >> topic >> assesstype)
    {
        // creates new grade struct
        grades newGrade = grades(grade,_topics[topic],_assessmentType[assesstype]);
        // adds it to list
        _grades.insert(newGrade);
    }
    // initializer will create a complete list with all grade structs

}

// print grades
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

dll classData::retGradesList() {
    return _grades;
}



#endif