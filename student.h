#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <string>

using namespace std;

// forward declaration
class Course;

class Student {

  // Allows Course class to access Student class variables and functions
  friend class Course;

  // ALlows University class to access private Student class variables
  friend class University;

  // Operator overload for <<
  // Prints all courses student is enrolled in
  friend ostream &operator<<(ostream &out, const Student &student);

  // Default constructor
  Student() = default;

  // Constructor with student ID, first name, and last name
  Student(int &studentID, string &firstName, string &lastName);

  // Drop student from given course, return true if successful
  bool dropCourse(const string &courseNumber);

  // Add student to the given course, return true if successful
  bool addCourse(Course *course);

  // Return true if student is in the given course
  bool isInCourse(const string &courseNumber) const;

  // Returns a string of all courses student is enrolled in
  string getEnrolledCourses();

  // Gets student ID
  int getID() const;

  // Gets student first name
  string getFirstName() const;

  // Gets student last name
  string getLastName() const;

private:
  // Map containing course number as key and Course pointers as value
  map<string, Course *> enrolledCourses;

  // Stores student first name
  string firstName;

  // Stores student last name
  string lastName;

  // Stores student id
  int studentID = 0;
};

#endif
