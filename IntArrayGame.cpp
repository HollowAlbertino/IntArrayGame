#include <iostream>

const int CAPACITY = 20;

using namespace std;

void displayArray(int array[], int numElements) {
    for (int i = 0; i < numElements; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void fillArray(int array[], int& numberOfElements) {
    int filled = 0;

    while (filled < CAPACITY && array[filled] != -1) {
        cout << "Enter an integer (-1 to stop): ";
        cin >> array[filled];

        if (array[filled] > 0) {
            filled++;
        } else if (array[filled] == -1) {
            cout << "Array filling stopped." << endl;
        } else {
            cout << "Invalid input. Please enter a positive integer or -1 to stop." << endl;
        }
    }

    numberOfElements = filled;
}

bool isArraySorted(int array[], int numElements) {
    for (int i = 0; i < numElements - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

int searchElement(int array[], int numberOfElements, int element) {
    for (int i = 0; i < numberOfElements; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

bool removeElement(int array[], int& numberOfElements, int position) {
    if (position < 0 || position >= numberOfElements) {
        cout << "Invalid position for removal." << endl;
        return false;
    }

    for (int i = position; i < numberOfElements - 1; i++) {
        array[i] = array[i + 1];
    }

    numberOfElements--;
    return true;
}

bool insertElement(int array[], int& numElements, int position, int target) {
    if (position < 0 || position > numElements || numElements == CAPACITY) {
        cout << "Invalid position or array is full." << endl;
        return false;
    }

    for (int i = numElements - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }

    array[position] = target;
    numElements++;
    return true;
}

int findPosition(int array[], int numElements, int target) {
    int position = 0;
    while (position < numElements && array[position] < target) {
        position++;
    }
    return position;
}

int main() {
    int numArray[CAPACITY];
    int numArrayElems = 0;

    fillArray(numArray, numArrayElems);
    cout << "Array after filling:\n";
    displayArray(numArray, numArrayElems);

    int valueToInsert;
    cout << "Enter a value to insert: ";
    cin >> valueToInsert;

    int insertPosition = findPosition(numArray, numArrayElems, valueToInsert);
    if (insertElement(numArray, numArrayElems, insertPosition, valueToInsert)) {
        cout << "Array after insertion:\n";
        displayArray(numArray, numArrayElems);
    } else {
        cout << "Insertion failed. Array is full or position is invalid." << endl;
    }

    if (isArraySorted(numArray, numArrayElems)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }

    int valueToRemove;
    cout << "Enter a value to remove: ";
    cin >> valueToRemove;

    int removePosition = searchElement(numArray, numArrayElems, valueToRemove);
    if (removeElement(numArray, numArrayElems, removePosition)) {
        cout << "Array after removal:\n";
        displayArray(numArray, numArrayElems);
    } else {
        cout << "Removal failed. Value not found or position is invalid." << endl;
    }

    return 0;
}
