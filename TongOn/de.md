# Đề Ôn Tập C: Quản Lý Danh Sách Sinh Viên
 
## 1. Mô Tả Đề Bài
 
### Chủ đề
 
Quản lý danh sách sinh viên bằng *mảng con trỏ struct*, tách chương trình thành nhiều module (mỗi nhóm chức năng một cặp .h`/.c` riêng), thao tác thêm/xóa/tìm/sắp xếp.
 
### Cấu trúc dữ liệu bắt buộc
 
typedef struct {
    char  id[10];      // Mã sinh viên, VD: "SV001"
    char  name[50];    // Họ tên
    int   age;
    float gpa;         // Điểm trung bình (0.0 - 4.0)
} Student;
 
Danh sách sinh viên phải lưu dưới dạng **Student *list[MAX_STUDENTS]** (mảng con trỏ, mỗi sinh viên malloc riêng lẻ). *Không* dùng mảng struct thường (Student list[MAX]) — đây là điểm mấu chốt để luyện con trỏ.
 
### Cấu trúc file (bắt buộc tách theo module)
 
| File | Nội dung |
|---|---|
| student.h | struct Student và #define dùng chung — chỉ chứa định nghĩa dữ liệu, không chứa prototype hàm |
| student_manage.h / student_manage.c | Prototype và cài đặt nhóm hàm quản lý vòng đời: createStudent, addStudent, deleteStudentById, freeAllStudents |
| student_search.h / student_search.c | Prototype và cài đặt nhóm hàm tìm kiếm: findStudentById |
| student_sort.h / student_sort.c | Prototype và cài đặt nhóm hàm sắp xếp: sortStudentsByGpa |
| student_io.h / student_io.c | Prototype và cài đặt nhóm hàm hiển thị: printAllStudents |
| main.c | Menu console, #include tất cả các header trên và gọi hàm tương ứng |
 
Tổng cộng 10 file: 1 header dữ liệu dùng chung, 4 cặp .h`/.c` theo nhóm chức năng, và main.c.
 
Mỗi file .h module (student_manage.h, student_search.h, student_sort.h, student_io.h) đều #include "student.h" để dùng chung struct Student — đây là cách tổ chức project nhiều module cùng chia sẻ 1 kiểu dữ liệu chung, tương tự cách chia file trong các dự án AUTOSAR/embedded thực tế (mỗi module có .h`/.c` riêng, dùng chung Std_Types.h).
 
### Các hàm bắt buộc cài đặt (rải theo từng file module ở trên)
 
Student* createStudent(const char *id, const char *name, int age, float gpa);
int      addStudent(Student *list[], int *count, Student *s);
int      deleteStudentById(Student *list[], int *count, const char *id);
Student* findStudentById(Student *list[], int count, const char *id);
void     sortStudentsByGpa(Student *list[], int count);   // giảm dần
void     printAllStudents(Student *list[], int count);
void     freeAllStudents(Student *list[], int count);      // tránh memory leak
 
### Yêu cầu chi tiết / bẫy để test hiểu bài
 
1. **#define**: MAX_STUDENTS 100, NAME_LEN 50, ID_LEN 10 — không hard-code số.
2. **createStudent** phải malloc(sizeof(Student)), nếu malloc thất bại (NULL) phải xử lý, không crash.
3. **deleteStudentById**: phải free() đúng con trỏ bị xóa, sau đó *dồn mảng con trỏ* (shift các phần tử phía sau lên) — chỗ dễ sai nhất (rò rỉ bộ nhớ hoặc dangling pointer nếu làm ẩu).
4. **sortStudentsByGpa**: chỉ hoán đổi *con trỏ* (Student *tmp), không copy nội dung struct. Mục đích: hiểu hoán đổi con trỏ khác hoán đổi giá trị.
5. **findStudentById**: trả về con trỏ Student* (hoặc NULL nếu không tìm thấy), dùng strcmp.
6. **freeAllStudents**: gọi khi thoát chương trình, đảm bảo không leak.
7. Không dùng biến toàn cục — count và list phải truyền qua tham số.
 
### Menu yêu cầu trong main.c
 
text
1. Thêm sinh viên
2. Xóa sinh viên theo mã
3. Tìm sinh viên theo mã
4. Sắp xếp theo GPA giảm dần
5. In danh sách
6. Thoát (giải phóng toàn bộ bộ nhớ)
 
### Ví dụ sử dụng chương trình sau khi hoàn thành
 
Dưới đây là một phiên chạy mẫu để hình dung chương trình hoạt động như thế nào. Phần in đậm là dữ liệu người dùng nhập vào.
 
#### Bước 1 — Thêm 3 sinh viên
 
text
===== QUAN LY SINH VIEN =====
1. Them sinh vien
2. Xoa sinh vien theo ma
3. Tim sinh vien theo ma
4. Sap xep theo GPA giam dan
5. In danh sach
6. Thoat
Chon: 1
Nhap ma SV: SV001
Nhap ho ten: Nguyen Van An
Nhap tuoi: 20
Nhap GPA: 3.2
Them thanh cong!
 
Chon: 1
Nhap ma SV: SV002
Nhap ho ten: Tran Thi Binh
Nhap tuoi: 21
Nhap GPA: 3.8
Them thanh cong!
 
Chon: 1
Nhap ma SV: SV003
Nhap ho ten: Le Van Cuong
Nhap tuoi: 19
Nhap GPA: 2.9
Them thanh cong!
 
#### Bước 2 — In danh sách (thứ tự theo lúc nhập)
 
text
Chon: 5
 
ID       Name                 Age   GPA
------------------------------------------
SV001    Nguyen Van An         20   3.20
SV002    Tran Thi Binh         21   3.80
SV003    Le Van Cuong          19   2.90
------------------------------------------
Tong so sinh vien: 3
 
#### Bước 3 — Sắp xếp theo GPA giảm dần
 
text
Chon: 4
Da sap xep theo GPA giam dan!
 
Chon: 5
 
ID       Name                 Age   GPA
------------------------------------------
SV002    Tran Thi Binh         21   3.80
SV001    Nguyen Van An         20   3.20
SV003    Le Van Cuong          19   2.90
------------------------------------------
Tong so sinh vien: 3
 
#### Bước 4 — Tìm sinh viên theo mã
 
text
Chon: 3
Nhap ma SV can tim: SV001
Tim thay: SV001 - Nguyen Van An - 20 tuoi - GPA 3.20
 
Chon: 3
Nhap ma SV can tim: SV999
Khong tim thay sinh vien!
 
#### Bước 5 — Xóa sinh viên và kiểm tra danh sách đã dồn đúng chưa
 
text
Chon: 2
Nhap ma SV can xoa: SV001
Xoa thanh cong!
 
Chon: 5
 
ID       Name                 Age   GPA
------------------------------------------
SV002    Tran Thi Binh         21   3.80
SV003    Le Van Cuong          19   2.90
------------------------------------------
Tong so sinh vien: 2
 
Lưu ý ở bước này: sau khi xóa SV001 (đang nằm giữa danh sách), các phần tử phía sau phải được dồn lên, count giảm từ 3 xuống 2, và vùng nhớ của SV001 phải được free(). Nếu in ra vẫn còn 3 dòng hoặc xuất hiện dữ liệu rác thì phần dồn mảng hoặc free đang sai.
 
#### Bước 6 — Thoát chương trình
 
text
Chon: 6
Da giai phong bo nho. Tam biet!
 
### Tiêu chí hoàn thành (Definition of Done)
 
- Biên dịch được toàn bộ project bằng lệnh:
  gcc -Wall -Wextra -o app main.c student_manage.c student_search.c student_sort.c student_io.c
- Không lỗi, không warning (ngoại trừ warning "unused parameter" khi thân hàm còn TODO).
- Chạy đủ 6 chức năng trong menu, không crash với input hợp lệ lẫn input rỗng/không tồn tại.
- Không leak bộ nhớ khi thoát chương trình (có thể kiểm tra bằng valgrind nếu có).
- sortStudentsByGpa chỉ hoán đổi con trỏ, không copy struct.
- Chạy lại được đúng kịch bản trong phần "Ví dụ sử dụng chương trình" ở trên.
 
---
 
## 2. Kiến Thức Cần Ôn Trước Khi Làm
 
### 2.1. Cơ bản về kiểu dữ liệu & biến
- Kiểu số nguyên (int), số thực (float), mảng ký tự (char[]) để biểu diễn chuỗi.
- Khác nhau giữa khai báo và định nghĩa biến.
 
### 2.2. struct
- Định nghĩa struct và typedef struct.
- Truy cập field bằng . (biến struct) và -> (con trỏ struct) — đề này dùng -> là chủ yếu.
 
### 2.3. Con trỏ (pointer) — phần trọng tâm nhất
- Con trỏ là gì, * và & dùng để làm gì.
- Con trỏ tới struct (Student *s).
- *Mảng con trỏ* (Student *list[MAX_STUDENTS]) khác mảng struct thường (Student list[MAX]) — điểm dễ nhầm nhất, list[i] là một địa chỉ, không phải bản sao dữ liệu.
- Con trỏ tới int (int *count) — vì sao addStudent phải nhận int *count mới thay đổi được count bên main.
- Phân biệt hoán đổi giá trị con trỏ (Student *tmp = list[i]; list[i] = list[j];) với hoán đổi nội dung struct (copy *list[i] sang *list[j]).
- Con trỏ NULL và kiểm tra NULL sau khi cấp phát.
 
### 2.4. Cấp phát bộ nhớ động
- malloc, sizeof, kiểm tra malloc trả về NULL.
- free và vì sao phải free đúng lúc, đúng con trỏ.
- *Memory leak* (quên free) và *dangling pointer* (dùng con trỏ sau khi đã free) — hai lỗi kinh điển ở deleteStudentById.
 
### 2.5. Chuỗi ký tự (string) trong C
- Chuỗi trong C là mảng char kết thúc bằng '\0'.
- Hàm chuẩn: strcpy`/strncpy` (copy chuỗi), strcmp (so sánh chuỗi, dùng cho so sánh id), strlen.
- Vì sao không thể dùng == để so sánh hai chuỗi.
 
### 2.6. #define và hằng số
- #define MAX_STUDENTS 100 — macro thay thế văn bản lúc biên dịch.
- Lợi ích: tránh "magic number", dễ sửa 1 chỗ.
 
### 2.7. Mảng (array)
- Mảng và con trỏ có quan hệ gì (list[i] tương đương *(list + i)).
- Duyệt mảng bằng vòng lặp for.
- Thao tác "dồn mảng" (shift trái) khi xóa 1 phần tử giữa mảng.
 
### 2.8. Hàm (function) & tách file .h / .c
- Khai báo prototype trong .h, định nghĩa trong .c, #include giữa các file.
- Truyền tham số theo giá trị (value) vs theo con trỏ (để thay đổi được biến gốc).
- #ifndef/#define/#endif (include guard) trong file .h.
 
### 2.9. Thuật toán sắp xếp cơ bản
- Bubble sort hoặc selection sort (chọn 1 trong 2), áp dụng để sort giảm dần theo GPA.
 
### 2.10. Thuật toán tìm kiếm cơ bản
- *Linear Search* (tìm kiếm tuần tự): duyệt từng phần tử, so sánh tới khi tìm thấy hoặc hết mảng. findStudentById ở mục 1 chính là Linear Search — độ phức tạp O(n).
- *Binary Search* (tìm kiếm nhị phân): chỉ áp dụng được khi mảng *đã sắp xếp* theo khóa tìm kiếm. Cắt đôi phạm vi tìm kiếm mỗi lần so sánh — độ phức tạp O(log n).
- Hiểu vì sao Binary Search nhanh hơn Linear Search nhưng đòi hỏi dữ liệu phải có thứ tự trước.
- Khái niệm cơ bản về độ phức tạp thuật toán: O(n) và O(log n) khác nhau như thế nào khi n lớn.
 
### 2.11. Đệ quy (Recursion)
- Một hàm gọi lại chính nó, có điều kiện dừng (base case) rõ ràng.
- Vì sao đệ quy không dừng đúng cách sẽ gây stack overflow.
- So sánh đệ quy với vòng lặp (loop) — cùng giải quyết 1 bài toán nhưng khác cách tổ chức code.
 
---
 
## 3. Yêu Cầu Nâng Cấp (Sau Khi Code Xong Bản Cơ Bản)
 
Phần này **chỉ làm sau khi** bạn đã hoàn thành và chạy đúng toàn bộ yêu cầu ở mục 1. Đây là bài tập nâng cấp (refactor), không phải yêu cầu ban đầu — đừng đọc phần này trước khi xong bản cơ bản.

 
### Yêu cầu nâng cấp: Con trỏ hàm (function pointer)
 
*Bài toán:* Hiện tại sortStudentsByGpa chỉ sort được theo 1 tiêu chí (GPA giảm dần). Yêu cầu nâng cấp: cho phép người dùng *chọn tiêu chí sắp xếp* (theo GPA, theo tên, theo tuổi...) mà *không viết nhiều hàm sort riêng lẻ*.
 
*Yêu cầu kỹ thuật:*
 
1. Viết 1 hàm sort tổng quát duy nhất, nhận thêm tham số là *con trỏ hàm so sánh*:
 
void sortStudents(Student *list[], int count, int (*cmp)(const Student *a, const Student *b));
 
2. Viết các hàm so sánh riêng biệt (không sort, chỉ so sánh và trả về kết quả):
 
int compareByGpaDesc(const Student *a, const Student *b);
int compareByNameAsc(const Student *a, const Student *b);
int compareByAgeAsc(const Student *a, const Student *b);
 
3. Trong main.c, cho người dùng chọn tiêu chí sort qua menu, sau đó gọi:
 
sortStudents(list, count, compareByGpaDesc);
// hoặc
sortStudents(list, count, compareByNameAsc);
 
*Ví dụ sử dụng sau khi nâng cấp:*
 
text
Chon: 4
 
--- Chon tieu chi sap xep ---
1. Theo GPA (giam dan)
2. Theo Ten (A-Z)
3. Theo Tuoi (tang dan)
Chon tieu chi: 2
Da sap xep theo Ten!
 
Chon: 5
 
ID       Name                 Age   GPA
------------------------------------------
SV003    Le Van Cuong          19   2.90
SV001    Nguyen Van An         20   3.20
SV002    Tran Thi Binh         21   3.80
------------------------------------------
Tong so sinh vien: 3
 
*Kiến thức cần đọc trước khi làm phần này:*
- Khái niệm con trỏ hàm (function pointer): cú pháp khai báo int (*cmp)(const Student *a, const Student *b), cách gán 1 hàm cho con trỏ hàm, cách gọi hàm thông qua con trỏ.
- Vì sao con trỏ hàm giúp tránh lặp code (1 hàm sort dùng chung cho nhiều tiêu chí, thay vì viết sortByGpa, sortByName, sortByAge riêng biệt).
- Liên hệ: đây chính là nguyên lý đứng sau hàm chuẩn qsort() trong <stdlib.h>. Nếu muốn mở rộng thêm, tìm hiểu và thử refactor lại bằng qsort().
 
*Tiêu chí hoàn thành phần nâng cấp:*
- Chỉ có 1 hàm sort duy nhất (không viết 3 hàm sort riêng cho 3 tiêu chí).
- Thêm tiêu chí sort mới chỉ cần viết thêm 1 hàm so sánh, không sửa hàm sort.
- Menu cho phép chọn tiêu chí và chạy đúng.
 
---
 
## 4. Yêu Cầu Nâng Cấp: Thuật Toán Tìm Kiếm & Đệ Quy
 
Phần này làm sau khi hoàn thành mục 1 (và có thể làm song song hoặc sau mục 3). Đây là bài tập nâng cấp, không phải yêu cầu ban đầu.

 
### 4.1. Binary Search
 
*Bài toán:* findStudentById hiện tại là Linear Search (O(n)). Viết thêm 1 hàm tìm kiếm bằng *Binary Search* để so sánh.
 
*Yêu cầu kỹ thuật:*
 
int sortStudentsById(Student *list[], int count);            // sắp xếp tăng dần theo id, điều kiện bắt buộc để binary search chạy đúng
Student* findStudentByIdBinary(Student *list[], int count, const char *id);
 
1. Binary Search chỉ chạy đúng khi list đã được sắp xếp theo id — phải gọi sortStudentsById trước khi gọi findStudentByIdBinary.
2. Cài đặt bằng vòng lặp (không dùng đệ quy ở bước này).
3. Thêm lựa chọn trong menu để người dùng so sánh kết quả giữa findStudentById (Linear Search) và findStudentByIdBinary (Binary Search) trên cùng 1 id.
4. Nếu list chưa được sắp xếp theo id mà gọi findStudentByIdBinary, kết quả có thể sai — phải tự nhận biết và xử lý (báo lỗi hoặc tự sort trước khi tìm).
 
*Ví dụ sử dụng sau khi nâng cấp:*
 
text
Chon: 7
Nhap ma SV can tim: SV003
 
[Linear Search]  Tim thay sau 3 lan so sanh: SV003 - Le Van Cuong
[Binary Search]  Tim thay sau 2 lan so sanh: SV003 - Le Van Cuong
 
*Tiêu chí hoàn thành:*
- findStudentByIdBinary trả về đúng kết quả trên danh sách đã sort theo id.
- Giải thích được (bằng lời, không cần code) vì sao Binary Search yêu cầu dữ liệu đã sort còn Linear Search thì không.
 
### 4.2. Đệ quy (Recursion)
 
*Bài toán:* Viết lại findStudentByIdBinary ở mục 4.1 bằng *đệ quy* thay vì vòng lặp.
 
*Yêu cầu kỹ thuật:*
 
Student* findStudentByIdBinaryRecursive(Student *list[], int low, int high, const char *id);
 
1. Xác định rõ *base case* (điều kiện dừng): khi low > high thì trả về NULL.
2. Mỗi lần gọi đệ quy phải thu hẹp phạm vi tìm kiếm (low`/high`), nếu không sẽ đệ quy vô hạn và stack overflow.
3. So sánh 2 bản cài đặt (vòng lặp ở mục 4.1 và đệ quy ở mục 4.2): cùng kết quả, khác cách tổ chức code.
 
*Tiêu chí hoàn thành:*
- Hàm đệ quy chạy đúng, không bị stack overflow với MAX_STUDENTS = 100.
- Chỉ ra được điểm dừng (base case) của hàm khi được hỏi.