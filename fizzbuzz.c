int printf();
int i;
int main(){
	for (i = 0 ; i < 100; i ++){
		if (i % 15 == 0){
			printf("%d is divisble by 15", i);
		}else if (i % 3 == 0){
			printf("%d is divisible by 3\n", i);
		}else if (i % 5 == 0){
			printf("%d is divisible by 5\n", i);
		}
	}
	return 0;
}
