//Tên: Bùi Tạ Quang Minh
//MSSV: 2524802010333
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

//Câu 1: hàm số nguyên tố
//Định nghĩa: Số > 1 chỉ chia hết cho 1 và chính nó
int snt(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
void ktSNT(int n) {
    vector<int> mang(n);
    cout << "nhap cac so nguyen: ";
    for (int i = 0; i < n; i++) cin >> mang[i];

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_so_luong_phan_tu_de_kiem_tra_snt.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file nhap_so_luong_phan_tu_de_kiem_tra_snt.txt!" << endl;
        return;
    }
    inputFile << "Danh sach snt da nhap:\n";
    for (int i = 0; i < n; i++) {
        inputFile << mang[i] << " ";
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_so_luong_phan_tu_de_kiem_tra_snt.txt\n";

    //ghi danh sách số nguyên tố out ra
    ofstream outFile("kiem_tra_snt.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Danh sach cac so nguyen to out ra la:\n";
    for (int i = 0; i < n; i++) {
        if (snt(mang[i])) {
            cout << mang[i] << " ";
        }
    }
    outFile << "Danh sach cac so nguyen to out ra la:\n";
    for (int i = 0; i < n; i++) {
        if (snt(mang[i])) {
            outFile << mang[i] << " ";
        }
    }
    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so nguyen to vao file kiem_tra_snt.txt\n";
}

//Câu 2: hàm số chính phương
//Định nghĩa: Số bằng bình phương của một số nguyên
int scp(int x) {
    if (x < 0) return 0;
    int r = sqrt(x);
    return r * r == x;
}
void ktSCP (int n) {
    vector<int> mang(n);
    cout << "nhap cac so nguyen: ";
    for (int i = 0; i < n; i++) cin >> mang[i];

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_so_luong_phan_tu_de_kiem_tra_scp.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file nhap_so_luong_phan_tu_de_kiem_tra_scp.txt!" << endl;
        return;
    }
    inputFile << "Danh sach snt da nhap:\n";
    for (int i = 0; i < n; i++) {
        inputFile << mang[i] << " ";
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_so_luong_phan_tu_de_kiem_tra_scp.txt\n";

    //ghi danh sách số chính phương out ra
    ofstream outFile("kiem_tra_scp.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Danh sach cac so chinh  out ra la:\n";
    for (int i = 0; i < n; i++) {
        if (scp(mang[i])) {
            cout << mang[i] << " ";
        }
    }
    outFile << "Danh sach cac so chinh phuong out ra la:\n";
    for (int i = 0; i < n; i++) {
        if (scp(mang[i])) {
            outFile << mang[i] << " ";
        }
    }
    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so nguyen to vao file kiem_tra_scp.txt\n";
}

//Câu 3: hàm số hoàn hảo
//Định nghĩa: Số bằng tổng các ước dương nhỏ hơn nó
int shh(int x) {
    if (x < 2) return 0;
    int tong = 1;
    for (int i = 2; i <= x/2; i++) {
        if (x % i == 0) tong += i;
    }
    return tong == x;
}
void ktSHH (int n) {
    vector<int> mang(n);
    cout << "nhap cac so nguyen: ";
    for (int i = 0; i < n; i++) cin >> mang[i];

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_so_luong_phan_tu_de_kiem_tra_shh.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file nhap_so_luong_phan_tu_de_kiem_tra_shh.txt!" << endl;
        return;
    }
    inputFile << "Danh sach shh da nhap:\n";
    for (int i = 0; i < n; i++) {
        inputFile << mang[i] << " ";
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_so_luong_phan_tu_de_kiem_tra_shh.txt\n";

    //ghi danh sách số hoàn hảo out ra
    ofstream outFile("kiem_tra_shh.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Danh sach cac so hoan hao out ra la:\n";
    for (int i = 0; i < n; i++) {
        if (shh(mang[i])) {
            cout << mang[i] << " ";
        }
    }
    outFile << "Danh sach cac so hoan hao out ra la:\n";
    for (int i = 0; i < n; i++) {
        if (shh(mang[i])) {
            outFile << mang[i] << " ";
        }
    }
    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so hoan hao vao file kiem_tra_shh.txt\n";
}

//4. Sắp xếp dãy số tăng dần
void tangDan(int n) {
    vector<int> mang(n);
    cout << "nhap cac so nguyen: ";
    for (int i = 0; i < n; i++) cin >> mang[i];

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_so_luong_phan_tu_de_sap_xep_tang_dan.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file nhap_so_luong_phan_tu_de_sap_xep_tang_dan.txt!" << endl;
        return;
    }
    inputFile << "Day so da nhap:\n";
    for (int i = 0; i < n; i++) {
        inputFile << mang[i] << " ";
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_so_luong_phan_tu_de_sap_xep_tang_dan.txt\n";

    //ghi lại dãy số sắp xếp tăng dần out ra
    ofstream outFile("sap_xep_tang_dan.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Day so sap xep tang dan out ra la:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] > mang[j]) {
                int sapXep = mang[i];
                mang[i] = mang[j];
                mang[j] = sapXep; 
            }
        }
    }
    for (int i = 0; i < n; i++) cout << mang[i] << " ";
    cout << endl;

    outFile << "Day so sap xep tang dan out ra la:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] > mang[j]) {
                int sapXep = mang[i];
                mang[i] = mang[j];
                mang[j] = sapXep; 
            }
        }
    }
    for (int i = 0; i < n; i++) outFile << mang[i] << " ";
    outFile << endl;

    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so hoan hao vao file sap_xep_tang_dan.txt\n";
}

//5. Sắp xếp dãy số giảm dần
void giamDan(int n) {
    vector<int> mang(n);
    cout << "nhap cac so nguyen: ";
    for (int i = 0; i < n; i++) cin >> mang[i];

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_so_luong_phan_tu_de_sap_xep_giam_dan.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file nhap_so_luong_phan_tu_de_sap_xep_giam_dan.txt!" << endl;
        return;
    }
    inputFile << "Day so da nhap:\n";
    for (int i = 0; i < n; i++) {
        inputFile << mang[i] << " ";
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_so_luong_phan_tu_de_sap_xep_giam_dan.txt\n";

    //ghi lại dãy số sắp xếp giảm dần out ra
    ofstream outFile("sap_xep_giam_dan.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Day so sap xep giam dan out ra la:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] < mang[j]) {
                int sapXep = mang[i];
                mang[i] = mang[j];
                mang[j] = sapXep; 
            }
        }
    }
    for (int i = 0; i < n; i++) cout << mang[i] << " ";
    cout << endl;

    outFile << "Day so sap xep giam dan out ra la:\n";
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mang[i] < mang[j]) {
                int sapXep = mang[i];
                mang[i] = mang[j];
                mang[j] = sapXep; 
            }
        }
    }
    for (int i = 0; i < n; i++) outFile << mang[i] << " ";
    outFile << endl;
    
    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so hoan hao vao file sap_xep_giam_dan.txt\n";
}

//6. Sắp xếp tên sinh viên tăng dần
string layTenSV(const string& s) {
    int vt = s.find_last_of(" ");
    if (vt == string::npos) return s; // nếu chỉ có 1 từ
    return s.substr(vt + 1);
}
void sapXepTen(int n) {
    vector<string> ds(n);
    for (int i = 0; i < n; i++) getline(cin, ds[i]);

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_ten_sinh_vien.txt");
    if (!inputFile) {
        cout << "Khong mo duoc file nhap_ten_sinh_vien.txt!" << endl;
        return;
    }
    inputFile << "Danh sach ten da nhap:\n";
    for (int i = 0; i < n; i++) {
        inputFile << ds[i] << endl;
    }
    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_ten_sinh_vien.txt\n";

    //Sắp xếp lại tên theo chữ cái từ a-z
    sort(ds.begin(), ds.end(), [](const string &a, const string &b){
        return layTenSV(a) < layTenSV(b);
    });

    //ghi danh sách tên sinh viên đã sắp xếp theo chữ cái a-z out ra
    ofstream outFile("sap_xep_ten_sinh_vien.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Danh sach cac ten sinh vien da sap xep a-z out ra la:\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i] << endl;
    }
    outFile << "Danh sach cac ten sinh vien da sap xep a-z out ra la:\n";
    for (int i = 0; i < n; i++) {
        outFile << ds[i] << endl;
    }
    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so hoan hao vao file sap_xep_ten_sinh_vien.txt\n";
}

//7. Tìm tất cả vị trí có phần tử x
void timX(int n, int m) {
    vector<vector<int>> mang(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mang[i][j];

    //nhập x để tìm vị trí
    int x; cin >> x;

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_mang_2_chieu.txt");
    if (!inputFile) {
        cout << "nhap_mang_2_chieu.txt!" << endl;
        return;
    }
    inputFile << "Mang 2 chieu da nhap:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile << mang[i][j] << " ";
        }
        inputFile << endl;
    }
    inputFile << endl;

    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_mang_2_chieu.txt\n";

    //ghi lại all vị trí của x out ra
    ofstream outFile("tat_ca_vi_tri_cua_x_trong_ma_tran_2_chieu.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Tat ca vi tri cua x trong ma tran 2 chieu out ra la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mang[i][j] == x) {
                cout << i << " " <<  j << endl;
            }
        }
    }
    outFile << "Tat ca vi tri cua x trong ma tran 2 chieu out ra la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mang[i][j] == x) {
                outFile << i << " " <<  j << endl;
            }
        }
    }
    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so hoan hao vao file tat_ca_vi_tri_cua_x_trong_ma_tran_2_chieu.txt\n";
}

//8. Tính định thức ma trận 3x3
void dthuc() {
    int a[3][3];
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            cin >> a[i][j];

    //ghi lại toàn bộ thông tin đã nhập
    ofstream inputFile("nhap_mang_2_chieu_de_tinh_dinh_thuc.txt");
    if (!inputFile) {
        cout << "nhap_mang_2_chieu_de_tinh_dinh_thuc.txt!" << endl;
        return;
    }
    inputFile << "Mang 2 chieu da nhap:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inputFile << a[i][j] << " ";
        }
        inputFile << endl;
    }
    inputFile << endl;

    inputFile.close();
    cout << "Da ghi toan bo danh sach cac phan tu nhap vo vao file nhap_mang_2_chieu_de_tinh_dinh_thuc.txt\n";

    //Tính định thức
    int det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
            - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
            + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);

    //kết quả sau khi tính định thức
    ofstream outFile("dinh_thuc.txt"); // tạo file txt để lưu kết quả
    if (!outFile) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    cout << "Dinh thuc tinh ra duoc la: " << det << endl;

    outFile << "Dinh thuc tinh ra duoc la: " << det << endl;

    outFile.close(); //đóng file
    cout << "\nda ghi danh sach cac so hoan hao vao file dinh_thuc.txt\n";
}

int main () {
    int chon, n, m;
    while (true) {
        cout << "\n==========MENU=========\n";
        cout << "1. Kiem tra so nguyen to\n";
        cout << "2. Kiem tra so chinh phuong\n";
        cout << "3. Kiem tra so hoan hao\n";
        cout << "4. Sap xep mang tang dan\n";
        cout << "5. Sap xep mang giam dan\n";
        cout << "6. Sap xep ten sinh vien tang dan\n";
        cout << "7. Tim tat ca vi tri co phan tu x\n";
        cout << "8. Tinh dinh thuc ma tran 2 chieu (3x3)\n";
        cout << "0. Thoat chuong trinh\n";

        cout << "Nhap lua chon tu menu: ";
        cin >> chon;
        if (chon == 1) {
            cout << "nhap phan tu n: ";
            cin >> n;
            ktSNT(n);
        }
        else if (chon == 2) {
            cout << "nhap phan tu n: ";
            cin >> n;
            ktSCP(n);
        }
        else if (chon == 3) {
            cout << "nhap phan tu n: ";
            cin >> n;
            ktSHH(n);
        }
        else if (chon == 4) {
            cout << "nhap phan tu n: ";
            cin >> n;
            tangDan(n);
        }
        else if (chon == 5) {
            cout << "nhap phan tu n: ";
            cin >> n;
            giamDan(n);
        }
        else if (chon == 6) {
            cout << "nhap so luong sinh vien muon nhap ten: ";
            cin >> n;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sapXepTen(n);
        }
        else if (chon == 7) {
            cout << "nhap kich thuoc mang n x m: ";
            cin >> n >> m;
            timX(n, m);
        }
        else if (chon == 8) {
            dthuc();
        }
        else if (chon == 0) return 0;
        else cout << "Lua chon khong hop le!\n";
    }
}