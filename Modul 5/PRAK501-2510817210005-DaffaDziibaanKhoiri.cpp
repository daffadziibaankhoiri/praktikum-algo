#include <iostream>
#include <string>
using namespace std;

bool isAllDigit(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

void tampilChar(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

void tampilInt(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void stringKeArray(string s, char arr[], int& n) {
    n = s.length();
    for (int i = 0; i < n; i++) {
        arr[i] = s[i];
    }
}

void angkaKeArray(string s, int arr[], int& n) {
    n = s.length();
    for (int i = 0; i < n; i++) {
        arr[i] = s[i] - '0';
    }
}

void insertionSortChar(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

void insertionSortInt(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

void mergeChar(char arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    char L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for (int i = 0; i < n2; i++) R[i] = arr[tengah + 1 + i];
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortChar(char arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSortChar(arr, kiri, tengah);
        mergeSortChar(arr, tengah + 1, kanan);
        mergeChar(arr, kiri, tengah, kanan);
    }
}

void mergeInt(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    int L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[kiri + i];
    for (int i = 0; i < n2; i++) R[i] = arr[tengah + 1 + i];
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortInt(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = (kiri + kanan) / 2;
        mergeSortInt(arr, kiri, tengah);
        mergeSortInt(arr, tengah + 1, kanan);
        mergeInt(arr, kiri, tengah, kanan);
    }
}

void shellSortChar(char arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void shellSortInt(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int partisiChar(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            char temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    char temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quickSortChar(char arr[], int low, int high) {
    if (low < high) {
        int pi = partisiChar(arr, low, high);
        quickSortChar(arr, low, pi - 1);
        quickSortChar(arr, pi + 1, high);
    }
}

int partisiInt(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return i + 1;
}

void quickSortInt(int arr[], int low, int high) {
    if (low < high) {
        int pi = partisiInt(arr, low, high);
        quickSortInt(arr, low, pi - 1);
        quickSortInt(arr, pi + 1, high);
    }
}

void bubbleSortChar(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
        }
    }
}

void selectionSortChar(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        char temp = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = temp;
    }
}

void selectionSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        int temp = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = temp;
    }
}

void prosesSort(int pilihan) {
    cout << endl;
    cout << "Masukkan data : ";
    cin.ignore();
    string input;
    getline(cin, input);

    bool modeAngka = (input.find(' ') == string::npos) && isAllDigit(input);

    if (modeAngka) {
        int arr[100], n;
        angkaKeArray(input, arr, n);


        switch (pilihan) {
            case 1: insertionSortInt(arr, n); break;
            case 2: mergeSortInt(arr, 0, n - 1); break;
            case 3: shellSortInt(arr, n); break;
            case 4: quickSortInt(arr, 0, n - 1); break;
            case 5: bubbleSortInt(arr, n); break;
            case 6: selectionSortInt(arr, n); break;
        }

        cout << "Hasil sort: ";
        tampilInt(arr, n);

    } else {
        string gabung = "";
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != ' ') gabung += input[i];
        }

        char arr[500];
        int n;
        stringKeArray(gabung, arr, n);


        switch (pilihan) {
            case 1: insertionSortChar(arr, n); break;
            case 2: mergeSortChar(arr, 0, n - 1); break;
            case 3: shellSortChar(arr, n); break;
            case 4: quickSortChar(arr, 0, n - 1); break;
            case 5: bubbleSortChar(arr, n); break;
            case 6: selectionSortChar(arr, n); break;
        }

        cout << "Hasil sort : ";
        for (int i = 0; i < n; i++) cout << arr[i];
        cout << endl;
    }
}


int main() {
    int pilihan;

    do {
        cout << endl;
        cout << "----------------------------------" << endl;
        cout << "               SORTING            " << endl;
        cout << "----------------------------------" << endl;
        cout << "  1. Insertion Sort               " << endl;
        cout << "  2. Merge Sort                   " << endl;
        cout << "  3. Shell Sort                   " << endl;
        cout << "  4. Quick Sort                   " << endl;
        cout << "  5. Bubble Sort                  " << endl;
        cout << "  6. Selection Sort               " << endl;
        cout << "  7. Exit                         " << endl;
        cout << "----------------------------------" << endl;
        cout << "Pilih menu [1-7]: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 6) {
            string namaSort[] = {
                "Insertion Sort", "Merge Sort", "Shell Sort",
                "Quick Sort", "Bubble Sort", "Selection Sort"
            };
            cout << endl;
            cout << "--- " << namaSort[pilihan - 1] << " ---" << endl;
            prosesSort(pilihan);
        } else if (pilihan == 7) {
            cout << endl;
            cout << "Terima kasih, program selesai!" << endl;
        } else {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }

    } while (pilihan != 7);

    return 0;
}