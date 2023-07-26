#include "university.h"
#include "student.h"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;

// Constructor with university name
University::University(string name) : name{std::move(name)} {}

// Destructor
University::~University() {
  for (auto &student : students) {
    delete student.second;
  }
  for (auto &course : courses) {
    delete course.second;
  }
}

// Read the student list for current active university
// return true if file successfully read
bool University::readStudentList(const string &filename) {
  ifstream input(filename);
  if (!input.is_open()) {
    return false;
  }
  int studentID = 0;
  string firstName;
  string lastName;
  while (input >> studentID >> firstName >> lastName) {
    if (students.find(studentID) == students.end()) {
      students.insert({studentID, new Student(studentID, firstName, lastName)});
    }
  }
  input.close();
  return true;
}

// Read the course list for current active university
// return true if file successfully read
bool University::readCourseList(const string &filename) {
  ifstream input(filename);
  if (!input.is_open()) {
    return false;
  }
  string courseNumber;
  string courseName;
  courseName.erase(courseName.begin(), courseName.end());
  while (input >> courseNumber) {
    getline(input, courseName);
    if (courseName[0] == ' ') {
      courseName = courseName.substr(1, courseName.length() - 1);
    }
    if (courses.find(courseNumber) == courses.end()) {
      courses.insert({courseNumber, new Course(courseNumber, courseName)});
    }
  }
  input.close();
  return true;
}

// Read the student enrollment information for current active university
// return true if file successfully read
bool University::readEnrollmentInfo(const string &filename) {
  ifstream input(filename);
  if (!input.is_open()) {
    return false;
  }
  int studentID = 0;
  string course;
  while (input >> studentID >> course) {
    addCourse(studentID, course);
  }
  input.close();
  return true;
}

// Add student to the given course, return true if successful
bool University::addCourse(int studentID, const string &courseNumber) {
  if ((students.find(studentID) == students.end()) ||
      (courses.find(courseNumber) == courses.end())) {
    return false;
  }
  Student *currStudent = students[studentID];
  Course *currCourse = courses[courseNumber];
  currStudent->addCourse(currCourse);
  currCourse->addStudent(currStudent);
  return true;
}

// Drop student from given course, return true if successful
bool University::dropCourse(int studentID, const string &courseNumber) {
  if ((students.find(studentID) == students.end()) ||
      (courses.find(courseNumber) == courses.end())) {
    return false;
  }
  Student *currStudent = students[studentID];
  currStudent->dropCourse(courseNumber);
  Course *currCourse = courses[courseNumber];
  currCourse->removeStudent(studentID);
  return true;
}

// Return true if student is in the given course
bool University::isInCourse(int studentID, const string &courseNumber) {
  if ((students.find(studentID) == students.end()) ||
      (courses.find(courseNumber) == courses.end())) {
    return false;
  }
  Student *currStudent = students[studentID];
  return currStudent->isInCourse(courseNumber);
}

// Return the courses student is enrolled in
// The returned courses are separated by commas and sorted by course name
string University::getEnrolledCourses(const int &studentID) {
  if (students.find(studentID) == students.end()) {
    return "";
  }
  Student *student = students[studentID];
  return student->getEnrolledCourses();
}

// Return class list sorted by last name of students
string University::getClassListByLastName(const string &courseNumber) {
  return courses[courseNumber]->getClassListByLastName();
}

// Return class list sorted by id of students
string University::getClassListByID(const string &courseNumber) {
  return courses[courseNumber]->getClassListByID();
}

// Return the title for the course
string University::getCourseTitle(string const &courseNumber) {
  if (courses.find(courseNumber) == courses.end()) {
    return "";
  }
  Course *currCourse = courses[courseNumber];
  return currCourse->name;
}

// Returns university name
string University::getUniversityName() const { return name; }
