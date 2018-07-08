#include<cstdio>
int main(){
	int num;
	char c[14] = {"0123456789ABC"};
	printf("#");
	for(int i = 0; i < 3; i++){
		scanf("%d" ,&num);
		printf("%c%c", c[num/13],c[num%13]);
	} 
}
