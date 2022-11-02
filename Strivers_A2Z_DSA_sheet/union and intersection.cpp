#include<bits/stdc++.h>

using namespace std;

int check_presence(int element, int set[], int length_of_set){
    int i;
    for(i=0; i<length_of_set; i++){
        if (element==set[i]){
            return 1;
        }
    }
    return 0;
}


void union_print(int length_of_set_1, int set_1[], int length_of_set_2, int set_2[]){
    int i;
    int last_index=0;
    int set_3[200];

    // For set1
    for(i=0; i<length_of_set_1; i++){
        if (!check_presence(set_1[i], set_3, last_index)){
            set_3[last_index] = set_1[i];
            last_index++;
        }
    }

    //For set2
    for(i=0; i<length_of_set_2; i++){
        if (!check_presence(set_2[i], set_3, last_index)){
            set_3[last_index] = set_2[i];
            last_index++;
        }
    }
    
    printf("\nUnion of entered sets : ");
    for(i=0; i<last_index; i++){
        printf("%d ",set_3[i]);
    }

}


void intersection_print(int length_of_set_1, int set_1[], int length_of_set_2, int set_2[]){
    int i;
    int last_index=0;
    int set_3[200];

    // For set1
    for(i=0; i<length_of_set_1; i++){
        if (!check_presence(set_1[i], set_3, last_index) && check_presence(set_1[i],set_2, length_of_set_2)){
            set_3[last_index] = set_1[i];
            last_index++;
        }
    }
    
    // Another loop for set2 is not needed.

    printf("\nIntersection of entered sets : ");
    for(i=0; i<last_index; i++){
        printf("%d ",set_3[i]);
    }

}


int main(){
    int length_of_set_1, length_of_set_2, i;
    int set_1[100], set_2[100];

    // Input set_1.
    printf("\nInput length of first set : ");
    scanf("%d",&length_of_set_1);
    printf("Input elements of first set : ");
    for(i=0; i<length_of_set_1; i++){
        scanf("%d",&set_1[i]);
    }

    // Input set_2.
    printf("\nInput length of second set : ");
    scanf("%d",&length_of_set_2);
    printf("Input elements of second set : ");
    for(i=0; i<length_of_set_2; i++){
        scanf("%d",&set_2[i]);
    }

    union_print(length_of_set_1, set_1, length_of_set_2, set_2);
    intersection_print(length_of_set_1, set_1, length_of_set_2, set_2);
    
    // Printing a new line just for the purpose of a good looking console.
    printf("\n");

    return 0;
}