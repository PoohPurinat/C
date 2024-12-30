#include <stdio.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_STUDENTS 10

struct Course{
    char courseCode[10],courseName[50];
    int credits;
};

struct Student{
    char studentID[10],name[50];
    struct Course registeredCourses[MAX_COURSES];
    int courseCount;

};

struct Course courses[MAX_COURSES];
struct Student students[MAX_STUDENTS];
int courseCount=0,studentCount=0;

void displaymenu(){
        printf("===== Course Registration System =====\n");
        printf("1. Add New Course\n");
        printf("2. Add New Student\n");
        printf("3. Register Course for Student\n");
        printf("4. Display Student's Registered Courses\n");
        printf("5. Save Data\n");
        printf("6. Load Data\n");
        printf("7. Exit\n");
        printf("Select an option (1-7): ");
}

void addCourse(){
    if(courseCount >= MAX_COURSES){
        printf("Can't add more courses.\n");
        return;
    }
     printf("Enter Course Code: ");
    fgets(courses[courseCount].courseCode, sizeof(courses[courseCount].courseCode), stdin);
    courses[courseCount].courseCode[strcspn(courses[courseCount].courseCode, "\n")] = '\0';

    printf("Enter Course Name: ");
    fgets(courses[courseCount].courseName, sizeof(courses[courseCount].courseName), stdin);
    courses[courseCount].courseName[strcspn(courses[courseCount].courseName, "\n")] = '\0';

    printf("Enter Credits: ");
    scanf("%d", &courses[courseCount].credits);
    getchar();

    courseCount++;
    printf("Course added successfully.\n");
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Can't add more students.\n");
        return;
    }
    printf("Enter Student ID: ");
    fgets(students[studentCount].studentID, sizeof(students[studentCount].studentID), stdin);
    students[studentCount].studentID[strcspn(students[studentCount].studentID, "\n")] = '\0';

    printf("Enter Student Name: ");
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0';

    students[studentCount].courseCount = 0;

    studentCount++;
    printf("Student added successfully.\n");
}

void registerCourse() {
    char studentID[10];
    char courseCode[10];

    printf("Enter Student ID: ");
    fgets(studentID, sizeof(studentID), stdin);
    studentID[strcspn(studentID, "\n")] = '\0';

    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter Course Code to Register: ");
    fgets(courseCode, sizeof(courseCode), stdin);
    courseCode[strcspn(courseCode, "\n")] = '\0';

    int courseIndex = -1;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].courseCode, courseCode) == 0) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    if (students[studentIndex].courseCount < MAX_COURSES) {
        students[studentIndex].registeredCourses[students[studentIndex].courseCount] = courses[courseIndex];
        students[studentIndex].courseCount++;
        printf("Course registered successfully.\n");
    } else {
        printf("Student has already registered for the maximum number of courses.\n");
    }
}

void displayStudentCourses() {
    char studentID[10];

    printf("Enter Student ID: ");
    fgets(studentID, sizeof(studentID), stdin);
    studentID[strcspn(studentID, "\n")] = '\0';

    int studentIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].studentID, studentID) == 0) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Courses registered by %s:\n", students[studentIndex].name);
    printf("%-15s %-45s %-15s\n", "Course Code", "Course Name", "Credits");
    for (int i = 0; i < students[studentIndex].courseCount; i++) {
    printf("%-15s %-45s %-15d\n",
           students[studentIndex].registeredCourses[i].courseCode,
           students[studentIndex].registeredCourses[i].courseName,
           students[studentIndex].registeredCourses[i].credits);
}
}

void saveData() {
    FILE *file = fopen("registration_data.txt", "w");
    if (!file) {
        printf("Failed to open file for saving data.\n");
        return;
    }

    fprintf(file, "Number of courses: %d\n", courseCount);
    fprintf(file, "Course details:\n");
    for (int i = 0; i < courseCount; i++) {
        fprintf(file, "Course %d:\n", i + 1);
        fprintf(file, "Course Code: %s\n", courses[i].courseCode);
        fprintf(file, "Course Name: %s\n", courses[i].courseName);
        fprintf(file, "Credits: %d\n", courses[i].credits);
    }

    fprintf(file, "Number of students: %d\n", studentCount);
    fprintf(file, "Student details:\n");
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "Student ID: %s\n", students[i].studentID);
        fprintf(file, "Student Name: %s\n", students[i].name);
        fprintf(file, "Courses registered: %d\n", students[i].courseCount);
        for (int j = 0; j < students[i].courseCount; j++) {
            fprintf(file, "Course Code: %s\n", students[i].registeredCourses[j].courseCode);
        }
    }

    fclose(file);
    printf("Data saved successfully.\n");
}

void loadData() {
    FILE *file = fopen("registration_data.txt", "r");
    if (!file) {
        printf("No data file found.\n");
        return;
    }

    if (fscanf(file, "Number of courses: %d\n", &courseCount) != 1) {
        printf("Error loading number of courses.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < courseCount; i++) {
        char temp[50];
        if (fscanf(file, "Course %d:\n", &i) != 1) break;
        if (fscanf(file, "Course Code: %s\n", courses[i].courseCode) != 1) break;
        if (fscanf(file, "Course Name: %[^\n]\n", temp) != 1) break;
        strcpy(courses[i].courseName, temp);
        if (fscanf(file, "Credits: %d\n", &courses[i].credits) != 1) break;
    }

    if (fscanf(file, "Number of students: %d\n", &studentCount) != 1) {
        printf("Error loading number of students.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        char temp[50];
        if (fscanf(file, "Student ID: %s\n", students[i].studentID) != 1) break;
        if (fscanf(file, "Student Name: %[^\n]\n", temp) != 1) break;
        strcpy(students[i].name, temp);
        if (fscanf(file, "Courses registered: %d\n", &students[i].courseCount) != 1) break;

        for (int j = 0; j < students[i].courseCount; j++) {
            if (fscanf(file, "Course Code: %s\n", students[i].registeredCourses[j].courseCode) != 1) break;

            // ค้นหารายวิชาใน courses[] เพื่อเติมข้อมูล Name และ Credits
            for (int k = 0; k < courseCount; k++) {
                if (strcmp(students[i].registeredCourses[j].courseCode, courses[k].courseCode) == 0) {
                    strcpy(students[i].registeredCourses[j].courseName, courses[k].courseName);
                    students[i].registeredCourses[j].credits = courses[k].credits;
                    break;
                }
            }
        }
    }

    fclose(file);
    printf("Data loaded successfully.\n");
}


int main(){
    int choice;

    while(1){
        displaymenu();
        scanf("%d", &choice);
        getchar();


        switch(choice){
            case 1:
                addCourse();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                registerCourse();
                break;
            case 4:
                displayStudentCourses();
                break;
            case 5:
                saveData();
                break;
            case 6:
                loadData();
                break;
            case 7:
                saveData();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    loadData();
}

