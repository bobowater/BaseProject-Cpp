#include "../src/main.h"
#include <assert.h>

void testGetTriangleType() {
    assert(getTriangleType(3, 4, 5) == 0);
}

int main() {
    assert(addNumber(5, 2) == 7);
    assert(minNumber(5, 2) == 3);
    testGetTriangleType();
    return 0;
}
