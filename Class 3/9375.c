#include <stdio.h>
#include <string.h>

typedef struct{
    char category[21];
    int count;
}Closet;

int main(void){
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int T;
        scanf("%d", &T);

        Closet closet[30];
        int count_category = 0;

        for(int j = 0; j < T; j++){
            char name[21], category[21];
            scanf("%s %s", name, category);

            int find_index = -1;
            for(int k = 0; k < count_category; k++){
                if(!strcmp(closet[k].category, category)){
                    find_index = k;
                    break;
                }
            }

            if(find_index != -1){
                closet[find_index].count++;
            }
            else{
                closet[count_category].count = 1;
                strcpy(closet[count_category].category, category);
                count_category++;
            }
        }
        long long com = 1;

        for(int i = 0; i < count_category; i++){
            com *= closet[i].count + 1;
        }

        printf("%d\n", com - 1);

    }
    return 0;
}