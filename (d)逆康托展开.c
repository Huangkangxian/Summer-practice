在（1，2，3，4，5）给出61可以算出起排列组合为34152。由上述的计算过程可以容易的逆推回来，具体过程如下：
用 61 / 4! = 2余13，说明a[5]=2,说明比首位小的数有2个，所以首位为3。
用 13 / 3! = 2余1，说明a[4]=2，说明在第二位之后小于第二位的数有2个，所以第二位为4。
用 1 / 2! = 0余1，说明a[3]=0，说明在第三位之后没有小于第三位的数，所以第三位为1。
用 1 / 1! = 1余0，说明a[2]=1，说明在第四位之后小于第四位的数有1个，所以第四位为5。
最后一位自然就是剩下的数2。
通过以上分析，所求排列组合为 34152

#include<stdio.h>
#define Max 4 
const int fact[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };//给出10以内的阶乘 

void revContor(int a[] , int rank) { 	
    int value, i,flag = 0; 
	int b[Max+1]; 
	rank -= 1; 	
	
	for(i = 1; i<Max; i++) 
	{ 
		value = rank / fact[Max - i]; 	
		rank = rank % fact[Max - i]; 
		flag = value + 1; 	
			for (value = 1; value <= Max; value++) 
			{ 	
				if (a[value] != 0) 		
					flag--; 		
				if (flag == 0) 	
					break; 		
			} 
		b[i] = a[value] ; 		
		a[value] = 0; 	
	} 	
	for (value = 1; value <= Max; value++) 
	{
	 	if (a[value] != 0) 
		{	b[i] = a[value]; 		
			for (i = 1; i <= Max; i++)
			{ 	printf("%5d", b[i]); 
			} 			return ; 		
		} 	
	} 
} 
int main(void){ 	int i; 	int arrange[Max + 1]; //先定义一个四以内排列,并且忽略0位 	
		int rank = 0; //排列的序号；
		for (i = 0; i <= Max; i++)
		{ 		
			arrange[i] = i; 	
		}
		scanf("%d", &rank);
		revContor(arrange, rank); 
		
		return 0;
}
