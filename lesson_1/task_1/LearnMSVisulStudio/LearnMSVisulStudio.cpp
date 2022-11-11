#include <fstream>
#include <iostream>

int main() {

    std::ifstream fin("in.txt");

    if (!fin.is_open()) {
        std::cout << "Can't open in file" << std::endl;
        return 1;
    }

    const unsigned expected_number_of_arrays = 2;
    int* arr[expected_number_of_arrays];
    unsigned arr_sizes[expected_number_of_arrays] = { 0, 0 };

    for (unsigned arr_idx = 0; arr_idx < 2; ++arr_idx) {
        fin >> arr_sizes[arr_idx];

        arr[arr_idx] = new int[arr_sizes[arr_idx]];

        for (int i = 0; i < arr_sizes[arr_idx]; ++i) {
            fin >> arr[arr_idx][i];
        }
    }
    fin.close();

    std::ofstream fout("out.txt");
    if (!fout.is_open()) {
        std::cout << "Can't open out file" << std::endl;
        // free memory here
        for (unsigned arr_idx = 0; arr_idx < 2; ++arr_idx) {
            delete [] arr[arr_idx];
        }
        return 2;
    }
    fout << arr_sizes[1] << '\n';
    for (int i = 0; i < arr_sizes[1]; ++i) {
        fout << (arr[1][(i + arr_sizes[1] - 1) % arr_sizes[1]]) << " ";
    }
	delete [] arr[1];

    fout << '\n';

    fout << arr_sizes[0] << '\n';
    for (int i = 0; i < arr_sizes[0]; ++i) {
        fout << (arr[0][(i + 1) % arr_sizes[0]]) << " ";
    }
	delete [] arr[0];

    fout.close();

    return 0;
}