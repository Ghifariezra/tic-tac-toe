/*
    Final Project - Game Tic Tac Toe
    File Name: main.cpp

    Kelompok:
        •⁠ Dheka Airlangga (45242100?)
        •⁠ Ghifari Ezra Ramadhan (4524210041)
        •⁠ Belvaria Henriyani (45242100?)

    Materi:
        •⁠  ⁠Pointer
        •⁠  ⁠⁠Stack
        •⁠  ⁠⁠Queue
        •⁠  ⁠⁠Sorting
        •⁠  ⁠⁠Searching
        •⁠  ⁠⁠Tree
        •⁠  ⁠⁠Graph
*/

#include <iostream>
#include <cstring>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int val) : data(val), next(nullptr) {}
};

struct Stack
{
    StackNode *top = nullptr;

    /// @brief Menambahkan elemen ke atas tumpukan
    /// @param val Nilai yang akan ditambahkan ke tumpukan
    /// @return void
    ///
    /// Fungsi ini menambahkan elemen baru dengan nilai `val` ke atas
    /// tumpukan dengan membuat node baru dan menghubungkannya sebagai
    /// elemen teratas dari tumpukan.

    /// @brief Menambahkan elemen ke atas tumpukan
    /// @param val Nilai yang akan ditambahkan ke tumpukan
    /// @return void
    ///
    /// Fungsi ini menambahkan elemen baru dengan nilai `val` ke atas
    /// tumpukan dengan membuat node baru dan menghubungkannya sebagai
    /// elemen teratas dari tumpukan.

    void push(int val)
    {
        StackNode *newNode = new StackNode(val);
        newNode->next = top;
        top = newNode;
    }

    /// @brief Mengeluarkan elemen teratas dari tumpukan
    /// @return Nilai elemen teratas dari tumpukan, atau -1 jika tumpukan kosong
    ///
    /// Fungsi ini mengeluarkan elemen teratas dari tumpukan dan mengembalikan
    /// nilai dari elemen tersebut. Jika tumpukan kosong, maka fungsi ini akan
    /// mengembalikan -1.
    int pop()
    {
        if (!top)
            return -1;
        int val = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    /// @brief Mengecek apakah tumpukan kosong
    /// @return true jika tumpukan kosong, false jika tumpukan tidak kosong
    ///
    /// Fungsi ini mengecek apakah tumpukan kosong dengan cara
    /// memeriksa apakah pointer `top` bernilai `nullptr` atau tidak.
    /// Jika `top` bernilai `nullptr`, maka fungsi ini akan mengembalikan
    /// nilai `true`, sebaliknya akan mengembalikan nilai `false`.
    bool isEmpty()
    {
        return top == nullptr;
    }

    /// @brief Destructor untuk membersihkan memori yang digunakan oleh tumpukan
    ///
    /// Destructor ini akan menghapus semua elemen yang ada di dalam tumpukan
    /// dengan cara memanggil fungsi `pop()` secara berulang hingga tumpukan
    /// menjadi kosong. Hal ini dilakukan untuk membersihkan memori yang
    /// digunakan oleh tumpukan.
    ~Stack()
    {
        while (top)
            pop(); // Clean up memory
    }
};

struct QueueNode
{
    char data[10];
    QueueNode *next;

    /// @brief Constructor untuk membuat QueueNode dengan nilai `val`
    ///
    /// Constructor ini akan membuat QueueNode dengan nilai `val` dan
    /// menginisialisasi pointer `next` dengan nilai `nullptr`.
    ///
    /// @param val Nilai yang akan disimpan di dalam QueueNode
    QueueNode(const char *val) : next(nullptr)
    {
        strcpy(data, val);
    }
};

struct Queue
{
    QueueNode *front = nullptr;
    QueueNode *rear = nullptr;

    /// @brief Constructor untuk membuat antrian dengan 2 elemen awal: "Player" dan "AI"
    ///
    /// Constructor ini akan membuat antrian yang awalnya berisi 2 elemen: "Player" dan "AI".
    /// Hal ini dilakukan untuk memudahkan dalam mengatur giliran pemain dan AI di dalam permainan Tic-Tac-Toe.
    ///
    /// @see enqueue
    Queue()
    {
        // enqueue("AI"); // Kalau mau AI bermain lebih dulu.

        enqueue("Player");
        enqueue("AI");
    }

    /// @brief Menambahkan elemen ke dalam antrian
    ///
    /// Fungsi ini menambahkan elemen `val` ke dalam antrian dengan cara
    /// membuat node baru dan menghubungkannya sebagai elemen terakhir
    /// dari antrian. Jika antrian awalnya kosong, maka fungsi ini akan
    /// menginisialisasi pointer `front` dan `rear` dengan nilai `newNode`.
    /// Jika antrian tidak kosong, maka fungsi ini akan menghubungkan
    /// node terakhir dengan node baru yang dibuat.
    ///
    /// @param val Nilai yang akan ditambahkan ke antrian
    void enqueue(const char *val)
    {
        QueueNode *newNode = new QueueNode(val);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    /// @brief Mengeluarkan elemen terdepan dari antrian
    ///
    /// Fungsi ini mengeluarkan elemen terdepan dari antrian dan mengembalikan
    /// nilai dari elemen tersebut. Jika antrian awalnya kosong, maka fungsi ini
    /// akan mengembalikan nullptr.
    ///
    /// @return Nilai elemen terdepan dari antrian, atau nullptr jika antrian kosong
    char *dequeue()
    {
        if (!front)
            return nullptr;
        QueueNode *temp = front;
        char *val = temp->data;
        front = front->next;
        if (!front)
            rear = nullptr;
        return val;
    }

    /// @brief Mengembalikan nilai elemen terdepan dari antrian
    ///
    /// Fungsi ini mengembalikan nilai dari elemen terdepan dari antrian
    /// tanpa mengeluarkannya dari antrian. Jika antrian awalnya kosong,
    /// maka fungsi ini akan mengembalikan nullptr.
    ///
    /// @return Nilai elemen terdepan dari antrian, atau nullptr jika antrian kosong
    char *peek()
    {
        if (!front)
            return nullptr;
        return front->data;
    }

    /// @brief Destructor untuk membersihkan memori yang digunakan oleh antrian
    ///
    /// Destructor ini akan menghapus semua elemen yang ada di dalam antrian
    /// dengan cara memanggil fungsi `dequeue()` secara berulang hingga antrian
    /// menjadi kosong. Hal ini dilakukan untuk membersihkan memori yang
    /// digunakan oleh antrian.
    ~Queue()
    {
        while (front)
        {
            QueueNode *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

struct TreeNode
{
    int value;
    TreeNode *left, *right;
    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    TreeNode *root = nullptr;

    /// @brief Menambahkan nilai ke dalam BST
    /// @param val Nilai yang akan ditambahkan ke BST
    /// @return void
    void insert(int val)
    {
        root = insertRec(root, val);
    }

    /// @brief Melakukan traversal inorder pada BST
    /// @param node Akar subtree yang akan di-traversal
    /// @return void
    ///
    /// Melakukan traversal inorder pada BST dengan cara
    /// pertama mengunjungi subtree kiri, lalu mengunjungi
    /// node, dan terakhir mengunjungi subtree kanan.
    void inorder(TreeNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    /// @brief Mencetak isi BST langkah pemain dengan traversal inorder
    ///
    /// Mencetak isi BST langkah pemain dengan traversal inorder
    /// dalam bentuk "Inorder BST langkah pemain: <langkah 1> <langkah 2> ... <langkah n>"\n
    /// diikuti dengan baris baru.
    void print()
    {
        cout << "Inorder BST langkah pemain: ";
        inorder(root);
        cout << endl;
    }

private:
    /// @brief Recursive helper function to insert a value into the BST
    /// @param node Akar subtree yang akan di-insert
    /// @param val Nilai yang akan di-insert
    /// @return Akar subtree yang telah di-insert
    ///
    /// Melakukan insert secara rekursif dengan cara
    /// jika node tidak ada, maka akan dibuat node baru
    /// lalu jika val lebih kecil dari node->value maka
    /// akan di-insert ke subtree kiri, sebaliknya akan
    /// di-insert ke subtree kanan.
    TreeNode *insertRec(TreeNode *node, int val)
    {
        if (!node)
            return new TreeNode(val);
        if (val < node->value)
            node->left = insertRec(node->left, val);
        else
            node->right = insertRec(node->right, val);
        return node;
    }
};

class Graph
{
public:
    int adj[10][2];
    int size[10];

    /// @brief Constructor untuk Graph yang menginisialisasi adjacency list
    ///        untuk representasi graf papan Tic-Tac-Toe. Setiap posisi pada
    ///        papan dihubungkan dengan posisi yang berdekatan secara horizontal
    ///        dan vertikal jika ada.

    Graph()
    {
        memset(size, 0, sizeof(size));
        for (int i = 1; i <= 9; ++i)
        {
            if (i % 3 != 0)
                adj[i][size[i]++] = i + 1;
            if (i <= 6)
                adj[i][size[i]++] = i + 3;
        }
    }

    /// @brief Mencetak isi adjacency list untuk representasi graf papan Tic-Tac-Toe\n
    ///        dalam bentuk "Graf papan Tic-Tac-Toe:" diikuti dengan baris baru,\n
    ///        lalu untuk setiap posisi 1 sampai 9 di papan, akan di cetak "Posisi X terhubung dengan: <posisi 1> <posisi 2> ... <posisi n>"\n
    ///        diikuti dengan baris baru.\n
    void print()
    {
        cout << "\nGraf papan Tic-Tac-Toe:\n";
        for (int i = 1; i <= 9; ++i)
        {
            cout << "Posisi " << i << " terhubung dengan: ";
            for (int j = 0; j < size[i]; ++j)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

class TicTacToe
{
private:
    char board[3][3];
    Stack moveHistory;
    Queue giliran;
    int langkahPlayer[20];
    int langkahSize = 0;
    BST bstLangkah;
    Graph papanGraf;

    /// @brief Menginisialisasi papan Tic-Tac-Toe dengan angka dari 1 hingga 9
    ///
    /// Mengisi setiap sel pada papan Tic-Tac-Toe dengan angka dari 1 hingga 9
    /// berturut-turut, mewakili posisi yang dapat dipilih oleh pemain.

    void init_board()
    {
        char *ptr = &board[0][0];
        for (int i = 0; i < 9; ++i)
            // Mengisi elemen array dengan karakter '1' sampai '9'
            // '1' memiliki nilai ASCII 49, jadi '1' + i akan menghasilkan '1', '2', ..., '9'
            *(ptr + i) = '1' + i;
    }

    /// @brief Mencetak papan Tic-Tac-Toe ke layar.
    ///
    /// Mencetak papan Tic-Tac-Toe ke layar dengan bentuk yang sesuai.
    /// Papan akan di cetak dengan format sebagai berikut:\n
    ///     |     |
    ///  X  |  O  |  3
    ///     |     |
    ///_____|_____|_____
    ///     |     |
    ///  4  |  5  |  6
    ///     |     |
    ///_____|_____|_____
    ///     |     |
    ///  7  |  8  |  9
    ///     |     |
    ///\n
    /// Dengan X dan O mewakili posisi yang telah diisi oleh pemain dan komputer.\n
    /// Jika posisi kosong maka akan di cetak nomor 1-9 sesuai dengan posisi yang\n
    /// kosong tersebut.\n
    void display_board()
    {
        cout << "\nTIC TAC TOE\nPlayer [X] vs Komputer [O]\n\n";
        for (int i = 0; i < 3; ++i)
        {
            cout << "     |     |     \n";
            cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "\n";
            if (i != 2)
                cout << "_____|_____|_____\n";
        }
        cout << "     |     |     \n\n";
    }

    /// @brief Memeriksa apakah langkah pemain valid atau tidak.
    ///
    /// Fungsi ini memeriksa apakah langkah pemain valid atau tidak dengan
    /// cara memeriksa apakah posisi yang diinput oleh pemain kosong atau
    /// tidak. Jika posisi kosong maka fungsi ini akan mengembalikan nilai
    /// true, sebaliknya akan mengembalikan nilai false.\n
    ///
    /// @param choice Langkah yang diinput oleh pemain.
    /// @param row    Baris dari posisi yang diinput oleh pemain.
    /// @param col    Kolom dari posisi yang diinput oleh pemain.
    /// @return true jika langkah valid, false jika langkah tidak valid.\n
    bool is_valid_move(int choice, int &row, int &col)
    {
        if (choice < 1 || choice > 9)
            return false;
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        return board[row][col] != 'X' && board[row][col] != 'O';
    }

    /// @brief Memeriksa apakah ada pemain yang menang di papan Tic-Tac-Toe
    ///
    /// Fungsi ini memeriksa apakah ada tiga simbol yang sama (X atau O) pada
    /// satu baris, kolom, atau diagonal di papan Tic-Tac-Toe. Jika ada, maka
    /// fungsi ini mengembalikan nilai true, menandakan bahwa ada pemain yang
    /// menang. Jika tidak ada tiga simbol yang sama dalam satu baris, kolom,
    /// atau diagonal, maka fungsi ini mengembalikan nilai false.

    bool check_win()
    {
        for (int i = 0; i < 3; ++i)
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
                return true;
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
            return true;
        return false;
    }

    /// @brief Memeriksa apakah permainan berakhir dengan hasil seri
    ///
    /// Fungsi ini memeriksa apakah semua posisi pada papan Tic-Tac-Toe sudah
    /// terisi tanpa ada pemenang. Fungsi ini mengembalikan nilai true jika
    /// semua posisi terisi oleh simbol 'X' atau 'O', menandakan bahwa tidak
    /// ada langkah lagi yang dapat dilakukan dan permainan berakhir seri.
    /// Jika ada posisi yang masih kosong, fungsi ini mengembalikan nilai false.

    bool is_draw()
    {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    /// @brief Mengatur langkah pemain Tic-Tac-Toe
    ///
    /// Fungsi ini mengatur langkah pemain Tic-Tac-Toe. Pemain akan di minta
    /// untuk memasukkan posisi (1-9) yang ingin diisi dengan simbol 'X'.
    /// Jika posisi yang dimasukkan sudah terisi atau tidak valid, maka
    /// pemain akan di minta untuk memasukkan posisi lagi. Jika posisi yang
    /// dimasukkan valid, maka fungsi ini akan menambahkan simbol 'X' ke
    /// papan Tic-Tac-Toe dan menambahkan langkah ke dalam BST dan array
    /// langkah pemain.
    void player_turn()
    {
        int choice, row, col;
        while (true)
        {
            cout << "Player [X] Masukkan posisi (1-9): ";
            cin >> choice;
            if (is_valid_move(choice, row, col))
            {
                board[row][col] = 'X';
                moveHistory.push(choice);
                langkahPlayer[langkahSize++] = choice;
                bstLangkah.insert(choice);
                break;
            }
            else
            {
                cout << "Langkah tidak valid. Ulangi.\n";
            }
        }
    }

    /// @brief Mengatur langkah AI Tic-Tac-Toe
    ///
    /// Fungsi ini mengatur langkah AI untuk Tic-Tac-Toe. AI akan mencari posisi
    /// kosong pertama (1-9) yang tersedia dan menempatkan simbol 'O' pada posisi tersebut.
    /// Langkah tersebut kemudian ditambahkan ke dalam history langkah.

    void ai_turn()
    {
        for (int i = 1; i <= 9; ++i)
        {
            int row, col;
            if (is_valid_move(i, row, col))
            {
                board[row][col] = 'O';
                moveHistory.push(i);
                break;
            }
        }
    }

    /// @brief Mencari langkah di history pemain
    ///
    /// Fungsi ini mencari apakah langkah target ada di history pemain.
    /// Jika langkah target ditemukan maka fungsi ini akan mencetak
    /// "Langkah <target> ditemukan di history pemain." ke layar, jika
    /// tidak maka fungsi ini akan mencetak "Langkah <target> tidak
    /// ditemukan di history pemain." ke layar.
    void searchLangkah(int target)
    {
        bool found = false;
        for (int i = 0; i < langkahSize; ++i)
        {
            if (langkahPlayer[i] == target)
            {
                found = true;
                break;
            }
        }
        if (found)
            cout << "Langkah " << target << " ditemukan di history pemain.\n";
        else
            cout << "Langkah " << target << " tidak ditemukan di history pemain.\n";
    }

    /// @brief Melakukan pengurutan langkah-langkah pemain dengan Selection Sort
    ///
    /// Fungsi ini menerima array of integer yang berisi langkah-langkah pemain dan
    /// jumlah elemen dalam array sebagai parameter, lalu melakukan pengurutan dengan
    /// menggunakan algoritma Selection Sort. Setelah pengurutan selesai, fungsi ini
    /// akan mengembalikan array yang telah diurutkan dalam bentuk ascending.
    ///
    /// Selection Sort adalah algoritma pengurutan yang membandingkan setiap elemen
    /// dalam array dengan elemen lainnya dan menggeser posisi elemen jika perlu.
    /// Pengurutan dilakukan dengan cara memilih elemen terkecil dari array dan
    /// menggeser posisinya ke awal array, lalu memilih elemen terkecil berikutnya
    /// dan menggeser posisinya ke awal array, dan seterusnya hingga array terurut
    /// dengan benar.
    ///
    /// Contoh penggunaan:
    /// int arr[] = {5, 2, 8, 3, 1, 4, 6};
    /// int n = sizeof(arr) / sizeof(arr[0]);
    /// sortLangkah(arr, n);
    /// // arr sekarang menjadi {1, 2, 3, 4, 5, 6, 8}
    void sortLangkah(int *arr, int n)
    {
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
    }

public:
    /// @brief Memulai permainan Tic-Tac-Toe
    ///
    /// Fungsi ini memulai permainan Tic-Tac-Toe dengan menginisialisasi papan
    /// permainan, lalu memanggil fungsi-fungsi lain untuk mengatur langkah
    /// pemain dan komputer. Setelah permainan selesai, fungsi ini akan
    /// mengurutkan langkah-langkah pemain dengan menggunakan Selection Sort
    /// dan menampilkan isi BST langkah pemain dalam bentuk inorder traversal.
    ///
    /// Permainan akan diakhiri jika terdapat pemenang atau bila permainan
    /// berakhir seri.
    void play()
    {
        init_board();
        papanGraf.print();

        while (true)
        {
            display_board();
            char *current = giliran.dequeue();

            // Hasil pemilihan giliran: Player atau AI
            cout << "Giliran: " << current << endl;

            if (current == nullptr)
                break;

            if (strcmp(current, "Player") == 0)
                player_turn();
            else
            {
                cout << "Komputer berpikir...\n";
                ai_turn();
            }

            if (check_win())
            {
                display_board();
                cout << "Pemenang: " << current << endl;
                break;
            }
            else if (is_draw())
            {
                display_board();
                cout << "Permainan Seri!\n";
                break;
            }

            giliran.enqueue(current);
        }

        int history[20];
        int count = 0;
        while (!moveHistory.isEmpty())
        {
            history[count++] = moveHistory.pop();
        }

        sortLangkah(history, count);
        cout << "\nLangkah terurut (Sorting): ";
        for (int i = 0; i < count; ++i)
            cout << history[i] << " ";
        cout << endl;

        searchLangkah(5);

        bstLangkah.print();
    }
};

/**
 * @brief Entry point dari program.
 *
 * Fungsi main ini memulai permainan Tic-Tac-Toe dengan membuat objek
 * TicTacToe dan memanggil fungsi play() untuk memulai permainan.
 *
 * @return 0 jika permainan selesai.
 */
int main()
{
    TicTacToe game;
    game.play();
    return 0;
}
