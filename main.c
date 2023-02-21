#include <stdio.h>

int main() {



    FILE *myfile = fopen("data.txt", "r");
    if (myfile == NULL) {
        printf("Cannot open file.\n");
        return 1;
    } else {
        int num;
        int department_prefs[5][5], programmer_prefs[5][5], assigned[5][5];
        do {
            num = fgetc(myfile);
        } while (num != EOF);
        rewind(myfile);
        int i, j;
        //Reading data from file to departments matrices
        for (i = 0; i < 5; i++) {
            fscanf(myfile, "%d %d %d %d %d", &department_prefs[i][0], &department_prefs[i][1], &department_prefs[i][2], &department_prefs[i][3], &department_prefs[i][4]);
            }
        //Reading data from file to programmers matrices
        for (i = 0; i < 5; i++) {
            fscanf(myfile, "%d %d %d %d %d", &programmer_prefs[i][0], &programmer_prefs[i][1], &programmer_prefs[i][2], &programmer_prefs[i][3], &programmer_prefs[i][4]);
            }
        
    int prog_dept[5] = {0}; //Array keeping track of where each programmer is currently assigned
    int dept_filled[5] = {0}; //Flag indicating whether a department has been filled

    //Iterating through departments in order of preference
    for (int i = 0; i < 5; i++) {
        //Iterate through programmers in order of preference for this department
        for (int j = 0; j < 5; j++) {
            int programmer_index = department_prefs[i][j] - 1; //Index of programmer in programmer_prefs
            //If the programmer has not been assigned
            if (prog_dept[programmer_index] == 0) {
                prog_dept[programmer_index] = i + 1; //Then assign the programmer to this department
                dept_filled[i] = 1; //And mark this department as filled
                break; //And move on to the next department
            }
            //If the programmer prefers this department to their current one
            else if (programmer_prefs[programmer_index][i] < programmer_prefs[programmer_index][prog_dept[programmer_index] - 1]) {
                dept_filled[prog_dept[programmer_index] - 1] = 0; //Then unassign the programmer from their current department
                prog_dept[programmer_index] = i + 1; //And assign the programmer to this department
                dept_filled[i] = 1; //And mark this department as filled
                break; //And move on to the next department
            }
        }
    }

    printf("Programmer assignments:\n");
    for (int i = 0; i < 5; i++) {
        printf("Programmer %d assigned to Department %d\n", i + 1, prog_dept[i]);
    }
        return 0;
    }
}