// AddressStruct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct Address {

    Address(std::string country,
        std::string city,
        std::string street,
        unsigned house,
        unsigned appartment,
        unsigned post_index) : country(country),
        city(city),
        street(street),
        house(house),
        appartment(appartment),
        post_index(post_index) {}

    std::string country;
    std::string city;
    std::string street;
    unsigned house;
    unsigned appartment;
    unsigned post_index;
};

void printAddress(const struct Address& address) {
    std::cout << "Страна : " << address.country << std::endl;
        std::cout << "Город : " << address.city << std::endl;
        std::cout << "Улица : " << address.street << std::endl;
        std::cout << "Номер дома : " << address.house << std::endl;
        std::cout << "Номер квартиры : " << address.appartment << std::endl;
        std::cout << "Почтовый индекс : " << address.post_index << std::endl;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    struct Address myAddress { "Russia", "Nizhny Novgorod", "Minina", 111, 13, 613045 };
    struct Address yourAddress { "Greece", "Sparta", "Julia Cesara", 10, 1, 26452 };

    printAddress(myAddress);
    printAddress(yourAddress);
}

