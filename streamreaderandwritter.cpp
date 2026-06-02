#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // deklarasi variable baris untuk menyimpan data string
    string baris;

    // membuka file dalam mode menulis
    ofstream outfile;
    // menunuk ke sebuahh nama file
    outfile.open("contohfile.txt");

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

    // unlimited loop untuk menulis file
    while (true)
    {
        cout << "- ";
        // mendapat setiap karakter dalam satu baris
        getline(cin, baris);
        // kondisi false jika baris hanya berisi karakter q
        if (baris == "q")
            break;
        // menulis fdan memasukan nilai dari variable baris ke dlaam file
        outfile << baris << endl;
    }
    // menutup file setelah penulisian selasai
    outfile.close();

    // membuka file setelah penulisan selesai
    ifstream infile;
    // menunjuk ke sebuah file
    infile.open("contohfile.txt");

    cout << endl
         << ">=Membuka dan membaca file " << endl;
    // kondisi jika file ada
    if (infile.is_open())
    {
        // perulangan untuk memunculkan setiap baris
        while (getline(infile, baris))
        {
            cout << baris << endl;
        }
        // menutup file jika telah selesai
        infile.close();
    }
    // kondisi jika file tidak ada
    else
        cout << "Unable to open file";
    return 0;
}