// omer-g@github

/*
    VECTOR OPTIMIZATION

    emplace_back() with rvalue stil calls copy constructor.
    A move constructor allows to point directly to the object and avoid copies.

    reserve() reduces need to resize and copy elements when an element is added.
*/

#include <iostream>
#include <vector>

struct Point {
    float x, y;
    Point(float x, float y): x(x), y(y) {}

    Point(const Point& other): x(other.x), y(other.y) {
        std::cout << "Copied" << std::endl;
    }

    // UNCOMMENT THIS TO OPTIMIZE
    // Point(const Point&& other): x(0), y(0) {}          // Move constructor   
};

int main(){
    // Relevant to C++14
    std::cout << "C++ version: " << __cplusplus << std::endl;
    
    std::vector<Point> v;

    // UNCOMMENT THIS TO OPTIMIZE
    // v.reserve(3);

    v.emplace_back(Point(1,2));
    v.emplace_back(Point(3,4));
    v.emplace_back(Point(5,6));
    // Without optimization - 6 calls to copy constructor
    // With optimization - no calls to copy constructor

    return 0;
}
