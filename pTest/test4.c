int a;
int z(){
    a = a+1;
}

int main(){
    a = 10;
    LOOP:do{
        if (a == 15){
            z();
            goto LOOP;
        }
        a++;
    }while(a < 20);
    return 0;
}
