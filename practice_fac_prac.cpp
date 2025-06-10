#include <bits/stdc++.h>
using namespace std;

class ShapeInterface
{
public:
    virtual void Draw() = 0; // Pure vir fuc
};

class Circle : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "CIRCLE" << endl;
    }
};

class Square : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "Square" << endl;
    }
};

class Cube : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "CUBE" << endl;
    }
};

class Sphere : public ShapeInterface
{
public:
    void Draw() override
    {
        cout << "SPHERE" << endl;
    }
};

class ShapeFactory
{
public:
    // Factory method to create shapes based on string input
    virtual ShapeInterface *GetShape(const string &str) = 0;
};

class ShapeFactory2d : public ShapeFactory
{
public:
    ShapeInterface *GetShape(const string &str)
    {
        if (str == "Circle")
        {
            return new Circle();
        }
        else if (str == "Square")
        {
            return new Square();
        }
        return nullptr;
    }
};

class ShapeFactory3d : public ShapeFactory
{
public:
    ShapeInterface *GetShape(const string &str)
    {
        if (str == "Cube")
        {
            return new Cube();
        }
        else if (str == "Sphere")
        {
            return new Sphere();
        }
        return nullptr;
    }
};

int main()
{
    string shape, dim;
    cout << "Enter 2D or 3D dim" << endl;
    cin >> dim;

    cout << "Enter shape" << endl;
    cin >> shape;

    ShapeFactory *fact = nullptr;
    if (dim == "2D")
    {
        fact = new ShapeFactory2d();
    }
    else if (dim == "3D")
    {
        fact = new ShapeFactory3d();
    }
    else
    {
        cout << "Invalid dim!" << endl;
        return 1;
    }

    ShapeInterface *shapeObj = fact->GetShape(shape);

    if (shapeObj)
    {
        shapeObj->Draw();
    }
    else
    {
        cout << "Unknown shape!" << endl;
    }

    // Clean up
    delete shapeObj;
    delete fact;

    return 0;
}