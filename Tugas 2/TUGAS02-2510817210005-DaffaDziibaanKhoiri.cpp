#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();
void hapusTargetHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
    menu:
    cout<< "Double Linked List Non Circular (DLLNC)" << endl;   
    cout<< "=====================================" << endl;
    cout<< "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl; 
    cout<< "1. DLLNC dengan head" << endl;
    cout<< "2. DLLNC dengan head dan tail" << endl;
    cout<< "3. Quit" << endl;
    cout<< "Pilihan : ";
    cin >> menu;
    system("cls");
    if(menu == 1) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) dengan head" << endl;
            cout << "=====================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang (ke-N dari belakang)" << endl;
            cout << "6. Hapus Target" << endl;
            cout << "7. Reset" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch(pil) {
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    hapusTargetH();
                    break;
                case 7:
                    clearH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout << "\npress any key to continue" << endl;
            _getch();
            system("cls");
        } while (pil < 8);

    } else if(menu == 2) {
        do {
            cout << "Double Linked List Non Circular (DLLNC) dengan head dan tail" << endl;
            cout << "=====================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang (ke-N dari belakang)" << endl;
            cout << "6. Hapus Target" << endl;
            cout << "7. Reset" << endl;
            cout << "8. Kembali ke Menu" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch(pil) {
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    hapusTargetHT();
                    break;
                case 7:
                    clearHT();
                    break;
                default:
                     system("cls");
                     goto menu;
            }

            cout << "\npress any key to continue" << endl;
            _getch();
            system("cls");

        } while (pil < 8);
    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Daffa Dziibaan Khoiri (2510817210005)." << endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(head == NULL && tail == NULL) return 1;
    else return 0;
}

void tambahDepanH(){
    cin.ignore();
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    string line;
    getline(cin, line);

    istringstream iss(line);
    string token;
    TNode *firstNew = NULL, *lastNew = NULL;

    while(iss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = NULL;
        baru->prev = NULL;
        if(firstNew == NULL) {
            firstNew = baru;
            lastNew = baru;
        } else {
            lastNew->next = baru;
            baru->prev = lastNew;
            lastNew = baru;
        }
    }

    if(firstNew == NULL) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    if(isEmptyH() == 1) {
        head = firstNew;
    } else {
        lastNew->next = head;
        head->prev = lastNew;
        head = firstNew;
    }

    cout << "Data berhasil ditambahkan di bagian depan" << endl;
}

void tambahDepanHT(){
    cin.ignore();
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    string line;
    getline(cin, line);

    istringstream iss(line);
    string token;
    TNode *firstNew = NULL, *lastNew = NULL;

    while(iss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = NULL;
        baru->prev = NULL;
        if(firstNew == NULL) {
            firstNew = baru;
            lastNew = baru;
        } else {
            lastNew->next = baru;
            baru->prev = lastNew;
            lastNew = baru;
        }
    }

    if(firstNew == NULL) {
        cout << "Tidak ada data yang dimasukkan." << endl;
        return;
    }

    if(isEmptyHT() == 1) {
        head = firstNew;
        tail = lastNew;
    } else {
        lastNew->next = head;
        head->prev = lastNew;
        head = firstNew;
    }

    cout << "Data berhasil dimasukkan di bagian depan" << endl;
}

void tambahBelakangH(){
    cin.ignore();
    cout << "Masukkan data baru (pisahkan dengan spasi) : ";
    string line;
    getline(cin, line);

    istringstream iss(line);
    string token;

    TNode *ekor = NULL;
    if(isEmptyH() == 0) {
        ekor = head;
        while(ekor->next != NULL) ekor = ekor->next;
    }

    while(iss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH() == 1) {
            head = baru;
            ekor = baru;
        } else {
            ekor->next = baru;
            baru->prev = ekor;
            ekor = baru;
        }
    }

    cout << "Data berhasil ditambahkan di bagian belakang" << endl;
}

void tambahBelakangHT(){
    cin.ignore();
    cout << "Masukkan data (pisahkan dengan spasi) : ";
    string line;
    getline(cin, line);

    istringstream iss(line);
    string token;

    while(iss >> token) {
        TNode *baru = new TNode;
        baru->data = token;
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    cout << "Data berhasil dimasukkan di bagian belakang" << endl;
}


void hapusDepanH(){
    TNode *hapus;
    string data;
    if(isEmptyH() == 0) {
        hapus = head;
        data = hapus->data;
        if(head != NULL) {
            head = head->next;
            head->prev = NULL;
        } else{
            initH();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus" << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

void hapusDepanHT(){
    TNode *hapus;
    string data;
    if(isEmptyHT() == 0) {
        hapus = head;
        data = hapus->data;
        if(head != NULL) {
            head = head->next;
            head->prev = NULL;
        } else{
            initHT();
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus" << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

void hapusBelakangH(){
    if(isEmptyH() == 1) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }

    int N;
    cout << "Masukkan posisi N dari belakang yang ingin dihapus : ";
    cin >> N;

    int count = 0;
    TNode *bantu = head;
    while(bantu != NULL) {
        count++;
        bantu = bantu->next;
    }

    if(N > count) {
        N = N % count;
        if(N == 0) N = count;
        cout << "N terlalu besar, menggunakan sistem mundur. Menghapus node ke-" << N << " dari belakang." << endl;
    }

    int targetFromFront = count - N + 1;
    TNode *hapus = head;
    for(int i = 1; i < targetFromFront; i++) {
        hapus = hapus->next;
    }

    string data = hapus->data;

    if(hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;

    if(hapus->next != NULL) hapus->next->prev = hapus->prev;

    delete hapus;
    cout << "Data \"" << data << "\" (posisi ke-" << N << " dari belakang) telah berhasil dihapus" << endl;
}

void hapusBelakangHT(){
    if(isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }

    int N;
    cout << "Masukkan posisi N dari belakang yang ingin dihapus : ";
    cin >> N;

    int count = 0;
    TNode *bantu = head;
    while(bantu != NULL) {
        count++;
        bantu = bantu->next;
    }

    if(N > count) {
        N = N % count;
        if(N == 0) N = count;
        cout << "N terlalu besar, menggunakan sistem mundur. Menghapus node ke-" << N << " dari belakang." << endl;
    }

    TNode *hapus = tail;
    for(int i = 1; i < N; i++) {
        hapus = hapus->prev;
    }

    string data = hapus->data;

    if(hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;

    if(hapus->next != NULL) hapus->next->prev = hapus->prev;
    else tail = hapus->prev;

    delete hapus;
    cout << "Data \"" << data << "\" (posisi ke-" << N << " dari belakang) telah berhasil dihapus" << endl;
}



void hapusTargetH(){
    if(isEmptyH() == 1) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus : ";
    cin >> target;

    TNode *bantu = head;
    int jumlahHapus = 0;

    while(bantu != NULL) {
        TNode *next = bantu->next;
        if(bantu->data == target) {
            if(bantu->prev != NULL) bantu->prev->next = bantu->next;
            else head = bantu->next; 

            if(bantu->next != NULL) bantu->next->prev = bantu->prev;

            delete bantu;
            jumlahHapus++;
        }
        bantu = next;
    }

    if(jumlahHapus == 0) {
        cout << "Data \"" << target << "\" tidak ditemukan dalam Linked List" << endl;
    } else {
        cout << "Data \"" << target << "\" berhasil dihapus sebanyak " << jumlahHapus << " node" << endl;
    }
}

void hapusTargetHT(){
    if(isEmptyHT() == 1) {
        cout << "Tidak terdapat data pada Linked List" << endl;
        return;
    }
    string target;
    cout << "Masukkan data target yang ingin dihapus : ";
    cin >> target;

    TNode *bantu = head;
    int jumlahHapus = 0;

    while(bantu != NULL) {
        TNode *next = bantu->next;
        if(bantu->data == target) {
            if(bantu->prev != NULL) bantu->prev->next = bantu->next;
            else head = bantu->next;

            if(bantu->next != NULL) bantu->next->prev = bantu->prev;
            else tail = bantu->prev; 

            delete bantu;
            jumlahHapus++;
        }
        bantu = next;
    }

    if(jumlahHapus == 0) {
        cout << "Data \"" << target << "\" tidak ditemukan dalam Linked List" << endl;
    } else {
        cout << "Data \"" << target << "\" berhasil dihapus sebanyak " << jumlahHapus << " node" << endl;
    }
}


void tampilkanH(){
    TNode *bantu;
    bantu = head;
    if(isEmptyH() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}

void tampilkanHT(){
    TNode *bantu;
    bantu = head;
    if(isEmptyHT() == 0) {
        while(bantu != NULL) {
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    } else cout << "Tidak terdapat data pada Linked List" << endl;
}


void clearH(){
    int urutan = 1;
    bool dariDepan = true; 

    while(isEmptyH() == 0) {
        string data;
        TNode *hapus;

        if(dariDepan) {
            hapus = head;
            data = hapus->data;
            head = head->next;
            if(head != NULL) head->prev = NULL;
        } else {
            hapus = head;
            while(hapus->next != NULL) hapus = hapus->next;
            data = hapus->data;
            if(hapus->prev != NULL) hapus->prev->next = NULL;
            else head = NULL; 
        }

        cout << "Penghapusan ke-" << urutan << " : \"" << data << "\"" << endl;
        delete hapus;
        urutan++;
        dariDepan = !dariDepan; 
    }

    initH();
    cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
}

void clearHT(){
    int urutan = 1;
    bool dariDepan = true; 

    while(isEmptyHT() == 0) {
        string data;
        TNode *hapus;

        if(dariDepan) {
            hapus = head;
            data = hapus->data;
            head = head->next;
            if(head != NULL) head->prev = NULL;
            else tail = NULL; 
        } else {
            hapus = tail;
            data = hapus->data;
            tail = tail->prev;
            if(tail != NULL) tail->next = NULL;
            else head = NULL; 
        }

        cout << "Penghapusan ke-" << urutan << " : \"" << data << "\"" << endl;
        delete hapus;
        urutan++;
        dariDepan = !dariDepan;
    }

    initHT();
    cout << "Seluruh data pada Linked List telah dibersihkan." << endl;
}