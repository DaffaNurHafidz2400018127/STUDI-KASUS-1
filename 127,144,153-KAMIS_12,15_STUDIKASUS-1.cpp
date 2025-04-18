#include <iostream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

const int JUMLAH_MENU = 2;
string menu[JUMLAH_MENU] = {"Ayam Goreng", "Ayam Bakar"};
int harga[JUMLAH_MENU] = {17000, 21000};
int jumlah[JUMLAH_MENU] = {0};

int menuDanPesan() {
    string input;
    int porsi, total = 0;

    cout << "===== MENU RUMAH MAKAN =====" << endl;
    for (int i = 0; i < JUMLAH_MENU; i++) {
        cout << i + 1 << ". " << menu[i] << " - Rp" << harga[i] << endl;
    }
    cout << "============================" << endl;

    while (true) {
        cout << "\nMasukkan nomor menu yang ingin dipesan (ketik 'n' untuk selesai): ";
        cin >> input;

        if (input == "n" || input == "N") break;

        int pilihan;
        try {
            pilihan = stoi(input); 
        } catch (...) {
            cout << "Input tidak valid!\n";
            continue;
        }

        if (pilihan < 1 || pilihan > JUMLAH_MENU) {
            cout << "Pilihan tidak tersedia!" << endl;
            continue;
        }

        cout << "Berapa porsi " << menu[pilihan - 1] << "? ";
        cin >> porsi;

        if (porsi < 1) {
            cout << "Jumlah porsi tidak valid!" << endl;
            continue;
        }

        jumlah[pilihan - 1] += porsi;
        total += porsi * harga[pilihan - 1];
    }

    return total;
}

double hitungDiskon(int total) {
    return (total > 45000) ? total * 0.10 : 0;
}

void tampilkanStruk(int total, double diskon, double totalAkhir) {
    cout << "\nTekan ENTER untuk melihat struk pembayaran...";
    cin.ignore();
    cin.get();

    system("CLS"); 

    cout << "======= STRUK PEMBAYARAN =======\n";
    for (int i = 0; i < JUMLAH_MENU; i++) {
        if (jumlah[i] > 0) {
            int subtotal = jumlah[i] * harga[i];
            cout << left << setw(15) << menu[i]
                 << setw(5) << jumlah[i]
                 << " x Rp" << setw(7) << harga[i]
                 << "= Rp" << subtotal << endl;
        }
    }

    cout << "--------------------------------\n";
    if (diskon > 0) {
        cout << "Diskon 10%       : Rp" << diskon << endl;
    }

    cout << "Total Bayar      : Rp" << totalAkhir << endl;
    cout << "===============================\n";
    cout << "Terima kasih atas kunjungannya!\n";
}

int main() {
    int total = menuDanPesan();
    double diskon = hitungDiskon(total);
    double totalAkhir = total - diskon;

    tampilkanStruk(total, diskon, totalAkhir);
    return 0;
}

