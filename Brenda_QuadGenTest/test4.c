int z(){
	int a, b, *p;
    a = 1;
    while(*p && !p){
        a = a + 1;
    }
    return b;
}

int f(){
    int c,d;
    c = 10;
    d = 20;
    do{
        d += c;
    }while(c < d);  
    return 0;
}

void g(){
    int i, j;
    for (i = 0 ; i < 10; i += 1){
        j += 1;
        if (i == 5){
            j += 2;
			break;
		}
		if (i < 5)
			continue;
		j += 1;
    }
	i += 1;
    return;
}
