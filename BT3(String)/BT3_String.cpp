//Tên: Bùi Tạ Quang Minh 
//MSSV: 2524802010333
//Lớp: D25CNTT06
//Câu 1:
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void menu() {
    cout << "\n===============MENU===============\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "1. String length\n";
    cout << "2. Count digits\n";
    cout << "3. License plate node\n";
    cout << "4. Toggle uppercase/lowercase\n";
    cout << "5. Replace spaces\n";
    cout << "6. Lexicographical comparison\n";
    cout << "7. Password validation\n";
    cout << "8. Gmail validation\n";
    cout << "9. Trim string\n";
    cout << "10. Most frequent alphabet\n";
}

//Câu 1: Viết chương trình nhập vào một chuỗi bất kì, in ra màn hình độ dài của chuỗi đó.
void DoDaiChuoi(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s); 
    cout << s.size();
}

//Câu 2: Viết chương trình nhập một chuỗi bất kỳ gồm nhiều từ. Đếm và in ra màn hình số kí tự là chữ số.
void DemVaInRaSoKiTuChuSo(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);

    int dem = 0;
    for (char c : s)
        if (c >= '0' && c <= '9')
            dem++; 
    cout << dem;
}

//Câu 3: Viết chương trình nhập vào một chuỗi bảng số xe gồm 2 phần: mã tĩnh
//và số xe cách nhau dấu gạch '-'. Tính là in ra màn hình số nút của số xe.
//Ví dụ: nhập bảng số xe "61A-17007"  sau có tổng số xe là : 1+7+7 = 15 => kết quả in ra 5
void NutCuaSoXe(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);
    
    // Cắt và lấy phần sau dấu "-"
    int VTri = s.find("-");
    string soXe = s.substr(VTri + 1);
    
    int tong = 0;
    for (char c : soXe) 
        if (isdigit(c))
            tong += c - '0'; 
    cout << tong % 10;
}

//Câu 4: Viết chương trình nhập vào một chuỗi bất kỳ gồm nhiều từ. In ra màn hình chuỗi sau khi chuyển kí tự hoa thành thường và ngược lại.
void DaoHoaThanhThuongVaDaoThuongThanhHoa(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);

    for (char &c : s) 
        if (islower(c)) 
            c = toupper(c);
        else 
            c = tolower(c);           
    cout << s;
}

//Câu 5: Viết chương trình nhập vào chuỗi bất kỳ gồm nhiều dấu cách. In ra màn chuỗi sau khi thay các dấu cách bằng kí tự 'A'.
void ChenChuAVaoDauCach(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);
    
    string kq;
    for (char c : s)
        if (c == ' ') kq += 'A';
        else kq += c;
    cout << kq;
}

/*Câu 6: Viết chương trình nhập vào 2 chuỗi S1,S2 bất kỳ gồm nhiều dấu cách.
Thực hiện so sánh 2 chuỗi (không sử dụng hàm có sẳn trong c/c++) theo nguyên tắc sau:
- So sánh từng cặp kí tự từ trái qua phải của S1 và S2, kí tự của chuỗi nào có mã
ASCII lớn hơn thì chuỗi đó lớn hơn.
Ví ụ: “AAAcbaaa” <“Aaabc”
 “bcdaBc” > “baacccaaa”
- Nếu S2 là phần đầu của S1 thì S1>S2
“ABBCdeee”>”ABBC”
Kết quả in ra:
S1>S2 in ra 1
S1<S2 in ra -1
S1=S2 in ra 0*/
void SoSanhChuoi(string &s1, string &s2) {
    cout << "Moi ban nhap chuoi s1: ";
    getline(cin, s1);
    cout << "Moi ban nhap chuoi s2: ";
    getline(cin, s2);
    
    cout << (s1 > s2 ?  1 : s1 < s2 ? -1 : 0); 
}

/*Câu 7: Viết chương trình nhập vào một password bất kì. Kiểm tra password
hợp lệ và in ra màn hình (Password hợp lệ có ít nhất 8 kí tự, bao gồm ít nhất 1 chữ cái
viết hoa, 1 cái viết thường và 1 kí tự đặc biệt).*/
void MKHopLe(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);

    if (s.size() < 8) {
        cout << 0;
        return;
    } else {
        bool chuHoa = false, chuThuong = false, kyTu = false;
        for (char c : s) 
            if (isupper(c)) chuHoa = true;
            else if (islower(c)) chuThuong = true;
            else if (!isalnum(c)) kyTu = true;
        cout << (chuHoa && chuThuong && kyTu ? 1 : 0);
    }
}


/* Câu 8: viết chương trình nhập vào một địa chỉ Email. Kiểm tra địa chỉ mail có
phải là gmail không, tức là chứa chuỗi '@gmail.com.' ( chú ý: không phân biệt chữ hoa,
chữ thường) */
void KTraCoPhaiGmailKhong(string &s) {
    cout << "Moi ban nhap email: ";
    getline(cin, s);

    cout << (s.find("gmail") != string::npos || s.find("Gmail") != string::npos ? 1 : 0);
}

//Câu 9: Viết chương trình nhập vào một chuỗi gồm các khoản trắng ở đầu và cuối. Viết hàm xóa các khoản trắng (Trim) ở đầu và cuối chuỗi và in ra màn hình.
void KTKhoangTrong(string &s) {  
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);

    int batDau = 0;
    while (batDau < s.size() && isspace(s[batDau])) 
        batDau++;
    
    int ketThuc = s.size() - 1;
    while (ketThuc >= 0 && isspace(s[ketThuc])) 
        ketThuc--;
    
    if (batDau > ketThuc) {
        cout << ""; // Trường hợp nếu người dùng nhập toàn khoảng trắng thì trả về chuỗi rỗng
        return;
    }
    // In ra chuỗi sau khi đã bỏ khoảng trắng ở đầu và cuối
    cout << s.substr(batDau, ketThuc - batDau + 1);
}

/* Câu 10: Viết chương trình nhập vào một chuỗi bất kỳ gồm nhiều từ. Đếm và in
ra màn hình kí tự Alphabets (‘a’ -> ‘z’) xuất hiện nhiều nhất và số lần xuất xuất hiện theo
định dạng, nếu có nhiều hơn 1 kí tự thì in trên nhiều dòng. */
void KTChuXuatHienNhieuNhat(string &s) {
    cout << "Moi ban nhap chuoi: ";
    getline(cin, s);

    // Đếm tần xuất của từng chữ cái trong chuỗi
    int chuCai[26] = {0};
    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);       
            chuCai[c - 'a']++;
        }
    }

    // Tìm tần số xuất hiện lớn nhất trong các chữ cái
    int nhieuNhat = 0; 
    for (int i = 0; i < 26; i++)
        if (chuCai[i] > nhieuNhat) 
            nhieuNhat = chuCai[i];

    // n ra chữ cái có số lần xuất hiện bằng gtri lớn nhất
    for (int i = 0; i < 26; i++)
        if (chuCai[i] == nhieuNhat) 
            cout << char(i + 'a') << ":" << chuCai[i] << endl;
}

int main() {
    string s, s1, s2;
    int chon;

    while(true){
        menu();
        cin >> chon;
        cin.ignore();

        switch(chon){
            case 1: DoDaiChuoi(s); break;
            case 2: DemVaInRaSoKiTuChuSo(s); break;
            case 3: NutCuaSoXe(s); break;
            case 4: DaoHoaThanhThuongVaDaoThuongThanhHoa(s); break;
            case 5: ChenChuAVaoDauCach(s); break;
            case 6: SoSanhChuoi(s1, s2); break;
            case 7: MKHopLe(s); break;
            case 8: KTraCoPhaiGmailKhong(s); break;
            case 9: KTKhoangTrong(s); break;
            case 10: KTChuXuatHienNhieuNhat(s); break;
            case 0: return 0;
            default: cout << "Lua chon khong hop le!";
        }
        cout << "\n";
    }
}