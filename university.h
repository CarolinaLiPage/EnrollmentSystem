#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "course.h"
#include "student.h"
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

class University {

  // Allows EnrollmentSystem class to access University class variables and
  // functions
  friend class EnrollmentSystem;

  // Default constructor
  University() = default;

  // Constructor with university name
  explicit University(string name);

  // Destructor
  ~University();

  // Read the student list for current active university
  // return true if file successfully read
  bool readStudentList(const string &filename);

  // Read the course list for current active university
  // return true if file successfully read
  bool readCourseList(const string &filename);

  // Read the student enrollment information for current active university
  // return true if file successfully read
  bool readEnrollmentInfo(const string &filename);

  // Add student to the given course, return true if successful
  bool addCourse(int studentID, const string &courseNumber);

  // Drop student from given course, return true if successful
  bool dropCourse(int studentID, const string &courseNumber);

  // Return true if student is in the given course
  bool isInCourse(int studentID, const string &courseNumber);

  // Return the courses student is enrolled in
  // The returned courses are separated by commas and sorted by course name
  string getEnrolledCourses(const int &studentID);

  // Return class list sorted by last name of students
  string getClassListByLastName(const string &courseNumber);

  // Return class list sorted by id of students
  string getClassListByID(const string &courseNumber);

  // Return the title for the course
  string getCourseTitle(string const &courseNumber);

  // Returns university name
  string getUniversityName() const;

private:
  // Stores university name
  string name;

  // unordered_map containing student id as key and student pointers as value
  unordered_map<int, Student *> students;

  // unordered_map containing course number as key and course pointers as value
  unordered_map<string, Course *> courses;
};

#endif
