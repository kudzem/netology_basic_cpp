#include <iostream>

class MyStringLengthChecker : public std::exception {
public:
    virtual const char* what() const { return "�� ����� ����� ��������� �����!"; }
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
    std::cout << "������� ��������� ����� : ";
    int forbidden_word_length = 0;
    std::cin >> forbidden_word_length;

    while (true) {
        std::cout << "������� ����� : ";
        std::string word;
        std::cin >> word;

        try {
            unsigned str_size = get_string_size(word, forbidden_word_length);
            std::cout << "����� ����� \"" << word << "\" ����� " << str_size << std::endl;
        }
        catch (MyStringLengthChecker& e) {
            std::cout << e.what() << std::endl;
            std::cout << "�� ��������" << std::endl;
            return 1; 
        }
        catch (const char *) {
            std::cout << "�� ����� ����� ��������� �����!" << std::endl;
            std::cout << "�� ��������" << std::endl;
            return 1;
        }
    }
}

//������� ��������� ����� : 5
//������� ����� : ������
//����� ����� "������" ����� 6
//������� ����� : ���
//����� ����� "���" ����� 3
//������� ����� : �����
//