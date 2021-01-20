## Assignment 4

~~### Due: 23:59, 27 November 2020 (System will be reopen on 11/21 00:00)~~

### Due: 11:59, 28 November 2020 (System is reopened)

For this assignment, you shuold have (1) src folder (2) test folder (3) bin folder (4) makefile in root folder.

In src -> vector.h

In test -> ut_main.cpp & ut_vector.h

Your ut_main.cpp should be compiled as a runnable with name -> bin/ut_all

### Before starting coding:

1. Before starting coding, using **git rm** to remove file from previous homework.

	git rm src/*

	git rm test/*

2. Commit the changes to local repository

	git commit -am "remove HW03"

3. Push changes to remote

	git pull

	git push

4. Add & Commit & Push files of HW03

	git add src/*

	git add test/*

	git commit -am "HW04"

	git push

Note: If you have redone git init, you need to do git pull to sync your local repository with the remote one

### Purpose of this assignment:

Due to the not so good outcomes from the midterm, students shuold practice more for the operator overload, copy assignment and area.

### Problems:

In class, you have learned how to use operator overload, copy assignment and calculate are. For this assignment, you need use functions into for **Vector** class, and test it!

Please implement and test the following member functions: (如果 vertor 如法相加減 需丟 exception)

- int dim()									(5 points) 回傳 vector 的 dimension
- double & at(int i)						(5 points) 回傳 vector 的第 i 的 element
- subtract(Vector v)                        (5 points) 以 member function 方式進行 兩個向量相減
- add(Vector v)                             (5 points) 以 member function 方式進行 兩個向量相加
- operator = (Vector v)                     (20 points) Copy Assignment
- operator - (Vector v)                     (20 points) Operator Overloadding 兩個向量相減
- operator + (Vector v)                     (20 points) Operator Overloadding 兩個向量相加
- double length()							(5 points) 回傳 vector 的長度

- Your test cases                           (25 points)

Total points: **110**
(For those functions, you have to write at least one test for each scenario(include Exception))

We will provide the prototype of **Vector** class as follow for this assignment.


**src/vector.h**

	#ifndef VECTOR_H
	#define VECTOR_H
	#include<iostream>
	#include<cmath>
	class Vector {
	public:
		Vector(double v[], int dim) {...}

		Vector(Vector const & v){...}

		// destructor
		~Vector() {...}

		// constant member function
		int dim() const{...}

		double & at(int i) const{...}

		void subtract(Vector const & v){...}

		void add(Vector const & v){...}

		Vector & operator = (Vector const & u){...}

		Vector operator - (Vector const & v) const{...}

		Vector operator + (Vector const & v) const{...}

		double length() const {...}

	private:
		int _dim;
		double * _v;
		void copy(int dim, double v[]){...}
	};

	#endif

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. Please test exception for operator -, +. Hint: ASSERT_ANY_THROW();
