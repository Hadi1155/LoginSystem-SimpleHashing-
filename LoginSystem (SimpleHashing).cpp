#include <iostream>
using namespace std;

//Hash Table

struct HashTable 
{
    //data
    string username, password;
}dataAkun[26];

// Function Hash

int HashFunction(string password) {

    return tolower(password[0]) - 97;
}

bool CheckDaftar(string username, string password)
{
    int index = HashFunction(password);

    if (dataAkun[index].username != "" && dataAkun[index].password != "")
    {
        return false;
    }
    else
    {
        dataAkun[index].username = username;
        dataAkun[index].password = password;
        return true;
    }
}

bool CheckLogin(string username, string password)
{
    int index = HashFunction(password);

    if (dataAkun[index].username == username && dataAkun[index].password == password)
    {
        cout << "|| LOGIN Berhasil! " << endl;
        return true;
    }
    else
    {
        cout << "Login Gagal!" << endl;
        return false;
    }
}

void Daftar()
{
    string username, password;
    cout << "\n== MENU DAFTAR ==\n\n";
    cout << "Masukan Username dan Password!" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    if (CheckDaftar(username, password) == true) {
        cout << "\n|| Akun berhasil terdaftar!\n\n";
    }
    else {
        cout << "\n|| Akun sudah ada!" << endl;
        cout << "|| Akun gagal terdaftar!\n" << endl;
    }
}

void ListDataAkun() {
    cout << "\nData Akun : " << endl;
    cout << "| Index\t - Username - Password |" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (dataAkun[i].username != "" && dataAkun[i].password != "") {

            cout << "| " << i << "\t - " << dataAkun[i].username << " - " << dataAkun[i].password << " | " << endl;
        }
        else
        {
            cout << "| " << i << "\t - n/a - n/a | " << endl;
        }

    }
}

void DeleteData()
{
    int index;
    cout << "\n== DELETE DATA ==\n" << endl;
    ListDataAkun();
    cout << "Index data yang ingin dihapus : ";
    cin >> index;

    if (index <= 26)
    {
        if (dataAkun[index].username != "" && dataAkun[index].password != "")
        {
            cout << "|| DATA AKUN BERHASIL DIHAPUS!" << endl;
            dataAkun[index].username = "";
            dataAkun[index].password = "";
        }
        else
        {
            cout << "Tidak ada data untuk dihapus" << endl; 
        }
    }
    else
    {
        cout << "Input Gagal!" << endl;
    }
}

void LoginMenu()
{
    while (true)
    {
        string pilihan;
        cout << "\n== LOGIN MENU! ==\n" << endl;
        cout << "Menu Pilihan : " << endl;
        cout << "1. Tambah Akun" << endl;
        cout << "2. Hapus Akun" << endl;
        cout << "3. Liat Tabel Akun " << endl;
        cout << "4. Logout " << endl;
        cout << "Pilih Menu [1|2|3|4] : ";
        cin >> pilihan;

        if (pilihan == "1") {
            Daftar();
        }
        else if (pilihan == "2") {
            DeleteData();
        }
        else if (pilihan == "3") {
            ListDataAkun();
        }
        else if (pilihan == "4")
        {
            cout << "\n== ANDA TELAH LOGOUT ==\n\n";
            break;
        }
        else
        {
            cout << "Pilihan Tidak Tersedia!" << endl;
        }
    }
}

void Login()
{
    string username, password;
    cout << "== LOGIN ACCOUNT ==\n" << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Username : ";
    cin >> password;

    if (CheckLogin(username, password) == true)
    {
        LoginMenu();
    }
    else
    {
        cout << "Login Gagal! \n\n" << endl;
    }

}

void Welcome()
{
    while (true)
    {
        string pilihan;
        cout << "== PROGRAM LOGIN SEDERHANA DENGAN HASHING ==\n" << endl;
        cout << "Menu Pilihan : " << endl;
        cout << "1. Daftar " << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar " << endl;
        cout << "Pilih Menu [1|2|3] : ";
        cin >> pilihan;

        if (pilihan == "1") {
            Daftar();
        }
        else if (pilihan == "2"){
            Login();
        }  
        else if (pilihan == "3") {
            cout << "\n== TERIMAKASIH TELAH MENGGUNAKAN APLIKASI LOGIN SEDRHANA ==\n\n";
            break;
        }
        else
        {
            cout << "Pilihan Tidak Tersedia!\n" << endl; 
        }
    }
}

int main()
{
    Welcome();
}


