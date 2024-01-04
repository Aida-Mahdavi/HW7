/*specifiedhw 1.7- Basic Programming Fall 2023- Group 6- Aida Mahdavi:40223078
Task-> Write a program which takes a letter n, followed by n words depicted to languages 1&2;
|_Then reads a phrase containing only letters from language 1 and converts in to language 2;
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int n, space_c=0, word_c=0, match_c=0, flag_end=1; 
    printf("Enter a number: ");
    scanf("%d", &n);
    char lang_1[n][21], lang_2[n][21], phrase[20*n+1], phrase_w[100][21];
    printf("\n");
    for (int i=0; i<n; i++){
        printf("Enter the %dth word for laguuages 1&2 in order: ", i+1);
        scanf("%s %s",lang_1[i], lang_2[i]);
    }

    getchar();
    printf("\nEnter a sentence containg only the words from language 1 in any order: ");
    gets(phrase);
    if(tolower(lang_1[0][0])==lang_1[0][0]){
        for(int i=0; i<20*n; i++){
            phrase[i]=tolower(phrase[i]);
        }
    }
    else{
        for(int i=0; i<20*n; i++){
            phrase[i]=toupper(phrase[i]);
        }
    }

    for(int i=0; i<100; i++){
        if(flag_end){
            for (int j=0; j<20; j++){
                if(phrase[j+space_c]!=' '&& phrase[j+space_c]!='\0'){
                    phrase_w[i][j]=phrase[space_c+j];
                }
                else if(phrase[j+space_c]=='\0'){
                    phrase_w[i][j]='\0';
                    word_c++;
                    flag_end=0;
                    break;
            }
                else{
                    space_c+=j+1;
                    phrase_w[i][j]='\0';
                    word_c++;
                    break;
                }
            }
        }
    }

    for(int i=0; i<word_c; i++){
        for (int j=0; j<n; j++){
            if(strlen(phrase_w[i])==strlen(lang_1[j])){
                int flag=1;
                for(int z=0; z<strlen(lang_1[j]); z++){
                    if(phrase_w[i][z]==lang_1[j][z]){
                        continue;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
                if (flag){
                    if(strlen(lang_1[j])>strlen(lang_2[j])){
                        for(int z=0; z<strlen(lang_2[j])+1; z++)
                            phrase_w[i][z]=lang_2[j][z];
                    }
                }
            }
        }
    }
    printf("------------------------------------------------------------\n");
    printf("\nYour converted sentence shall be: ");
    for(int i=0; i<word_c; i++){
        printf("%s ", phrase_w[i]);
    }
}
