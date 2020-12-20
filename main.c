#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memory_allocation_check(void *pointer){
    if(pointer == NULL){
        printf("Cannot allocate memory\n");
        exit(1);
    }
}

char* get_std_char(int size){//used for getting filename
    char *name = malloc(sizeof(char) * size);//MAX_SIZE of filename
    memory_allocation_check(name);//check if malloc works
    while (1){
        if (fgets(name, size, stdin)) {//get what has been typed
            name[strcspn(name, "\n")] = '\0';//replace /n with \0, for opening
            break;
        } else {
            printf("Error reading\n");
        }
    }

    return name;
}

int main() {
    char *name = NULL;
    char *surname = NULL;
    char *age = NULL;
    printf("Enter name: ");
    name = get_std_char(30);
    while(strcmp(name, "\0") == 0){
        printf("Enter name: ");
        name = get_std_char(30);
    }
    printf("Enter surname: ");
    surname = get_std_char(30);
    while(strcmp(surname, "\0") == 0){
        printf("Enter surname: ");
        surname = get_std_char(30);
    }
    int age_int = 0;
    while (age_int == 0){
        printf("Enter age: ");
        age = get_std_char(30);
        age_int = atoi(age);
    }

    char *school;
    char *answer;
    if(age_int < 18){
        printf("Enter high school: ");
        school = get_std_char(100);
    } else {
        printf("Are you currently studying? [Y/N]: ");
        answer = get_std_char(10);
        if(strcmp(answer, "Y") == 0){
            printf("Enter university: ");
            school = get_std_char(50);
        }
    }

    char *gender;
    char  picture[150];
    int other = 0;
    printf("Are you male, female or other: ");
    gender = get_std_char(10);
    if(strcmp(gender, "male") == 0){
        strcpy(picture, "https://cdn1.iconfinder.com/data/icons/toilet-glyph/100/toilet_Glyph-02-512.png" );
    } else if (strcmp(gender, "female") == 0){
        strcpy(picture, "https://cdn1.iconfinder.com/data/icons/toilet-glyph/100/toilet_Glyph-03-512.png" );
    } else {
        strcpy(picture, "https://static.wikia.nocookie.net/simpsons/images/d/d4/Tapped_Out_Unlock_Kang.png/revision/latest?cb=20180529210835" );
        other = 1;

    }

    FILE *file_pointer;
    if ((file_pointer = fopen("main.html", "w")) == NULL) {//file_name
        printf("Error! opening file, please make sure the file exists\n");
    }

    fprintf(file_pointer, "<!DOCTYPE html>\n");
    fprintf(file_pointer, "<html>\n");
    fprintf(file_pointer, "<body>\n");
    fprintf(file_pointer, "<style>\n"
                          "body {\n"
                          "  background-image: url('https://venngage-wordpress.s3.amazonaws.com/uploads/2018/09/Minimalist-Crumpled-Paper-Simple-Background-Image.jpg');\n"
                          "  background-repeat: no-repeat;\n"
                          "  background-attachment: fixed;\n"
                          "  background-size: cover;\n"
                          "}\n"
                          "</style>\n");
    fprintf(file_pointer, "<h1 style=\"text-align:center\"> About me</h1>\n");
    if (other == 1){
        fprintf(file_pointer, "<h1> \"%s\"</small></h1>\n", gender);
    }
    fprintf(file_pointer, "<img src=\"%s\" alt=\"\">\n", picture);
    fprintf(file_pointer, "<h1> Name: <small> %s </small></h1>\n", name);
    fprintf(file_pointer, "<h1> Surname: <small> %s </small></h1>\n", surname);
    fprintf(file_pointer, "<h1> Age: <small> %s </small></h1>\n", age);
    if(age_int < 18){
        fprintf(file_pointer, "<h1> High school: <small> %s </small></h1>\n", school);
    } else  if(strcmp(answer, "Y") == 0){
        fprintf(file_pointer, "<h1> University: <small> %s </small></h1>\n", school);
    } else {
        fprintf(file_pointer, "<h1> I hope you have a job</h1>\n");
    }
    fprintf(file_pointer, "</body>\n");
    fprintf(file_pointer, "</html>\n");
}