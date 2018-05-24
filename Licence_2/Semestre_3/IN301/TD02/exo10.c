#include <stdio.h>
#include <stdlib.h>

int valAbs(int i){
	if (i<0){
		return -i;
	}
	return i;
}

int main(){
	float entier;
	float test;
	float i=2.0;
	float epsilon=0.01;
	float racineCarre=0;
	printf("Donne un nombre : ");
	scanf("%f",&entier);
	/*for(i=0;i<entier;i=i+epsilon){
		if((i*i==(entier+epsilon))||(i*i==(entier-epsilon))){
			printf("%f",i);
		}
	}*/
	printf("%f",entier/i);
	while(valAbs(entier-racineCarre*racineCarre)>epsilon){
		
		test=entier/i;
		printf("%f",test*test);
		
		if(test*test>entier){
			racineCarre=test/2;
			printf("1\n");
		}
		else if(test*test<=entier){
			racineCarre=(test+entier)/2;
			printf("2\n");
		}
		printf("encore\n");
		
		test = racineCarre;
	}
	printf("%f",i);
	
	return 0;
}
