//Tên: Bùi Tạ Quang Minh
//MSSV: 2524802010333
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//1. Fibonacci
int fibo(int n) {
    if (n <= 2) return 1;
    return fibo(n - 1) + fibo(n - 2);
    /*
        ví dụ chạy
        nhập n = 6
        f(6) = f(5) + f(4)
        Mà f(5) = f(4) + f(3)
        f(4) = f(3) + f(2)
        f(3) = f(2) + f(1)
        Nhưng f(2) và f(1) = 1
        => f(3) = 1 + 1 = 2
        => f(4) = 2 + 1 = 3
        => f(5) = 3 + 2 = 5
        => f(6) = 5 + 3 = 8
        Vậy f(6) = 8 =))
    */
}

//2. To hop C(k,n)
long long giaiThua(int n) {
    if (n <= 1) return 1;
    return n * giaiThua(n-1);

    /*
        ví dụ chạy
        nhập n = 5
        giaiThua(5) = n * giaThua(4)
        giaiThua(4) = n * giaiThua(3)
        giaiThua(3) = n * giaiThua(2)
        giaiThua(2) = n * giaiThua(1)
        Mà giaiThua(1) = 1 do n đã = 1
        nên giaiThua(2) = 2 * 1 = 2
            giaiThua(3) = 3 * 2 = 6
            giaiThua(4) = 4 * 6 = 24
            giaiThua(5) = 5 * 24 = 120
    */
}
long long Ckn(int k, int n) {
    return giaiThua(n) / (giaiThua(k) * giaiThua(n - k));

    /*
        ví dụ chạy
        do nhập n = 5, k = 3
        => dựa vào công thức trên ta có:
        giaiThua(5) / (giaiThua(3) * giaiThua(5 - 3))
        mà giaiThua(5) = 120, giaiThua(3) = 6, giaiThua(2) = 2
        nên 120 / (6*2) = 10
        Vậy C(5,3) = 10 =))
    */
}

//3. Tìm max trong mảng
int timMax(vector<int> a, int n) {
    if (n == 1) return a[0];
    return max(a[n - 1], timMax(a, n - 1));
    /* 
        Ví dụ chạy với A = [7,0,3,10,6], n=5
        timMax(5) = max(A[4], timMax(4))
        timMax(4) = max(A[3], timMax(3))
        timMax(3) = max(A[2], timMax(2))
        timMax(2) = max(A[1], timMax(1))
        timMax(1) = A[0] = 7
        => timMax(2) = max(0,7) = 7
        => timMax(3) = max(3,7) = 7
        => timMax(4) = max(10,7) = 10
        => timMax(5) = max(6,10) = 10
    */
}

//4. Đổi số nguyên sang mã nhị phân
void nhiPhan(int n) {
    if (n == 0) return;
    nhiPhan(n/2);
    cout << n%2;
    /*
        ví dụ chạy n = 10
        nhiPhan(10) = nhiPhan(5), 10%2 = 0
        nhiPhan(5) = nhiPhan(2), 5%2 = 1
        nhiPhan(2) = nhiPhan(1), 2%2 = 0
        nhiPhan(1) = nhiPhan(0), 1%2 = 1
        nhiPhan(0) đã đạt điều kiện dừng nên ko in gì nữa
        do n = 0 nên giờ máy nó sẽ đi ngược lên lại
        tức nhiPhan(1) = 1
            nhiPhan(2) = 0
            nhiPhan(5) = 1
            nhiPhan(10) = 0
        => 10 khi chuyển sang nhị phân là 1010
    */
}

//5. Đảo chuỗi
void daoChuoi(const string& s, int i) {
    if (i < 0) return;
    cout << s[i];
    daoChuoi(s, i - 1);

    /*
        ví dụ chạy "Lap trinh c" có 11 ký tự (kể cả khoảng trắng)
        daoChuoi(Lap trinh c, 10) => s[10] = c
        daoChuoi(Lap trinh , 9) => s[9] = khoảng trắng
        ...
        daoChuoi(L, 0) => s[0] = L

        Vậy chuỗi đảo ngược là "c hnirt paL"
    */
}

//6. Tháp Hà Nội
void thapHN(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << " -> " << C << endl;
        return;
    }
    thapHN(n-1, A, C, B);
    cout << A << " -> " << C << endl;
    thapHN(n-1, B, A, C);

    /* 
        1.
        Ví dụ chạy vs n = 2, A->B
        HN(2, A, C, B) 
        = HN(1, A, B, C), in A->B, HN(1, B, A, C)
        => A->B, A->C, B->C

        2.
        Ví dụ chạy với n=3, A->C
        HN(3,A,B,C)
        = HN(2,A,C,B), in A->C, HN(2,B,A,C)

        HN(2,A,C,B)
        = HN(1,A,B,C), in A->B, HN(1,C,A,B)
        => A->C, A->B, C->B

        Quay lên: in A->C

        HN(2,B,A,C)
        = HN(1,B,C,A), in B->C, HN(1,A,B,C)
        => B->A, B->C, A->C
    */
}

//7.Dãy Hailstone
void hailstone(int n) {
    cout << n << " ";
    if (n == 1) return;
    if (n % 2 == 0) hailstone(n/2);
    else hailstone(3*n+1);

    /*
        ví dụ chạy n = 13
        hailstone(13) có n lẻ nên = hailstone(3*13+1) = 40
        hailstone(40) có n chẵn nên = hailstone(40/2) = 20
        cứ lặp lại đến khi hailstone có n = 1 thì dừng lại 
    */
}

//8. a^n
double mu(int a, int n) {
    if (n == 0) return 1;
    return a * mu(a, n-1);

    /*
        ví dụ chạy a = 2, n = 3
        mu(2, 3) = 2 * mu(2, 3-1=2)
        mu(2, 2) = 2 * mu(2, 2-1=1)
        mu(2, 1) = 2 * mu(2, 1-1=0)
        do n đã = 0 nên return 1
        => mu(2, 0) = 1
        => mu(2, 1) = 2 * 1 = 2
        => mu(2, 2) = 2 * 2 = 4
        => mu(2, 3) = 2 * 4 = 8
    */
} 

//9. s(n)
double s(int n) {
    if (n == 1) return 1.0/(1*2);
    return s(n-1) + 1.0/(n*(n+1));

    /*
        ví dụ chạy n = 3
        s(3) = s(3-1=2) * 1.0/(3*(3+1))
        s(2) = s(2-1=1) * 1.0/(2*(2+1))
        do s(1) đã có n = 1 nên ta có
        => s(1) = 1.0/(1*2) = 0.5
        => s(2) = 0.5 + 1.0/(2*(2+1)) = 0.6666667
        => s(3) = 0.666667 + 1.0/(3*(3+1)) = 0.75
    */
}

//10. ucln
int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a%b);

    /*
        ví dụ chạy a = 4, b = 6
        ucln(4, 6) = ucln(6, 4%6 = 4) -> a=6, b=4
        ucln(6, 4) = ucln(4, 6%4 = 2) -> a=4, b=2
        ucln(4, 2) = ucln(2, 4%2 = 0) -> a=2, b=0
        do ucln(2, 0) đã có b = 0 nên return a = 2
        Vậy ucln của 4 và 6 là 2
    */
}
int main() {
    int chon;
    while (true) {
         cout << "\n===== MENU DE QUY =====\n";
        cout << "1. Fibonacci\n";
        cout << "2. To hop C(k,n)\n";
        cout << "3. Tim max trong mang\n";
        cout << "4. Doi sang nhi phan\n";
        cout << "5. Dao chuoi\n";
        cout << "6. Thap Ha Noi\n";
        cout << "7. Day Hailstone\n";
        cout << "8. Tinh a^n\n";
        cout << "9. Tinh S(n)\n";
        cout << "10. UCLN\n";
        cout << "0. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> chon;

        if (chon == 1) {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            cout << fibo(n) << endl;
        }
        else if (chon == 2) {
            int n, k;
            cout << "Nhap k: ";
            cin >> k;
            cout << "Nhap n: ";
            cin >> n;
            cout << Ckn(k, n) << endl;
        }
        else if (chon == 3) {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            vector<int> a(n);
            cout << "Nhap mang n phan tu";
            for (int i = 0; i < n; i++) cin >> a[i];
            cout << "Phan tu max trong mang la: " << timMax(a, n) << endl;
        }
        else if (chon == 4)  {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            nhiPhan(n); 
            cout << endl;
        }
        else if (chon == 5) {
            string s; 
            cin.ignore();
            getline(cin, s);
            daoChuoi(s, s.size() - 1);
            cout << endl;
        }
        else if (chon == 6) {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            thapHN(n, 'A', 'B', 'C');
            cout << endl;
        }
        else if (chon == 7) {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            hailstone(n);
            cout << endl;
        }
        else if (chon == 8) {
            int a, n;
            cout << "Nhap co so a: ";
            cin >> a;
            cout << "Nhap mu n: ";
            cin >> n;
            cout << "a^n = " << mu(a, n) << endl;;
        }
        else if (chon == 9) {
            int n;
            cout << "Nhap n: ";
            cin >> n;
            cout << s(n) << endl; 
        }
        else if(chon == 10) {
            int a, b;
            cout << "Nhap a va b: ";
            cin >> a >> b;
            cout << ucln(a, b) << endl;
        }
        else if (chon == 0) return 0;
        else cout << "Lua chon khong hop le!\n";
    }
    return 0; 
}