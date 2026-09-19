

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define ID_LEN 10

typedef struct{
    char id[ID_LEN];            //MSSV
    char name[NAME_LEN];        //Họ và Tên
    int age;                    //Tuổi
    float gpa;                  //Điểm trung bình
}Student;