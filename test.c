int a;
int b;
extern int i;
int main(){
	static int j;
    int k;
	a = a+b;
    k = a+j;
}

int g(){
    static int j;
    j = 2;
}
