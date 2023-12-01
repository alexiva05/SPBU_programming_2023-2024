#include <iostream>
#include <fstream>
#include "sort.h"
#include "tobin.h"

int main(int argc, char* argv[]) {

    if (argc == 0) {
        std::cout << "Нет необходимых параметров для корректной работы программы!!!" << std::endl;
        return 0;
    }

    if (argc > 4) {
        std::cout << "Введено слишком много параметров!!!" << std::endl;
        return 0;
    }

    std::string name_of_file = "";
    std::string param1 = "";
    std::string param2 = "";
    std::string which_sort = "QuickSort";
    std::string num_sys = "10";
    int counter1 = 0, counter2 = 0;

    if (argc == 2) {
        name_of_file = argv[1];
    } else if (argc == 3) {
        name_of_file = argv[1];
        param1 = argv[2];
    } else if (argc == 4) {
        name_of_file = argv[1];
        param1 = argv[2];
        param2 = argv[3];       
    }

    if ((param1 == "QuickSort" || param1 == "InsertionSort" || param1 == "SelectionSort" || param1 == "BubbleSort") && param2 == "" && argc == 3) {
        which_sort = param1;
        ++counter1;
    }

    if ((param1 == "2" || param1 == "10") && param2 == "" && argc == 3) {
        num_sys = param1;
        ++counter2;
    }

    if (argc == 3 && counter1 == 0 && counter2 == 0) {
        std::cout << "Введен некорректный параметр!!!" << std::endl;
        return 0;
    }


    if (which_sort != "QuickSort" && which_sort != "InsertionSort" && which_sort != "BubbleSort" && which_sort != "SelectionSort") {
        std::cout << "Введено некорректное имя сортировки!" << std::endl;
        return 0;
    }

    if (param1 != "" && param2 != "" && ((param1 != "QuickSort" && param1 != "InsertionSort" && param1 != "BubbleSort" && param1 != "SelectionSort" && param1 != "2" && param1 != "10")
        || (param2 != "QuickSort" && param2 != "InsertionSort" && param2 != "BubbleSort" && param2 != "SelectionSort" && param2 != "2" && param2 != "10")) && argc == 4) {
        std::cout << "Введены некорректные параметры!!!" << std::endl;
        return 0;
    }

    if (argc == 4){
        if (param1 == "QuickSort" || param1 == "InsertionSort" || param1 == "SelectionSort" || param1 == "BubbleSort") {
            which_sort = param1;
            num_sys = param2;
        } else {
            which_sort = param2;
            num_sys = param1;
        }
    }

    //Открытие файла, и проверка открыт ли он.
    //В первой строке файла указан размер массива, в последующих строчках указаны значения массива.
    std::fstream myfile;
    myfile.open(name_of_file, std::ios_base::in);
    if (myfile.is_open()) {
        std::cout << "Файл успешно открыт." << std::endl;
        std::cout << std::endl;
    } else if (name_of_file == "") {
        std::cout << "Не указано имя файла, в котором лежат элементы массива!!!" << std::endl;
        return 0;
    } else {
        std::cout << "Файла, с указанным именем не существует!!!" << std::endl;
        return 0;
    }

    //Size of array
    int size = 0;
    std::string a;

    while (!myfile.eof()) {
        myfile >> a;
        ++size;
    }
    myfile.close();



    //Declaration and initialization of array
    std::fstream myfile1;
    myfile1.open(name_of_file, std::ios_base::in);
    int arr1[size];
    for (int i = 0; i < size; ++i) {
        myfile1 >> arr1[i];
    }
    myfile1.close();

    std::string str_arr1[size];
    std::fstream myfile2;
    myfile2.open(name_of_file, std::ios_base::in);
    for (int i = 0; i < size; ++i) {
        myfile2 >> str_arr1[i];
    }
    myfile2.close();


    int arr2[size];
    for (int i = 0; i < size; ++i) {
        arr2[i] = Convert_to_Decimal(str_arr1[i]);
    }

    //Применение одной из сортировок
    if (num_sys == "10") {
        std::cout << "Неотсортированный массив:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << arr1[i] << ' ';
        }
        std::cout << std::endl;
        std::cout << std::endl;

        if (which_sort == "QuickSort") {
            std::cout << "Массив отсортирован при помощи Quicksort:" << std::endl;
            QuickSort(arr1, 0, size - 1);
        } else if (which_sort == "InsertionSort"){
            std::cout << "Массив отсортирован при помощи InsertionSort:" << std::endl;
            InsertionSort(arr1, size);
        } else if (which_sort == "BubbleSort") {
            std::cout << "Массив отсортирован при помощи BubbleSort:" << std::endl;
            BubbleSort(arr1, size);
        } else if (which_sort == "SelectionSort") {
            std::cout << "Массив отсортирован при помощи SelectionSort:" << std::endl;
            SelectionSort(arr1, size);
        }

        for (int i = 0; i < size; ++i) {
            std::cout << arr1[i] << ' ';
        }
        std::cout << std::endl;
    } else if (num_sys == "2") {
        std::cout << "Неотсортированный массив:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << str_arr1[i] << ' ';
        }
        std::cout << std::endl;
        std::cout << std::endl;

        if (which_sort == "QuickSort") {
            std::cout << "Массив отсортирован при помощи Quicksort:" << std::endl;
            QuickSort(arr2, 0, size - 1);
        } else if (which_sort == "InsertionSort"){
            std::cout << "Массив отсортирован при помощи InsertionSort:" << std::endl;
            InsertionSort(arr2, size);
        } else if (which_sort == "BubbleSort") {
            std::cout << "Массив отсортирован при помощи BubbleSort:" << std::endl;
            BubbleSort(arr2, size);
        } else if (which_sort == "SelectionSort") {
            std::cout << "Массив отсортирован при помощи SelectionSort:" << std::endl;
            SelectionSort(arr2, size);
        }    

        //Вывод отсортированного массива
        for (int i = 0; i < size; ++i) {
            std::cout << rev_string(Convert_To_Binary(arr2[i])) << ' ';
        }
        std::cout << std::endl;
    }
}
