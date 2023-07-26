#include "enrollmentsystem.h"
#include "university.h"
#include <cassert>
#include <cctype>
#include <unordered_map>

using namespace std;

EnrollmentSystem::~EnrollmentSystem() {
  for (auto &university : universities) {
    delete university.second;
  }
}

// Add university to the enrollments system
bool EnrollmentSystem::addUniversity(const string name) {
  if (universities.find(name) == universities.end()) {
    universities.insert({name, new University(name)});
    return true;
  }
  return false;
}

// Set this university as the active university for other functions
bool EnrollmentSystem::setCurrentUniversity(const string &name) {
  auto itr = universities.find(name);
  if (itr == universities.end()) {
    return false;
  }
  currentUniversity = itr->second;
  return true;
}

// Return the current active university name
string EnrollmentSystem::getUniversityName() const {
  if (currentUniversity == nullptr) {
    return "";
  }
  return currentUniversity->getUniversityName();
}

// Read the student list for current active university
// return true if file successfully read
bool EnrollmentSystem::readStudentList(const string &filename) const {
  if (currentUniversity == nullptr) {
    return false;
  }
  return currentUniversity->readStudentList(filename);
}

// Read the course list for current active university
// return true if file successfully read
bool EnrollmentSystem::readCourseList(const string &filename) const {
  if (currentUniversity == nullptr) {
    return false;
  }
  return currentUniversity->readCourseList(filename);
}

// Read the student enrollment information for current active university
// return true if file successfully read
bool EnrollmentSystem::readEnrollmentInfo(const string &filename) {
  if (currentUniversity == nullptr) {
    return false;
  }
  return currentUniversity->readEnrollmentInfo(filename);
}

// Drop student from given course, return true if successful
bool EnrollmentSystem::dropCourse(int studentID,
                                  const string &courseNumber) const {
  if (currentUniversity == nullptr) {
    return false;
  }
  return currentUniversity->dropCourse(studentID, courseNumber);
}

// Add student to the given course, return true if successful
bool EnrollmentSystem::addCourse(int studentID,
                                 const string &courseNumber) const {
  if (currentUniversity == nullptr) {
    return false;
  }
  return currentUniversity->addCourse(studentID, courseNumber);
}

// Return true if student is in the given course
bool EnrollmentSystem::isInCourse(int studentID,
                                  const string &courseNumber) const {
  if (currentUniversity == nullptr) {
    return false;
  }
  return currentUniversity->isInCourse(studentID, courseNumber);
}

// Return the courses student is enrolled in
// The returned courses are separated by commas and sorted by course name
string EnrollmentSystem::getEnrolledCourses(const int &studentID) const {
  if (currentUniversity == nullptr) {
    return "";
  }
  return currentUniversity->getEnrolledCourses(studentID);
}

// Return the title for the course
string EnrollmentSystem::getCourseTitle(const string &courseNumber) const {
  if (currentUniversity == nullptr) {
    return "";
  }
  return currentUniversity->getCourseTitle(courseNumber);
}

// Return class list sorted by last name of students
string EnrollmentSystem::getClassListByLastName(const string &courseNumber) {
  if (currentUniversity == nullptr) {
    return "";
  }
  return currentUniversity->getClassListByLastName(courseNumber);
}

// Return class list sorted by id of students
string EnrollmentSystem::getClassListByID(const string &courseNumber) {
  if (currentUniversity == nullptr) {
    return "";
  }
  return currentUniversity->getClassListByID(courseNumber);
}
