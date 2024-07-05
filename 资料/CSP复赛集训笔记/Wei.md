# Wei
## 审题：
#### 数据范围，开数组按 $100\%^+$ 开
#### 前两题，不用经典算法的：数据范围小，多用模拟；数据范围大，多用数学思路。
#### 数学：
1. 多项式展开
2. 方程分析：$x<y$ 且 $y<z$ 且 $y-x=z-y$：等差序列
#### 四舍五入
```cpp
float num=0;
cin >> num;
num=(int)((num+0.05)*10)/10.0;
printf("%.1f",num);
```
#### 程序模板
```cpp
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
//	freopen("mine.in","r",stdin);
//	freopen("mine.out","w",stdout);

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
```