#include <iostream>
using namespace std;

class LayangLayang;
class BelahKetupat 
{
private:
    float sisi, d1, d2;

public:
    void input() {
        cout << "--- Input Belah Ketupat ---" << endl;
        cout << "Masukkan sisi: "; cin >> sisi;
        cout << "Masukkan diagonal 1: "; cin >> d1;
        cout << "Masukkan diagonal 2: "; cin >> d2;
    }

    float hitungLuas() {
        return 0.5 * d1 * d2;
    }

    float hitungKeliling() {
        return 4 * sisi;
    }

    void output() {
        cout << "Luas Belah Ketupat: " << hitungLuas() << endl;
        cout << "Keliling Belah Ketupat: " << hitungKeliling() << endl;
    }
    
    void cetakKelilingLayang(LayangLayang &l);
};

class LayangLayang 
{
private:
    float s1, s2, d1, d2;

public:
    friend void BelahKetupat::cetakKelilingLayang(LayangLayang &l);

    void input() {
        cout << "\n--- Input Layang-Layang ---" << endl;
        cout << "Masukkan sisi miring 1: "; cin >> s1;
        cout << "Masukkan sisi miring 2: "; cin >> s2;
        cout << "Masukkan diagonal 1: "; cin >> d1;
        cout << "Masukkan diagonal 2: "; cin >> d2;
    }

    float hitungLuas() {
        return 0.5 * d1 * d2;
    }

    float hitungKeliling() {
        return 2 * (s1 + s2);
    }

    void output() {
        cout << "Luas Layang-Layang: " << hitungLuas() << endl;
        cout << "Keliling Layang-Layang: " << hitungKeliling() << endl;
    }
};

void BelahKetupat::cetakKelilingLayang(LayangLayang &l) 
{
    cout << "Akses Friend Method: Keliling Layang-Layang adalah " << l.hitungKeliling() << endl;
}

int main() 
{
    BelahKetupat bk;
    LayangLayang ly;

    bk.input();
    bk.output();

    ly.input();
    ly.output();

    cout << "\n--- Uji Coba Friend Method ---" << endl;
    bk.cetakKelilingLayang(ly);

    return 0;
}