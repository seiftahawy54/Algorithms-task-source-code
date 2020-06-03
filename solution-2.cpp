#include <iostream>
#include <algorithm>
#define maxSize 200
#define maxMaxSize 400

using namespace std;


int findKthElementUsingDAC(int* first, int* second, int startFirst, int EndFirst, int startSecond, int endSecond, int key)
{
    // First array base case
    if (startFirst == EndFirst)
    {
        return second[key];
    }
    // Second array base case
    if (startSecond == endSecond)
    {
        return first[key];
    }

    // Conquer
    int center1 = (EndFirst - startFirst) / 2;
    int center2 = (endSecond - startSecond) / 2;

    if (center1 + center2 < key)
    {
        if (first[center1] < second[center2])
            findKthElementUsingDAC(first + center1 + 1, second, startFirst + center1 + 1, EndFirst, startSecond, endSecond, key - center1 - 1);
        else
            findKthElementUsingDAC(first, second + center2 + 1, startFirst, EndFirst, startSecond + center2 + 1, endSecond, key - center2 - 1);
    }
    else
    {
        if (first[center1] < second[center2])
            findKthElementUsingDAC(first, second, startFirst, EndFirst, startSecond, startSecond + center2, key);
        else
            findKthElementUsingDAC(first, second, startFirst, startFirst + center1, startSecond, endSecond, key);
    }
}

int main()
{
    int a[maxSize], b[maxSize], aSize = 0, bSize = 0, kth;
    cout << "Enter first array size: " << endl;
    cin >> aSize;
    cout << "Enter second array size: " << endl;
    cin >> bSize;
    cout << "Enter first array: " << endl;
    for (int i = 0; i < aSize; i++)
        cin >> a[i];
    cout << "Enter second array: " << endl;
    for (int i = 0; i < bSize; i++)
        cin >> b[i];
    cout << "Enter kth element to search: " << endl;
    cin >> kth;

    int kthelement = findKthElementUsingDAC(a, b, 0, aSize, 0, bSize, kth-1);

    cout << "The " << kth << "th number is: " << kthelement << endl;

    return 0;
}