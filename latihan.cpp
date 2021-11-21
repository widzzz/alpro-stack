//header
#include<iostream>
#define maxstack 2
using namespace std;

//struct declaration
struct STACK{
    int top;
    string judulBuku[1];
};

//isi input variable
string isi;

//assign struct as abstract type
struct STACK tumpukanBuku;

//check stack is full?
bool isfull()
{
    if(tumpukanBuku.top == maxstack)
        return true;
    else
        return false;
}

//check stack is empty
bool isempty()
{
    if(tumpukanBuku.top == -1)
        return true;
    else
        return false;
}

//adds item to stack
void push(string isi){
    if(isfull() == true){
        cout << "Penuh!!";
    } else{
        tumpukanBuku.top++;
        tumpukanBuku.judulBuku[tumpukanBuku.top]=isi;
    }
}

//remove items in stack
void pop()
{
    if(isempty() == true)
    {
        cout << "Tidak ada tumpukan buku! (kosong)";
    } else{
        cout << "Buku yang diambil : " <<tumpukanBuku.judulBuku[tumpukanBuku.top]<<endl;
        tumpukanBuku.top--;
    }
}

//print all stack items
void print(){
    for(int i=0; i<=tumpukanBuku.top; i++){
        cout << tumpukanBuku.judulBuku[i]<<"\n";
    }
}

//removes all stack items
void clear(){
    tumpukanBuku.top = -1;
    cout << "Seluruh buku berhasil diambil!\n";
}

//clear terminal output
//alternative of deprecated system("cls")
//maintain multi-platform support
void ClearScreen(){
    cout << string(100,'\n');
}

//menu procedure
void mainMenu(){
    char menu, ulang, exitConfirm, errorConfirm;

    ClearScreen();
    cout << "NIM\t: 4612421035\n";
    cout << "Nama\t: Muhammad Raihan Widagdo\n";
    cout << "Prodi\t: Sistem Informasi\n";
    cout << "Latihan Stack\n\n";
    cout << "========== TUMPUKAN BUKU ==========\n";
    cout << "1==> Push\n";
    cout << "2==> Pop\n";
    cout << "3==> Cetak\n";
    cout << "4==> Clear\n";
    cout << "5==> Keluar\n";
    cout << "Menu yang ingin dipilh...";
    cin >> menu;

    //switch menu input to function
    switch (menu){
        case '1':
            cout << "\n==> Push\n";
            cout << "Masukkan judul buku : " << endl;
            // clear input buffer
            cin.ignore();
            getline(cin,isi);
            push(isi);
            cout << "Masukkan (y) untuk kembali ke menu ";
            cin >> ulang;
            switch (ulang){
                default:
                return mainMenu();
            }
        case '2':
            cout << "\n==> Pop\n";
            pop();
            cout << "\nMasukkan (y) untuk kembali ke menu ";
            cin >> ulang;
            switch (ulang){
                default:
                return mainMenu();
            }
        case '3':
            cout << "\n==> Print\n";
            cout << "Daftar judul buku : \n";
            print();
            cout << "\nMasukkan (y) untuk kembali ke menu ";
            cin >> ulang;
            switch (ulang){
                default:
                return mainMenu();
            }
        case '4':
            cout << "\n==> Clear\n";
            clear();
            cout << "\nMasukkan (y) untuk kembali ke menu ";
            cin >> ulang;
            switch (ulang){
                default:
                return mainMenu();
            }
        case '5':
            cout << "\nApakah anda yakin ingin keluar? (y/n) ";
            cin >> exitConfirm;
            switch (exitConfirm){
                case 'y':
                    exit(0);
                case 'Y':
                    exit(0);
                default:
                return mainMenu();
            }
        default:
            cout << "Input menu gagal\nMasukkan (y) untuk kembali ke menu ";
            cin >> errorConfirm;
            switch (errorConfirm){
                default:
                return mainMenu();
            }
    }
}

//main function
int main(){
    //top variable declaration
    tumpukanBuku.top = -1;

    //call the procedure
    mainMenu();
}
