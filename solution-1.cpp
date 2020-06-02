#include <iostream>
#include <algorithm>
#define maxSize 200
#define maxMaxSize 400

using namespace std;

// Brute force solution
// Merging two arrays in one.
void mergeTwoArraysInOne(int first[], int second[], int third[], int fs, int ss, int ts)
{
    for (int i = 0, j=0, k=0; i < ts;)
    {
        if (first[k] < second[j])
        {
            third[i++] = first[k];
            k++;
        }
        else
        {
            third[i++] = second[j];
            j++;
        }
    }
}

// Search in brute force way
int kthSmallestUsingBruteForce(int arr[], int arrsize, int kthelement)
{
    int position = 0;
    for (int i = 0; i < arrsize; i++)
    {
        if (kthelement == arr[i])
        {
            return position;
        }
        else
        {
            position++;
        }
    }

    return -1;
}

int main()
{
    int fs, ss, ts, first[maxSize], second[maxSize], third[maxMaxSize], inkth, theFinalelem;
    cout << "Enter first size: " << endl;
    cin >> fs;
    cout << "Enter second size: " << endl;
    cin >> ss;

    cout << "Enter first array: " << endl;
    for (int i = 0; i < fs; i++)
        cin >> first[i];

    cout << "enter second array: " << endl;
    for (int i = 0; i < ss; i++)
        cin >> second[i];

    ts = fs + ss;

    mergeTwoArraysInOne(first, second, third, fs, ss, ts);

    cout << "\nEnter the kth element you want to find: " << endl;
    cin >> inkth;

    theFinalelem = kthSmallestUsingBruteForce(third, ts, inkth)+1;
    if (theFinalelem == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "The kth element is: " << theFinalelem << endl;
    }

    return 0;
}
