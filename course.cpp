#include "course.h"
#include "student.h"
#include <algorithm>
#include <cassert>
#include <sstream>

using namespace std;

// Constructor course number and course name
Course::Course(string &number, string &name) : number{number}, name{name} {}

// Add given student to the course, return true if successful
bool Course::addStudent(Student *student) {
  if (studentsByID.find(student->getID()) == studentsByID.end()) {
    studentsByID.insert({student->getID(), student});
    studentsByLastName.insert({student->getLastName(), student});
    return true;
  }
  return false;
}

// Removes given student from course, return true if successful
bool Course::removeStudent(int studentID) {
  if (studentsByID.find(studentID) == studentsByID.end()) {
    return false;
  }
  const string studentLastName = studentsByID[studentID]->getLastName();
  studentsByID.erase(studentID);
  studentsByLastName.erase(studentLastName);
  return true;
}

// Return class list sorted by last name of students
string Course::getClassListByLastName() {
  string students = "[";
  for (auto student = studentsByLastName.begin();
       student != studentsByLastName.end(); student++) {
    if (next(student) == studentsByLastName.end()) {
      students += student->second->getLastName() + ", " +
                  student->second->getFirstName() + " (" +
                  to_string(student->second->getID()) + ")";
    } else {
      students += student->second->getLastName() + ", " +
                  student->second->getFirstName() + " (" +
                  to_string(student->second->getID()) + "), ";
    }
  }
  students += "]";
  return students;
}

// Return class list sorted by id of students
string Course::getClassListByID() {
  string students = "[";
  for (auto student = studentsByID.begin(); student != studentsByID.end();
       student++) {
    if (next(student) == studentsByID.end()) {
      students += student->second->getLastName() + ", " +
                  student->second->getFirstName() + " (" +
                  to_string(student->second->getID()) + ")";
    } else {
      students += student->second->getLastName() + ", " +
                  student->second->getFirstName() + " (" +
                  to_string(student->second->getID()) + "), ";
    }
  }
  students += "]";
  return students;
}

// Gets course number
string Course::getNumber() const { return number; }

// Gets course name
string Course::getName() const { return name; }
