#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    string priority;
    bool completed;

    Task(string desc, string prio) : description(desc), priority(prio), completed(false) {}
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description, const string& priority) {
        tasks.emplace_back(description, priority);
        cout << "Tugas berhasil ditambahkan.\n";
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "Tidak ada tugas.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " (Prioritas: " << tasks[i].priority << ")";
            if (tasks[i].completed) {
                cout << " [Selesai]";
            }
            cout << "\n";
        }
    }

    void markTaskCompleted(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Tugas berhasil ditandai sebagai selesai.\n";
        } else {
            cout << "Nomor tugas tidak valid.\n";
        }
    }

    void deleteTask(int index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Tugas berhasil dihapus.\n";
        } else {
            cout << "Nomor tugas tidak valid.\n";
        }
    }
};

void addTask(TaskManager& manager);
void displayTasks(const TaskManager& manager);
void markTaskCompleted(TaskManager& manager);
void deleteTask(TaskManager& manager);

int main() {
    TaskManager manager;
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
        cin.ignore(); 

        switch (choice) {
            case 1:
                addTask(manager);
                break;
            case 2:
                displayTasks(manager);
                break;
            case 3:
                markTaskCompleted(manager);
                break;
            case 4:
                deleteTask(manager);
                break;
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}

void addTask(TaskManager& manager) {
    string description, priority;
    cout << "Masukkan deskripsi tugas: ";
    getline(cin, description);
    cout << "Masukkan prioritas tugas: ";
    getline(cin, priority);
    manager.addTask(description, priority);
}

void displayTasks(const TaskManager& manager) {
    manager.displayTasks();
}

void markTaskCompleted(TaskManager& manager) {
    int index;
    cout << "Masukkan nomor tugas yang ingin ditandai sebagai selesai: ";
    cin >> index;
    cin.ignore(); 
    manager.markTaskCompleted(index);
}

void deleteTask(TaskManager& manager) {
    int index;
    cout << "Masukkan nomor tugas yang ingin dihapus: ";
    cin >> index;
    cin.ignore(); 
    manager.deleteTask(index);
}
