// Test_dll_lib.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <locale>
#include <string>
#include <codecvt>
#include"Translit_text.h"

int main()
{
    Trans_text test;
    wifstream in_file;
    wofstream file_out;
    int i;

    in_file.open("in.txt");
    if (!in_file.is_open())
    {
        cout << "Error!";
        return -1;
    }
    in_file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    file_out.open("out.txt");
    if (!file_out.is_open())
    {
        cout << "Error!";
        return -1;
    }
    file_out.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

    cout << "Enter 0 or 1:\n";
    cin >> i;

    wstring text, finish_text;

    while (!in_file.eof())
    {
        getline(in_file, text);
        if (i == 0)
        {
            finish_text = test.lat_to_cyr(text);
        }
        else
        {
            finish_text = test.cyr_to_lat(text);
        }

        file_out << finish_text;
        file_out << endl;
    }

    in_file.close();
    file_out.close();
    

    return 0;
}

