//Họ và tên: Bùi Tạ Quang Minh
//MSSV: 2524802010333
//Lớp: D25CNTT06
#include <iostream>
#include <vector>
#include <limits>
#include <cctype>
#include <string>
#include <algorithm>
#include <numeric> //để dùng gcd tìm ucln
#include <fstream>
using namespace std;
// Bài 1: danh sách sinh viên thi lại
struct bt1 {
    string sv;
    string hoTenSV;
    double diemCS;
    double diemChuyenNganh;
};

void bai1(vector<bt1>& ds1, int n) {
    ds1.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds1[i].sv);
        getline(cin, ds1[i].hoTenSV);
        cin >> ds1[i].diemCS;
        cin >> ds1[i].diemChuyenNganh;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Ghi toàn bộ dữ liệu nhập vào
    ofstream inputFile("sinhvien_input.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file sinhvien_input.txt!" << endl;
        return;
    }
    inputFile << "Danh sach sinh vien da nhap:\n";
    for (int i = 0; i < ds1.size(); i++) {
        inputFile << i + 1 << "\t"
                  << ds1[i].sv << "\t"
                  << ds1[i].hoTenSV << "\t"
                  << ds1[i].diemCS << "\t"
                  << ds1[i].diemChuyenNganh << endl;
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach vao file sinhvien_input.txt\n";

    // Ghi danh sách sinh viên thi lại
    ofstream outfile("sinhvien_thilai.txt"); // tạo file txt để lưu kết quả
    if (!outfile) {
        cout << "khong mo đc file!" << endl;
        return;
    }

    outfile << "Danh sach sinh vien thi lai:\n";
    cout << "Danh sach sinh vien thi lai:\n";
    for (int i = 0; i < ds1.size(); i++) {
        if (ds1[i].diemCS < 5 || ds1[i].diemChuyenNganh < 5) {
            outfile << i + 1 << "\t"
                    << ds1[i].sv << "\t"
                    << ds1[i].hoTenSV << "\t"
                    << ds1[i].diemCS << "\t"
                    << ds1[i].diemChuyenNganh << endl;

            cout << i + 1 << "\t"
                 << ds1[i].sv << "\t"
                 << ds1[i].hoTenSV << "\t"
                 << ds1[i].diemCS << "\t"
                 << ds1[i].diemChuyenNganh << endl;
        }
    }

    outfile.close(); //đóng file
    cout << "da ghi danh sach sinh vien thi lai vao file sinhvien_thilai.txt\n";
}

// Bài 2: tìm sinh viên theo mã số
struct bt2 {
    string sv;
    string hoTenSV;
    double diemCS;
    double diemChuyenNganh;
};

void bai2(vector<bt2>& ds2, int n) {
    ds2.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds2[i].sv);
        getline(cin, ds2[i].hoTenSV);
        cin >> ds2[i].diemCS;
        cin >> ds2[i].diemChuyenNganh;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nhap mssv can tim: ";
    string tim;
    getline(cin, tim);
    for (auto &c : tim) c = tolower(c);

    bool timThay = false;
    for (int i = 0; i < n; i++) {
        string svChuThuong = ds2[i].sv;
        for (auto &c : svChuThuong) c = tolower(c);

        if (tim == svChuThuong) {
            cout << ds2[i].sv << "\t"
                 << ds2[i].hoTenSV << "\t"
                 << ds2[i].diemCS << "\t"
                 << ds2[i].diemChuyenNganh << endl;
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien co ma so " << tim << endl;
    }
}

// Bài 3: danh sách sinh viên và học lực
struct bt3 {
    string hoTenSV;
    double diemTin;
    double diemNgoaiNgu;
};

void bai3(vector<bt3>& ds3, int n) {
    ds3.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds3[i].hoTenSV);
        cin >> ds3[i].diemTin;
        cin >> ds3[i].diemNgoaiNgu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Danh sach sinh vien va hoc luc:\n";
    for (int i = 0; i < ds3.size(); i++) {
        double dtb = (ds3[i].diemTin + ds3[i].diemNgoaiNgu) / 2;
        string hocLuc;
        if (dtb >= 8) hocLuc = "gioi";
        else if (dtb >= 7) hocLuc = "kha";
        else if (dtb >= 5) hocLuc = "trung binh";
        else if (dtb >= 4) hocLuc = "yeu";
        else hocLuc = "kem";

        cout << i + 1 << "\t"
             << ds3[i].hoTenSV << "\t"
             << ds3[i].diemTin << "\t"
             << ds3[i].diemNgoaiNgu << "\t"
             << hocLuc << endl;
    }
}

//bài 4: đếm số lg sinh viên thi lại
struct bt4 {
    string hoTenSV;
    double diemTin;
    double diemNgoaiNgu;
};

void bai4(vector<bt4>& ds4, int n) {
    ds4.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds4[i].hoTenSV);
        cin >> ds4[i].diemTin;
        cin >> ds4[i].diemNgoaiNgu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int dem = 0;
    cout << "So luong sinh vien thi lai la: ";
    for (int i = 0; i < ds4.size(); i++) {
        if (ds4[i].diemTin < 5 || ds4[i].diemNgoaiNgu < 5) {
            dem++;
        }
    }
    cout << dem << endl; 
}

// bài 5: danh sách sinh viên có học lực giỏi
struct bt5 {
    string hoTenSV;
    double diemTin;
    double diemNgoaiNgu;
};

void bai5(vector<bt5>& ds5, int n) {
    ds5.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds5[i].hoTenSV);
        cin >> ds5[i].diemTin;
        cin >> ds5[i].diemNgoaiNgu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int stt = 1;
    cout << "Danh sach sinh vien co hoc luc gioi:\n";
    for (int i = 0; i < ds5.size(); i++) {
        double dtb = (ds5[i].diemTin + ds5[i].diemNgoaiNgu) / 2;
        string hocLuc;
        if (dtb >= 8) { 
            hocLuc = "gioi";
            cout << stt << "\t"
                << ds5[i].hoTenSV << "\t"
                << ds5[i].diemTin << "\t"
                << ds5[i].diemNgoaiNgu << "\t"
                << dtb << "\t"
                << hocLuc << endl;
            stt++;
        }
    }
}

// Bài 6: danh sách sinh viên có đtb cao nhất lớp
struct bt6 {
    string hoTenSV;
    double diemTin;
    double diemNgoaiNgu;
};

void bai6(vector<bt6>& ds6, int n) {
    ds6.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds6[i].hoTenSV);
        cin >> ds6[i].diemTin;
        cin >> ds6[i].diemNgoaiNgu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int stt = 1;
    double dtbMax = 0;
    vector<double> dtbList(n); // Để lưu riêng điểm trung bình cho từng sinh viên

    //Tính điểm trung bình và tìm max
    for (int i = 0; i < ds6.size(); i++) {
        dtbList[i] = (ds6[i].diemTin + ds6[i].diemNgoaiNgu) / 2;
        if (dtbList[i] >= dtbMax) dtbMax = dtbList[i];
    }
    cout << "Danh sach cac sinh vien dtb cao nhat lop:\n";
    for (int i = 0; i < ds6.size(); i++) {  
        if (dtbList[i] == dtbMax) { 
            string hocLuc; 
            if (dtbMax >= 8) hocLuc = "gioi";
            else if (dtbMax >= 7) hocLuc = "kha";
            else if (dtbMax >= 5) hocLuc = "trung binh";
            else if (dtbMax >= 4) hocLuc = "yeu";
            else hocLuc = "kem";

            cout << stt << "\t"
                    << ds6[i].hoTenSV << "\t"
                    << ds6[i].diemTin << "\t"
                    << ds6[i].diemNgoaiNgu << "\t"
                    << dtbList[i] << "\t"
                    << hocLuc << endl;
            stt++;
        }
    }
}

// Bài 7: danh sách sinh viên giảm dần theo điểm trung bình
struct bt7 {
    string hoTenSV;
    double diemTin;
    double diemNgoaiNgu;
};

void bai7(vector<bt7>& ds7, int n) {
    ds7.resize(n);
    for (int i = 0; i < n; i++) {
        getline(cin, ds7[i].hoTenSV);
        cin >> ds7[i].diemTin;
        cin >> ds7[i].diemNgoaiNgu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Sắp xếp giảm dần theo điểm trung bình 
    sort(ds7.begin(), ds7.end(), [](const bt7 &a, const bt7 &b) { 
        double dtbA = (a.diemTin + a.diemNgoaiNgu) / 2; 
        double dtbB = (b.diemTin + b.diemNgoaiNgu) / 2; 
        return dtbA > dtbB; // giảm dần 
    });
    int stt = 1;
    cout << "Danh sach sinh vien giam dan theo dtb:\n";
    for (int i = 0; i < ds7.size(); i++) {   
            string hocLuc; 
            double dtb = (ds7[i].diemTin + ds7[i].diemNgoaiNgu) / 2;
            if (dtb >= 8) hocLuc = "gioi";
            else if (dtb >= 7) hocLuc = "kha";
            else if (dtb >= 5) hocLuc = "trung binh";
            else if (dtb >= 4) hocLuc = "yeu";
            else hocLuc = "kem";

            cout << stt << "\t"
                    << ds7[i].hoTenSV << "\t"
                    << ds7[i].diemTin << "\t"
                    << ds7[i].diemNgoaiNgu << "\t"
                    << dtb << "\t"
                    << hocLuc << endl;
            stt++;
    }
}

// Bài 8: in ra phân số tối giản
struct bt8 {
    long long tu; // dùng kiểu dữ liệu long long để tránh bị tràn số
    long long mau;
};

void bai8(bt8& ps) {
    cout << "nhap tu va mau: ";
    cin >> ps.tu >> ps.mau;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //sao chép ra biến riêng để dễ xử lý
    long long tu = ps.tu;
    long long mau = ps.mau;

    //tìm ucln để rút gọn
    long long ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;

    //trg hợp 1: nếu tu == 0 thì in ra 0
    if (tu == 0) {
        cout << 0 << endl;
        return;
    }

    //trg hợp 2: nếu mau == 0 thi in ra mẫu ko hợp lệ
    if (mau == 0) {
        cout << "Mau so khong hop le!" << endl;
        return;
    }

    //trg hợp 3: nếu tu == mau thì in ra 1 luôn
    if (tu == mau) {
        cout << 1 << endl;
        return;
    }

    //trg hợp 4 nếu mau == 1 và (tu > 0 hoặc tu < 0) thì chỉ in ra tu
    if ((tu > 0 && mau == 1) || (tu < 0 && mau == 1)) {
        cout << tu << endl;
        return;
    }

    //trg hợp 5 là đảm bảo mau ko âm để in dấu âm trước tu
    if (mau < 0) { 
        tu = -tu;
        mau = -mau;
    }
    cout << "phan so toi gian: " << tu << "/" << mau << endl;
}

// Bài 9: cộng 2 phân số tối giản
struct bt9 {
    long long tu; // dùng long long để tránh bị tràn số nếu ng dùng nhập vào số lớn
    long long mau;
};

void bai9(bt9& ps1, bt9& ps2) {
    cout << "nhap tu va mau 1: ";
    cin >> ps1.tu >> ps1.mau;
    cout << "nhap tu va mau 2: ";
    cin >> ps2.tu >> ps2.mau;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //quy đồng lên
    long long tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    long long mau = ps1.mau * ps2.mau;

    //tìm ucln để rút gọn
    long long ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;

    //trg hợp 1: nếu tu == 0 thì in ra 0
    if (tu == 0) {
        cout << 0 << endl;
        return;
    }

    //trg hợp 2: nếu mau == 0 thi in ra mẫu ko hợp lệ
    if (mau == 0) {
        cout << "Mau so khong hop le!" << endl;
        return;
    }

    //trg hợp 3: nếu tu == mau thì in ra 1 luôn
    if (tu == mau) {
        cout << 1 << endl;
        return;
    }

    //trg hợp 4 nếu mau == 1 và (tu > 0 hoặc tu < 0) thì chỉ in ra tu
    if ((tu > 0 && mau == 1) || (tu < 0 && mau == 1)) {
        cout << tu << endl;
        return;
    }

    //trg hợp 5 là đảm bảo mau ko âm để in dấu âm trước tu
    if (mau < 0) { 
        tu = -tu;
        mau = -mau;
    }
    cout << "Phan so toi gian sau khi cong 2 phan so lai la: " << tu << "/" << mau << endl;
} 

// Bài 10: so sánh 2 phân số
struct bt10 {
    int tu;
    int mau;
};

void bai10(bt10& ps3, bt10& ps4) {
    cout << "nhap tu va mau 1: ";
    cin >> ps3.tu >> ps3.mau;
    cout << "nhap tu va mau 2: ";
    cin >> ps4.tu >> ps4.mau;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    //nhân chéo tử mẫu của 2 phân số lại để so sánh
    long long left = 1LL * ps3.tu * ps4.mau; 
    long long right = 1LL * ps4.tu * ps3.mau;

    // nếu left > right thì ps3 > ps4, ngược lại thì nhỏ hơn, bằng nhau thì bằng
    if (left > right) cout << 1 << endl;
    else if (left < right) cout << -1 << endl;
    else cout << 0 << endl;
} 
int main() {
    int n;
    vector<bt1> ds1;
    vector<bt2> ds2;
    vector<bt3> ds3;
    vector<bt4> ds4;
    vector<bt5> ds5;
    vector<bt6> ds6;
    vector<bt7> ds7;
    bt8 ps;
    bt9 ps1, ps2;
    bt10 ps3, ps4;
    int chon;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "0. Thoat\n";
        cout << "1. Bai 1 - Danh sach SV thi lai\n";
        cout << "2. Bai 2 - Tim SV theo ma so\n";
        cout << "3. Bai 3 - Danh sach SV va hoc luc\n";
        cout << "4. Bai 4 - So luong sinh vien thi lai\n";
        cout << "5. Bai 5 - Danh sach sinh vien co hoc luc gioi\n";
        cout << "6. Bai 6 - Danh sach sinh vien co diem trung binh cao nhat lop\n";
        cout << "7. Bai 7 - Danh sach sinh vien giam dan theo diem trung binh\n";
        cout << "8. Bai 8 - In ra phan so toi gian\n";
        cout << "9. Bai 9 - Tong 2 phan so toi gian\n";
        cout << "10. Bai 10 - So sanh 2 phan so\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (chon == 1) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai1(ds1, n);
        }
        else if (chon == 2) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai2(ds2, n);
        }
        else if (chon == 3) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai3(ds3, n);
        }
        else if (chon == 4) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai4(ds4, n);
        }
        else if (chon == 5) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai5(ds5, n);
        }
        else if (chon == 6) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai6(ds6, n);
        }
        else if (chon == 7) {
            cout << "Nhap so luong sinh vien: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bai7(ds7, n);
        }
        else if (chon == 8) {
            bai8(ps);
        }
        else if (chon == 9) {
            bai9(ps1, ps2);
        }
        else if (chon == 10) {
            bai10(ps3, ps4);
        }
        else if (chon == 0) {
            cout << "Thoat chuong trinh.\n";
            break;
        }
        else {
            cout << "Lua chon khong hop le!\n";
        }
    }
    return 0;
}