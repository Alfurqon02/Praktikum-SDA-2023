#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <stack>

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

std::map<node_t, std::string> node_name;

// graph dalam bentuk adjacency matrix
double graph[NODE_COUNT][NODE_COUNT];

void add_edge(node_t src, node_t dst, double weight) {
    graph[src][dst] = weight;
    graph[dst][src] = weight;
}

int main() {
    node_name[RUMAH] = "Rumah";
    node_name[UNIVERSITAS_SEBELAS_MARET] = "Universitas Sebelas Maret";
    node_name[RUMAH_SAKIT_DR_MOEWARDI] = "Rumah Sakit dr. Moewardi";
    node_name[SMP_NEGERI_8_SURAKARTA] = "SMP Negeri 8 Surakarta";
    node_name[PECEL_MADIUN_PUCANGSAWIT] = "Pecel Madiun Pucangsawit";
    node_name[SMP_NEGERI_4_SURAKARTA] = "SMP Negeri 4 Surakarta";
    node_name[SMA_NEGERI_3_SURAKARTA] = "SMA Negeri 3 Surakarta";

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

    // himpunan node yang sudah dikunjungi dan belum dikunjungi
    std::set<node_t> visited, unvisited;
    for (int i = 0; i < NODE_COUNT; i++) {
        unvisited.insert((node_t)i);
    }

    // jarak ke node yang bersangkutan
    std::map<node_t, double> path_distance;
    for (int i = 0; i < NODE_COUNT; i++) {
        path_distance[(node_t)i] = INFINITY;
    }

    // parent dari tiap-tiap node
    std::map<node_t, node_t> path_parent;
    for (int i = 0; i < NODE_COUNT; i++) {
        path_parent[(node_t)i] = NODE_INVALID;
    }

    // atur node asal dan tujuan
    node_t node_src = UNIVERSITAS_SEBELAS_MARET;
    node_t node_dst = SMP_NEGERI_4_SURAKARTA;

    // atur supaya node asal dikunjungi pertama kali
    path_distance[node_src] = 0.0;

    while (!unvisited.empty()) {
        // ambil node unvisited dgn jarak terpendek
        node_t pick = NODE_INVALID;
        for (
            std::set<node_t>::iterator it = unvisited.begin();
            it != unvisited.end();
            ++it
        ) {
            if (pick == NODE_INVALID) {
                pick = *it;
            } else {
                if (path_distance[*it] < path_distance[pick]) {
                    pick = *it;
                }
            }
        }

        // tandai sudah dikunjungi
        visited.insert(pick);
        unvisited.erase(pick);

        // cek apabila node tujuan sudah dikunjungi
        // jika sudah langsung berhenti saja
        if (visited.count(node_dst) == 1) {
            break;
        }

        // perbarui jarak-jarak tetangga
        for (int i = 0; i < NODE_COUNT; i++) {
            if ((graph[pick][i] > 0.0) && (unvisited.count((node_t)i) == 1)) {
                // perbarui apabila jarak baru lebih kecil dari jarak sebelumnya
                double distance_old = path_distance[(node_t)i];
                double distance_new = path_distance[pick] + graph[pick][i];
                if (distance_new < distance_old) {
                    path_distance[(node_t)i] = distance_new;
                    path_parent[(node_t)i] = pick;
                }
            }
        }
    }

    // tampilkan rute terpendek
    // menggunakan bantuan stack supaya urutannya sesuai
    double path_shortest_distance = 0.0;
    std::stack<node_t> path_stack;
    for (node_t path = node_dst; path != NODE_INVALID; path = path_parent[path]) {
        path_stack.push(path);
    }
    while (!path_stack.empty()) {
        node_t path = path_stack.top();
        path_stack.pop();

        double weight = 0.0;
        if (path != node_src) {
            weight = graph[path][path_parent[path]];
            path_shortest_distance = path_shortest_distance + weight;
        }

        std::cout << "Path includes node: " << node_name[path] << " (travels " << weight << " units)" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Distance: " << path_shortest_distance << " units" << std::endl;

    return 0;
}
