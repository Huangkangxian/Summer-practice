原理：利用三角形的三条边的边长直接求三角形面积的公式。表达式为：S=√p(p-a)(p-b)(p-c)

#include <stdio.h>
#include <math.h> 
int main() {
	
	double s,area,a,b,c;
	
	printf("请输入三条边长：");
	scanf("%lf%lf%lf",&a,&b,&c);
	
	if(a+b>c&&b+c>a&&a+c>b)
	{
		s=(a+b+c)/2.0;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		printf("三角形的面积是%lf",area);
	}
	else
		printf("不能构成三角形"); 
	
	
	return 0;
}
