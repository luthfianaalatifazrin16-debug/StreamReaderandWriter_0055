#include <iostream>
using namespace std;

int main()
{
    // membuat isi dari try untuk pengujuian error
    try
    {
        cout << "Selamat belajar di prodi TI UMY" << endl;
        //
        cout << "Pernyataan tidak akan ditampilkan" << endl;
    }
    // throw 0.5; // melemparkan sebuah integer maka
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}