# OOP midterm exam
#### Fall 2020
#### 12 November 2020, 18:00pm - 21:00pm
----------------------------------------
### Summary:

In this exam, you'll implement a polynomial with single variable in mathematics.

The following are examples of a polynomial with single variable:
```
x³ + 6x - 7         // polynomial 1
x⁸ - 4.5x⁵ + 9x³    // polynomial 2
```

#### Polynomials and Terms
A polynomial can be composed of one or more terms. For instance, there are four terms in the first polynomial above.

As you can see, a term consists of a pair of numbers: the **coefficient** and the **exponent**, which can be represented as (c, e). For instance, x³ can be written as (1, 3) in our program. Similarly, -4.5x⁵ and 5 can be written as (-4.5, 5) and (5, 0). In addition, please don't forget that the constant 0 is also a term.

#### Degree of Polynomials
The degree of a polynomial is the degree of the polynomial's term owning the highest degree with non-zero coefficient. For instance, the degree of the polynomial 1 above is three because the degree of the term that has the highest degree is three.

### Requirements:
- **After cloning your code from gitlab, please put the template into your hw directory, push your code to gitlab and check the result on jenkins first.**
- Please pack your terms into polynomial in **ascending way**. So you won't have to handle the problem of sorting the order of terms.<br/>
examples:
    ```
    x³ + 6x - 7 => { (-7, 0), (6, 1), (0, 2), (1, 3) }
    5x² - 0.8   => { (-0.8, 0), (0, 1), (5, 2) }
    ```
- Please write unit tests in "test/test_term.h" and "test/test_polynomial.h", and implement two classes, the class "Term" in "src/term.h" file and the class "Polynomial" in "src/polynomial.h"
- You have to write a **copy contructor** for class Polynomial.
- Your **destructor** should keep **memory leak** from occurring.
- Please use the code template and make sure that your code should be written in the correct file.
- Please use makefile we provide in the template to compile your code.

### Grading Standard:
- Term::Term() -> 5%
- Term::Term(double, int) -> 5%
- Term Term::operator= -> 5%
- Term Term::operator+ -> 10%
- Term Term::operator* -> 5%
- bool Term::operator== -> 5%
- double Term::getCoefficient() -> 5%
- int Term::getExponent() -> 5%
- double Term::evaulate(double) -> 5%

- Polynomial::Polynomial(Term[], int degree) -> 5%
- Polynomial::Polynomial(Polynomial const &p) -> 5%
- Polynomial::~Polynomial() -> 5%
- Polynomial Polynomial::operator+ -> 10%
- Polynomial Polynomial::operator= -> 5%
- Term Polynomial::getTermByExponent(int) -> 10%
- int Polynomial::getDegree() -> 5%
- double Polynomial::evaulate(double) -> 5%

### Hints:
- You should use **ASSERT_NEAR(expected, actual, delta)** when you assert a double, where delta is the acceptable difference between expected and actual value, you should set delta to 0.001.
- You should use **ASSERT_ANY_THROW(statement)** to test your expection, don't use try catch or you will get 0 point for that sub-problem.

### Notes:
- Please implement your test cases reasonably and use the correct syntax, or you will get 0 point for that sub-problem.
- Please test **exception** (Polynomial::getTermByExponent() and Term::operator+()) if needed.
- There are only four websites allowed to visit: [cplusplus.com](https://www.cplusplus.com/) [cambridge dictionary](https://dictionary.cambridge.org/zht/) [code in class](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f), [Teacher's Homework repo](https://css-gitlab.csie.ntut.edu.tw/qoolili/oop2020f_hw) and your homework repo. You will be considered as cheating if you visit other websites.
