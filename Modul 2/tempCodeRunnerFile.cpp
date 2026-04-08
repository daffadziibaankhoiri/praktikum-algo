#include <iostream>

using namespace std;

const int maksimal = 5;
struct Stack
{
    int data[maksimal];
    int atas;
} Tumpuk;

void bersih()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

int kosong(){
    if(Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}

int penuh()
{
    if(Tumpuk.atas == maksimal-1)
        return 1;
    else
        return 0;
}

void input(int data)
{
    if (kosong()==1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack ";
    }
    else if(penuh()==0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data "<< Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack ";
    }
    else
        cout << "Tumpukan Penuh";
}

void hapus()
{
    if(kosong()== 0)
    {
        cout << "Data Teratas Sudah Terambil";
        Tumpuk.atas--;
    }
    else
        cout <<" Data Kosong";
}

void tampil()
{
    if (kosong()== 0)
    {
        for(int i = Tumpuk.atas; i>=0; i--)
        {
            cout <<"\nTumpukan Ke " << i << " = "
                 <<Tumpuk.data[i];
        }
    }
    else
        cout << "Tumpukan Kosong";
}

int main(){
    int pilihan, data;
    bersih();

    do {
        cout<<"\n\nMenu Stack";
        cout<<"\n1. Input Data";
        cout<<"\n2. Tampilkan Data";
        cout<<"\n3. Hapus Data";
        cout<<"\n4. Bersihkan semua Data";
        cout<<"\n\nMasukkan Pilihan : ";cin>>pilihan;

        switch (pilihan) {
        case 1:
            cout<<"Masukkan Data : ";cin>>data;
            input(data);
            break;
        case 2:
            tampil();
            break;
        case 3:
            hapus();
            break;
        case 4:
            bersih();
            break;
        }
    }
    while (pilihan != 0);
    
    return 0;
}