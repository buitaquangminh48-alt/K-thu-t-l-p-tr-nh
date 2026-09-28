// Họ và tên: Bùi Tạ Quang Minh
// Mssv: 2524802010333
// Lớp: D25CNTT06

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std::chrono;
using namespace std;

//hàm đo tgian thuật toán
template <typename Func> // nhận vào 1 hàm bát kỳ như 1 tham số mà ko cần khai báo kiểu dữ liệu cụ thể
void doTGian(Func func) {
    auto start = high_resolution_clock::now(); //thiệt ra có thể viết std::chrono::time_point<std::chrono::high_resolution_clock> start = high_resolution_clock::now(); nhma hơi dài dòng
    func(); 
    auto end = high_resolution_clock::now(); 
    // Đo bằng giây 
    duration<double> elapsed_s = end - start; 
    cout << fixed << setprecision(9) << "thoi gian chay: " << elapsed_s.count() << " s\n"; //.count() để in ra tgian kq số thực
}
//hàm nhập mảng
void nhapMT(int** &a, int &n, int &m) {
    cout << "nhap phan tu n: ";
    cin >> n;
    cout << "nhap phan tu m: ";
    cin >> m;
    a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    cout << "nhap mang moi:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }    
    cout << endl;
}
//hàm menu
void menu() {
    cout << "===============MENU===============\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "1. Tinh dong\n";
    cout << "2. Tinh cot\n";
    cout << "3. Tong duong cheo chinh cua ma tran vuong\n";
    cout << "4. Tong GTLN tren moi dong\n";
    cout << "5. Tinh trung binh gia tri nho nhat tren moi cot\n";
    cout << "6. Tong tung GTNN cua tung duong cheo\n";
    cout << "7. Tim vi tri cua phan tu lon nhat trong ma tran so nguyen\n";
    cout << "8. Tim vi tri cua phan tu chan cuoi cung trong mang\n";
    cout << "9. Tim phan tu am le lon nhat trong mang\n";
    cout << "10. Tim phan tu chan duong nho nhat trong mang\n";
    cout << "11. Tim phan tu lon nhat tren duong cheo chinh\n";
    cout << "12. Hoan vi 2 dong, 2 cot\n";
    cout << "13. Xoa 1 dong, xoa 1 cot\n";
    cout << "14. Chen 1 dong, chen 1 cot\n";
    cout << "15. Tim phan tu chan duong lon nhat trong mang\n";
    cout << "16. Tim vi tri xuat hien dau tien cua x\n";
    cout << "17. Xoa dong co tong so thuc lon nhat\n";
    cout << "18. Sap xep ma tran tang dan\n";
    cout << "19. Tich cua 2 ma tran\n";
    cout << "20. Tong cua 2 ma tran\n";
    cout << "21. Nhap them mang moi\n";
    cout << endl;
}
//hàm chọn công việc trên menu
void lua(int &chon) {
    cout << "ban muon chuong trinh thuc hien cong viec gi?\n";
    cout << "chon: ";
    cin >> chon;
}
//hàm giải phóng bộ nhớ cho mọi loại ma trận
template <typename T>
void giaiPhong(T** &matran, int n) {
    if (matran != nullptr) {
        for (int i = 0; i < n; i++) {
            if (matran[i] != nullptr) {
                delete[] matran[i]; // giải phóng từng dòng (mảng con)
            }
        }
        delete[] matran; // giải phóng mảng con trỏ dòng
        matran = nullptr; // gán lại để tránh trỏ vào vùng nhớ rác
    }
}
//1. tong dong
void tongDong(int** a, int n, int m) {
    int tong = 0, k;
    cout << "ban muon tinh tong dong may? (vd muon tinh dong 1 thi nhap 1)\n";
    cout << "dong: ";
    cin >> k;
    if (k < 1 || k > n) {
        cout << "Chi so khong hop le" << endl;
        return;
    }

    for (int j = 0; j < m; j++) {
        tong += a[k - 1][j];
    }
    cout << "Tong dong la: " << tong << endl;
}
//2. tong cot
void tongCot(int** a, int n, int m) {
    int tong = 0, k;
    cout << "ban muon tinh tong cot may? (vd muon tinh cot 1 thi nhap 1)\n";
    cout << "cot: ";
    cin >> k;
    if (k < 1 || k > m) {
        cout << "Chi so khong hop le" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        tong += a[i][k - 1];
    }
    cout << "Tong cot la: " << tong << endl;
}
//3  tong duong cheo chinh
void tongDuongCheoChinh(int** a, int n, int m) {
    int tong = 0;
    if (n != m) cout << "Day khong phai ma tran vuong\n";
    else {
        for (int i = 0; i < n; i++) {
              tong += a[i][i];
        }
        cout << "Tong duong cheo chinh trong ma tran vuong la: " << tong << endl;
    }
}
//4. tong gtln cua tung dong
void tongGTLNCuaTungDong(int** a, int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        int gtln = a[i][0];
        for (int j = 1; j < m; j++) {
             if (a[i][j] > gtln) gtln = a[i][j];
        }
        tong += gtln;
    }
    cout << "Tong cac GTLN tren moi dong la: " << tong << endl;
}
//5. tinh trung binh gtnn cua moi cot
void tinhTrungBinhGTNNCuaMoiCot(int** a, int n, int m) {
    int tong = 0;
    for (int j = 0; j < m; j++) {
        int gtnn = a[0][j];
        for (int i = 1; i < n; i++) {
             if (a[i][j] < gtnn) {
                 gtnn = a[i][j];
             }
        }
        tong += gtnn;
    }
    cout << "Gia tri trung binh cua cac phan tu nho nhat tren moi cot la: " << (double) tong / m << endl;
}
//6. tong gtnn cua tung duong cheo song song duong cheo chinh
void tongGTNNCuaTungDgCheo(int** a, int n, int m) {
    int tong = 0;
    if (n != m) {
        cout << "Day khong phai ma tran vuong nen khong tinh tong GTNN tren tung duong cheo.\n";
    }
    else {
        for (int d = -(n-1); d <= n-1; d++) {
            int gtnn = INT_MAX;
            bool coGTNN = false; // chưa tìm thấy phần tử hợp lệ
            for (int i = 0; i < n; i++) {
                int j = i - d;
                if (j >= 0 && j < n) {
                    if (a[i][j] < gtnn) {
                        gtnn = a[i][j];
                        coGTNN = true;
                    }
                }
            }   
            if (coGTNN)
                tong += gtnn;
        }
        cout << "Tong cac gia tri nho nhat tren tung duong cheo la: " << tong << endl;
    }
}
//7. tim vi tri cua phan tu lon nhat
void timVTPhanTuLonNhat(int** a, int n, int m) {
    int gtln = a[0][0];
    //tim gia tri lon nhat
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {       
            if (a[i][j] > gtln) {   
                gtln = a[i][j];                     
            }     
        }          
    } 
    //in ra tat ca vi tri co gia tri = gtln
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == gtln) {
                cout << "Phan tu lon nhat cua ma tran so nguyen nam o vi tri a[" << i << "][" << j << "]" << endl;
            }
        }
    }
}
//8. tim vi tri chan cuoi cung
void VTChanCuoiCung(int** a, int n, int m) {
    int vt_i = 0, vt_j = 0;
    bool coPhanTuChan = false; // chưa tìm thấy phần tử hợp lệ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] % 2 == 0) {
                vt_i = i;
                vt_j = j;
                coPhanTuChan = true;
            }
        }
    }
    if (coPhanTuChan)
        cout << "Vi tri cua phan tu chan cuoi cung nam tai a[" << vt_i << "][" << vt_j << "]" << endl;
    else
        cout << "Mang khong co phan tu chan" << endl;
}
//9. tim phan tu am le lon nhat
void PTuAmLeLonNhat(int** a, int n, int m) {
    int amLe = INT_MIN;
    bool coPhanTu = false; // chưa tìm thấy phần tử hợp lệ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = a[i][j];
            if (x < 0 && x % 2 != 0) {
                if (!coPhanTu || x > amLe){
                    amLe = x;
                    coPhanTu = true;
                }
            }            
        }
    }
    if (coPhanTu)
        cout << "Phan tu am le lon nhat mang la: " << amLe << endl;
    else
        cout << "Mang khong co phan tu am le" << endl;
}
//10. tim chan duong nho nhat
void chanDuongNhoNhat(int** a, int n, int m) {
    int chanDuong = INT_MAX;
    bool coPhanTu = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = a[i][j];
            if (x > 0 && x % 2 == 0) {
                if (!coPhanTu || x < chanDuong) {
                    chanDuong = x;
                    coPhanTu = true;
                }
            }
        }
    }
    if (coPhanTu)
        cout << "Phan tu chan duong nho nhat la: " << chanDuong << endl;
    else
        cout << "Mang khong co phan tu chan duong" << endl;
}
//11. tim phan tu lon nhat tren dg cheo chinh
void ptuLonNhatDgCheoChinh(int** a, int n, int m) {
    int gtln = a[0][0];
    if (n != m) cout << "Day khong phai ma tran vuong nen khong tim duoc phan tu lon nhat tren dg cheo chinh\n";
    else {
        for (int i = 0; i < n; i++) {
            if (a[i][i] > gtln) {
                gtln = a[i][i];
            }
        }
        cout << "Phan tu lon nhat tren dg cheo chinh la: " << gtln << endl;
    }
}
//12. hoan vi 2 dong, 2 cot
//a) doi dong
void hviHaiDong(int** a, int n, int m, int d1, int d2) {
    cout << "Ban muon hoan doi dong nao? (vd dong 1 thi nhap 1, dong 2 thi nhap 2)\n";
    cout << "Dong: ";
    cin >> d1;
    cout << "Va dong: ";
    cin >> d2;
    if (d1 < 1 || d1 > n || d2 < 1 || d2 > n) {
        cout << "Chi so khong hop le" << endl;
        return;
    }
    //hoan doi 2 dong
    for (int j = 0; j < m; j++) {
        int hoanDoi = a[d1 - 1][j];
        a[d1 - 1][j] = a[d2 - 1][j];
        a[d2 - 1][j] = hoanDoi;
    }
    //xuat ra lai man hinh ma tran da hoan doi
    cout << "Ma tran sau khi hoan doi\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//b) doi cot
void hviHaiCot(int** a, int n, int m, int c1, int c2) {
    cout << "Ban muon hoan doi cot nao? (vd cot 1 thi nhap 1, cot 2 thi nhap 2)\n";
    cout << "Cot: ";
    cin >> c1;
    cout << "Va cot: ";
    cin >> c2;
    if (c1 < 1 || c1 > m || c2 < 1 || c2 > m) {
        cout << "Chi so khong hop le" << endl;
        return;
    }
    //hoan doi 2 cot
    for (int i = 0; i < n; i++) {
        int hoanDoi = a[i][c1 - 1];
        a[i][c1 - 1] = a[i][c2 - 1];
        a[i][c2 - 1] = hoanDoi;
    }
    //xuat ra lai man hinh ma tran da hoan doi
    cout << "Ma tran sau khi hoan doi\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
//13. xoa 1 dong, xoa 1 cot
//a) xoa dong
void xoaDong(int** a, int &n, int m) {
    if (n == 0) {
        cout << "Ma tran rong nen khong co gi de xoa" << endl;
        return;
    }
    
    int k;
    cout << "Ban muon xoa dong nao? (vd dong 1 thi nhap 1)\n";
    cout << "Dong: ";
    cin >> k;
    if (k < 1 || k > n) {
        cout << "Chi so khong hop le" << endl;
        return;
    }
    
    for (int i = k - 1; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[i + 1][j];
        }
    }
    n--; //giam dong 
    //xuat ra lai ma tran ra man hinh 
    cout << "Ma tran sau khi xoa dong " << k << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";           
        }
        cout << endl;
    }
    cout << endl;
}
//b) xoa cot
void xoaCot(int** a, int n, int &m) {
    if (m == 0) {
        cout << "Ma tran rong nen khong co gi de xoa" << endl;
        return;
    }
    
    int k;
    cout << "Ban muon xoa cot nao? (vd cot 1 thi nhap 1)\n";
    cout << "Cot: ";
    cin >> k;
    if (k < 1 || k > m) {
        cout << "Chi so khong hop le"  << endl;
        return;
    }
    
    for (int j = k - 1; j < m - 1; j++) {
        for (int i = 0; i < n; i++) {
            a[i][j] = a[i][j + 1];
        }
    }
    m--; //giam cot
    //xuat ra lai ma tran ra man hinh 
    cout << "Ma tran sau khi xoa cot " << k << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//14. chen 1 dong, chen 1 cot
//a) chen dong
void chenDong(int** a, int &n, int m) {
    int k;
    cout << "Ban muon chen dong vao vi tri nao? (vd neu chen vao dong 1 thi cac dong duoi se lui xuong)\n";
    cout << "Dong: ";
    cin >> k;
    if (k < 1 || k > n + 1) {
        cout << "Chi so khong hop le" << endl;
        return;
     }
    
    n++; // tang them dong
    //dich chuyen cac dong di xuong de them dong vao do
    for (int i = n - 1; i > k - 1; i--) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[i - 1][j];
        }
    }
    //nhap them dong moi
    for (int j = 0; j < m; j++) {
        cin >> a[k - 1][j];        
    }
    
    //xuat ra lai ma tran ra man hinh 
    cout << "Ma tran sau khi chen them dong tai vi tri " << k << " la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//b) chen cot
void chenCot(int** a, int n, int &m) {
    int k;
    cout << "Ban muon chen cot vao vi tri nao? (vd neu chen vao cot 1 thi cac cot ke ben se duoc day qua phai)\n";
    cout << "Cot: ";
    cin >> k;
    if (k < 1 || k > m + 1) {
        cout << "Chi so khong hop le" << endl;
        return;
     }
    
    m++; // tang them cot
    //dich chuyen cac cot qua phai de them cot vao do
    for (int j = m - 1; j > k - 1; j--) {
        for (int i = 0; i < n; i++) {
            a[i][j] = a[i][j - 1];
        }
    }
    //nhap them cot moi
    for (int i = 0; i < n; i++) {
        cin >> a[i][k - 1];        
    }
    
    //xuat ra lai ma tran ra man hinh 
    cout << "Ma tran sau khi chen them cot tai vi tri " << k << " la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//15. tim chan duong lon nhat
void chanDuongLonNhat(int** a, int n, int m) {
    int chanDuong = INT_MIN;
    bool coPhanTu = false; // chưa tìm thấy phần tử hợp lệ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = a[i][j];
            if (x > 0 && x % 2 == 0) {
                if (!coPhanTu || x > chanDuong) {
                    chanDuong = x;
                    coPhanTu = true;
                }
            }
        }
    }
    if (coPhanTu)
        cout << "Phan tu chan duong lon nhat la: " << chanDuong << endl;
    else
        cout << "Mang khong co phan tu chan duong" << endl;
}
//16. tim vi tri xuat hien dau tien cua x
void vtriDauTienCuaX(int** a, int n, int m) {
    int x;
    cout << "Ban muon tim gia tri x nao? (vd neu ban nhap x = 5 thi no se in ra vi tri dau cua x = 5)\n";
    cout << "x = ";
    cin >> x;
    
    bool timThayPhanTuX = false;
    for (int i = 0; i < n && !timThayPhanTuX; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == x) {
                cout << "Vay " << x << " xuat hien lan dau tien tai vi tri a[" << i << "][" << j << "]";
                timThayPhanTuX = true;             
            }            
        }
        cout << endl;
    }
    if (!timThayPhanTuX) {
        cout << "Khong tim thay phan tu " << x << " trong ma tran!" << endl;
    }
}
//17. xoa dong co tong so thuc lon nhat
void xoaDongTongSoThucLonNhat(double** &b, int &n, int &m) {
    cout << "Vi 17 la cau dac biet nen vui long nhap lai n, m va mang (chi nhap so thap phan)\n";
    cout << "Nhap lai phan tu dong n: ";
    cin >> n;
    cout << "Nhap lai phan tu cot m: ";
    cin >> m;
    if (n == 0) {
        cout << "Ma tran rong nen khong co dong de xoa" << endl;
        return;
    }
    cout << "Nhap lai mang toan so thap phan\n";
    b = new double*[n];
    for (int i = 0; i < n; i++) {
        b[i] = new double[m];
    }
    cout << "nhap mang moi vs toan so thuc:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    cout << endl;
        
    //tim dong co tong lon nhat
    int dongLonNhat = 0;
    double tongLonNhat = -1e18;
    for (int i = 0; i < n; i++) {
        double tong = 0;
        for (int j = 0; j < m; j++) {
            tong += b[i][j];
        }
        if (tong > tongLonNhat) {
            tongLonNhat = tong;
            dongLonNhat = i;
        }
    }
    
    //xoa dong co tong lon nhat
    for (int i = dongLonNhat; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = b[i + 1][j];
        }
    }
    n--;
    
    //xuat lai ma tran ra man hinh sau khi xoa dong co tong so thuc lon nhat
    cout << "Ma tran sau khi da xoa dong co tong so thuc lon nhat\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//18. sap xep lai ma tran tang dan tu trai sang phai tu tren xuong duoi
void sapXepMaTranTangDan(int** a, int n, int m) {
    //flatten (lam phang) ma tran thanh vector
    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v.push_back(a[i][j]);
        }
    }
    
    //sap xep vector tang dan
    sort(v.begin(), v.end());
    
    //gan nguoc lai vao ma tran
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = v[idx++];
        }
    }
    
    //in ra lai ma tran sau da sap xep tang dan
    cout << "Ma tran sau khi da sap tang dan la\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//19. tich 2 ma tran
void tich2MaTran(int** a, int** &bb, int** &c, int &n, int &m, int &p) {
    bb = new int*[m];
    for (int i = 0; i < m; i++) {
      bb[i] = new int[p];
    }
    c = new int*[n];
    for (int i = 0; i < n; i++) {
      c[i] = new int[p];
    }
    cout << "Nhap kich thuoc ma tran b (m*p)\n";
    cout << "Nhap p: ";
    cin >> p;
    cout << "Nhap them ma tran b:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cin >> bb[i][j];
        }
    }
    // n*m nhan m*p = n*p
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * bb[k][j];
            }
        }
    }
    
    // in ma tran c[i][j] (tich cua ma tran a[i][j] * b[i][j])
    cout << "Tich cua ma tran c = a * b la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
//20. tong 2 ma tran
void tong2MaTran(int** a, int** &bbb, int &n, int &m) {
    bbb = new int*[n];
    for (int i = 0; i < n; i++) {
        bbb[i] = new int[m];
    }
    cout << "Nhap them ma tran bbb:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> bbb[i][j];
        }
    }
    cout << "Tong 2 ma tran a + bbb la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] + bbb[i][j] << "\t";      
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int** a = nullptr;
    int** bb = nullptr;
    int** bbb = nullptr;
    int** c = nullptr;
    double** b = nullptr;
    int n, m, p, d1, d2, c1, c2, chon;
    
    nhapMT (a, n, m);   
    menu();

    while (true) {

        lua(chon);

        if (chon == 0) return 0;
        else if (chon == 1) {
            doTGian([&]() {  tongDong(a, n, m); } );
        }
        else if (chon == 2) {
            doTGian([&]() {  tongCot(a, n, m); } );
        }
        else if (chon == 3) {
            doTGian([&]() {  tongDuongCheoChinh(a, n, m); } );
        }
        else if (chon == 4) {
            doTGian([&]() {  tongGTLNCuaTungDong(a, n, m); } );
        }
        else if (chon == 5) {
            doTGian([&]() {  tinhTrungBinhGTNNCuaMoiCot(a, n, m); } );
        }
        else if (chon == 6) {
            doTGian([&]() {  tongGTNNCuaTungDgCheo(a, n, m); } );
        }
        else if (chon == 7) {
            doTGian([&]() {  timVTPhanTuLonNhat(a, n, m); } );
        }
        else if (chon == 8) {
            doTGian([&]() {  VTChanCuoiCung(a, n, m); } );
        }
        else if (chon == 9) {
            doTGian([&]() {  PTuAmLeLonNhat(a, n, m); } );
        }
        else if (chon == 10) {
            doTGian([&]() {  chanDuongNhoNhat(a, n, m); } );
        }        
        else if (chon == 11) {
            doTGian([&]() {  ptuLonNhatDgCheoChinh(a, n, m); } );
        }
        else if (chon == 12) {
            cout << "Ban muon hoan doi dong hay cot? (Nhap d de doi dong, c de doi cot)\n";
            char phim; cin >> phim;
            if (phim == 'd') {
                doTGian([&]() {  hviHaiDong(a, n, m, d1, d2); } );
            }
            else if (phim == 'c') {
                doTGian([&]() {  hviHaiCot(a, n, m, c1, c2); } );
            }
        }
        else if (chon == 13) {
            cout << "Ban muon xoa dong hay cot? (Nhap d de xoa dong, c de xoa cot)\n";
            char phim; cin >> phim;
            if (phim == 'd') {
                doTGian([&]() {  xoaDong(a, n, m); } );
            }
            else if (phim == 'c') {
                doTGian([&]() {  xoaCot(a, n, m); } );
            }
        }
        else if (chon == 14) {
            cout << "Ban muon chen them dong hay cot? (Nhap d de chen dong, c de chen cot)\n";
            char phim; cin >> phim;
            if (phim == 'd') {
                doTGian([&]() {  chenDong(a, n, m); } );
            }
            else if (phim == 'c') {
                doTGian([&]() {  chenCot(a, n, m); } );
            }
        }
        else if (chon == 15) {
            doTGian([&]() {  chanDuongLonNhat(a, n, m); } );
        }
        else if (chon == 16) {
            doTGian([&]() {  vtriDauTienCuaX(a, n, m); } );
        }
        else if (chon == 17) {
            doTGian([&]() {  xoaDongTongSoThucLonNhat(b, n, m); } );
        }
        else if (chon == 18) {
            doTGian([&]() {  sapXepMaTranTangDan(a, n, m); } );
        }
        else if (chon == 19) {
            doTGian([&]() { tich2MaTran(a, bb, c, n, m, p); } );
        }
        else if (chon == 20) {
            doTGian([&]() { tong2MaTran(a, bbb, n, m); } );
        }
        else if (chon == 21) {
            //Giải phóng bộ nhớ của mảng cũ nếu người dùng chọn nhập mảng mới
            if (a) giaiPhong(a, n);
            if (b) giaiPhong(b, n);
            if (bb) giaiPhong(bb, m);   // chú ý: bb có m dòng
            if (bbb) giaiPhong(bbb, n);
            if (c) giaiPhong(c, n);
    
            nhapMT (a, n, m);
            menu();
            continue; // quay lại vòng lặp nơi đã có hàm lua(chon)
        }
    }
    //GIẢI PHÓNG BỘ NHỚ KHI NGƯỜI DÙNG THOÁT CHƯƠNG TRÌNH
    giaiPhong(a, n);
    giaiPhong(b, n);
    giaiPhong(bb, m);
    giaiPhong(bbb, n);
    giaiPhong(c, n);
}