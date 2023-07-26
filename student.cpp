#include "student.h"
#include "course.h"
#include <sstream>

using namespace std;

// Constructor with student ID, first name, and last name
Student::Student(int &studentID, string &firstName, string &lastName)
    : firstName{firstName}, lastName{lastName}, studentID{studentID} {}

// Drop student from given course, return true if successful
bool Student::dropCourse(const string &courseNumber) {
  if (enrolledCourses.find(courseNumber) == enrolledCourses.end()) {
    return false;
  }
  enrolledCourses.erase(courseNumber);
  return true;
}

// Add student to the given course, return true if successful
bool Student::addCourse(Course *course) {
  if (enrolledCourses.find(course->getNumber()) == enrolledCourses.end()) {
    enrolledCourses.insert({course->getNumber(), course});
    return true;
  }
  return false;
}

// Return true if student is in the given course
bool Student::isInCourse(const string &courseNumber) const {
  return (enrolledCourses.find(courseNumber) != enrolledCourses.end());
}

// Returns a string of all courses student is enrolled in
string Student::getEnrolledCourses() {
  string enrolled = "[";
  for (auto course = enrolledCourses.begin(); course != enrolledCourses.end();
       course++) {
    if (next(course) == enrolledCourses.end()) {
      enrolled += course->first;
    } else {
      enrolled += course->first + ", ";
    }
  }
  enrolled += "]";
  return enrolled;
}

// Gets student ID
int Student::getID() const { return studentID; }

// Gets student first name
string Student::getFirstName() const { return firstName; }

// Gets student last name
string Student::getLastName() const { return lastName; }

// Operator overload for <<
// Prints all courses student is enrolled in
ostream &operator<<(ostream &out, const Student &student) {
  out << "[";
  for (auto course = student.enrolledCourses.begin();
       course != student.enrolledCourses.end(); course++) {
    if (next(course) == student.enrolledCourses.end()) {
      out << course->first;
    } else {
      out << course->first + ", ";
    }
  }
  out << "]";
  return out;
}
