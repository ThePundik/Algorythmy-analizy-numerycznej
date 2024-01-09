#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>



int main()
{
    std::vector<int> mojVector = {1, 2, 3, 4, 5};
    int rozmiarVector = mojVector.size();
    std::cout << rozmiarVector << std::endl;
}