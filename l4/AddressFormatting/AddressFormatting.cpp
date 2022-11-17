#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class Address {
public:
    Address(std::string city, std::string street, unsigned houseNumber, unsigned appartNumber = 1) :
        _city(city),
        _street(street),
        _houseNumber(houseNumber),
        _appartNumber(appartNumber)
    {};

    bool operator<(const Address& other) {
        return other._city < this->_city;
    }

    std::string get() const {
        return _city + ", " +
            _street + ", " +
            std::to_string(_houseNumber) + ", " +
            std::to_string(_appartNumber);
    }
private:
    std::string _city;
    std::string _street;
    unsigned _houseNumber;
    unsigned _appartNumber;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream in_file("in.txt");
    if (!in_file.is_open()) {
        return 1;
    }

    std::string line;
    unsigned number_of_addresses_in_db = 0;
    std::getline(in_file, line);
    number_of_addresses_in_db = std::stoi(line);

    Address** addresses_from_file = new Address*[number_of_addresses_in_db];

    for (unsigned i = 0; i < number_of_addresses_in_db; ++i) {
        std::string city, street;
        std::getline(in_file, city);
        std::getline(in_file, street);

        unsigned houseNumber(0), appartNumber(0);
        std::getline(in_file, line);
        houseNumber = std::stoi(line);

        std::getline(in_file, line);
        appartNumber = std::stoi(line);
        
        addresses_from_file[i] = new Address(city, street, houseNumber, appartNumber);
    }
    in_file.close();

    std::sort(addresses_from_file, addresses_from_file + number_of_addresses_in_db);

    std::ofstream out_file("out.txt");
    if (!out_file.is_open()) {
        return 2;
    }

    out_file << number_of_addresses_in_db << std::endl;
    for (unsigned i = 0; i < number_of_addresses_in_db; ++i) {
        out_file << addresses_from_file[i]->get() << std::endl;
    }
    out_file.close();

    for (unsigned i = 0; i < number_of_addresses_in_db; ++i) {
        delete addresses_from_file[i];
    }
    delete [] addresses_from_file;

    return 0;
}
