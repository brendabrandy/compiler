int f(){
    int a;
    int remainder;
    int rem0, rem1, rem2;
    rem0 = 0;
    rem1 = 0;
    rem2 = 0;
    for (a = 0; a < 100; a++){
        remainder = a % 2;
        switch(remainder){
            case 0:
                rem0 += 1;
                break;
            case 1:
                rem1 += 1;
            default:
                rem2 += 1;
                break;
        }
    }
}
