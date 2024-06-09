#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct tugas {
    string description,prioritas;
    bool selesai;
    tugas(string desc, string prio) : description(desc), prioritas(prio), selesai(false) {}
};

class pengaturan {
private:
    vector<tugas> Tugas;

public:
    void tambah(const string description, const string prioritas) {
        Tugas.emplace_back(description, prioritas);
        cout << "tugas berhasil ditambahkan\n";
    }

    void tampilkan() const {
        if (Tugas.empty()) {
            cout << "tidak ada tugas\n";
            return;
        }

        for (size_t i = 0; i < Tugas.size(); ++i) {
            cout << i + 1 << ". " << Tugas[i].description << " (Prioritas: " << Tugas[i].prioritas << ")";
            if (Tugas[i].selesai) {
                cout << " [Selesai]";
            }
            cout << "\n";
        }
    }

    void status_tugas(int index) {
        if (index > 0 && index <= Tugas.size()) {
            Tugas[index - 1].selesai = true;
            cout << "Tugas berhasil ditandai sebagai selesai.\n";
        } else {
            cout << "Nomor tugas tidak valid.\n";
        }
    }

    void hapus(int index) {
        if (index > 0 && index <= Tugas.size()) {
            Tugas.erase(Tugas.begin() + index - 1);
            cout << "Tugas berhasil dihapus.\n";
        } else {
            cout << "Nomor tugas tidak valid.\n";
        }
    }
};

void tambah(pengaturan &manage);
void tampilkan(const pengaturan &manage);
void status_tugas(pengaturan &manage);
void hapus(pengaturan &manage);

int main() {
    pengaturan manage;
    int choice;

    while (true) {
        cout << "=== Daftar Tugas ===\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Tampilkan Semua Tugas\n";
        cout << "3. Tandai Tugas Selesai\n";
        cout << "4. Hapus Tugas\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // mengabaikan karakter newline setelah memasukkan angka

        switch (choice) {
            case 1:
                tambah(manage);
                break;
            case 2:
                tampilkan(manage);
                break;
            case 3:
                status_tugas(manage);
                break;
            case 4:
                hapus(manage);
                break;
            case 5:
                return 0;
            default:
                cout << "pilihan tidak tersedia\n";
        }
    }
    return 0;
}
void tambah(pengaturan &manage) {
    string description, priority;
    cout << "Masukkan deskripsi tugas: ";
    getline(cin, description);
    cout << "Masukkan prioritas tugas: ";
    getline(cin, priority);
    manage.tambah(description, priority);
}

void tampilkan(const pengaturan &manage) {
    manage.tampilkan();
}

void status_tugas(pengaturan &manage) {
    int index;
    cout << "Masukkan nomor tugas yang ingin ditandai sebagai selesai: ";
    cin >> index;
    cin.ignore(); // mengabaikan karakter newline setelah memasukkan angka
    manage.status_tugas(index);
}

void hapus(pengaturan &manager) {
    int index;
    cout << "Masukkan nomor tugas yang ingin dihapus: ";
    cin >> index;
    cin.ignore(); // mengabaikan karakter newline setelah memasukkan angka
    manager.hapus(index);
}