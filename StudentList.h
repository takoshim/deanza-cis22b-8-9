#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

class StudentList {
  private:
    struct ListNode {
      Student stu;
      ListNode * next;
    };

  public:
    StudentList();
    void displayList() const;
    void insertNode(Student dataIn);
    bool deleteNode(string target);
    ~StudentList();
};

#endif