# OOP Final exam
#### Fall 2020
#### 14 Janurary 2020, 18:00pm - 21:00pm
----------------------------------------
**For this exam, use the given code template to implement your classes and functions. You will implement four classes in folder ```src\```: ```Binary.h```, ```uChar.h```, ```uShort.h```, ```uInt.h```, ```sInt.h``` and some utility functions in ```util.h```. Partial test code has been written for you and can be found in the folder ```test\``` with ```ut_binary.h``` for testing  ```Binary```,  ```ut_numeric.h``` for ```uChar,``` ```uShort,``` ```uInt,``` and ```sInt,``` and ```ut_util.h``` for the utility functions. The compiled binary file should be ```ut_all```.**

### [Link to Jenkins](https://css-lab.csie.ntut.edu.tw/)

### Total Grade:

110

### Problem:

In this exam, you will implement a basic numeric systems that includes binary in class ```Binary```, unsigned char in ```uChar```, unsigned short integers in ```uShort```, unsigned integers in ```uInt```, and signed integers in ```sInt```.

Where:

- ```Binary``` numbers only use _binary digits (bits)_ 0 and 1. A binary number can have any number of bits, for example 01001 is a binary number of 5 bits. 代表 1 個或是多個 bit 的數值

- ```uChar``` represents positive decimal numbers with a length of 8-bits. 代表 8 個 bits 的 unsigned char

- ```uShort``` represents positive decimal numbers with a length of 16-bits. 代表 16 個 bits 的 unsigned short

- ```uInt``` represents positive decimal numbers with a length of 32-bits. 代表 32 個 bits 的 unsigned int

- ```sInt``` represents positive or negative decimal numbers with a length of 32-bits. 代表 32 個 bits 的 signed int

### Program Specification:

Here are the main points:

- Class ```Binary``` has a constructor that takes an array of integers and its length, and throws an exception if any bit is not 0 or 1:

- In real world, the least significant is the rightmost bit. 注意：真實世界中，最小 bit 是在最右邊
```real world bits
0,1,1,0,0,0,1
```

- In your program, the least significant bit of the brinay shuold be at the index 0 of array. 注意：在程式中，最小 bit 是在 index 0
```c++
int b1[] = {1,0,0,0,1,1,0};
Binary b(b1, 7);
b.toDec(); // output should be 49
```

- The decimal classes ```uChar, uShort, uInt``` and ```sInt``` each has a constructor that takes a ```Binary``` as input, and throws an exception if the length of ```Binary``` is _too long_ to fit in the decimal number. To do this, each of decimal classes has a public static function ```canConvert``` that returns true if input ```Binary``` can be converted to that type;

- You will implement a template function ```findAll``` that finds binary numbers in a random access container that matches the given condition;
```c++
std::vector<Binary*> bins = {...};
//example 1
std::vector<Binary*> result = findAll(bins.begin(), bins.end(), [](Binary *b){
  return b->toDec()<=29555;
});//fina binarys that decimal value less or equal to 29555
//example 2
std::vector<Binary*> result = findAll(bins.begin(), bins.end(), [](Binary *b){
  return uShort::canConvert(*b);
});//fina binarys that can be convert to uShort
```

- You will also implement a template function ```convertAll``` that converts any matched binary numbers in a ```std::vector``` to the specified type;
```c++
//example
std::vector<Binary*> bins = {...};
std::vector<uShort> result = convertAll<uShort>(bins); //convert all binary that match the requirement of uShort to uShort
```

- Your **destructors** must keep **memory leak** from occurring.

- You must use **test fixtures** for the tests you write.

### Detailed grading rubrics and test scenarios:

**class Binary**

```Binary::Binary()```
  - the default constructor of class Binary (bits = nullptr and size = 0)

```Binary::Binary(int bits[], int size)```
  - the required constructor of class Binary
  - throw exception if any input number is not 0 or 1 or size is less than 0 (4%)

```Binary(Binary const & b), Binary & operator=(Binary const & b)```
  - copy constructor and copy assignment.

```Binary::~Binary()```
  - the destructor of class Binary

```int Binary::at(int i) const```
  - get the bit at location i
  - throw if input i is out of range (4%)

```unsigned int Binary::toDec() const```
  - convert binary to decimal (4%)

```friend ostream & operator << (ostream & output, const Binary & bin)```
  - output from binary to string (10%)
  - output shuold be in real world format 注意：真實世界中，最小 bit 是在最右邊
  - example
```
int b1[] = {0,1,1,0,0,0,0,0} -> {0,0,0,0,0,1,1,0}
```

```friend istream & operator >> (istream & input, Binary & bin)```
  - input to binary from string (10%)
  - input shuold be in real world format 注意：真實世界中，最小 bit 是在最右邊
  - example
```
{0,0,0,0,0,1,1,0} -> int b1[] = {0,1,1,0,0,0,0,0};
```

```Binary Binary::fillWithZero(int n) const``` 幫 binary bits 由左邊補零
  - Fill zero in front of binary to given size(5%), 
  
  - In real-world example 注意：真實世界中，最小 bit 是在最右邊
```
0,1,1,0 -> fillWithZero(8) -> 0,0,0,0,0,1,1,0
```

  - In your program 注意：在程式中，最小 bit 是在 index 0
```c++
int array[] = {0,1,1,0}; // index 0 is the least significant bit
Binary b1(array, 4);
Binary b2 = b1.fillWithZero(8); // the array in b2 shuold be {0,1,1,0,0,0,0,0} after this line
```

  - throw exception if given size is smaller then original binary size(5%)

**class uChar**

```static bool uChar::canConvert(Binary const & bits)```
  - check if input binary matches the requirement of uChar(size<=8)(3%)

```uChar::uChar(Binary const & bits)```
  - accept a binary (3%)
  - throw exception if binary does not meet the specification (3%)

```char Char::toChar()```
  - convert to the type char of C/C++ (3%)

**class uShort**

```static bool uShort::canConvert(Binary const & bits)```
  - check if input binary matches the requirement of uShort(size<=16)(3%)

```uShort::uShort(Binary const & bits)```
  - accept a binary (3%)
  - throw exception if binary does not meet the specification (3%)

```unsigned short uShort::toDec()```
  - convert to unsigned short(3%)

**class uInt**

```static bool uInt::canConvert(Binary const & bits)```
  - check if input binary matches the requirement of uInt(size<=32)(3%)

```uInt::uInt(Binary const & bits)```
  - accept a binary (3%)
  - throw exception if binary does not meet the specification (3%)

```unsigned int uInt::toDec()```
  - convert to unsigned int(3%)

**class sInt** (must derived from class uInt)

You should call uInt::canConvert to check if input binary matches the requirement of sInt

```sInt::sInt(char sign, Binary const & bits)```
  - sign is either "+" for positive or "-" for negative
  - accept a binary
  - throw exception if binary does not meet the specification (3%)

```long long int sInt::toDec()```
  - convert to signed long long int (3%)

```void sInt::fromString(stringstream & input)```
  - convert to signed int (6%)
  - Format -> Signe (+/-) number of bits {binary array} 注意：真實世界中，最小 bit 是在最右邊
```
+ 4 {1,1,1,0}
```
  - Seperate by blanks

**util**

```C++
template <class RandomAccessIterator, class Condition>
std::vector<Binary*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
```
 - find all binaries that meet the given condition(10%)
 - you should test at last two different conditions

```C++
template <class T>
std::vector<T> convertAll(std::vector<Binary*> const & bins)
```

  - convert the binaries to the given type(10%)
  - you should test conversion to at last two different types

### Hints:
- You should use **ASSERT_ANY_THROW(statement)** to test your exceptions, don't use try catch or you will get 0 point for that sub-problem.
- Use of lambda to test your ```findAll``` is encouraged but not required. You can still use pointer to function or object covered in class.

### Notes:
- Please implement your test cases reasonably and use the correct syntax, or you will get 0 point for that sub-problem.
- There are only four websites allowed to visit: [cplusplus.com](https://www.cplusplus.com/) [cambridge dictionary](https://dictionary.cambridge.org/zht/) [code in class](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/oop2020s) and your homework repo. You will be considered as cheating if you visit other websites.
