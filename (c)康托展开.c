举个例子说明：
在5个数的排列组合中，计算 34152的康托展开值。
首位是3，则小于3的数有两个，为1和2，a[5]=2,则首位小于3的所有排列组合为 a[5]×(5-1)!
第二位是4，由于第一位小于4，1、2、3中一定会有1个充当第一位，所以排在4之下的只剩2个，所以其实计算的是在第二位之后小于4的个数。因此 a[4]=2 。
第三位是1，则在其之后小于1的数有0个，所以 a[3]=0。
第四位是5，则在其之后小于5的数有1个，为2，所以a[2]=1  。
最后一位就不用计算啦，因为在它之后已经没有数了，所以a[1]  固定为0
根据公式：X=2×4!+2×3!+0×2！+1×1！+0×0！=61
所以比34152小的组合有61个，即34152是排第62。

#include <stdio.h>
int fact(int num)
{
	if(num <= 1)
		return 1;
	else
		return (fact(num-1)*num);
}

int main() {
	
	int i=0,j=0,k=0,count=0,sum=0;
	int num[10];
	char s[10];
	char val;
	
	while(scanf("%c",&val))
	{
		if(val == '\n')
			break;
		else
		{
			s[count] = val;
			count ++;
		}
	}
	printf("count = %d\n",count);
	
	for(i=0;i<count;i++)
	{
		printf("*************************%c************************\n",s[i]);

		for(j=i+1;j<count;j++)
		{
			if(s[i]>s[j])
			{
				printf("%d: %c\t%c\n",j,s[i],s[j]);
				k ++;
			}
		}

		printf("%d\n",k);
		num[i] = k;
		k = 0;
	}
	
	for(j=count-1;j>=0;j--)
	{
		sum += fact(j) * num[k];
		printf("%d:%d = %d*%d\n",k,sum,fact(j),num[k]);
		k++;
	}
	
	printf("是第%d大数\n",sum+1);
	
		return 0;
}
