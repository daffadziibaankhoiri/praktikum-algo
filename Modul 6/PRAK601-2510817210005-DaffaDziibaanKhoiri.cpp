#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int randomNum(int bil)
{
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize()
{
    srand(time(NULL));
}

void clrscr()
{
    system("cls");
}

void sequentialSearching()
{
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++)
    {
        data[i] = randomNum(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");

    for (int i = 0; i < 100; i++)
    {
        if (data[i] == cari)
        {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1)
    {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d\n", save);
    }
    else
    {
        printf("Data tidak ada!\n");
    }
}


void binarySearching()
{
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (angka[j] > angka[j + 1])
            {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "--------------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++)
    {
        cout << angka[i] << " ";
    }
    cout << "\n--------------------------------------------------------------------------------\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan)
    {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])
        {
            ketemu = true;
            break;
        }
        else if (key < angka[tengah])
        {
            kanan = tengah - 1;
        }
        else
        {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true)
    {
        cout << "Angka ditemukan! ";
    }
    else
    {
        cout << "Angka tidak ditemukan!";
    }
}

void jelaskanPerbedaan()
{
    clrscr();
    cout << "PERBEDAAN SEQUENTIAL SEARCHING & BINARY SEARCHING\n\n";

    cout << "1. SEQUENTIAL SEARCHING\n";
    cout << "   Cara kerja : Mencari data satu per satu dari awal hingga akhir.\n";
    cout << "   Kelebihan  :\n";
    cout << "     - Dapat digunakan pada data yang tidak terurut.\n";
    cout << "     - Implementasi sederhana dan mudah dipahami.\n";
    cout << "   Kekurangan :\n";
    cout << "     - Lambat untuk data berukuran besar dengan kompleksitas (O(n)).\n";
    cout << "     - Tidak efisien jika data yang dicari ada di akhir.\n\n";

    cout << "2. BINARY SEARCHING\n";
    cout << "   Cara kerja : Membagi array menjadi dua bagian, lalu\n";
    cout << "                membandingkan nilai tengah dengan data yang dicari.\n";
    cout << "   Kelebihan  :\n";
    cout << "     - Jauh lebih cepat untuk data besar dengan komplekstas (O(log n)).\n";
    cout << "     - Efisien karena setiap iterasi membuang setengah data.\n";
    cout << "   Kekurangan :\n";
    cout << "     - Data harus terurut terlebih dahulu.\n";
    cout << "     - Lebih kompleks dalam implementasi.\n\n";
}

int main()
{
    int pilih;

    do
    {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            sequentialSearching();
            break;
        case 2:
            binarySearching();
            break;
        case 3:
            jelaskanPerbedaan();
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

        if (pilih != 4)
        {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore();
            cin.get();
        }

    } while (pilih != 4);

    return 0;
}