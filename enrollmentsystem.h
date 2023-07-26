#ifndef ENROLLMENTSYSTEM_H
#define ENROLLMENTSYSTEM_H

#include "university.h"
#include <string>
#include <unordered_map>

using namespace std;

class EnrollmentSystem {

public:
  // Default constructor
  EnrollmentSystem() = default;

  // EnrollmentSystem(EnrollmentSystem &enrollmentSystem);

  ~EnrollmentSystem();
  // Add university to the enrollments system
  bool addUniversity(string name);

  // Set this university as the active university for other functions
  bool setCurrentUniversity(const string &name);

  // Return the current active university name
  string getUniversityName() const;

  // Read the student list for current active university
  // return true if file successfully read
  bool readStudentList(const string &filename) const;

  // Read the course list for current active university
  // return true if file successfully read
  bool readCourseList(const string &filename) const;

  // Read the student enrollment information for current active university
  // return true if file successfully read
  bool readEnrollmentInfo(const string &filename);

  // Drop student from given course, return true if successful
  bool dropCourse(int studentID, const string &courseNumber) const;

  // Add student to the given course, return true if successful
  bool addCourse(int studentID, const string &courseNumber) const;

  // Return true if student is in the given course
  bool isInCourse(int studentID, const string &courseNumber) const;

  // Return the courses student is enrolled in
  // The returned courses are separated by commas and sorted by course name
  string getEnrolledCourses(const int &studentID) const;

  // Return the title for the course
  string getCourseTitle(const string &courseNumber) const;

  // Return class list sorted by last name of students
  string getClassListByLastName(const string &courseNumber);

  // Return class list sorted by id of students
  string getClassListByID(const string &courseNumber);

private:
  // current active university
  University *currentUniversity = nullptr;

  // Store of known universities
  unordered_map<string, University *> universities;
};

#endif
