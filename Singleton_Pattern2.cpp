#include <bits/stdc++.h>
using namespace std;

// -------------------------
// Singleton Class Definition
// -------------------------
class A
{
public:
    // Static method to access the single instance of class A
    static A *getInstance()
    {
        // If no instance exists yet, create one
        if (ptr == nullptr)
        {
            ptr = new A(); // Only one object of A will be created
        }
        return ptr; // Return the same instance every time
    }

private:
    A() = default; // Private constructor to prevent outside instantiation
    static A *ptr; // Static pointer to hold the single instance
};

// Static member initialization
A *A::ptr = nullptr;

int main()
{
    // Get the singleton instance
    A *ptr = A::getInstance();

    // All calls to A::getInstance() will return the same instance
    // So even if we do:
    A *x = A::getInstance();
    A *y = A::getInstance();

    // x and y will point to the same object
    cout << "Address of x: " << x << endl;
    cout << "Address of y: " << y << endl;
    // Both addresses will be the same => Singleton is working
}

/* ----------------------------------------------------------------
   ✅ THEORY & KEY POINTS — SINGLETON PATTERN IN C++

🔹 1. Can we declare a method before data members in a class?
   - ✅ Yes, C++ allows this.
   - C++ reads the entire class definition as a single unit during parsing.
   - So even if the method is declared before the data member it uses, it works.
   - ❌ However, if you define the method inline inside the class and try to use
     a data member *before* it's declared, it will give a compilation error.

🔹 2. Are we reinitializing the static pointer in main()?
   - ❌ No. The `ptr` declared in `main()` is a **local variable**.
   - It just stores the return value of `A::getInstance()`.
   - The class-level static member `A::ptr` remains unchanged behind the scenes.

🔹 3. Can we create multiple instances of A?
   - ❌ No, we can't.
   - The constructor is `private`, so no one outside the class can do `new A()`.
   - Only `getInstance()` has access to create the object, and it does so **only once**.
   - All subsequent calls return the same pointer.

   ✅ Example:
   ```cpp
   A* x = A::getInstance();
   A* y = A::getInstance();
   // x and y will have the same memory address.
*/