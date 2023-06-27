#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Representasi struktur graph
struct Edge {
    int tujuan;
    int bobot;
};

// Fungsi Dijkstra untuk mencari rute terpendek dari rumah ke sekolah
vector<int> dijkstra(vector<vector<Edge>>& graph, int rumah, int jumlahVertex) {
    // Vektor jarak minimum dari rumah ke setiap vertex
    vector<int> jarak(jumlahVertex, INT_MAX);

    // Inisialisasi jarak rumah ke dirinya sendiri dengan 0
    jarak[rumah] = 0;

    // Priority queue untuk memilih vertex dengan jarak minimum
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Masukkan rumah ke priority queue
    pq.push(make_pair(0, rumah));

    while (!pq.empty()) {
        // Ambil vertex dengan jarak minimum dari priority queue
        int u = pq.top().second;
        pq.pop();

        // Iterasi melalui semua tetangga vertex u
        for (const Edge& edge : graph[u]) {
            int v = edge.tujuan;
            int bobot = edge.bobot;

            // Perbarui jarak minimum jika ditemukan jarak yang lebih pendek
            if (jarak[u] + bobot < jarak[v]) {
                jarak[v] = jarak[u] + bobot;
                pq.push(make_pair(jarak[v], v));
            }
        }
    }

    return jarak;
}

int main() {
    int jumlahVertex = 7;
    int rumah = 0;
    int sekolah = 6;

    // Representasi graph menggunakan adjacency list
    vector<vector<Edge>> graph(jumlahVertex);

    // Inisialisasi graph dengan sisi-sisi dan bobotnya
    graph[0].push_back({1, 2});   // Rumah -> Vertex 1, bobot 2
    graph[0].push_back({2, 4});   // Rumah -> Vertex 2, bobot 4
    graph[1].push_back({2, 1});   // Vertex 1 -> Vertex 2, bobot 1
    graph[1].push_back({3, 7});   // Vertex 1 -> Vertex 3, bobot 7
    graph[2].push_back({4, 3});   // Vertex 2 -> Vertex 4, bobot 3
    graph[3].push_back({5, 1});   // Vertex 3 -> Vertex 5, bobot 1
    graph[4].push_back({6, 5});   // Vertex 4 -> Sekolah, bobot 5
    graph[5].push_back({6, 2});   // Vertex 5 -> Sekolah, bobot 2

    // Panggil fungsi Dijkstra untuk mencari rute terpendek dari rumah ke sekolah
    vector<int> jarak = dijkstra(graph, rumah, jumlahVertex);

    // Cetak jarak terpendek dari rumah ke sekolah
    cout << "Jarak terpendek dari rumah ke sekolah: " << jarak[sekolah] << endl;

    return 0;
}
