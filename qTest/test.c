int c(){
	int a, *b;
	int arr[10][20];
	b = &(*arr);
    // b = &a + 4;
    *b = a + 4;
}

int h(){
    int d[10][20][30], i, j, k, v;
    v = d[i][j][k];
}
