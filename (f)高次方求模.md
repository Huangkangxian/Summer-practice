# 高次方求模
## 当N可以拆分成n个数相乘时，即N=N1×N2×N3×…×Nn,有如下公式成立：
## N mod m = [N1 mod m×N2mod m×N3 mod m×…×Nn mod m] mod m
## n的p次方很容易拆成几个数相乘的形式。其中采用二分法拆分较为简单高效。


#### 比如: 7^100我们可以写成
#### (7^50)^2 = ((7^25)^2)^2 = .....=(((7^1)^2)....)^2
#### 还要知道一个模运算:(a * a) % b = (a%b * a%b)%b;
#### 所以知道了 ans = (7^1) % 3;
#### 我们就可以算出来 ((7^1)^2) % 3 = (7^1 * 7^1) % 3
#### 就是 (ans * ans ) % 3
#### 依次类推
#### 最终有 ans = (7^50) % 3;
#### 所以 7^100 = (7^50 * 7^50) % 3 = ans * ans % 3
#### 还有一种特殊情况
#### 比如 7^13 = (7^6)^2*7; ->多乘一个7

```c
#include <stdio.h>
int fact(int n,int p,int mod){
	int result;
	
	if(p=0)
		return 1;
	if(p=1)
		return n%mod;
	result=fact(n,p/2,mod);
	if(p%2==1)
		result=(result*result)%mod*(n%mod);
	else
		result=(result*result)%mod;
		
	return result;	
}
int main() {
	
	int n,p,mod,result;
	
	printf("请输入n,p,mod:");
	scanf("%d%d%d",&n,&p,&mod);
	
	result=fact(n,p,mod);
	printf("模是%d",result);
	
	return 0;
}
```
