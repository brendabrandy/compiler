int printf();

int main(){
    int i, j, arr[10][10];
    int horiz_sum;
    for (i = 0; i < 10; i++){
        for (j = 0 ; j < 10; j++){
            arr[i][j] = i + j;
        }
    }

    for (i = 0 ; i < 10; i++){
        horiz_sum = 0;
        for (j = 0; j < 10; j++){
            printf("%d\t", arr[i][j]);
            horiz_sum += arr[i][j];
        }
        printf("\thorizontal sum is %d\n", horiz_sum);
    }
    return 0;
}
