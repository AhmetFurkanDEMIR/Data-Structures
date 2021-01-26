#include <stdio.h> 
#include <stdlib.h> 

float cal(float money, float faiz, int vade){

	if(vade==0){
		return money;
	}

	money += money*faiz;
	money = cal(money, faiz+=faiz*(1/100), vade-1);

	return money;

}

int main(){ 

	float money = 10;
	float faiz = 1;
	int vade = 5;


	money = cal(money, faiz, vade);

	printf("Money : %f",money);

	return 0; 
} 
