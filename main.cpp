#include "ArrayTemplate.h"
#include "Date.h"

#include <iostream>

int main() {
    ArrayTemplate<int> intArray(3);
    ArrayTemplate<float> floatArray(3);
    ArrayTemplate<std::string> stringArray(3);
    ArrayTemplate<Date> dateArray(3);
    for (int i = 0; i < 3; i++) {
        intArray.setValue(i, i);
        floatArray.setValue(i, i + 0.5);
        stringArray.setValue(i, "Hello");
        dateArray.setValue(i, Date(1970, 1, i + 1));
    }
    intArray.display();
    floatArray.display();
    stringArray.display();
    dateArray.display();
    return 0;
}
