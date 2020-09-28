#include <stdio.h>
#define MAX 101

typedef struct {
	int degree;
	float coef [MAX];
} polynomial;

int maxof(polynomial A, polynomial B){
	if (A.degree > B.degree) return A.degree;
	else B.degree;
}

polynomial add1 (polynomial A, polynomial B){
	polynomial C;
	int Apos=0,Bpos=0, Cpos=0;		//�迭�� �ε����� ���ϴ� ���� 
	int degree_a= A.degree;		//_������ ��������  (�����ϸ鼭 ������ ����ٴ� ��) 
	int degree_b= B.degree;		//_���� degree�� ���������� �����ðž� 
	C.degree=maxof(A,B);
	
	while (Apos <= A.degree && Bpos <= B.degree){	
		if (degree_a > degree_b){
			C.coef[Cpos++]=A.coef[Apos++];
			degree_a--; 
		} 
		else if (degree_a == degree_b){
			C.coef[Cpos++]= A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++]=B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
	
} 

void print_polynomial(polynomial p){
	int i;
	for (i=p.degree; i>0; i--){
		if (p.coef[p.degree-i]==0) continue;
		printf("%3.1fx^%d + ", p.coef[p.degree-i],i);
	}
		
	printf("%3.1f\n", p.coef[p.degree]);
}

int main (){
	polynomial a= {3,{4,2,0,5}};
	polynomial b= {3,{2,6,0,4}};
	polynomial c;
	
	c=add1(a,b);
	print_polynomial(a);
	print_polynomial(b);
	printf("--------------------------------------------\n");
	print_polynomial(c);
	return 0;
}
