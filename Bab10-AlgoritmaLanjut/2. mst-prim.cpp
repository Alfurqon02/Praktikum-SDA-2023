#include <iostream>
#include <list>
#include <set>
#include <map>
#include <cmath>

enum node_t {
    RUMAH,
    UNIVERSITAS_SEBELAS_MARET,
    RUMAH_SAKIT_DR_MOEWARDI,
    SMP_NEGERI_8_SURAKARTA,
    PECEL_MADIUN_PUCANGSAWIT,
    SMP_NEGERI_4_SURAKARTA,
    SMA_NEGERI_3_SURAKARTA,

    NODE_COUNT,
    NODE_INVALID = -1
};

// graph dalam bentuk adjacency matrix
double graph[NODE_COUNT][NODE_COUNT];

void add_edge(node_t src, node_t dst, double weight) {
    graph[src][dst] = weight;
    graph[dst][src] = weight;
}

int main() {
    for (int i = 0; i < NODE_COUNT; i++) {
        for (int j = 0; j < NODE_COUNT; j++) {
            if (i == j) {
                graph[i][j] = 0.0;
            } else {
                graph[i][j] = -1.0;
            }
        }
    }

    add_edge(RUMAH, UNIVERSITAS_SEBELAS_MARET, 2.97);
    add_edge(RUMAH, PECEL_MADIUN_PUCANGSAWIT, 2.54);
    add_edge(UNIVERSITAS_SEBELAS_MARET, RUMAH_SAKIT_DR_MOEWARDI, 2.86);
    add_edge(UNIVERSITAS_SEBELAS_MARET, SMP_NEGERI_8_SURAKARTA, 1.61);
    add_edge(RUMAH_SAKIT_DR_MOEWARDI, SMP_NEGERI_4_SURAKARTA, 1.43);
    add_edge(SMP_NEGERI_8_SURAKARTA, SMP_NEGERI_4_SURAKARTA, 2.99);
    add_edge(SMP_NEGERI_8_SURAKARTA, SMA_NEGERI_3_SURAKARTA, 1.25);
    add_edge(PECEL_MADIUN_PUCANGSAWIT, SMP_NEGERI_4_SURAKARTA, 4.00);
    add_edge(PECEL_MADIUN_PUCANGSAWIT, SMA_NEGERI_3_SURAKARTA, 2.28);

    // himpunan MST dan non-MST
    std::set<node_t> mst_inside, mst_outside;
    for (int i = 0; i < NODE_COUNT; i++) {
        mst_outside.insert((node_t)i);
    }

    // bobot dan node asal MST
    std::map<node_t, double> mst_weight;
    std::map<node_t, node_t> mst_parent;
    for (int i = 0; i < NODE_COUNT; i++) {
        mst_weight[(node_t)i] = INFINITY;
        mst_parent[(node_t)i] = NODE_INVALID;
    }

    // mulai dari node RUMAH
    mst_weight[RUMAH] = 0.0;
    mst_parent[RUMAH] = NODE_INVALID;

    while (!mst_outside.empty()) {
        // pilih node dgn bobot MST terkecil
        node_t pick = NODE_INVALID;
        for (
            std::set<node_t>::iterator it = mst_outside.begin();
            it != mst_outside.end();
            ++it
        ) {
            if (pick == NODE_INVALID) {
                pick = *it;
            } else {
                if (mst_weight[*it] < mst_weight[pick]) {
                    pick = *it;
                }
            }
        }

        // masukkan ke dalam himpunan MST, dan keluarkan dari himpunan non-MST
        mst_inside.insert(pick);
        mst_outside.erase(pick);

        // perbarui semua nilai bobot MST dari tetangga non-MST dari node yang dipilih
        for (int i = 0; i < NODE_COUNT; i++) {
            if ((graph[pick][i] > 0.0) && (graph[pick][i] != INFINITY) && (mst_outside.count((node_t)i) == 1)) {
                double w = graph[pick][i];

                // perbarui jika bobot edge lebih kecil dari bobot MST sebelumnya
                if (w < mst_weight[(node_t)i]) {
                    mst_weight[(node_t)i] = w;
                    mst_parent[(node_t)i] = pick;
                }
            }
        }
    }

    std::list<double> mst; // edge yang termasuk MST (untuk ditampilkan ke layar saja)
    for (
        std::map<node_t, node_t>::iterator it = mst_parent.begin();
        it != mst_parent.end();
        ++it
    ) {
        if (it->second != NODE_INVALID) {
            mst.push_back(graph[it->first][it->second]);
        }
    }

    double mst_total_weight = 0.0;
    for (
        std::list<double>::iterator it = mst.begin();
        it != mst.end();
        ++it
    ) {
        std::cout << "MST includes edge: " << *it << std::endl;
        mst_total_weight = mst_total_weight + *it;
    }
    std::cout << std::endl;
    std::cout << "MST total weight: " << mst_total_weight << std::endl;

    return 0;
}
