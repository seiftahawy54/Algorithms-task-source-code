#include <iostream>
#include <algorithm>
#define maxSize 200
#define maxMaxSize 400

using namespace std;

// Divide and conquer solution
int findKthElementUsingDAC(int* firstArray, int* secondArray, int firstStart, int firstEnd, int secondStart, int secondEnd, int key)
{
    // First array base case
    if (firstArray[firstStart] == firstArray[firstEnd])
    {
        return secondArray[key];
    }
    // Second array base case
    if (secondArray[secondStart] == secondArray[secondEnd])
    {
        return firstArray[key];
    }
    // Simple cases to handle
    if (key == 0)
        return min(firstArray[key], secondArray[key]);
 
    // Conquer
    int center1 = (firstEnd - firstStart) / 2;
    int center2 = (secondEnd - secondStart) / 2;

    if (center1 + center2 < key)
    {
        if (firstArray[center1] < secondArray[center2])
            findKthElementUsingDAC(firstArray + center1 + 1, secondArray, firstStart + center1 + 1, firstEnd, secondStart, secondEnd, key - center1 - 1);
        else
            findKthElementUsingDAC(firstArray, secondArray, firstStart, firstEnd, secondStart + center2 + 1, secondEnd, key - center2 - 1);
    }   
    else
    {
        if (firstArray[center1] < secondArray[center2])
            findKthElementUsingDAC(firstArray, secondArray, firstStart, firstEnd, secondStart + center1, secondEnd, key);
        else
            findKthElementUsingDAC(firstArray, secondArray, firstStart + center1, firstEnd, secondStart, secondEnd, key);
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