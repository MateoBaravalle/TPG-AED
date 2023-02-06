#include <stdio.h>
#include <string.h>

void writeRoutine(char *memberName) {
    char routine[3800];
    int wordCount = 0;
    int i;
    
    printf("Enter routine for member %s (max 380 words):\n", memberName);
    fgets(routine, 3800, stdin);
    
    // Count the number of spaces in the routine
    for (i = 0; i < strlen(routine); i++) {
        if (routine[i] == ' ') {
            wordCount++;
        }
    }
    
    // Add one to the word count to account for the final word
    wordCount++;
    
    if (wordCount <= 380) {
        FILE *f = fopen("routines.txt", "a");
        fprintf(f, "Routine for member %s:\n%s\n", memberName, routine);
        fclose(f);
        printf("Routine for member %s has been successfully registered.\n", memberName);
    } else {
        printf("Error: Routine for member %s exceeds 380 words.\n", memberName);
    }
}

int main() {
    char memberName[100];
    
    printf("Enter name of member:\n");
    fgets(memberName, 100, stdin);
    
    // Remove newline character from memberName
    memberName[strlen(memberName) - 1] = '\0';
    
    writeRoutine(memberName);
    
    return 0;
}

