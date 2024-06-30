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
  title: [向量],
  subtitle: [Vector],
  author: [RainPPR],
  date: datetime.today(),
)

#let (init, slides, touying-outline, alert) = utils.methods(s)
#show: init

#show strong: alert

#let (slide, title-slide, focus-slide) = utils.slides(s)
#show: slides

= 有向线段

带有方向的线段称为有向线段。有向线段的三要素为：起点、方向、长度。

那么只要知道这三要素，这个有向线段就已经被确定了，也就是终点可知。

从另一个角度思考，也可以认为是知道起点、重点，就可以唯一的确定一个有向线段。

一个有向线段由其两个端点表示，记为 $arrow(A B)$ 或 $bold(a)$，同时我们记其长度，#emph[称为向量的模]。

= 向量

== 向量的定义

向量（vector）又称欧几里得向量（Euclidean vector）。

目前没有准确而统一的中文翻译，在物理、工程中通称矢量。

一般指一个同时具有大小和方向，且满足平行四边形法则的几何对象。

向量是数学、物理学和工程科学等多个自然科学中的基本概念。 

与向量相对的概念称标量、纯量、数量，即：

只有大小、绝大多数情况下没有方向（电流是特例）、不满足平行四边形法则的量。

== 固定向量和自由向量

*固定向量*：尤其在物理学领域，有些向量会与起点有关（力与其的作用点有关，质点运动速度与该质点的位置有关），因而假设向量有确定的起点和终点，当起点和终点改变后，构成的向量就不再是原来的向量。这样的向量也被称为固定向量。

*自由向量*：向量的位置可自由移动。在另一些时候，由于向量的共性都具有大小和方向，会认为向量的起点和终点并不那么重要。两个起点不一样的向量，只要大小相等，方向相同，就可以称为是同一个向量。这样的向量被称为自由向量。在数学中，一般只研究自由向量，并且数学中所指的向量就是指自由向量。也就是只要大小以及方向一样，即可视为同一向量，与向量的起始点并无关系。

== 特殊的向量

遇到某些特殊情况（如表示磁场的磁感应强度）需要表示与记载纸面垂直的向量，则会使用圆圈中打叉或打点的方式来表示（如右图）。圆圈中带点的记号（⊙）表示由纸下方指向纸上方的向量，而圆圈中带叉的记号（⊗）则表示由纸的上方指向纸下方的向量。由于这种记号不表示向量的大小，所以必须时需要在旁边或其它地方另外注明。

==

下文为高中数学中定义的向量。

无特殊说明，下文的向量均指#strong[自由向量]，大部分都是#strong[平面向量]。

既有大小又有方向的量称为向量。这个定义很抽象，我们逐个分解。

我们已经有了有向线段，但是实际应用中，大部分时候，向量的位置并不重要。

于是我们将有向线段的起点不固定，将一个有向线段抽象为一个可以随意移动的量。

==

此时，你也许发现了。有向线段其实可以再次表示为，起点和一个向量。

我们通常把向量表示在平面直角坐标系内，没有说明的话，起点通常标在坐标轴原点。

我们取这个向量在横、纵坐标上延伸的长度作为两个元素，将向量记为 $lr((a , b))$。

那么我们就得出了向量的几何意义，即向量 $lr((a , b))$ 表示向右走 $a$、向上走 $b$ 的位移。

已知两点 $A lr((a , b)) , B lr((c , d))$，易证 $arrow(A B) = lr((c - a , d - b))$。

== 向量的模

对于一个向量 $bold(a)$，有向线段 $bold(a)$ 的长度称为向量的模，即为这个向量的大小。

符号表示为 $lr(|bold(a)|)$ 或 $lr(|arrow(A B)|)$ ，根据勾股定理，我们知道 $lr(|bold(a)|) = lr(|lr((x , y))|) = sqrt(x^2 + y^2)$。

== 特殊的向量

#strong[零向量]：模为 $0$ 的向量，零向量的方向任意（不过其实是无意义）。一般记为：$arrow(0)$。

#strong[单位向量]：模为 $1$ 的向量称为单位向量。一般记为 $bold(e)$，最常见的单位向量就是基向量。

#strong[基向量]：$bold(i) = lr((1 , 0))$ 表示 $x$ 方向的单位向量，$bold(j) = lr((0 , 1))$ 表示 $y$ 方向的单位向量。

#strong[平行向量]：方向相同或相反的两个非零向量，零向量与任何向量平行。记作：$bold(x) parallel bold(y)$。

#strong[共线向量]：任一组平行向量都可以平移到同一直线上，所以平行向量又叫共线向量。

#strong[相等向量]：模相等且方向相同的向量。

#strong[相反向量]：模相等且方向相反的向量。

= 向量数乘

==

我们规定实数 $lambda$ 与向量 $bold(a)$ 的积为一个向量，称为向量的数乘运算，记作 $lambda arrow(a)$。

我们定义 $lambda bold(a) = lambda lr((x , y)) = lr((lambda x , lambda y))$。据此，我们可以得出以下向量数乘常用的结论：

- $lr(|lambda bold(a)|) = lr(|lambda|) lr(|bold(a)|)$；
- 当 $lambda > 0$ 时，$lambda bold(a)$ 与 $bold(a)$ 同向；
- 当 $lambda = 0$ 时，$lambda bold(a) = arrow(0)$；
- 当 $lambda < 0$ 时，$lambda bold(a)$ 与 $bold(a)$ 方向相反。

==

根据数乘的定义，可以得出向量的数乘满足交换律、结合律、分配律等，即，

#mitex("
\lambda(\mu\bm a)=(\lambda\mu)\bm a\\\\
\lambda(\bm a+\bm b)=\lambda\bm a+\lambda\bm b\\\\
(\lambda+\mu)\bm a=\lambda\bm a+\mu\bm a\\\\
(-\lambda)\bm a=-(\lambda\bm a)=\lambda(-\bm a)
")

= 向量加法

==

下面讨论向量的加法，类比的，向量的减法可以从公式入手理解。

类比物理中的位移，从 $A$ 经 $B$ 到 $C$，那么经过的位移等价于直接从 $A$ 到 $C$。

符号表示即：$arrow(A B) + arrow(B C) = arrow(A C)$，其实这个也就是三角形法则所表述的。

向量减法类似：$arrow(O A) - arrow(O B) = arrow(O A) + arrow(B O) = arrow(B A)$，后面用到了交换律。

同时，注意到力的合成法则（平行四边形法则），同样也可以看做向量的相加。

==

因此，我们得出向量相加的两个运算法则，即三角形法则、平行四边形法则：

- 三角形法则：首尾顺次相连，和为从第一个向量的起点指向最后一个向量的终点；
- 平行四边形法则：向量共起点，和为以这两个向量为邻边的平行四边形的对角线，起点为两个向量共有的起点，方向沿平行四边形对角线方向。

这样，向量的加法就具有了几何意义。并且向量的加法满足交换律与结合律。

==

然后从几何的角度可以推出一些公式，其中三角形法则的公式比较简单，如下：

$ lr((x_1 , y_1)) + lr((x_2 , y_2)) = lr((x_1 + x_2 , y_1 + y_2)) $

向量加法满足结合律和交换律，画图理解即可。

向量加法可以导出三角形不等式，

$ lr(||) bold(a) lr(|-|) bold(b) lr(||) lt.eq lr(|bold(a) + bold(b)|) lt.eq lr(|bold(a)|) + lr(|bold(b)|) $

当且仅当两向量方向相同（注意不是平行），取等。

= 向量的点积

== 声明

对于向量的乘法：

#figure(align(center)[#table(
    columns: 4,
    align: (col, row) => (auto, auto, auto, auto,).at(col),
    inset: 12pt,
    [*物理*],
    [*数学*],
    [*直译*],
    [*俗称*],
    [标量积],
    [数量积],
    [内积],
    [点积],
    [矢量积],
    [向量积],
    [外积],
    [叉积],
  )])

物理和数学上的用语采用了意译的方法，分别表示运算的结果为标量和矢量。

在数学学科，通常也可以翻译成「内积」和「外积」，是两个名词的直译。

而「点积」和「叉积」是根据运算符号得来的俗称，这种俗称也很常见。

== 定义

#emph[点积的概念对于任意维数的向量都适用]。

已知两个向量 $bold(a) , bold(b)$ ，它们的夹角为 $theta$，那么这两个向量的点积为：

$ bold(a) dot.op bold(b) = lr(|bold(a)|) lr(|bold(b)|) cos theta $

其中，我们称 $lr(|bold(a)|) cos theta$ 为 $bold(a)$ 在 $bold(b)$ 方向上的投影。

其中，$theta in lr([0 , pi])$，但是直线的夹角 $theta in \[ 0 , pi \)$，因为相反向量是完全不同的。

== 意义

点积的几何意义即为：点积 $bold(a) dot.op bold(b)$ 等于 $bold(a)$ 的模与 $bold(b)$ 在 $bold(a)$ 方向上的投影的乘积。

另外，我们定义向量点积数值上表示为（简记为先相乘再相加）：

$ lr((x_1 , y_1)) dot.op lr((x_2 , y_2)) = x_1 x_2 + y_1 y_2 $

可以发现，这种运算得到的结果是一个标量，并不属于向量的线性运算。

向量与零向量点积，结果为 $arrow(0)$。在不引起混淆的情况下，点积的点号可以省略不写。

== 性质

向量点乘满足交换律：

$ bold(a) dot.op bold(b) = bold(b) dot.op bold(a) = lr(|bold(a)|) dot.op lr(|bold(b)|) dot.op cos theta $

向量点乘对数乘有结合律：

$ lr((lambda bold(a))) dot.op bold(b) = lambda lr((bold(a) dot.op bold(b))) = bold(a) dot.op lr((lambda bold(b))) $

向量点乘对向量加法有分配率：

$ lr((bold(a) + bold(b))) dot.op bold(c) = bold(a) dot.op bold(c) + bold(b) dot.op bold(c) $

但是向量点乘不满足结合律，

$ lr((bold(a) dot.op bold(b))) dot.op bold(c) eq.not bold(a) dot.op lr((bold(b) dot.op bold(c))) $

== 性质

注意到向量运算具有大部分的数字运算的性质（除了除法），因此可以当做字母计算。

可以得到，若 $bold(b) eq.not bold(c)$，$bold(a) dot.op bold(b) = bold(a) dot.op bold(c)$ 的充要条件是 $bold(a) tack.t lr((bold(b) - bold(c)))$，

#mitex("
\bm a\cdot\bm b=\bm a\cdot\bm c\\\\
\bm a\cdot(\bm b-\bm c)=\vec0
")

即，

$ bold(a) tack.t lr((bold(b) - bold(c))) $

== 性质

我们可以发现，

#mitex("
|\bm a+\bm b|^2-|\bm a-\bm b|^2=4\bm a\cdot\bm b\\\\
\bm a\cdot\bm b={1\over4}\\left(|\bm a+\bm b|^2-|\bm a-\bm b|^2\\right)
")

即极化恒等式，我们可以不通过求夹角的方式得出两向量点积。

== 性质

同时，常用的，

$ lr(|bold(a) + bold(b)|)                                      & = lambda\
lr((bold(a) + bold(b))) dot.op lr((bold(a) + bold(b)))       & = lambda^2\
lr(|bold(a)|)^2 + 2 bold(a) dot.op bold(b) + lr(|bold(b)|)^2 & = lambda^2 $

即，

#mitex("
|\bm a|^2+2\bm a\cdot\bm b+|\bm b|^2=|\bm a+\bm b|^2\\\\
\bm a\cdot\bm b={1\over2}\\left(|\bm a+\bm b|^2-|\bm a|^2-|\bm b|^2\\right)
")

== 性质

总结一下，上面两个式子，

#mitex("
\bm a\cdot\bm b={1\over4}\\left(|\bm a+\bm b|^2-|\bm a-\bm b|^2\\right)\\\\
\bm a\cdot\bm b={1\over2}\\left(|\bm a+\bm b|^2-|\bm a|^2-|\bm b|^2\\right)
")

再结合点乘的定义，

#mitex("
\bm a\cdot\bm b=|\bm a|\cdot|\bm b|\cdot\cos\\theta\\\\
\cos\\theta={\bm a\cdot\bm b\over|\bm a|\cdot|\bm b|}
")

就可以求出向量夹角。

== 性质

特殊的，

#mitex("
\\theta=0\,(\cos\\theta=1),\,\bm a\cdot\bm b=|\bm a|\cdot|\bm b|\\\\
\\theta=\pi\,(\cos\\theta=-1),\,\bm a\cdot\bm b=-|\bm a|\cdot|\bm b|\\\\
\\theta=\pi/2\,(\cos\\theta=0),\,\bm a\cdot\bm b=0\\\\
\bm a\cdot\bm a=|\bm a|^2,\,|\bm a|=\sqrt{\bm a\cdot\bm a}\\
")

其中，第三条即，垂直向量向量点积等于零。

根据 $cos 90^circle.stroked.tiny = 0$，$bold(a) tack.t bold(b) arrow.l.r.double bold(a) dot.op bold(b) = 0$。

== 柯西不等式向量形式

$ lr(|bold(a) dot.op bold(b)|) lt.eq lr(|bold(a)|) dot.op lr(|bold(b)|) $

当且仅当两向量共线，取等。

据此，可以判断两向量共线：

两个非零向量 $bold(a)$ 与 $bold(b)$ 共线，等价于，有唯一实数 $lambda$，使得 $bold(b) = lambda bold(a)$。

由数乘的定义知，对于非零向量 $bold(a)$，如果存在实数 $lambda$，使得 $bold(b) = lambda bold(a)$，那么 $bold(a) parallel bold(b)$。

数值上，有判别式 $bold(a) = lambda bold(b) arrow.l.r.double lr(|bold(a) dot.op bold(b)|) = lr(|bold(a)|) lr(|bold(b)|)$。

= 平面直角坐标系中的应用

== 平面向量基本定理

基底 $bold(e)_1 , bold(e)_2$ 不共线，对于平面内任一向量 $bold(a)$，存在唯一实数 $x , y$ 使得 $bold(a) = x bold(e)_1 + y bold(e)_2$。

形式化的，平面内的任一向量都可以唯一的表示为两个不共线向量的线性组合。

存在性的证明：感性理解（雾

唯一性的证明，反证：假设存在两组实数 $angle.l x_1 , y_1 angle.r$、$angle.l x_2 , y_2 angle.r$，

#mitex("
\bm a=x_1\bm e_1+y_1\bm e_2=x_2\bm e_1+y_2\bm e_2\\\\
\bm e_1(x_1-x_2)=\bm e_2(y_2-y_1)
")

因为 $x_1 eq.not x_2 , y_1 eq.not y_2$，则 $bold(e)_1 , bold(e)_2$ 共线，与条件不符，因此存在唯一性。

== 平面向量基本定理的证明

考虑构造性的证明，

若，

#mitex("
\bm a\cdot\bm e_1=a_1,\,\bm a\cdot\bm e_2=a_2\\\\
\langle\bm e_1,\bm e_2\\rangle=\\theta
")

设，$bold(a)=x bold(e)_1+y bold(e)_2$，用 $a_1,a_2,theta$ 表示 $bold(a)$。

考虑，

#mitex("
\bm e_1\bm e_2=\cos\\theta\\\\
\bm a\cdot\bm e_1=x+y\bm e_1\bm e_2=a_1\\\\
\bm a\cdot\bm e_2=y+x\bm e_1\bm e_2=a_2
")

== 平面向量基本定理的证明

列出方程组，

#mitex("
\begin{cases}
x+y\cos\\theta=a_1\\\\
y+x\cos\\theta=a_2
\end{cases}
")

解得，

#mitex("
\left\{\begin{aligned}
x={a_1-a_2\cos\\theta\over\sin^2\\theta}\\\\
y={a_2-a_1\cos\\theta\over\sin^2\\theta}
\end{aligned}\\right.
")

这个思想很重要，常用一个很奇怪的式子，去点乘两个不共线向量。

常常在内心外心垂心中心处，根据这些信息，列方程，就可以解出来 $x,y$ 的值。

== 线段中点

设 $A lr((x_1 , y_1))$、$B lr((x_2 , y_2))$ 为一平面内两点。

设 $C lr((x , y))$ 为线段 $A B$ 中点，则 $arrow(A C) = arrow(C B)$：

#mitex("
x-x_1=x_2-x\\\\
y-y_1=y_2-y
")

最终解得，

#mitex("
C\\left({x_1+x_2\\over2},{y_1+y_2\\over2}\\right)
")

即中点坐标。

== 线段长度

设 $A lr((x_1 , y_1))$、$B lr((x_2 , y_2))$ 为一平面内两点，则，

$ lr(|arrow(A B)|) = sqrt(arrow(A B) dot.op arrow(A B)) = sqrt(lr((x_1 - x_2))^2 + lr((y_1 - y_2))^2) $

则线段 $A B$，

$ lr(|A B|) = lr(|arrow(A B)|) = sqrt(lr((x_1 - x_2))^2 + lr((y_1 - y_2))^2) $

即线段长度。

== 三点共线

对于线段 $A B$ 及一点 $Q$，若存在一点 $O$ 满足，

$ arrow(O Q) = lambda arrow(O A) + lr((1 - lambda)) arrow(O B) $

则 $Q$ 在直线 $A B$ 上，即 $A , B , Q$ 三点共线。

类似的，若 $C$ 是线段 $A B$ 中点，则对于任意一点 $O$，有，

#mitex("
\\overrightarrow{OC}={1\\over2}\\overrightarrow{OA}+{1\\over2}\\overrightarrow{OB}
")

= 解三角形

== 三角形的心

#figure(align(center)[#table(
    columns: 3,
    align: (col, row) => (center, center, center,).at(col),
    inset: 12pt,
    [编号],
    [心的名称],
    [定义],
    [$X_1$],
    [内心],
    [三条#strong[角平分线]的交点],
    [$X_2$],
    [重心],
    [三条#strong[中线]的交点],
    [$X_3$],
    [外心],
    [三条#strong[中垂线]的交点],
    [$X_4$],
    [垂心],
    [三条#strong[高线]的交点],
  )])

== 三角形重心

存在有塞瓦定理、塞瓦定理逆定理。

+ 三角形重心到其各个顶点向量之和为零。

+ 一个三角形的重心同时也是其中点三角形的重心。

+ 重心到顶点的距离与重心到对边中点的距离之比为 $2 : 1$。

+ 在平面直角坐标系中，重心的坐标是顶点坐标的算术平均。

+ 重心和三角形任意两个顶点组成的三个三角形面积相等。

+ 重心到三条边的距离与三条边的长成反比。（上一条的推论）

+ 重心到三边距离之积最大、到三角形三个顶点距离的平方和最小。

+ 瓦塞定理：三顶点选一个作为起点，定一方向，绕一圈，三组比例相乘为一。

== 正弦定理

回顾初中几何，三角形面积，

#mitex("
S={1\\over2}ab\\sin C={1\\over2}bc\\sin A={1\\over2}ac\\sin B
")

下面的证明过程只考虑锐角三角形，对于钝角三角形，结论不变。

做过 $angle A$ 的垂线，则该垂线长度 $h$：

$ h = b sin C = c sin B $

对每个角应用，最后可得，

#mitex("
{a\\over\\sin A}={b\\over\\sin B}={c\\over\\sin C}=k
")

== 正弦定理

做出该三角形的外接圆，过圆心做 $B C$ 的高，则，

#mitex("
a=2R\\sin A,\\,{a\\over\\sin A}=2R
")

即值 $k$ 为三角形外接圆直径 $2 R$。

常常这么写：

#mitex("
a=2R\sin A,\,b=2R\sin B,\,c=2R\sin C\\\\
\sin A={a\over2R},\,\sin B={b\over2R},\,\sin C={c\over2R}
")

== 正弦定理

有推论：

+ 大边对大角，小边对小角。

+ 三角形外接圆半径：

$ R=(a b c)/(4S) $

== 余弦定理

在 $triangle.stroked.t A B C$ 中，

$ arrow(A B) = arrow(C B) - arrow(C A)\
lr(|arrow(A B)|)^2 = lr(|arrow(C B)|)^2 + lr(|arrow(C A)|)^2 - 2 lr(|arrow(C B)|) dot.op lr(|arrow(C A)|) dot.op cos theta\
c^2 = a^2 + b^2 - 2 a b cos theta $

其中 $theta$ 为 $c$ 的对角，即 $angle C$；第二步就是两边平方。

== 余弦定理

常写作：

#mitex("
\cos A={b^2+c^2-a^2\over2bc},\,\cos B={a^2+c^2-b^2\over2ac},\,\cos C={a^2+b^2-c^2\over2ab}
")

有推论：

$ a^2 + b^2 - c^2 > 0 & arrow.r.double cos C > 0 arrow.r.double C in lr((0 , pi \/ 2))\
a^2 + b^2 - c^2 = 0 & arrow.r.double cos C = 0 arrow.r.double C = pi \/ 2\
a^2 + b^2 - c^2 < 0 & arrow.r.double cos C < 0 arrow.r.double C in lr((pi \/ 2 , pi)) $

== 解三角形

回忆初中平几，根据全等三角形的判断：

如果知道 ASA、AAS、SAS、SSS、HL 就可以唯一的确定一个三角形。

总结一下就是两个角全都可以，三个边可以，一个角两个边就需要是夹角。

即知道 $a C b$、$c B a$、$b A c$，才可以唯一确定一个两边一角的三角形。

另外，至于 SSA，这个角如果是直角（HL）或者钝角，就也是确定的。

三角形确定，意味着我们可以求出所有边的长度以及所有角度的大小。

也有解四边形的，大部分是把四边形分割为两个三角形。

通过找到两个三角形的联系，解整个四边形。

== 解三角形

正弦定理、余弦定理就为我们提供了方法：可以利用角度和边长互相表示。

像这样，确定三角形边、角的过程，就是解三角形。

如何选择正弦定理、余弦定理？

遇到正弦选正弦定理，遇到齐次式考虑正弦定理。

遇到余弦选余弦定理，遇到边的二次齐次式考虑余弦定理。

原则：边角统一。

== 中线长定理

在 $triangle.stroked.t A B C$ 中，$B C$ 的中点为 $M$，对于中线 $A M$，有：

#mitex("
AM^2={1\\over2}b^2+{1\\over2}c^2-{1\\over4}a^2
")

或，

#mitex("
AM^2+BM^2={1\\over2}(AC^2+AB^2)
")

或，

#mitex("
AM={1\\over2}\\sqrt{2b^2+2c^2-a^2}
")

== 中线长定理

证明，基底分解：

#mitex("
\\overrightarrow{AM}={1\\over2}\\overrightarrow{AB}+{1\\over2}\\overrightarrow{AC}\\\\
\\overrightarrow{BM}={1\\over2}\\overrightarrow{AC}-{1\\over2}\\overrightarrow{AB}
")

则，

#mitex("
|\\overrightarrow{AM}|^2+|\\overrightarrow{BM}|^2={1\\over2}|\\overrightarrow{AB}|^2+{1\\over2}|\\overrightarrow{AC}|^2
")

== 角平分线定理

在 $triangle.stroked.t A B C$ 中，$angle A$ 的平分线 $A M$，有：

#mitex("
{BM\\over CM}={AB\\over AC}
")

是分角定理的直接推论，证明见下。

== 分角定理

在 $triangle.stroked.t A B C$ 中，$B C$ 上有一点 $M$，则：

#mitex("
{BM\\over CM}={AB\\sin\\angle BAM\\over AC\\sin\\angle CAM}
")

证明，左右两边等面积法：

#mitex("
{BM\\over CM}={S_{\\triangle ABM}\\over S_{\\triangle ACM}}={AB\\cdot AM\\sin\\angle BAM\\over AC\\cdot AM\\sin\\angle CAM}={AB\\sin\\angle BAM\\over AC\\sin\\angle CAM}
")

== 分角定理

或正弦定理：

#mitex("
{BM\\over\\sin\\angle BAM}={AB\\over\\sin\\angle AMB}\\\\
{CM\\over\\sin\\angle CAM}={AC\\over\\sin\\angle AMC}
")

上下做比。Q.E.D.

== 海伦公式

任意三角形面积可以表示为：

#mitex("
\\begin{aligned}
S&=\\sqrt{p(p-a)(p-b)(p-c)}\\\\
p&={a+b+c\\over2}
\\end{aligned}
")

其中 $p$ 为三角形的半周长。

== 奔驰定理

在锐角 #mi("\\triangle ABC") 中，

#mitex("
S_{\\triangle BOC}\cdot\overrightarrow{OA}+S_{\\triangle AOC}\cdot\overrightarrow{OB}+S_{\\triangle AOB}\cdot\overrightarrow{OC}=\vec0
")

推论：

+ 设 $I$ 为内心，则 #mi("a\cdot\overrightarrow{IA}+b\cdot\overrightarrow{IB}+c\cdot\overrightarrow{IC}=\vec0").

+ 设 $H$ 为垂心，则 #mi("\\tan A\cdot\overrightarrow{HA}+\\tan B\cdot\overrightarrow{HB}+\\tan C\cdot\overrightarrow{HC}=\vec0").

+ 设 $O$ 为外心，则 #mi("\sin2A\cdot\overrightarrow{OA}+\sin2B\cdot\overrightarrow{OB}+\sin2C\cdot\overrightarrow{OC}=\vec0").

== 布雷特施奈德公式

布雷特施奈德公式：任意四边形面积可以表示为，

#mitex("
\begin{aligned}
S&=\sqrt{(p-a)(p-b)(p-c)(p-d)-abcd\cos^2{\alpha+\beta\over2}}\\\\
p&={a+b+c+d\over2}
\end{aligned}
")

其中 $p$ 为四边形的半周长，$alpha,beta$ 为其中二个对角。

布雷特施奈德公式可视为婆罗摩笈多公式之推广。 

== 婆罗摩笈多公式

注意到圆内接四边形对角互补，其半角余弦值为零。

即 $cos 90degree=0$ 则圆内接四边形面积可以简化为：

#mitex("
\begin{aligned}
S&=\sqrt{(p-a)(p-b)(p-c)(p-d)}\\\\
p&={a+b+c+d\over2}
\end{aligned}
")

其中 $p$ 为四边形的半周长。

== 一些结论

在三角形中，$a = b cos C + c cos B$。

若 $sin^2 A + sin^2 B = sin^2 C$，则该三角形是以 $angle C$ 为直角的 $upright(R t triangle.stroked.t)$。

解三角形里面常用的奇怪三角函数：

#mitex("
\\sin15^\\circ=\\cos75^\\circ={\\sqrt6-\\sqrt2\\over4}\\\\
\\sin75^\\circ=\\cos15^\\circ={\\sqrt6+\\sqrt2\\over4}
")

此外，善用初中的几何模型、相似等。不要什么都用向量啊三角函数之类的解。

= 例题

== 例题一

#mitex("
2\cos^2{B\over2}+\sqrt3\sin B=3
")

+ 求 $B$.

== 题解：例题一

#mitex("
\cos B=2\cos^2{B\over2}-1\\\\
\cos B+\sqrt3\sin B=2\\\\
{\sqrt3\over2}\sin B+{1\over2}\cos B=1\\\\
\sin B\cos30^\circ+\cos B\sin30^\circ=1\\\\
\sin(B+30^\circ)=1=\sin90^\circ\\\\
B=60^\circ
")

== 例题二

#mitex("
(\sin B-\sin C)^2=\sin^2 A-\sin B\sin C
")

+ 求 $A$.
+ 若 $sqrt(2)a + b= 2c$，求 $C$.

== 题解：例题二

观察到是角的二次齐次式，且都是正弦，考虑正弦定理，

#mitex("
(\sin B-\sin C)^2=\sin^2 A-\sin B\sin C\\\\
(b-c)^2=a^2-bc\\\\
b^2+c^2-2bc=a^2-bc\\\\
a^2=b^2+c^2-bc
")

于是，

#mitex("
\cos A={b^2+c^2-a^2\over2bc}={1\over2}\\\\
A=60^\circ
")

== 题解：例题二

观察到 $sqrt(2)a + b= 2c$ 为边的一次齐次，考虑用正弦定理。

#mitex("
\sqrt2a+b=2c\\\\
\sqrt2\sin A+\sin B=2\sin C
")

根据上一问，#mi("\sin A=\\sin60^\circ=\sqrt3/2")，

#mitex("
\sqrt6/2+\sin B=2\sin C\\\\
\sqrt6/2+\sin(120-C)=2\sin C\\\\
\sqrt6/2+\sqrt3/2\cos C+\sin C/2=2\sin C
")

继续整理，

== 题解：例题二

#mitex("
{\sqrt6\over2}+{\sqrt3\over2}\cos C+{1\over2}\sin C=2\sin C\\\\
{3\over2}\sin C-{\sqrt3\over2}\cos C={\sqrt6\over2}\\\\
{\sqrt3\over2}\sin C-{1\over2}\cos C={\sqrt2\over2}\\\\
\sin C\cos30^\circ-\cos C\sin30^\circ={\sqrt2\over2}\\\\
\sin(C-30^\circ)={\sqrt2\over2}=\sin45^\circ
")

== 题解：例题二

因为 $C in (0degree,120 degree)$，$C-30degree in(-30degree,90degree)$，因此，

$
C-30degree=45degree,space
C=75degree
$

总结一下，这里用到了类似辅助角公式的套路。

一般来说可以看特殊角来凑，但是我们复习一下辅助角公式的一个结论。

#mitex("
A\sin\\alpha+B\cos\alpha=\sqrt{A^2+B^2}\sin(\alpha+\phi)
")

其中 $phi$ 是有公式的，但是不好用，不如记住前面的然后凑。

== 例题三

在锐角 #mi("\\triangle ABC") 中，

#mitex("
2b\sin A-\sqrt3a=0
")

+ 求 $B$.
+ 求 $cos A+cos B+cos C$ 的取值范围.

== 题解：例题三

不考虑 $sin A$ 是边的二次齐次式，于是应用正弦定理，

#mitex("
2\sin B\sin A-\sqrt2\sin A=0\\\\
2\sin B=\sqrt3\\\\
\sin B=\sqrt3/2
")

因为 $angle B$ 是锐角，

$
B=60degree
$

== 题解：例题三

设，

#mitex("
\begin{aligned}
S&=\cos A+\cos B+\cos C\\\\
&=\cos A+\cos C+1/2\\\\
&=\cos(120\degree-C)+\cos C+1/2\\\\
&=-{1\over2}\cos C+{\sqrt3\over2}\sin C+\cos C+{1\over2}\\\\
&={\sqrt3\over2}\sin C+{1\over2}\cos C+{1\over2}\\\\
&=\sin C\cos30\degree+\cos C\sin30\degree
+1/2\\\\
&=\sin(C+30\degree)+1/2
\end{aligned}
")

== 题解：例题三

因为 #mi("0^\circ<A,B,C<90^\circ")，

#mitex("
\begin{cases}
0\degree<&C&<90\degree\\\\
0\degree<&B&<90\degree
\end{cases}
\Longleftrightarrow
\begin{cases}
0\degree<&C&<90\degree\\\\
0\degree<&120-C&<90\degree
\end{cases}
")

即，#mi("30^\circ<C<90^\circ")，#mi("60^\circ<C+30^\circ<120^\circ")。

画出单位圆，易得 #mi("\sin(C+30\degree)\in(\sqrt3/2,1]")，即，

#mitex("
\cos A+\cos B+\cos C\in\\left({\sqrt3+1\\over2},{3\\over2}\\right]
")

== 例题四

在 #mi("\\triangle ABC") 中，$a+b=11$，

#mitex("
\cos A={1\over8},\,\cos B={9\over16}
")

+ 求 $a,b$。

== 题解：例题四

考虑余弦转正弦，因为是三角形的角，因此正弦值非负，

#mitex("
\sin A=\sqrt{1-\cos^2 A}=\sqrt{63\over64}={3\sqrt7\over8}\\\\
\sin B=\sqrt{1-\cos^2 B}=\sqrt{175\over256}={5\sqrt7\over16}
")

#mitex("
{a\over b}={\sin A\over\sin B}={6\over5}
")

因此 $a=6,space b=5$。

== 例题五

#mitex("
{\sin A\over\sin B-\sin C}={b+c\over b-a}
")

+ 求 $cos C$。

== 题解：例题五

考虑 $cos C$ 可以怎么表示，可以通过 $sin C$ 用毕达哥拉斯定理，也可以余弦定理。

考虑到这个原形式是一次齐次，因此考虑角化变。

#mitex("
{a\over b-c}={b+c\over b-a}\\
b^2-c^2=ab-a^2\\
c^2=a^2+b^2-ab
")

因此，

#mitex("
\cos C={a^2+b^2-c^2\over2bc}={1\over2}
")

== 例题六

若，

#mitex("
\begin{cases}
\sin A=3\sin B\\\\
c=\sqrt5\\\\
\cos C=5/6
\end{cases}
")

+ 求 $a$。

== 题解：例题六

尝试考虑这三个东西各自什么用。

最容易发现第二个式子最简单，可以最后带入用。

因为 $cos$ 关于余弦定理，关于边数多，因此考虑后用。

第一个式子结构很好，是一次齐次，因此带入第一个正弦定理。

$
a=3b
$

又因为，

$
cos C=(a^2+b^2-c^2) /(2a b)
$

带入即可，解得 $a=3$。

== 例题七

若，

#mitex("
\begin{cases}
b\sin2A=a\sin B\\\\
c=2b
\end{cases}
")

+ 求 #mi[a/b]。

== 题解：例题七

考虑到第二个式子的形式很简单，因此用于消元。

第一个形式中，出现了二倍角，是不好处理的，因此考虑正弦定理。

#mitex("
\sin B\sin2A=\sin A\sin B\\\\
\sin A=\sin2A\\\\
\sin A=2\sin A\cos A\\\\
\cos A=1/2
")

考虑到 #mi[a/b] 是一个一次其次的比例式，因此余弦定理，

#mitex("
\cos A={b^2+c^2-a^2\over2bc}
")

带入，解得 $a^2=3b^2$，即 #mi("a/b=\sqrt3")。

== 例题八

在 #mi("\\triangle ABC") 中，

#mitex("
S=a^2-(b-c)^2
")

+ 求 $\sin A$。

== 题解：例题八

这个式子没有很好的性质，考虑展开，

#mitex("
S=a^2-b^2-c^2+2bc
")

注意到这个形式，而且还是二次齐次式，根据余弦定理，

#mitex("
a^2=b^2+c^2-2bc\cos A
")

有，

#mitex("
S=2bc(1-\cos A)={1\over2}bc\sin A\\\\
\sin A=4-4\cos A
")

== 题解：例题八

联立得方程，

#mitex("
(4-4\cos A)^2+\cos^2A=1\\\\
16(1-\cos A)^2=(1-\cos A)(1+\cos A)\\\\
16-16\cos A=1+\cos A\\\\
\cos A={15\over17},\,
\sin A={8\over17}
")

== 例题九

在 #mi("\\triangle ABC") 中，

#mitex("
\sin A=2\sin B\cos C\\\\
a^2=b^2+c^2-bc
")

+ 求，#mi("\\triangle ABC") 形状。

== 题解：例题九

两个式子都很典型，第二个好说，先处理，

联立二式及余弦定理，

#mitex("
a^2=b^2+c^2-bc\\\\
a^2=b^2+c^2-2bc\cos A
")

得，

$
cos A=1/2,space A=60degree
$

== 题解：例题九

第一个式子，可以不带入 $A$，尝试通过三角函数的变换，

#mitex("
\begin{aligned}
\sin A&=\sin(\pi-B-C)=\sin(B+C)\\\\
&=\sin B\cos C+\cos B\sin C
\end{aligned}
")

联立下式及一式，

#mitex("
\sin B\cos C+\cos B\sin C=2\sin B\cos C\\\\
\sin B\cos C=\cos B\sin C\\\\
\\tan B=\\tan C
")

因为 $B,C in(0,pi)$，正切函数在此范围内唯一，则

$
B=C=A=60degree
$

即 #mi("\\triangle ABC") 是正三角形。

== 例题十

在 #mi("\\triangle ABC") 中，

$
cos(2B+C)+cos C>0
$
+ 判断三角形是锐角、直角、钝角三角形。

== 题解：例题十

容易发现，$cos$ 里面的角有很好的性质，考虑和差化积，

#mitex("
\begin{aligned}
&\cos(2B+C)+\cos C\\\\
=\;&2\cos(B+C)\cos B\\\\
=\;&-2\cos A\cos B>0
\end{aligned}
")

因此，

$
cos A cos B<0
$

即 $A,B$ 中有一个钝角，即 #mi("\\triangle ABC") 为钝角三角形。

== 例题十一

在 #mi("\\triangle ABC") 中，三边长分别为 $a,a+2,a+4$，且最小角余弦值为 $13\/14$。

+ 求该三角形的面积

== 题解：例题十一

因为大边对大角，因此最小角是 $a$ 对的，

#mitex("
\cos A={(a+2)^2+(a+4)^2-a^2\over2(a+2)(a+4)}={13\over14}
")

解得，$a=3$，于是用海伦公式，

$
p=(3+5+7)/2=15/2
$

$
S=sqrt(15/2 dot 9/2 dot 5/2 dot 1/2)=(15sqrt(3))/4
$

顺便提一句，求面积还可以用余弦定理求出一个角的余弦值，再用毕达哥拉斯定理求出其正弦值，再用面积公式 $S=a b cos C$ 求解，这个算法对于处理边长带根号的一般会更快（因为海伦公式是四项相乘）。

== 例题十二

在 #mi("\\triangle ABC") 中，$angle A=120degree$，$B C=6$。

+ 求：其面积最大值。

== 题解：例题十二

考虑面积可以怎么表示。

Solution 1:

$
S=1/2b c sin A=sqrt(3)/4b c
$

根据余弦定理，

$
36=a^2=b^2+c^2-2b c cos A=b^2+c^2+b c >= 3b c
$

即，

$
b c <= 12,space S <= 3sqrt(3)
$

== 题解：例题十二

Solution 2：

考虑到顶角不变，则可以固定底边，使顶点移动。

易知其轨迹为一个圆弧，则面积最大即底边高线最大。

高线最大即该三角形为等腰三角形，做出高线，

$
S=1/2a h=3sqrt(3)
$

== 例题十三

在 #mi("\\triangle ABC") 中，若

$
a-b=c(cos B-cos A)
$

+ 判断其形状。

== 题解：例题十三

考虑到余弦定理展开后是三次式，有点复杂，因此正弦定理。

$
sin A-sin B=sin C cos B-sin C cos A
$

考虑凑项，右边的两项很像正弦的和角公式，于是，

#mitex("
\begin{aligned}
&\sin(B+C)-\sin(A+C)\\\\
=\;&\sin B\cos C+\sin C\cos B-\sin A\cos C-\sin C\cos A\\\\
=\;&\sin C\cos B-\sin C\cos A
\end{aligned}
")

化简，

$
(sin B-sin A)cos C=0
$

即 $sin A=sin B$ 或 $cos C=0$，

即 #mi("\\triangle ABC") 为等腰三角形或直角三角形。

== 例题十四

若 #mi("\\triangle ABC") 中，$angle C$ 为钝角，且其面积，

$
S=sqrt(3)/4(a^2+c^2-b^2)
$

+ 求 $angle B$。

== 题解：例题十四

考虑到 $a^2+c^2-b^2$ 是经典掉牙的形式，

$
cos B=(a^2+c^2-b^2)/(2a c)
$

于是，

#mitex("
S={\sqrt3\over4}\cdot2ac\cos B={\sqrt3\over2}ac\cos B
")

考虑很经典的面积公式，

#mitex("
S={1\over2}ac\sin B={\sqrt3\over2}ac\cos B\\\\
\sin B=\sqrt3\cos B\\\\
\\tan B=\sqrt3,\,B=60^\circ
")

== 例题十五

在 #mi("\\triangle ABC") 中，

$
sin^2A-sin^2B-sin^2C=sin B sin C
$

+ 求 $A$.
+ 若 $B C=3$，求其周长最大值。

== 题解：例题十五

因为是正弦的二次齐次式，考虑正弦定理，

$
a^2=b^2+c^2+b c
$

于是 $angle A=120degree$。

考虑周长最大，即 $b+c$ 最大，

#mitex("
a^2=9=b^2+c^2+bc\ge3bc\\
bc\le3
")

考虑周长如何建立联系

#mitex("
b+c=\sqrt{b^2+c^2+2bc}=\sqrt{9+bc}\le2\sqrt3
")

即周长，

$
a+b+c <= 2sqrt(3)+3
$

== 例题十六

在 #mi("\\triangle ABC") 中，

#mitex("
\sin A+2\sin B\cos C=0\\
c=\sqrt3b
")

+ 求 $tan A$。

== 题解：例题十六

考虑到第二个很适合消元 $c$，于是第一个式子可以看成一次齐次，

#mitex("
a+2b\cos C=0\\\\
\cos C=-{a\over2b}={a^2+b^2-c^2\over2bc}={a^2-2b^2\over2bc}
")

因此，

#mitex("
a^2=b^2\\\\
a=b
")

因为 $c=sqrt(3)b$，这是一个 $30degree,30degree,120degree$ 的等腰三角形，

#mitex("
\\tan A=\\tan30^\circ={\sqrt3\over3}
")

== 例题十七

在 #mi("\\triangle ABC") 中，

$
a^2+b^2=2022c^2
$

求，

#mitex("
{2\\tan A\\tan B\over\\tan C(\\tan A+\\tan B)}
")

== 题解：例题十七

考虑到没有什么好玩的结构，因此展开正切。

#mitex("
\begin{aligned}
S&={2\\tan A\\tan B\over\\tan C(\\tan A+\\tan B)}\\\\
&={2\sin A\sin B\over\sin C/\cos C\cdot(\sin A\cos B+\cos A+\sin B)}\\\\
&={2\sin A\sin B\cos C\over\sin^2C}
\end{aligned}
")

== 题解：例题十七

考虑到上下正弦构成二次齐次，正弦定理，

#mitex("
\begin{aligned}
S&={2\sin A\sin B\cos C\over\sin^2C}\\\\
&={2ab\cos C\over c^2}
\end{aligned}
")

注意到 $2a b$ 和 $cos C$ 的余弦定理的分母类似，

#mitex("
\cos C={a^2+b^2-c^2\over2ab}
")

#mitex("
\begin{aligned}
S&={a^2+b^2-c^2\over c^2}={a^2+b^2\over c^2}-1\\\\
&=2022-1=2021
\end{aligned}
")

== 例题十八

在锐角三角形 $A B C$ 中，$a^2-b^2=b c$。

求证：$A=2B$。

== 题解：例题十八

经典题，因为角不好表示，上式又是边的二次齐次式，考虑，

#mitex("
\cos A={b^2+c^2-a^2\over2bc}={c^2-bc\over2bc}={c-b\over2b}\\
")

#mitex("
\begin{aligned}
\cos 2B&=2\cos^2B-1=2\left({a^2+c^2-b^2\over2ac}\\right)^2-1\\\\
&=2\left({c+b\over2a}\\right)^2-1={2c^2+2b^2+4bc-4a^2\over4a^2}\\\\
&={2c^2-2b^2\over4b^2+4bc}={2(c+b)(c-b)\over4b(b+c)}={c-b\over2b}
\end{aligned}
")

于是，

#mitex("
(\cos A=\cos2B)\Longrightarrow(A=2B)
")

= 例题：CF995C

== 题目描述

题目：#link("https://www.luogu.com.cn/problem/CF995C")[CF995C Leaving the Bar]

题目简述：给定 $n$ 个向量，你将一些向量取反，试求出一种取反方法，使得这 $n$ 个向量之和的模小于 $1.5 times 10^6$。

== 正解思路

考虑任意三个向量 $arrow(v)_1 , arrow(v)_2 , arrow(v)_3$ 及其取反的向量 $- arrow(v)_1 , - arrow(v)_2 , - arrow(v)_3$。此时一共有了 $6$ 个向量。根据抽屉原理，这六个向量一定存在两个向量，其夹角小于等于 $60^circle.stroked.tiny$。根据余弦定理 $a^2 = b^2 + c^2 - 2 b c cos theta$。当 $theta lt.eq 60^circle.stroked.tiny$，$2 cos theta gt.eq 1$，则 $2 b c cos theta gt.eq b c$。记 $M = max { b , c }$，有 $a^2 lt.eq b^2 + c^2 - a b lt.eq 2 M^2 - M^2 = M^2$。也就是这两个向量相加后得到的向量的模一定不超过这两个向量的模的较大值。于是我们考虑合并任意三个向量，最终得到两个长度不超过 $10^6$ 的向量，然后我们考虑这两个向量如何定向去合并，那么当这两个向量垂直的时候，他们合并的结果最大，且一定不超过 $sqrt(2) times 10^6 < 1.5 times 10^6$。

== 题解

然而作者不会这个思路。于是采取了一个随机化的方法。考虑随机重排这些向量。然后用（假的）贪心思路来合并，即对于每一个向量只考虑合并上它的当前的最优情况。那么这个思路可能（很容易）被 Hack。于是我们重复这个过程，知道找到一组解即可。

== 代码

```cpp

#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()

struct emm {
    int id, x, y;
};

mt19937 rd(time(0) * clock());

int n;
vector<emm> a;
vector<int> ans;




double dis(int x, int y) {
    return sqrt(1.0 * x * x + 1.0 * y * y);
}

double solev() {
    shuffle(range(a), rd);
    int x = 0, y = 0;
    for (auto &[id, i, j] : a) {
        ans[id] = dis(x + i, y + j) < dis(x - i, y - j) ? 1 : -1;
        x += i * ans[id], y += j * ans[id];
    } return dis(x, y);
}



void print() {
    for (int i : ans) cout << i << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; a.resize(n), ans.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y, a[i].id = i;
    while (1) if (solev() <= 1.5e6) print(), exit(0);
    return 0;
}
```
