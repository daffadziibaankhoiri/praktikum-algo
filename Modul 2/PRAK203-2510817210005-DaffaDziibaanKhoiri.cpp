#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define n 10
using namespace std;

int PIL, F, R;
char PILIHAN[1], HURUF;
char Q[n];

void INSERT(){
    if(R == n - 1){
       cout<<"Queue Penuh";
    } else{
        if(F == -1) F = 0;

        cout<<"Masukkan satu huruf : ";cin>>HURUF;
        R++;
        Q[R] = HURUF;
        cout <<"Data '"<< HURUF << "' berhasil masuk ke Queue";

    }
};
void DELETE(){
    if(F == -1 || F > R){
        cout<<"Queue Kosong"<< endl;
    }else{
        cout<< "Karakter '" << Q[F] << "' keluar dari Queue" << endl;
        F++;
    }
};
void CETAKLAYAR(){
     if(F ==-1 || F > R){
        cout<<"Queue Kosong"<< endl;
    }else{
        cout<< "Isi Queue saat ini : ";
        for (int i = F; i <= R; i++){
            cout<< Q[i] << " ";
        }
        cout << endl;
    }
};
void Inisialisasi(){
    F = -1;
    R = -1;
};

void RESET(){
    F = -1;
    R = -1;
    cout<<"Queue telah di kosongkan";
};

int main()
{
    Inisialisasi();
    do
    {
        cout<<"QUEUE"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. RESET QUEUE"<<endl;
        cout<<"5. QUIT"<<endl;
        cout<<"PILIHAN : "; cin>>PILIHAN;
        PIL=atoi(PILIHAN);

        switch (PIL)
        {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            case 4:
                RESET();
                break;
            default:
                cout<<"TERIMA KASIH"<<endl;
                break;
        }
        cout<<"press any key to continue"<<endl;
        getch();
        system("cls");
    }
    while (PIL<4);
}