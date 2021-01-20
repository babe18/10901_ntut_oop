## Assignment 5

### Due: 23:59, 14 December 2020 (System will be reopen on 7 December 12:00)

For this assignment, you shuold have (1) src folder (2) test folder (3) bin folder (4) makefile in root folder.

In src -> vector.h

In test -> ut_main.cpp & ut_vector.h

Your ut_main.cpp should be compiled as a runnable with name -> bin/ut_all

### Before starting coding:

You don't need to remove any files from HW04. Continue from your previous files.

### Purpose of this assignment:

Sort the vector in correct order and calculate polygon's area.

### Problems:

In class, you have learned how to use operator overload, copy assignment and calculate are. For this assignment, you need use functions into for **Vector** class, and test it!

Please implement and test the following member functions:

- Vector centroid(Vector vec[],int sides) 	(25 points) 回傳多個 vector 所組成的重心
- distance(Vector u, Vector v)				(25 points) 回傳兩個 vector 的距離
- double area(Vector u, Vector v, Vector w) (25 points) 回傳三個 vector 所圍成的三角形面積
- double area(Vector a[], int sides)		(25 points) 回傳多個 vector 所圍成的多邊形面積
- double perimeter(Vector a[], int sides)	(25 points) 回傳多個 vector 所圍成的多邊形周長

- Your test cases                           (25 points)

Total points: **150**
(For those functions, you have to write at least one test for each scenario(include Exception))

(You need to use the bubbleSort function written in the course instead of std::sort.)

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
3. Please test exception. Hint: ASSERT_ANY_THROW();
