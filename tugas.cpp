#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;

class TokoElektronik
{
private:
    array<string, 3> etalase;

public:
    // Constructor mengisi data awal
    TokoElektronik()
    {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range &e)
        {
            throw string(
                "Gagal Mengambil Barang : Rak nomor " +
                to_string(nomorRak) +
                " kosong atau tidak tersedia!");
        }
    }
};

void tampilkanBarang()
{
    ifstream file("gudang.txt");

    cout << "\n===== DATA GUDANG =====\n";

    string barang;
    int nomor = 1;

    while (getline(file, barang))
    {
        cout << nomor++ << ". " << barang << endl;
    }

    if (nomor == 1)
    {
        cout << "Gudang masih kosong.\n";
    }

    file.close();
}

void tambahBarang()
{
    ofstream file("gudang.txt", ios::app);

    string barang;

    cin.ignore();
    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}

void bacaBarang()
{
    tampilkanBarang();
}

void updateBarang()
{
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang))
    {
        data.push_back(barang);
    }

    file.close();

    tampilkanBarang();

    int nomor;

    cout << "\nPilih nomor barang yang ingin diubah : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size())
    {
        cout << "Nomor tidak valid.\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan nama barang baru : ";
    getline(cin, data[nomor - 1]);

    ofstream tulis("gudang.txt");

    for (string item : data)
    {
        tulis << item << endl;
    }

    tulis.close();

    cout << "Data berhasil diperbarui.\n";
}

void hapusBarang()
{
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang))
    {
        data.push_back(barang);
    }

    file.close();

    tampilkanBarang();

    int nomor;

    cout << "\nPilih nomor barang yang ingin dihapus : ";
    cin >> nomor;

    if (nomor < 1 || nomor > data.size())
    {
        cout << "Nomor tidak valid.\n";
        return;
    }

    data.erase(data.begin() + (nomor - 1));

    ofstream tulis("gudang.txt");

    for (string item : data)
    {
        tulis << item << endl;
    }

    tulis.close();

    cout << "Data berhasil dihapus.\n";
}

void simulasiEtalase()
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    try
    {
        cout << "\nSkenario 1 (Rak 1)\n";
        cout << "Barang : "
             << toko.ambilProduk(1)
             << endl;
    }
    catch (string pesan)
    {
        cout << pesan << endl;
    }

    // Skenario 2
    try
    {
        cout << "\nSkenario 2 (Rak 5)\n";
        cout << "Barang : "
             << toko.ambilProduk(5)
             << endl;
    }
    catch (string pesan)
    {
        cout << pesan << endl;
    }
}

int main()
{
    int pilihan;

    do
    {
        cout << "\n=========================\n";
        cout << " TOKO ELEKTRONIK GIBRAN JAYA\n";
        cout << "=========================\n";

        tampilkanBarang();

        cout << "\nMenu:\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";

        cout << "\nPilih menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBarang();
            break;

        case 2:
            bacaBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}