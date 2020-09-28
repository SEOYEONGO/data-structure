#include <stdio.h>
//두번째 방법으로 특정 다항식 표현하기 (계수, 차수 형식 )
//하나의 배열에 모두다 저장하는 것.
#define MAX 101 

typedef struct {
	float coef;
	int expon;
} polynomial;

polynomial fam[MAX]={{1,3}, {-1, 0},  {5,3},{8,2},{10,0}};
int avail=5;			//전역변수 

char compare (int a, int b){
	if (a>b) return '>';
	else if (a==b) return '=';
	else return '<';
}
void attach(float coef, int expon){
	fam[avail].coef=coef;
	fam[avail].expon=expon;
	avail++;
}
void  poly_add2 (int As, int Ae, int Bs, int Be, int *Cs, int * Ce){
	float tempcoef;
	*Cs=avail;
	
	while (As <= Ae && Bs<= Be){
		switch (compare (fam[As].expon, fam[Bs].expon)){
		case '>':
			attach (fam[As].coef, fam[As].expon);
			As++; break;
			
		case '=':
			tempcoef= fam[As].coef + fam[Bs].coef;
			if (tempcoef)
				attach (tempcoef, fam[As].expon);
			As++; Bs++; break;
			
		case '<':
			attach (fam[Bs].coef, fam[Bs].expon);
			Bs++; break;
		}
	}
	for (; As <=Ae ; As++)
		attach (fam[As].coef, fam[As].expon);
	for (; Bs <=Be ; Bs++)
		attach (fam[Bs].coef, fam[Bs].expon);
	*Ce=avail-1;
}

void print_poly (int s, int e){
	int i;
	for (i=s;i<e;i++)
		printf("%3.1fx^%d + ", fam[i].coef, fam[i].expon);
	printf("%3.1fx^%d\n", fam[e].coef, fam[i].expon);
}
//{{1,3}, {-1, 0},  {5,3},{8,2},{10,0}}
int main (){
	int As=0, Ae=1, Bs=2, Be=4, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	
	print_poly(As,Ae);
	print_poly(Bs,Be);
	printf("------------------------------------------\n");
	print_poly(Cs,Ce);
	return 0;
}
