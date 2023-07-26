#ifndef COURSE_H
#define COURSE_H

#include <map>
#include <string>

using namespace std;

// forward declaration
class Student;

class Course {
  // Allows Student class to access Course class variables and functions
  friend class Student;

  // ALlows University class to access private Student class variables
  friend class University;

  // Default constructor
  Course() = default;

  // Constructor course number and course name
  Course(string &number, string &name);

  // Add given student to the course, return true if successful
  bool addStudent(Student *student);

  // Removes given student from course, return true if successful
  bool removeStudent(int studentID);

  // Return class list sorted by last name of students
  string getClassListByLastName();

  // Return class list sorted by id of students
  string getClassListByID();

  // Gets course number
  string getNumber() const;

  // Gets course name
  string getName() const;

private:
  // Map containing student id as key and student pointers as value
  map<int, Student *> studentsByID;

  // Map containing student last name as key and student pointers as value
  map<string, Student *> studentsByLastName;

  // Stores course number
  string number;

  // Stores course name
  string name;
};

#endif
