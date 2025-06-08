//-----------------S.O.L.I.D Principles-------------------
// I - Interface Segregation Principle (ISP)
// Clients should not be forced to depend on interfaces they do not use.

#include <bits/stdc++.h>
using namespace std;

/*
class ShapeInterface
{
public:
    virtual int GetArea() = 0; // Pure virtual function for area
    virtual int Volume() = 0;  // Pure virtual function for perimeter
};

class Square : public ShapeInterface
{
public:
    Square(int length) : length_(length) {};

    int GetArea() override
    {
        return length_ * length_; // Area of squarere
    }
    // since square is 2D, volume is not applicable
    // But as Volume is a pure virtual function, we need to implement it
    // hence it will throw an error if called
    // Cliemt should not be forced to implement methods they do not use
    // Square was forced to implement Volume method

private:
    int length_; // Length of the square
};

class Sphere : public ShapeInterface
{
public:
    Sphere(int radius) : radius_(radius) {}

    int GetArea() override
    {
        return 4 * M_PI * radius_ * radius_; // Surface area of sphere
    }

    int Volume() override
    {
        return (4 / 3) * M_PI * radius_ * radius_ * radius_; // Volume of sphere
    }

private:
    int radius_; // Radius of the sphere
};
*/

// we can solve the above problem by segregating the interface into two separate interfaces
// One for 2D shapes and another for 3D shapes
class TwoDimShapeInterface
{
public:
    virtual int GetArea() = 0; // Pure virtual function for area
};
class ThreeDimShapeInterface
{
public:
    virtual int GetArea() = 0;   // Pure virtual function for area
    virtual int GetVolume() = 0; // Pure virtual function for Volume
};

class Square : public TwoDimShapeInterface
{
public:
    Square(int length) : length_(length) {};

    int GetArea() override
    {
        return length_ * length_; // Area of squarere
    }

private:
    int length_; // Length of the square
};

class Sphere : public ThreeDimShapeInterface
{
public:
    Sphere(int radius) : radius_(radius) {}

    int GetArea() override
    {
        return 4 * M_PI * radius_ * radius_; // Surface area of sphere
    }

    int GetVolume() override
    {
        return (4 / 3) * M_PI * radius_ * radius_ * radius_; // Volume of sphere
    }

private:
    int radius_; // Radius of the sphere
};
int main()
{
    Sphere sphere(5);                                        // Create a sphere with radius 5
    cout << "Sphere Area: " << sphere.GetArea() << endl;     // Output area
    cout << "Sphere Volume: " << sphere.GetVolume() << endl; // Output volume
    Square square(4);                                        // Create a square with length 4
    cout << "Square Area: " << square.GetArea() << endl;     // Output area
    return 0;
}