#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data(15);
    data.name = "Alice";
    data.value = 3.14f;

    uintptr_t raw = Serializer::serialize(&data);
    Data* dataPtr = Serializer::deserialize(raw);

    if (dataPtr == &data)
    {
        std::cout << "[OK] Data pointer round-trip" << std::endl;
        std::cout << "id = " << dataPtr->idNumber
                  << ", name = " << dataPtr->name
                  << ", value = " << dataPtr->value << std::endl;
    }
    else
    {
        std::cout << "[FAIL] Data pointer round-trip" << std::endl;
        return 1;
    }

    uintptr_t nullRaw = Serializer::serialize(NULL);
    Data* nullPtr = Serializer::deserialize(nullRaw);
    if (nullPtr == NULL)
        std::cout << "[OK] NULL round-trip" << std::endl;
    else
    {
        std::cout << "[FAIL] NULL round-trip" << std::endl;
        return 1;
    }

    return 0;
}
