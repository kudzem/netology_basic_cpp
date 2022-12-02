#include <iostream>

class MyStringLengthChecker : public std::exception {
public:
    virtual const char* what() const { return "Вы ввели слово запретной длины!"; }
};

unsigned get_string_size(std::string str, int forbidden_length) {
    unsigned str_size = str.size();
    //if (str_size == forbidden_length) {
    //    throw MyStringLengthChecker();
    //}

    if (str_size == forbidden_length) {
        throw "bad length";
    }

    return str_size;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите запретную длину : ";
    int forbidden_word_length = 0;
    std::cin >> forbidden_word_length;

    while (true) {
        std::cout << "Введите слово : ";
        std::string word;
        std::cin >> word;

        try {
            unsigned str_size = get_string_size(word, forbidden_word_length);
            std::cout << "Длина слова \"" << word << "\" равна " << str_size << std::endl;
        }
        catch (MyStringLengthChecker& e) {
            std::cout << e.what() << std::endl;
            std::cout << "До свидания" << std::endl;
            return 1; 
        }
        catch (const char *) {
            std::cout << "Вы ввели слово запретной длины!" << std::endl;
            std::cout << "До свидания" << std::endl;
            return 1;
        }
    }
}

//Введите запретную длину : 5
//Введите слово : Привет
//Длина слова "Привет" равна 6
//Введите слово : мир
//Длина слова "мир" равна 3
//Введите слово : пирог
//