#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

/////////////////////// STRATEGY PATTERN EXAMPLE ///////////////////////

// ----------------------- Strategy Interface ----------------------------
// Defines the interface for all concrete sorting strategies.
class SortingStrategy
{
public:
    virtual void Sort(std::vector<int> &data) const = 0; // Pure virtual function
    virtual ~SortingStrategy() = default;                // Virtual destructor for proper cleanup
};

// ---------------------- Bubble Sort Strategy ---------------------------
// One concrete strategy that implements Bubble Sort
class BubbleSortStrategy : public SortingStrategy
{
public:
    void Sort(std::vector<int> &data) const override
    {
        int n = data.size();
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < n - i - 1; ++j)
            {
                if (data[j] > data[j + 1])
                {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// ---------------------- Quick Sort Strategy ----------------------------
// Another concrete strategy that implements Quick Sort
class QuickSortStrategy : public SortingStrategy
{
public:
    void Sort(std::vector<int> &data) const override
    {
        Quicksort(data, 0, data.size() - 1);
    }

private:
    void Quicksort(std::vector<int> &data, int low, int high) const
    {
        if (low < high)
        {
            int pi = Partition(data, low, high); // Partition index
            Quicksort(data, low, pi - 1);
            Quicksort(data, pi + 1, high);
        }
    }

    int Partition(std::vector<int> &data, int low, int high) const
    {
        int pivot = data[high]; // Choosing the last element as pivot
        int i = low - 1;
        for (int j = low; j < high; ++j)
        {
            if (data[j] < pivot)
            {
                ++i;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
};

// -------------------------- Context Class -----------------------------
// Context maintains a reference to a strategy object
// and delegates sorting to the strategy instance.
class Sorter
{
private:
    SortingStrategy *strategy_; // Pointer to current sorting strategy

public:
    // Constructor accepts a strategy object
    explicit Sorter(SortingStrategy *strategy) : strategy_(strategy) {}

    // Allows changing the strategy at runtime
    void SetStrategy(SortingStrategy *strategy) { strategy_ = strategy; }

    // Delegates sorting behavior to the strategy object
    void Sort(std::vector<int> &data) const { strategy_->Sort(data); }
};

int main()
{
    std::vector<int> data = {34, 7, 23, 32, 5, 62};

    // Using Bubble Sort strategy
    BubbleSortStrategy *bubble_sort = new BubbleSortStrategy();
    Sorter *sorter = new Sorter(bubble_sort); // Context is using Bubble Sort now
    sorter->Sort(data);

    std::cout << "Bubble Sorted data: ";
    for (const int &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Switch to Quick Sort strategy
    data = {34, 7, 23, 32, 5, 62}; // Reset data
    QuickSortStrategy *quick_sort = new QuickSortStrategy();
    sorter->SetStrategy(quick_sort); // Changing strategy at runtime
    sorter->Sort(data);

    std::cout << "Quick Sorted data: ";
    for (const int &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// 🧠 STRATEGY DESIGN PATTERN (Behavioral Pattern)
//
// ➤ Purpose: Define a family of algorithms (strategies), encapsulate each one,
//   and make them interchangeable. This lets the algorithm vary independently
//   from clients that use it.
//
// ➤ Use Case: Here, we have different sorting algorithms like Bubble Sort and
//   Quick Sort. The client (Sorter) can switch between them at runtime.
//
// ➤ Benefits:
//   - Promotes Open/Closed Principle (add new strategies without changing code).
//   - Makes the algorithm easily swappable.
//   - Separates "how" an algorithm is implemented from "when" it is used.
///////////////////////////////////////////////////////////////////////////////