#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
#include "Student.h"

class StudentList {
private:
  
  struct ListNode
  {
    Student stu;
    ListNode *next;
  };

  ListNode *head;
  int count;

public:
  StudentList();
  int getCount() const {return count;};
  void displayList() const;
  void insertNode(Student dataIn);
  bool deleteNode(std::string target);
  ~StudentList();
};

#endif