#include <iostream>
using namespace std;

struct karakter
{
    char huruf[2], kata[10];
    int angka;
};

struct karakter data[1];

int main(){
    
    cout<<"Masukkan Sebuah Huruf : "; cin>>data[0].huruf;
    cout<<"Masukkan Sebuah Kata : "; cin>>data[0].kata;
    cout<<"Masukkan Angka : "; cin>>data[0].angka;
    cout<<"\nHuruf yang Anda masukkan : "<<data[0].huruf;
    cout<<"\nKata yang Anda masukkan : "<<data[0].kata;
    cout<<"\nAngka yang Anda masukkan : "<<data[0].angka;
    cout<<endl<<endl;
    
    return 0;
}