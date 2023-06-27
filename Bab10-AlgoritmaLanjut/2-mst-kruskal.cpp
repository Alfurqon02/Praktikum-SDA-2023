#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Representasi struktur graph
struct Sisi {
    int desa1;
    int desa2;
    int panjangJalan;
};

// Fungsi untuk membandingkan panjang jalan pada sisi
bool perbandinganPanjangJalan(const Sisi& s1, const Sisi& s2) {
    return s1.panjangJalan < s2.panjangJalan;
}

// Temukan subset dari sebuah desa
int temukanSubset(vector<int>& subset, int desa) {
    if (subset[desa] != desa)
        subset[desa] = temukanSubset(subset, subset[desa]);
    return subset[desa];
}

// Gabungkan dua subset menjadi satu subset
void gabungkanSubset(vector<int>& subset, int desa1, int desa2) {
    int desa1Subset = temukanSubset(subset, desa1);
    int desa2Subset = temukanSubset(subset, desa2);
    subset[desa1Subset] = desa2Subset;
}

// Algoritma Kruskal untuk mencari Minimum Spanning Tree
vector<Sisi> kruskalMST(vector<Sisi>& graph, int jumlahDesa) {
    vector<Sisi> mst; // Minimum Spanning Tree
    vector<int> subset(jumlahDesa);

    // Inisialisasi subset untuk setiap desa
    for (int desa = 0; desa < jumlahDesa; desa++)
        subset[desa] = desa;

    // Urutkan sisi berdasarkan panjang jalan dari terkecil ke terbesar
    sort(graph.begin(), graph.end(), perbandinganPanjangJalan);

    // Proses setiap sisi secara berurutan
    for (Sisi s : graph) {
        int desa1Subset = temukanSubset(subset, s.desa1);
        int desa2Subset = temukanSubset(subset, s.desa2);

        // Jika sisi ini tidak membentuk siklus, tambahkan ke MST
        if (desa1Subset != desa2Subset) {
            mst.push_back(s);
            gabungkanSubset(subset, desa1Subset, desa2Subset);
        }
    }

    return mst;
}

int main() {
    int jumlahDesa = 6;
    int jumlahJalan = 9;

    vector<Sisi> graph = {
        {0, 1, 4},
        {0, 2, 2},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, 8},
        {2, 4, 10},
        {3, 4, 2},
        {3, 5, 6},
        {4, 5, 3}
    };

    // Cari Minimum Spanning Tree menggunakan algoritma Kruskal
    vector<Sisi> mst = kruskalMST(graph, jumlahDesa);

    // Hitung panjang jalan terpendek yang dapat diaspal
    int panjangJalanTerpendek = 0;
    for (Sisi s : mst)
        panjangJalanTerpendek += s.panjangJalan;

    cout << "Panjang jalan terpendek yang dapat diaspal: " << panjangJalanTerpendek << endl;

    return 0;
}
