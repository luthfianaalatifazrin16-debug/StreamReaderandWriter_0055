#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // deklarasi variable baris dan namafile
    string baris, NamaFile;

    // membuat input untuk menangkap nama file
    cout << "Masukan nama file : ";
    cin >> NamaFile;

    // membuat file dalam mode menulis
    ofstream outfile;
    // menunjuk ke sebuah nama file dengan ekstensi txt
    outfile.open(NamaFile + ".txt", ios ::out);

    cout << " >= Menulis File, \'q\' untuk keluar" << endl;