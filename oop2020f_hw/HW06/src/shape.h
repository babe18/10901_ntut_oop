#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

class Shape{
public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
};

template <class RandomAccessIterator, class Condition>
std::vector<Shape *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
{
    std::vector<Shape *> v;
    for(RandomAccessIterator j = begin; j != end; j++)
        if (cond(*j))
        {
            v.push_back(*j);
        }
    return v;
}

#endif
