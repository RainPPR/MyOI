#import "@preview/touying:0.3.2": *
#import "@preview/m-jaxon:0.1.1" as latex
#import "@preview/mitex:0.2.2": *

#let heiti = ("Noto Sans", "Noto Sans CJK SC");
#let songti = ("New Computer Modern", "Noto Serif CJK SC");

#set text(font: songti, size: 12pt, lang: "zh", region: "CN")

// Themes: default, simple, metropolis, dewdrop, university, aqua
#let s = themes.metropolis.register(aspect-ratio: "16-9")
#let s = (s.methods.info)(
  self: s,
  title: [三角函数],
  subtitle: [Triangle],
  author: [RainPPR],
  date: datetime.today(),
)

#let (init, slides, touying-outline, alert) = utils.methods(s)
#show: init

#show strong: alert

#let (slide, title-slide, focus-slide) = utils.slides(s)
#show: slides

= 任意角和角的计量 <一任意角和角的计量>
== 任意角的定义 <一任意角的定义>
平面内一条射线绕其端点从一个位置旋转到另一个位置形成的图形叫做角。

开始的位置称为始边，结束的位置称为终边。并规定：

- 按逆时针方向旋转形成的角叫做正角，其角度为正；
- 按顺时针方向旋转形成的角叫做负角，其角度为负；
- 终边相对于始边没有做任何旋转的角叫做零角，其角度为 $0$。

为什么逆时针是正角？考虑点 $lr((1 , 0))$ 绕着 $lr((0 , 0))$ 转一个锐角：

得到的点 $A lr((x , y))$ 一定满足 $x , y > 0$，因此定义逆时针为正角。

这样就把角的概念推向了任意角。

== 弧度制的定义 <二弧度制的定义>
弧度用符号 $upright("rad")$ 表示，读作「弧度」。

定义正角的弧度为正、负角的弧度为负，零角的弧度为 $0$；

如果半径为 $r$ 的圆的圆心角 $alpha$ 所对弧长为 $l$ ，则：

$ lr(|alpha|) = l / r $

与角 $alpha$ 终边位置相同的角的集合很容易得出，为：

$ { phi divides phi = alpha + 2 k pi , k in bb(Z) } $

== 弧度与角度的转化 <三弧度与角度的转化>
关键是，$180^circle.stroked.tiny = pi$，具体的：

以度数表示的角，把数字乘以 $pi / 180^circle.stroked.tiny$ 便转换成弧度；

以弧度表示的角，乘以 $180^circle.stroked.tiny / pi$ 便转换成度数。

= 三角函数的定义 <二三角函数的定义>
== 用直角三角形定义 <一用直角三角形定义>
直角三角形只有锐角三角函数的定义。

指定锐角 $theta$，可做出直角三角形，使一个内角为 $theta$：

定义：正弦 $sin alpha$ 表示 $alpha$ 的对边与斜边的比值。

定义：余弦 $cos alpha$ 表示 $alpha$ 的邻边与斜边的比值。

定义：正切 $tan alpha$ 表示 $alpha$ 的对边与邻边的比值。

== 用直角坐标系定义 <二用直角坐标系定义>
设点 $P lr((x , y))$ 是平面直角坐标系 $x O y$ 中的一点。

我们记 $theta$ 是从 $x$ 旋转到 $O P$ 的角度，$r$ 是 $O P$ 长度。

则：

$ r = sqrt(x^2 + y^2)\
sin theta = y / r,space cos theta = x / r,space
tan theta = y / x\ $

这样可以定义任何角度的三角函数（除非当定义式无意义时）。

== 用单位圆定义 <三用单位圆定义>
单位圆指半径为单位长度的圆。

通常是平面直角坐标系中以 $lr((0 , 0))$ 为圆心、半径为 $1$ 的圆。

单位圆上的点满足：$x^2 + y^2 = 1$，即毕达哥拉斯定理。

指定一角 $theta$，点 $lr((1 , 0))$ 旋转 $theta$ 度得到的点 $A lr((x , y))$，那么：

$ x^2 + y^2 = 1\
sin theta = y,space
cos theta = x,space
tan theta = y / x\ $

== 常见的三角函数定义 <四常见的三角函数定义>
$ tan alpha = frac(sin alpha, cos alpha)\
cot alpha = frac(1, tan alpha)\
sec alpha = frac(1, cos alpha)\
csc alpha = frac(1, sin alpha) $

== 常见角度的三角函数 <五常见角度的三角函数>

#figure(
  align(
    center,
  )[#table(
      columns: 5,
      align: (col, row) => (center, center, center, center, center,).at(col),
      inset: 12pt,
      [角度],
      [弧度],
      [正弦（$sin$）],
      [余弦（$cos$）],
      [正切（$tan$）],
      [$0^circle.stroked.tiny$],
      [$0$],
      [$0$],
      [$1$],
      [$0$],
      [$30^circle.stroked.tiny$],
      [$pi \/ 6$],
      [$1 \/ 2$],
      [$sqrt(3) \/ 2$],
      [$sqrt(3) \/ 3$],
      [$45^circle.stroked.tiny$],
      [$pi \/ 4$],
      [$sqrt(2) \/ 2$],
      [$sqrt(2) \/ 2$],
      [$1$],
      [$60^circle.stroked.tiny$],
      [$pi \/ 3$],
      [$sqrt(3) \/ 2$],
      [$1 \/ 2$],
      [$sqrt(3)$],
      [$90^circle.stroked.tiny$],
      [$pi \/ 2$],
      [$1$],
      [$0$],
      [无意义],
      [$120^circle.stroked.tiny$],
      [$2 pi \/ 3$],
      [$sqrt(3) \/ 2$],
      [$- 1 \/ 2$],
      [$- sqrt(3)$],
      [$135^circle.stroked.tiny$],
      [$3 pi \/ 4$],
      [$sqrt(2) \/ 2$],
      [$- sqrt(2) \/ 2$],
      [$- 1$],
      [$150^circle.stroked.tiny$],
      [$5 pi \/ 6$],
      [$1 \/ 2$],
      [$- sqrt(3) \/ 2$],
      [$- sqrt(3) \/ 3$],
    )],
)


#figure(
  align(
    center,
  )[#table(
      columns: 5,
      align: (col, row) => (center, center, center, center, center,).at(col),
      inset: 12pt,
      [角度],
      [弧度],
      [正弦（$sin$）],
      [余弦（$cos$）],
      [正切（$tan$）],
      [$180^circle.stroked.tiny$],
      [$pi$],
      [$0$],
      [$- 1$],
      [$0$],
      [$210^circle.stroked.tiny$],
      [$7 pi \/ 6$],
      [$- 1 \/ 2$],
      [$- sqrt(3) \/ 2$],
      [$sqrt(3) \/ 3$],
      [$225^circle.stroked.tiny$],
      [$5 pi \/ 4$],
      [$- sqrt(2) \/ 2$],
      [$- sqrt(2) \/ 2$],
      [$1$],
      [$240^circle.stroked.tiny$],
      [$4 pi \/ 3$],
      [$- sqrt(3) \/ 2$],
      [$- 1 \/ 2$],
      [$sqrt(3)$],
      [$270^circle.stroked.tiny$],
      [$3 pi \/ 2$],
      [$- 1$],
      [$0$],
      [无意义],
      [$300^circle.stroked.tiny$],
      [$5 pi \/ 3$],
      [$- sqrt(3) \/ 2$],
      [$1 \/ 2$],
      [$- sqrt(3)$​],
      [$315^circle.stroked.tiny$],
      [$7 \/ 4$],
      [$- sqrt(2) \/ 2$],
      [$sqrt(2) \/ 2$],
      [$- 1$],
      [$330^circle.stroked.tiny$],
      [$11 pi \/ 6$],
      [$- 1 \/ 2$],
      [$sqrt(3) \/ 2$],
      [$- sqrt(3) \/ 3$],
    )],
)


= 正切函数及其性质 <三正切函数及其性质>

#image("7dd98d1001e9390162eda5112a369fee37d19611.png")

定义域：${ x divides x eq.not k pi + pi \/ 2 , k in bb(Z) }$；

值域：$lr((- oo , + oo))$

周期性：$T = pi$；

单调性：在 $lr((k pi - pi \/ 2 , k pi + pi \/ 2))$ 单调递增。

对称性：奇函数，关于 $lr((k pi , 0)) , k in bb(Z)$ 对称。

= 正弦、余弦函数及其性质
分析函数的套路：定义域、值域、周期性、单调性、就像、对称轴、对称中心、最大值、最小值、零点。

定义：正弦曲线，形如 $y = A sin lr((omega x + phi))$。

注意到 $sin$、$cos$ 其实都属于正弦曲线。

== 图像 <图像>

#figure(
  image("bbb.jpg", width: 50%),
  caption: [
    $y = sin lr((x))$ 函数图像
  ],
)

#figure(
  image("aaa.jpg", width: 50%),
  caption: [
    $y = cos lr((x))$ 函数图像
  ],
)

== 基本性质

=== 周期性 <周期性>
$ sin alpha = sin lr((alpha + 2 pi))\
cos alpha = cos lr((alpha + 2 pi)) $

可知 $sin$、$cos$ 是最小正周期为 $2 pi$ 的周期函数。

=== 奇偶性 <奇偶性>
正弦函数是奇函数，余弦函数是偶函数。

== 基本性质

=== 对称性 <对称性>
+ 正弦函数：
  - 中心对称：$lr((k pi , 0)) , k in bb(Z)$；
  - 轴对称：$x = k pi - pi \/ 2 , k in bb(Z)$；
+ 余弦函数：
  - 中心对称：$lr((k pi - pi \/ 2)) , k in bb(Z)$；
  - 轴对称：$x = k pi , k in bb(Z)$。

- 对称中心：零点；对称轴：极值点。

== 基本性质

=== 单调性 <单调性>
+ 正弦函数：
  - 单调递增：$lr([2 k pi - pi \/ 2 , 2 k pi + pi \/ 2]) , k in bb(Z)$；
  - 单调递减：$lr([2 k pi + pi \/ 2 , 2 k pi + 3 pi \/ 2]) , k in bb(Z)$；
+ 余弦函数：
  - 单调递增：$lr([2 k pi - pi , 2 k pi]) , k in bb(Z)$；
  - 单调递减：$lr([2 k pi , 2 k pi + pi]) , k in bb(Z)$；

= 正弦曲线及其性质

== 函数 $y = A sin x$ 的性质 <二函数-yasin-x-的性质>
我们发现这个操作其实就是对 $y$ 轴的伸缩：

若 $A > 1$，图像伸长；若 $A < 1$，图像压缩；伸缩倍率为 $A$。

也就是图像上任何一个点的纵坐标变成了原来的 $A$ 倍。

其中 $A$ 决定了函数上的点的纵坐标的变化幅度，我们称为振幅。

== 函数 $y = sin lr((x + phi))$ 的性质 <三函数-ysinxvarphi-的性质>
我们发现这个操作其实就是对 $y = sin x$ 图像的平移：

若 $phi > 0$，图像向左平移；若 $phi < 0$ 图像向右平移；平移单位为 $lr(|phi|)$。

也就是点 $P lr((x , sin x))$ 平移到了 $P prime lr((x - phi , sin x))$。

其中 $phi$ 决定了初始时刻的位置，我们称为初相。

== 函数 $y = sin lr((omega x))$ 的性质 <四函数-ysinomega-x-的性质>
我们发现这个操作其实就是对 $x$ 轴的伸缩：

若 $omega > 1$，图像压缩；若 $omega < 1$，图像伸长；伸缩倍率为 $1 \/ omega$。

也就是点 $P lr((x , sin x))$ 平移到了 $P prime lr((x / omega , sin x))$。

其中 $omega$ 决定了函数值的变化快慢，我们称为角速度。

由于 $sin x$ 的最小正周期为 $2 pi$，因此 $sin lr((omega x))$ 的最小正周期为：

$ T = frac(2 pi, omega) $

== 函数 $y = sin lr((omega x + phi))$ 的性质 <五函数-ysinomega-xvarphi-的性质>
我们把上面两个操作合在一起，但是，顺序？我们来分析一下。

考虑 $y = sin x$ 平移 $phi$ 和 $x$ 轴伸缩 $omega$ 这两个操作以不同的顺序会得到什么：

- 先平移 $phi$，后 $x$ 轴伸缩 $omega$：
  + $y = sin x$
  + $y = sin lr((x + phi))$
  + $y = sin lr((omega x + phi))$
- 先 $x$ 轴伸缩 $omega$，后平移 $phi$：
  + $y = sin x$
  + $y = sin lr((omega x))$
  + $y = sin lr((omega lr((x + phi))))$
  + $y = sin lr((omega x + omega phi))$


== 函数 $y = sin lr((omega x + phi))$ 的性质 <五函数-ysinomega-xvarphi-的性质>

易错点：

  - 平移是对于 $x$ 的，而伸缩（在 $x$ 轴上）是对应整个函数的。
  - 把函数 $y = sin lr((omega x + phi))$（可以看为 $f lr((x)) = sin lr((omega x + phi))$）：
  - 平移 $phi prime$ 是 $y = sin lr((omega lr((x + phi prime)) + phi))$，而不是 $y = sin lr((omega x + phi prime + phi))$
  - 伸缩 $omega prime$ 是 $y = sin lr((omega prime omega x + phi))$，而不是 $y = sin lr((omega prime lr((omega x + phi))))$
  - 即，平移是对于 $x$ 的操作，伸缩是对于传入函数的值的操作。

== 函数 $y = sin lr((omega x + phi))$ 的性质 <五函数-ysinomega-xvarphi-的性质>

注意到 $y = sin lr((omega x + phi))$ 相当于 $y = sin lr((omega x))$ 平移 $phi / omega$ 得到的，

这个函数过点 $P lr((- phi / omega , 0))$，而不是 $y = sin lr((omega x + omega phi))$ 过 $P prime lr((- phi , 0))$。

据此，我们得出，从 $y = sin x$ 变换到 $y = sin lr((omega x + phi))$，需要：

- 先平移 $phi$，再对 $x$ 轴伸缩 $omega$。

因此可以得出，$P lr((x , sin x))$ 平移到了 $P prime lr((frac(x - phi, omega) , sin x))$。

== 正弦函数到 $y = A sin lr((omega x + phi))$ 的变换 <六正弦函数到-yasinomega-xvarphi-的变换>
其实就相当于对函数 $y = sin lr((omega x + phi))$ 的 $y$ 轴伸缩 $A$ 倍。

注意到 $A$ 只是对 $y$ 轴的伸缩，因此可以在任意时间变换。

注意到 $omega$ 是对 $x$ 轴的伸缩，因此需要在 $phi$ 的变换之后（前文已述）。

当然上面说的是分别进行三个变换各一次的顺序，据此我们进行组合：

+ 平移 $phi$；
+ $x$ 轴伸缩 $omega$；
+ $y$ 轴伸缩 $A$。

可以从 $y = sin x$ 得到 $y = A sin lr((omega x + phi))$ 的组合有：

$ lr((1 , 2 , 3)) , lr((1 , 3 , 2)) , lr((3 , 1 , 2)) $

三种方式。

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 图像 <图像-1>

#image("5882b2b7d0a20cf49cf473387a094b36adaf99f5.png")


== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

上文写的很详细了，再梳理一遍：

我们知道，正弦函数和余弦函数只差了一个平移，

因此下文只讨论了正弦函数对应的正弦曲线，余弦函数的自己脑补。

PS：（其实也包括上文）

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

首先我们整理一下各个字母的含义：

- $A$ 表示振幅：
  - 若 $A > 1$，图像在 $y$ 轴上伸长；
  - 若 $A < 1$，图像在 $y$ 轴上压缩；
  - 伸缩倍率为 $A$。
- $omega$ 表示角速度：
  - 若 $omega > 1$，图像在 $x$ 轴上压缩；
  - 若 $omega < 1$，图像在 $x$ 轴上伸长；
  - 伸缩倍率为 $1 \/ omega$。
- $phi$ 表示初相，但是并不单独决定函数的位置。

这个函数相当于函数 $y = sin x$ 进行一定的操作（下面再说）。

其中，点 $P lr((x , sin x))$ 平移到了 $P lr((frac(x - phi, omega) , A sin x))$。

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 定义域和值域 <定义域和值域>
我们在这里统一说明正弦曲线的定义域和值域：

定义域，$bb(R)$；值域，$lr([- A , A])$。

因此，$sin$、$cos$ 函数的值域就是 $lr([- 1 , 1])$。

=== 最小正周期 <最小正周期>
由于其进行的变换对最小正周期没有影响，因此：

$ T = frac(2 pi, omega) $

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 绘制简图 <绘制简图>
五点作图法：正弦曲线在一个周期内，一定是上去下来上去（或是歪了的）。

因此我们可以对于周期内的五个点（分为四个区间）画图：

比如，最小正周期为 $pi$ 的，我们可以做出 $lr([0 , pi \/ 4 , pi \/ 2 , 3 pi \/ 4 , pi])$ 五个点的图像。

然后用光滑的曲线连接，再根据周期性画出其他部位的图像即可。

也可以先看出来在所求范围内，函数的极大、极小点在哪里。

也就是正弦函数的最值点，求出传入函数的值中 $x$ 对应多少。

然后先把这些点画出来，再找三个或更多上述性质的点求解、画图。

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 单调区间 <单调区间>
可以用下面的方式：

我们知道正弦函数的单增区间是 $lr([2 k pi - pi \/ 2 , 2 k pi + pi \/ 2])$。

意思是当传入正弦函数的值在这个区间内，函数值单增。

因此可以把传入函数的值当做一个整体，对于 $y = A sin lr((omega x + phi))$：

$ 2 k pi - pi \/ 2 lt.eq omega x + phi lt.eq 2 k pi + pi \/ 2 $

就是单调区间，化简即可。

单减区间是 $lr([2 k pi + pi \/ 2 , 2 k pi + pi])$，计算同理。

不过单减区间还有一个求法，就是单增区间的两个端点都加上 $T \/ 2$。

原理就是单增区间往右到下一个单增区间是单减的且长度是半周期。

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 极大、极小值 <极大极小值>
对于整个图像的最值，就是函数的值域 $lr([- A , A])$。

对于一个区间的最值，可以有两个方法：

+ 画出函数简图，找到区间在图像上的位置，找到极大极小点求解。
+ 画出单位圆的示意图，在单位圆上找到函数的极大极小点，求解。

=== 对称轴、对称中心 <对称轴对称中心>
对称轴：最值点。

正弦函数的最值点都可以表示为 $k pi + pi \/ 2 , k in bb(Z)$，余弦函数不加 $pi \/ 2$。

对称中心：零点。

余弦函数的零点都可以表示为 $k pi + pi \/ 2 , k in bb(Z)$，正弦函数不加 $pi \/ 2$。

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 求正弦曲线解析式 <求正弦曲线解析式>
也就是求三个值：$A$、$omega$、$phi$。

其中 $A$ 只与函数的最值有关，因此我们可以求出来它，则 $A$ 就是函数的最值。

其次 $omega$ 表示的是角速度，根据公式 $T = 2 pi \/ omega$ 可以写出 $omega = 2 pi \/ T$。

而 $T$ 就是两个相邻极值点的距离的两倍、极值和零点的距离的四倍。

考虑 $phi$，易发现最好求的方法就是函数与 $y$ 轴的交点 $y \|_(x = 0)$，那么就有

$ A sin phi = y \|_(x = 0) $

求解即可。其次我们可以用函数的最值点、零点等，列：

$ A sin lr((omega x_0 + phi)) = y \|_(x = x_0) $

解方程时要注意 $phi$ 的取值一般是 $0 lt.eq phi < T$，$A$、$omega$ 的取值一般是正数。

== 函数 $y = A sin lr((omega x + phi))$ 的性质 <七函数-yasinomega-xvarphi-的性质>

=== 求 $omega$ 的范围问题 <求-omega-的范围问题>
一、把所有确定性的条件转化为式子

比如，给定零点横坐标、对称轴，转化为：

$ omega x_0 + phi = lambda k pi lr((+ pi \/ 2)) $

然后如果可以求出 $omega$ 的一些条件（比如奇数偶数），直接求出来。

二、给定单调区间

首先可以写出，单调区间长度小于等于半周期，即

$ r_0 - l_0 lt.eq T / 2 = pi / omega $

三、然后呢？不行就枚举。

= 诱导公式 <五诱导公式>
== 函数关于 2π 的周期性 <一函数关于-2π-的周期性>
是 $sin$、$cos$ 的周期。

$ sin lr((alpha + 2 pi)) & = sin alpha\
cos lr((alpha + 2 pi)) & = cos alpha\
tan lr((alpha + 2 pi)) & = tan alpha $

== 函数关于 π 的周期性 <二函数关于-π-的周期性>
是 $tan$、$cot$ 的周期。

$ sin lr((alpha + pi)) & = - sin alpha\
cos lr((alpha + pi)) & = - cos alpha\
tan lr((alpha + pi)) & = tan alpha $

== 函数的奇偶性 <三函数的奇偶性>
奇函数：$sin$、$tan$、$cot$，偶函数：$cos$。

$ sin lr((- alpha)) & = - sin alpha\
cos lr((- alpha)) & = cos alpha\
tan lr((- alpha)) & = - tan alpha\ $

== 函数关于 y 轴的对称性 <四函数关于-y-轴的对称性>
用单位圆象限角理解。

$ sin lr((pi - alpha)) & = sin alpha\
cos lr((pi - alpha)) & = - cos alpha\
tan lr((pi - alpha)) & = - tan alpha $

== 余函数恒等式 <五余函数恒等式>
用单位圆象限角理解。

$ sin lr((pi \/ 2 - alpha)) & = cos alpha\
cos lr((pi \/ 2 - alpha)) & = sin alpha\
tan lr((pi \/ 2 - alpha)) & = cot alpha $

== 在直角三角形中的转换 <六在直角三角形中的转换>
用单位圆象限角理解。

$ sin lr((pi \/ 2 + alpha)) & = cos alpha\
cos lr((pi \/ 2 + alpha)) & = - sin alpha\
tan lr((pi \/ 2 + alpha)) & = - cot alpha\ $

== 综合：单位圆象限角 <七综合单位圆象限角>
上述所有式子有一个联系：

$ sin lr((k pi \/ 2 plus.minus alpha)) & , k in bb(Z)\
cos lr((k pi \/ 2 plus.minus alpha)) & , k in bb(Z)\
tan lr((k pi \/ 2 plus.minus alpha)) & , k in bb(Z) $

== 综合：单位圆象限角 <七综合单位圆象限角>
转换法则：

- 当 $k$ 为偶数时，三角函数则不变换。
- 当 $k$ 为奇数时，$sin$变为 $cos$，$cos$ 变为 $sin$，$tan$ 变为 $cot$，$cot$ 变为 $tan$。
- 对于正负号，则要看最后角所在的象限进行判断。

可使用口诀：奇变偶不变，符号看象限（ASTC, All Students Take Calculus）记忆。

- 第一象限的 A 即是 All（全部皆正）。
- 第二象限的 S 即是 Sine（正弦以及余割为正）。
- 第三象限的 T 即是 Tangent（正切以及余切为正）。
- 第四象限的 C 即是 Cosine（余弦以及正割为正）。

常见化简方法：周期性（$sin$、$cos$ 是 $2 pi$，$tan$、$cot$ 是 $pi$），奇偶性（$sin$、$tan$、$cot$ 是奇函数，$cos$ 是偶函数），出现 $pi \/ 2$ 系列的要变符号，画出单位圆求解。

= 毕达哥拉斯三角恒等式 <六毕达哥拉斯三角恒等式>
== 基础形式 <一基础形式>
$ sin^2 alpha + cos^2 alpha = 1 $

也称为三角函数的勾股定理。

== 正弦和余弦的转换 <二正弦和余弦的转换>
根据上面的，易得：

$ sin^2 alpha & = 1 - cos^2 alpha\
cos^2 alpha & = 1 - sin^2 alpha $

开方，得：

$ sin alpha & = plus.minus sqrt(1 - cos^2 alpha)\
cos alpha & = plus.minus sqrt(1 - sin^2 alpha) $

一定要注意正负号，正负号由该角所在象限决定。

= 和差恒等式及其推导 <七和差恒等式及其推导>
也称为「和差定理」、「和差公式」或「和角公式」。

== 和差恒等式 <一和差恒等式>
$ sin lr((alpha plus.minus beta)) & = sin alpha cos beta plus.minus cos alpha sin beta\
cos lr((alpha plus.minus beta)) & = cos alpha cos beta minus.plus sin alpha sin beta\
tan lr((alpha plus.minus beta)) & = frac(tan alpha plus.minus tan beta, 1 minus.plus tan alpha tan beta) $

注意正负号的对应。

== 二倍角公式 <二二倍角公式>
$ sin 2 alpha & = 2 sin alpha cos alpha\
cos 2 alpha & = cos^2 alpha - sin^2 alpha\
            & = 1 - 2 sin^2 alpha\
            & = 2 cos^2 alpha - 1\
tan 2 alpha & = frac(2 tan alpha, 1 - tan^2 alpha) $

可以根据里面的结论推出降次公式。

== 正切半角公式 <三正切半角公式>
也称为万能公式。

#mitex("
\begin{aligned}
\sin\alpha&={2\\tan{\alpha\over2}\over1+\\tan^2{\alpha\over2}}\\\\
\cos\alpha&={1-\\tan^2{\alpha\over2}\over1+\\tan^2{\alpha\over2}}\\\\
\\tan\alpha&={2\\tan{\alpha\over2}\over1-\\tan^2{\alpha\over2}}
\end{aligned}
")

其中下面的一个也等价于正切函数的二倍角公式。

== 降次公式 <四降次公式>
$ sin^2 alpha & = frac(1 - cos 2 alpha, 2)\
cos^2 alpha & = frac(1 + cos 2 alpha, 2)\
tan^2 alpha & = frac(1 - cos 2 alpha, 1 + cos 2 alpha) $

补充一个属于幂简约公式的：

#mitex("
\\sin^2\\alpha\\cos^2\\alpha={1-\\cos4\\alpha\\over8}
")

可以根据里面的结论推出半角公式。

== 半角公式 <五半角公式>
#mitex("
\begin{aligned}
\sin\frac{\alpha}{2}&=\pm\sqrt{\frac{1-\cos\alpha}{2}}\\\\
\cos\frac{\alpha}{2}&=\pm\sqrt{\frac{1+\cos\alpha}{2}}\\\\
\\tan{\frac{\alpha}{2}}&=\pm{\sqrt{1-\cos\\theta\over1+\cos\\theta}}\\\\
&=\frac{\sin\alpha}{1+\cos\alpha}=\frac{1-\cos\alpha}{\sin\alpha}
\end{aligned}
")

正负号由半角所在象限决定。

== 三倍角公式 <六三倍角公式>
#mitex("
\begin{aligned}
\sin3\alpha&=3\sin\alpha-4\sin^2\alpha\\\\
\cos3\alpha&=4\cos^2\alpha-3\cos\alpha\\\\
\\tan3\alpha&={3\\tan\alpha-\\tan^3\alpha\over1-3\\tan^2\alpha}\\
\end{aligned}
")

= 「和差化积」和「积化和差」恒等式 <八和差化积和积化和差恒等式>
== 和差化积恒等式 <一和差化积恒等式>
#mitex("
\begin{aligned}
\sin\alpha+\sin\beta&=2\sin{\alpha+\beta\over2}\cos{\alpha-\beta\over2}\\\\
\sin\alpha-\sin\beta&=2\cos{\alpha+\beta\over2}\sin {\alpha-\beta\over2}\\\\
\cos\alpha+\cos\beta&=2\cos{\alpha+\beta\over2}\cos {\alpha-\beta\over2}\\\\
\cos\alpha-\cos\beta&=-2\sin{\alpha+\beta\over2}\sin {\alpha-\beta\over2}
\end{aligned}
")

== 积化和差恒等式 <二积化和差恒等式>
#mitex("
\begin{aligned}
\sin\alpha\cos\beta&={\sin(\alpha+\beta)+\sin(\alpha-\beta)\over2}\\\\
\cos\alpha\sin\beta&={\sin(\alpha+\beta)-\sin(\alpha-\beta)\over2}\\\\
\cos\alpha\cos\beta&={\cos(\alpha+\beta)+\cos(\alpha-\beta)\over2}\\\\
\sin\alpha\sin\beta&=-{\cos(\alpha+\beta)-\cos(\alpha-\beta)\over2}
\end{aligned}
")

= 平方差公式 <九平方差公式>
$ sin lr((x + y)) sin lr((x - y)) & & & = sin^2 x - sin^2 y & & = cos^2 y - cos^2 x\
cos lr((x + y)) cos lr((x - y)) & & & = cos^2 x - sin^2 y & & = cos^2 y - sin^2 x $

注意到右边的式子还可以用平方差公式展开。

= 辅助角公式 <十辅助角公式>
==
对于式子：

$ a sin x + b cos x $

如果 $a = r cos phi$，$b = r sin phi$，

可知

$ a^2 + b^2 = r^2 lr((sin^2 phi + cos^2 phi)) = r^2 $

即 $r = sqrt(a^2 + b^2)$，则有 $cos phi = a \/ r$，$sin phi = b \/ r$。
==
化简式子：

$ a sin x + b cos x & = r cos phi sin x + r sin phi cos x\
                  & = r sin lr((x + phi)) = sqrt(a^2 + b^2) sin lr((x + phi)) $

其中，$phi$ 满足：

$ cases(delim: "{", cos phi & = a \/ r, sin phi & = b \/ r) $

若 $a > 0$，可以写成 $phi = arctan b \/ a$ 的形式。

也就是 $a sin x + b cos x = sqrt(a^2 + b^2) sin lr((x + arctan b \/ a))$。

= 三角形中的三角函数 <十一三角形中的三角函数>
条件，在三角形中，有 $x + y + z = pi$（三角形内角和），那么：

== 正切恒等式：形式一 <形式一>
$ tan x + tan y + tan z = tan x tan y tan z $

证明：

#mitex("
\begin{aligned}
\\tan z&=\\tan(\pi-x-y)=-\\tan(x+y)\\\\
\\tan z&=-{\\tan x+\\tan y\over1-\\tan x\\tan y}
\end{aligned}")

下面的式子整理即可。

== 正切恒等式：形式二
#mitex("
\\tan{x\over2}\\tan{y\over2}+\\tan{y\over2}\\tan{z\over2}+\\tan{z\over2}\\tan{x\over2}=1
")

证明：

#mitex("
\begin{aligned}
\\tan{z\\over2}&=\\tan\\left({\\pi\over2}-{x\over2}-{y\over2}\\right)={1\\over\\tan({x\over2}+{y\over2})}\\\\
\\tan{z\\over2}&={1-\\tan{x\over2}\\tan{y\over2}\over\\tan{x\over2}+\\tan{y\over2}}
\end{aligned}
")

下面的式子整理即可。

== 余切恒等式 <二余切恒等式>
=== 形式一 <形式一-1>
$ cot x cot y + cot y cot z + cot z cot x = 1 $

证明：

根据 #mi("\displaystyle\\tan\alpha={1\over\cot\alpha}") 展开正切的形式一即可。

=== 形式二 <形式二-1>
#mitex("
\cot{x\over2}+\cot{y\over2}+\cot{y\over2}=\cot{x\over2}\cot{y\over2}\cot{y\over2}
")

证明：

根据 #mi("\displaystyle\\tan\alpha={1\over\cot\alpha}") 展开正切的形式二即可。

== 一倍角弦：形式一 <形式一-2>
#mitex("
\sin x+\sin y+\sin z=4\cos{x\over2}\cos{y\over2}\cos{z\over2}")

证明：

#mitex("
\begin{aligned}
\sin x+\sin y&=2\sin{x+y\over2}\cos{x-y\over2}\\\\
&=2\cos{z\over2}\cos{x-y\over2}\\\\
\sin z&=2\sin{z\over2}\cos{z\over2}\\\\
&=2\cos{z\over2}\cos{x+y\over2}
\end{aligned}
")
然后加起来用和差化积公式即可。

== 一倍角弦：形式二 <形式一-2>
#mitex("
\cos x+\cos y+\cos z=1+4\sin{x\over2}\sin{y\over2}\sin{z\over2}")

证明：

#mitex("
\begin{aligned}
\cos z&=1-\sin^2{z\over2}\\\\
&=1-\sin{z\over2}\cos{x+y\over2}\\\\
\cos x+\cos y&=2\cos{x+y\over2}\cos{x-y\over2}\\\\
&=2\sin{z\over2}\cos{x-y\over2}
\end{aligned}
")

然后加起来用和差化积公式即可。

== 二倍角弦：形式一 <形式一-3>
$ sin 2 x + sin 2 y + sin 2 z = 4 sin x sin y sin z $

证明：

$ sin 2 z           & = 2 sin z cos z\
                  & = - 2 sin z cos lr((x + y))\
sin 2 x + sin 2 y & = 2 sin lr((x + y)) cos lr((x - y))\
                  & = 2 sin z cos lr((x - y)) $

然后加起来用和差化积公式即可。

== 二倍角弦：形式二 <形式一-3>
$ cos 2 x + cos 2 y + cos 2 z = - 1 - cos x cos y cos z $

证明：

$ cos 2 z           & = 2 cos^2 z - 1\
                  & = - 2 cos z cos lr((x + y)) - 1\
cos 2 x + cos 2 y & = 2 cos lr((x + y)) cos lr((x - y))\
                  & = - 2 cos z cos lr((x - y)) $

然后加起来用和差化积公式即可。

= 例题 <例例题>

== 例题一

已知 $tan beta$ 有意义，且 #mi("\sin(\alpha+\beta)={1\over2}")，#mi("\sin(\alpha-\beta)={1\over3}")，求 $frac(tan alpha, tan beta)$。

== 题解：例题一

=== Solution 1：和差恒等式

易得：

#mitex("\begin{cases}
\sin(\alpha+\beta)=\sin\alpha\cos\beta+\cos\alpha\sin\beta={1\over2}\\\\
\sin(\alpha-\beta)=\sin\alpha\cos\beta-\cos\alpha\sin\beta={1\over3}\\\\
\end{cases}
")

解得：

#mitex("
\begin{cases}
\sin\alpha\cos\beta={5\over12}\\\\
\cos\alpha\sin\beta={1\over12}
\end{cases}")

易知：

#mitex("
{\\tan\alpha\over\\tan\beta}={\sin\alpha\cos\beta\over\cos\alpha\sin\beta}={{5\over12}\over{1\over12}}=5
")

== 题解：例题一

=== Solution 2：和差化积恒等式

易得：

#mitex("
\begin{cases}
\sin(\alpha+\beta)+\sin(\alpha-\beta)=2\sin\alpha\cos\beta={1\over2}+{1\over3}={5\over6}\\\\
\sin(\alpha+\beta)-\sin(\alpha-\beta)=2\cos\alpha\sin\beta={1\over2}-{1\over3}={1\over6}
\end{cases}")

易知：

#mitex("
{\\tan\alpha\over\\tan\beta}={2\sin\alpha\cos\beta\over2\cos\alpha\sin\beta}={{5\over6}\over{1\over6}}=5")

== 例题二
已知 $theta in \[ 0 , 2 pi \)$ 且 $sin lr((x + theta))$ 是偶函数，求 $theta$。
== 题解：例题二
根据偶函数定义：

$ sin lr((x + theta)) = sin lr((- x + theta))\
sin theta cos x + cos theta sin x = sin theta cos x - cos theta sin x\
cos theta sin x = 0 $

因为 $x in bb(R)$，所以 $cos theta = 0$，即：#mi("\displaystyle\\theta={\pi\over2}/{3\pi\over2}")。

知识点：偶函数、和差恒等式。

== 例题三

求函数 #mi("\displaystyle g(x)=\sin^2\\left(x+{\pi\over12}\\right)+\sin^2\\left(x+{\pi\over4}\\right)") 的值域。
== 题解：例题三

化简：

#mitex("
\begin{aligned}
&\sin^2\\left(x+{\pi\over12}\\right)+\sin^2\\left(x+{\pi\over4}\\right)\\\\
=\;&{1\over2}\\left[1-\cos\\left(2x+{\pi\\over6}\\right)+1-\cos\\left(2x+{\pi\over2}\\right)\\right]\\\\
=\;&1-{1\over2}\\left[\cos\\left(2x+{\pi\\over6}\\right)+\cos\\left(2x+{\pi\over2}\\right)\\right]\\\\
=\;&1-{1\over2}\\left({\sqrt3\over2}\cos2x-{1\over2}\sin2x-\sin2x\\right)\\
=\;&1+{1\over4}\\left(3\sin2x-\sqrt3\cos2x\\right)\\\\
=\;&1+{\sqrt3\over2}\sin\\left(2x-{\pi\\over6}\\right)\end{aligned}
")

== 题解：例题三

然后就忒简单了，答案是，

函数 $g$ 的值域为 #mi("\displaystyle\\left[1-{\sqrt3\\over2},1+{\sqrt3\\over2}\\right]")。

知识点：函数、和差恒等式、降次公式、辅助角公式。

PS：最后辅助角公式的应用中，$arctan b \/ a$ 可以不用算出来，因为 $x$ 属于实数域，$sin$ 函数里面一定是任何一个实数都取得到，直接取 $r = sqrt(a^2 + b^2) = 2 sqrt(3)$ 即可得出答案。

= The END.
