#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Representasi struktur graph
struct Sisi {
    int desa1;
    int desa2;
    int panjangJalan;
};

// Temukan indeks desa dengan jarak minimum
int temukanDesaMinimum(vector<int>& jarak, vector<bool>& sptSet, int jumlahDesa) {
    int minJarak = INT_MAX;
    int minDesa;

    for (int desa = 0; desa < jumlahDesa; desa++) {
        if (!sptSet[desa] && jarak[desa] < minJarak) {
            minJarak = jarak[desa];
            minDesa = desa;
        }
    }

    return minDesa;
}

// Algoritma Prim untuk mencari Minimum Spanning Tree
vector<Sisi> primMST(vector<vector<int>>& graph, int jumlahDesa) {
    vector<Sisi> mst; // Minimum Spanning Tree
    vector<int> jarak(jumlahDesa, INT_MAX); // Jarak minimum dari MST
    vector<bool> sptSet(jumlahDesa, false); // Subset MST

    // Mulai dari desa pertama
    jarak[0] = 0;

    for (int count = 0; count < jumlahDesa - 1; count++) {
        int u = temukanDesaMinimum(jarak, sptSet, jumlahDesa);

        sptSet[u] = true;

        for (int v = 0; v < jumlahDesa; v++) {
            if (graph[u][v] && !sptSet[v] && graph[u][v] < jarak[v]) {
                jarak[v] = graph[u][v];
            }
        }
    }

    // Konstruksi MST berdasarkan jarak minimum
    for (int desa = 1; desa < jumlahDesa; desa++) {
        Sisi s;
        s.desa1 = desa;
        s.desa2 = desa;
        s.panjangJalan = jarak[desa];
        mst.push_back(s);
    }

    return mst;
}

int main() {
    int jumlahDesa = 6;
    int jumlahJalan = 9;

    vector<vector<int>> graph = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    // Cari Minimum Spanning Tree menggunakan algoritma Prim
    vector<Sisi> mst = primMST(graph, jumlahDesa);

    // Hitung panjang jalan terpendek yang dapat diaspal
    int panjangJalanTerpendek = 0;
    for (Sisi s : mst)
        panjangJalanTerpendek += s.panjangJalan;

    cout << "Panjang jalan terpendek yang dapat diaspal: " << panjangJalanTerpendek << endl;

    return 0;
}
