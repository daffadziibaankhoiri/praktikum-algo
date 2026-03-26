#include <iostream>
using namespace std;

struct kendaraan
{
    char plat[10], tipe[20], pemilik[20], alamat[30], kota [20];
};

struct kendaraan data[1] = {
        {"DA1234MK", "RUSH", "Andika Hartanto", "Jl. Kayu Tangi 1", "Banjarmasin"}
    };

int main(){
    
    cout<<"\nPlat Nomor Kendaraan : "<<data[0].plat;
    cout<<"\nJenis Kendaraan : "<<data[0].tipe;
    cout<<"\nNama Pemilik : "<<data[0].pemilik;
    cout<<"\nAlamat : "<<data[0].alamat;
    cout<<"\nKota : "<<data[0].kota;
    cout<<endl<<endl;
    
    return 0;
}