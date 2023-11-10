#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vemaybay {
protected:
    string tenchuyen;
    string ngaybay;
    double giave;

public:
    Vemaybay() {
        tenchuyen = "";
        ngaybay = "";
        giave = 0.0;
    }

    Vemaybay(string ten, string ngay, double gia) : tenchuyen(ten), ngaybay(ngay), giave(gia) {}

    double getgiave() {
        return giave;
    }

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        cin >> tenchuyen;
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi(string ten, string gt, int age) : hoten(ten), gioitinh(gt), tuoi(age) {}

    void Nhap() {
        cout << "Nhap ho ten: ";
        cin >> hoten;
        cout << "Nhap gioi tinh: ";
        cin >> gioitinh;
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi {
private:
    Vemaybay* ve;
    int soluong;

public:
    Hanhkhach(string ten, string gt, int age) : Nguoi(ten, gt, age) {
        ve = nullptr;
        soluong = 0;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; ++i) {
            cout << "Nhap thong tin ve may bay " << i + 1 << ":\n";
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        for (int i = 0; i < soluong; ++i) {
            cout << "Thong tin ve may bay " << i + 1 << ":\n";
            ve[i].Xuat();
        }
        cout << "Tong tien phai tra: " << tongtien() << endl;
    }

    double tongtien() {
        double total = 0;
        for (int i = 0; i < soluong; ++i) {
            total += ve[i].getgiave();
        }
        return total;
    }

    ~Hanhkhach() {
        delete[] ve;
    }
};

bool CompareTongTien(Hanhkhach& a, Hanhkhach& b) {
    return a.tongtien() > b.tongtien();
}

int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    vector<Hanhkhach> danhSachHanhKhach;

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hanh khach " << i + 1 << ":\n";
        Hanhkhach hanhKhach = Hanhkhach("", "", 0);
        hanhKhach.Nhap();
        danhSachHanhKhach.push_back(hanhKhach);
    }

    cout << "Danh sach hanh khach va so tien phai tra tuong ung:\n";
    for (Hanhkhach& hanhKhach : danhSachHanhKhach) {
        hanhKhach.Xuat();
        cout << "-----------------------\n";
    }

    // Sắp xếp theo chiều giảm dần của tổng tiền
    sort(danhSachHanhKhach.begin(), danhSachHanhKhach.end(), CompareTongTien);

    cout << "Danh sach hanh khach sau khi sap xep theo tong tien giam dan:\n";
    for (Hanhkhach& hanhKhach : danhSachHanhKhach) {
        hanhKhach.Xuat();
        cout << "-----------------------\n";
    }

    return 0;
}
