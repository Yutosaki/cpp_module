#include <stdint.h>

#include <iostream>

#include "../include/Data.h"
#include "../include/Serializer.h"

int main() {
    Data* data = new Data();
    data->name = "test";
    data->value = 42;

    std::cout << "Address: " << data << "  Name: " << data->name
              << "  Value: " << data->value << '\n';

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized: " << serialized << '\n';

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Address: " << deserialized << "  Name: " << deserialized->name
              << "  Value: " << deserialized->value << '\n';

    std::cout << "same pointer: " << (data == deserialized ? "true" : "false")
              << '\n';

    delete data;
    return 0;
}
