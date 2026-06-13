#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *kiri;
    Node *kanan;
};

void tambah(Node **root, int databaru) {
    if (*root == NULL) {
        Node *baru = new Node;
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
    } else if (databaru < (*root)->data) {
        tambah(&(*root)->kiri, databaru);
    } else if (databaru > (*root)->data) {
        tambah(&(*root)->kanan, databaru);
    }
}

int diameter;

int hitungHeight(Node *root) {
    if (root == NULL) return 0;

    int heightKiri  = hitungHeight(root->kiri);
    int heightKanan = hitungHeight(root->kanan);

    int jarakMelaluiNode = heightKiri + heightKanan;
    diameter = max(diameter, jarakMelaluiNode);

    return 1 + max(heightKiri, heightKanan);
}

int main() {
    int n;
    cin >> n;

    Node *pohon = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tambah(&pohon, x);
    }

    diameter = 0;
    hitungHeight(pohon);

    cout << diameter << endl;

    return 0;
}