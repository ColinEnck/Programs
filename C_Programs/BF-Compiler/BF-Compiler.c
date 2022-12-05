#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

char openingLines();
char *readFromFile(char filename[], int length);
char *readFromConsole(int *length);
void bfTranspiler(char bfcode[], int length);
void numOfTabs(FILE *p_outFile, int passedOpeningBrackets, int passedClosingBrackets);

int main(int argc, char **argv){
    int length;
    char *bfcode;
    if (argc == 3){
        char *filename = argv[1];
        char *lengthStr = argv[2];
        length = atoi(lengthStr); 
        bfcode = readFromFile(filename, length);

        bfTranspiler(bfcode, length);  
        system("gcc BF.c -o BF.exe");
        system("BF");
    }

    // redefine length and bfcode
    if (openingLines() == 'c'){
        length = 0;
        bfcode = readFromConsole(&length);
        bfTranspiler(bfcode, length);
        system("gcc BF.c -o BF.exe");
        system("BF");
    }
}

char openingLines(){
    printf("\n\nPress any key to continue... ");
    getchar();
    system("cls");
    printf("Welcome to the BF Compiler Menu!\n");
    printf("---------------------------\n");
    printf("Developed by Colin Enck\n");
    printf("-----------------------\n\n");
    printf("Parameters: the first is the filename and the second is the character length of said file.\n\n");
    printf("This program will compile a .bf file into C code in a file called BF.c as well as\n");
    printf("create an executable named BF.exe. Running this without any parameters allows you to input\n");
    printf("the code in the terminal if you so wish to. Personally I just borrowed examples from\n");
    printf("Wikipedia to test this program, but if you wanna write your own, I'm impressed.\n\n");
    printf("Recieve input from (c)onsole or (e)xit? ");

    return getchar();
}

char *readFromFile(char filename[], int length){
    FILE *p_inputFile;
    p_inputFile = fopen(filename, "r");
    if (p_inputFile == NULL) exit(1);

    char *bfcode = malloc(length * sizeof(char));
    if (!bfcode) exit(1);

    for (int i = 0; i < length; i++)
        bfcode[i] = fgetc(p_inputFile); 
    
    fclose(p_inputFile);
    return bfcode;
}

char *readFromConsole(int *length){
    int i;
    system("cls");
    printf("All characters other than <>+-.,[] will be ignored, but an \"x\"\n");
    printf("will quit the input.\n\n");
    printf("How long do you think this will be? ");
    getchar();
    *length = getchar();
    printf("\nType here your BF code.\n");

    char *bfcode = malloc(*length * sizeof(char));
    getchar();
    for (i = 0; i < *length; i++){
        if ((bfcode[i] = getchar()) == 'x') break;
    }

    return bfcode;
}

void bfTranspiler(char bfcode[], int length){
    FILE *p_outFile;
    p_outFile = fopen("BF.c", "w");
    if (p_outFile == NULL) exit(1);
    
    fprintf(p_outFile, "#include <stdio.h>\n#include <stdlib.h>\n\n");
    fprintf(p_outFile, "int main(){\n");
    fprintf(p_outFile, "\tchar array[30000] = {0};\n");
    fprintf(p_outFile, "\tchar *p_array = array;\n");

    int passedOpeningBrackets = 0, passedClosingBrackets = 0;

    for (int i = 0; i < length; i++){
        switch (bfcode[i]){
        case '<':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\t--p_array;\n");
            break;

        case '>':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\t++p_array;\n");
            break;

        case '+':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\t++*p_array;\n");
            break;

        case '-':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\t--*p_array;\n");
            break;

        case '.':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\tputchar(*p_array);\n");
            break;

        case ',':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\t*p_array = getchar();\n");
            break;

        case '[':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\twhile (*p_array){\n");

            passedOpeningBrackets++;
            break;

        case ']':
            numOfTabs(p_outFile, passedOpeningBrackets, passedClosingBrackets);
            fprintf(p_outFile, "\t}\n");

            passedClosingBrackets++;
            break;

        default:
            break;
        }
    }
    fprintf(p_outFile, "}");
    fclose(p_outFile);
}

void numOfTabs(FILE *p_outFile, int passedOpeningBrackets, int passedClosingBrackets){
    for (int i = 0; i < passedOpeningBrackets - passedClosingBrackets; i++)
        fprintf(p_outFile, "\t");
}