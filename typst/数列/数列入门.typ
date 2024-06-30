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
  title: [数列 入门],
  subtitle: [Sequence Junior],
  author: [RainPPR],
  date: datetime.today(),
)

#let (init, slides, touying-outline, alert) = utils.methods(s)
#show: init

#show strong: alert

#let (slide, title-slide, focus-slide) = utils.slides(s)
#show: slides

下文中重要公式，均用 $#box(stroke: black, inset: 3pt, [$ $])$ 框出来。

= 数列基础 <数列基础>
#strong[数列]是由数字组成的有序序列，数列中的每一个数都叫做这个数列的#strong[项]。

#strong[项数]有限的数列成为#strong[有限数列]，项数无穷多的成为#strong[无穷数列]。

排在第一位的数称为这个数列的#strong[首项]，有限数列的最后一个数成为这个数列的#strong[末项]。

注意：无穷数列只有首项，没有末项。

对于数列，更严谨的定义，考虑最一般的复数，下文再说。

== 无穷数列 <无穷数列>
一个 $lr((a : bb(N) arrow.r bb(C)))$ 的函数被称为#strong[无穷数列]。

可记为 ${ a_i }_(i in bb(N))$ 或 $lr((a_i))_(i in bb(N))$ 或 $angle.l a_i angle.r_(i in bb(N))$。

一个数列 $a$ 的第 $i$ 项，通常记为 $a lr((i))$，简记为 $a_i$。

== 有限数列 <有限数列>
若 $I_n = { 1 , 2 , dots.h , n }$，则一个 $lr((a : I_n arrow.r bb(C)))$ 的函数被称为#strong[有限数列]。

可记为 ${ a_i }_(i = 1)^n$ 或 $lr((a_i))_(i = 1)^n$ 或 $angle.l a_i angle.r_(i = 1)^n$。

同时，也可以将 $0$ 作为数列的首项，类似的。

== 单调性 <单调性>
对于 $forall n in bb(Z)^(\*)$，

- 若 $a_(n + 1) gt.eq a_n$，那么称 $a$ 为#strong[单调递增]数列。

- 若 $a_(n + 1) > a_n$，那么称 $a$ 为#strong[严格单调递增]数列。

- 若 $a_(n + 1) lt.eq a_n$，那么称 $a$ 为#strong[单调递减]数列。

- 若 $a_(n + 1) < a_n$，那么称 $a$ 为#strong[严格单调递减]数列。

== 一般的表示方法 <一般的表示方法>
=== 列举法 <列举法>
例如，

$ a = angle.l 1 , 2 , 4 , 8 , 16 angle.r $

对于无穷数列很不好用。

=== 图像法 <图像法>
数列是离散的，因此数列的图像是一个散点图。

一般这个不好用。

== 通项公式 <通项公式>
定义，表示 $n$ 和 $a_n$ 的关系的公式，叫做 $a$ 的#strong[通项公式]。

把数列看成函数的形式，

$ a_n = f lr((n)) $

数列对应函数的解析式，被称为数列的通项公式。

例如，

$ a_n = 2^n $

== 递推公式 <递推公式>
定义，表示 $a_n$ 和 $a_n$ 的前一或前几项的关系的公式，叫做 $a$ 的#strong[递推公式]。

例如，

$ a_(n + 1) = a_n + 2 $

特殊的，如果要根据递推公式确定一个数列，还需要知道数列的任意一项。

一般会表示数列的首项，例如，

$ a_1 = 1 $

如果一个数列只跟其前面的 $k$ 项有关，其中 $k$ 是满足这个条件的最小正整数，

那么称这个数列的阶数为 $k$，即这个数列是一个 $k$ 阶数列。

== 级数 <级数>
数列中各个项的和称为#strong[级数]，具体的，

一个数列 $a_i thin lr((i in bb(N)))$ 的级数是另外一个数列 $s_i thin lr((i in bb(N)))$，具有以下特性：

- $s_0 = a_0$，
- $s_n = s_(n - 1) + a_n thin lr((forall n in bb(Z)^(\*)))$

一般会将 ${ s_i }_(i in bb(N))$ 写为，

$ sum_(i = 0)^n a_i $

== 级数 <级数>

甚至，更直观的 $a_0 + a_1 + dots.h + a_n$ 来凸显级数源于求和的直观概念。

对于从 $1$ 开始的数列，同理，一般直接使用求和符号简记为，

$ s_i = sum_(i = 1)^n a_i $

== 数列和函数 <数列和函数>
容易发现，数列，

$ a_n = f lr((n)) $

其级数，即为 $f$ 函数的积分，

$ s_n = g lr((n)) $

其差分，即为 $f$ 函数的微分，

$ d_n = k lr((n)) $

只不过，函数一般是连续的，而数列一般是离散的。

= 等差数列 <等差数列>
在等差数列中，任何相邻两项的差相等，该差值称为#strong[公差] $d$。

具体的，可以表示为，

$ a_n = d + q n $

的，都是等差数列。

上式中，公差为 $d$，首项 $a_1 = d + q$。

- 若 $d > 0$，等差数列为一个严格单调递增数列。
- 若 $d < 0$，等差数列为一个严格单调递减数列。
- 特殊的，若 $d = 0$，等差数列退化为一个常数列。

== 递推公式 <递推公式-1>
形如，

$ #box(
  stroke: black,
  inset: 3pt,
  [$ a_(n + 1) = a_n + d , lr((n in bb(Z)^(\*))) $],

) $

或者记为，

$ a_(n + 1) - a_n = d $

即公差的定义式。

== 通项公式 <通项公式-1>
形如，

$ #box(stroke: black, inset: 3pt, [$ a_n = a_1 + lr((n - 1)) d $]) $

即，角标减一，等于公差个数。

或者对于从 $0$ 开始的数列，

$ a_n = a_0 + n d $

前面的一项即为首项，其与公差需为给定的确定的数。

== 性质

除了上述几条，

给定任意两项 $a_n , a_m$，则公差，

$ #box(
  stroke: black,
  inset: 3pt,
  [$ d=(a_n-a_m)/(n-m) $],

) 
$

在等差数列中，前项与后项和为该项两倍，具体的，

$ a_(n - 1) + a_(n + 1) & = a_n - d + a_n + d\
                      & = 2 a_n $

从另一个角度看，等差数列中的任意一项，是其前项和后项的算术平均：

#mitex("
a_n={a_{n-1}+a_{n+1}\\over2}
")

== 性质

对于正整数 $m , n , p , q$，若 $m + n = p + q$，则，

$ #box(stroke: black, inset: 3pt, [$ a_m + a_n = a_p + a_q $]) $

或者简化一下，

$ #box(stroke: black, inset: 3pt, [$ a_m + a_n = a_(m - k) + a_(n + k) $]) $

据此，有，

$ #box(stroke: black, inset: 3pt, [$ a_(n - k) + a_(n + k) = 2 a_n $]) $

对于 $a_(n - k) , a_n , a_(n + k)$ 有意义。

== 性质

据此，同理，

#mitex("
a_n={a_{n-k}+a_{n+k}\\over2}
")

若 $angle.l a_n angle.r$ 为一个等差数列，则，

- $angle.l b + a_n angle.r$：为一个等差数列；
- $angle.l b times a_n angle.r$：为一个等差数列；
- $angle.l b^(a_n) angle.r$：为一个等比数列（见下）；

== 项数公式 <项数公式>
给定等差数列首项 $a_1$ 及公差 $d$，有项 $a_k$，则，

#mitex("
\\begin{aligned}
a_k=a_1+(k-1)d\\\\
k-1={a_k-a_1\\over d}
\\end{aligned}
")

$ #box(stroke: black, inset: 3pt, [$ k=(a_k-a_1)/(d)+1 $]) $

或对于 $a_0$，

#mitex("
\\begin{aligned}
a_k=a_0+kd\\\\
k={a_k-a_0\\over d}\\\\
\\end{aligned}
")

== 项数公式 <项数公式>
另外的，函数思想，有，

$ a_n = f lr((n))\
n = g lr((a_n)) $

即 $f , g$ 互为反函数，这个可以用于求多种数列。

== 求和公式 <求和公式>
一般考虑，

$ S_i = sum_(i = 1)^n a_i $

有常用公式，

$ S_n - S_(n - 1) = a_n $

考虑求解出，求和公式的封闭形式，

$ S_n & = a_1 + lr((a_1 + d)) + lr((a_1 + 2 d)) + dots.h + lr([a_1 + lr((n - 1)) d])\
    & = n a_1 + d lr([1 + 2 + 3 + dots.h lr((n - 1))])\
    & = n a_1 + d T_(n - 1) $

== 求和公式 <求和公式>
而对于，

$ T_n = 1 + 2 + 3 + dots.h + n $

我们首位配对，

$ T_n = n + lr((n - 1)) + dots.h + 1 $

两者相加，

$ 2 T_n = n lr((n + 1))\
T_n = n lr((n + 1)) \/ 2 $

== 求和公式 <求和公式>
于是，

#latex.render("
\\begin{aligned}
S_n&=na_1+dT_{n-1}\\\\
&=\\boxed{na_1+{n(n-1)\\over2}d}\\\\
&={n\\over2}[2a_1+(n-1)d]\\\\
&=\\boxed{{n(a_1+a_n)\\over2}}
\\end{aligned}
")

或者，对于原始公式直接首位配对，用上面的结论，也可以得出。

总结一下，一般写为，

#latex.render("
\\boxed{S_n={[2a_1+(n-1)]d\\over2}\\cdot n={n(a_1+a_n)\\over2}}
")

== 求和公式 <求和公式>
常用二次函数的思想：

#latex.render("
\\boxed{S_n={d\\over2}n^2+\\left(a_1-{d\\over2}\\right)n}
")

据此，可以等差数列和的极点存在于，

#mitex("
n={d/2-a_1\\over d}={1\\over2}-{a_1\\over d}
")

我们发现，该函数图像过原点，因此我们定义，

$ S_0 = 0 $

== 求和公式 <求和公式>
同时，对于上面的式子，如果我们假设存在 $a_0$，那么求和，

得出很重要的一个结论，任何一个二次函数，都可以表示为一个等差数列的级数。

等差数列和在中文教科书中常表达为：

一个等差数列的和，等于其首项与末项的和，乘以项数除以二。

== 等差中项 <等差中项>
对于 $a , b$，有 $c$ 满足，

$ c - a = b - c $

即，

#mitex("
c={a+b\\over2}
")

即算术平均数。

或者，若 ${ a , b , c }$ 为一个等差数列，那么 $ b - a = c - b $ 一般写为， $ a + c = 2 b $ 可以用这个来判断一个三项数列是否为等差数列。

例题，对于等差数列 ${ a , b , c }$，证明，

#latex.render("
\\left\\{{1\\over\\sqrt b+\\sqrt c},{1\\over\\sqrt c+\\sqrt a},{1\\over\\sqrt a+\\sqrt b}\\right\\}
")

也是一个等差数列。

== 等差中项 <等差中项>
暴力展开，

#latex.render("
\\begin{eqnarray}
{2\\over\\sqrt c+\\sqrt a}={1\\over\\sqrt b+\\sqrt c}+{1\\over\\sqrt a+\\sqrt b}\\\\
{2\\over\\sqrt c+\\sqrt a}={2\\sqrt b+\\sqrt a+\\sqrt c\\over b+\\sqrt b(\\sqrt a+\\sqrt c)+\\sqrt{ac}}\\\\
2b+2\\sqrt{ac}+2\\sqrt b(\\sqrt a+\\sqrt c)=2\\sqrt b(\\sqrt a+\\sqrt c)+a+c+\\sqrt ac\\\\
a+c=2b
\\end{eqnarray}
")

对于等差数列 ${ a , b , c }$ 成立。Q.E.D.

== 等差中项 <等差中项>
或者，观察到原式中，分母都是根号的形式，考虑分母有理化，

#latex.render("
\begin{eqnarray}
{2\\over\\sqrt c+\\sqrt a}={1\\over\\sqrt b+\\sqrt c}+{1\\over\\sqrt a+\\sqrt b}\\\\
{2(\\sqrt c-\\sqrt a)\\over2d}={\\sqrt c-\\sqrt b\\over d}+{\\sqrt b-\\sqrt a\\over d}
\end{eqnarray}
")

显然成立。

== 累加法 <累加法>
最简单的，形如，

$ a_n = a_(n - 1) + f lr((n)) $

都可以使用累加法，具体的，

$ a_n       & = a_(n - 1) + f lr((n))\
a_(n - 1) & = a_(n - 2) + f lr((n - 1))\
          & dots.h\
a_3       & = a_2 + f lr((3))\
a_2       & = a_1 + f lr((2)) $

上述所有式子相加，得

$ a_n = a_1 + f lr((2)) + f lr((2)) + dots.h + f lr((n)) $

== 多阶等差数列 <多阶等差数列>
容易发现，我们对于公差求前缀和，可以得到一个普通等差数列。

那么，我们对于普通等差数列再求和，就可以得到二阶等差数列。

具体的，定义常数为零阶等差数列，普通等差数列为一阶等差数列。

容易发现，若 ${ a_i }$ 为一阶等差数列，${ b_i }$ 同样，那么 ${ a_i b_i }$ 为一个二阶等差数列。

根据定义，对于一个二阶等差数列，其相邻两项的差为一个一阶等差数列，相邻两项差的相邻两项差为一个常数。

= 等比数列 <等比数列>
在等比数列中，任何相邻两项的比例相等，该比值称为公比 $q$。

具体的，可以表示为，

$ a = p q^n $

的，都是等比数列。

上式中，公比为 $q$，首项 $a_1 = p q$。

== 递推公式 <递推公式-2>
形如，

$ #box(
  stroke: black,
  inset: 3pt,
  [$ a_(n + 1) = q a_n , thin lr((n in bb(Z)^(\*) , q eq.not 0)) $],

) $

或者记为，

#latex.render("
\\boxed{q={a_{n+1}\\over a_n}}
")

即公比的定义式。

易知此式中，$a_n eq.not 0$，为了方便，我们一般规定 $q eq.not 0$。

== 通项公式 <通项公式-2>
形如，

$ #box(stroke: black, inset: 3pt, [$ a_n = a_1 q^(n - 1) $]) $

换句话说，任意一个等比数列 ${ a_n }$ 都可以写为，

$ { a , a q , a q^2 , dots.h a q^(n - 1) } $

即，角标减一，等于公比幂次。

== 性质 <性质-1>
除了上述几条，

在等比数列中，前项与后项积为该项平方，具体的，

$ a_(n - 1) times a_(n + 1) & = a q^(n - 2) a q^n\
                          & = a^2 q^(2 n - 2)\
                          & = lr((a q^(n - 1)))^2\
                          & = a_n^2 $

对于正整数 $m , n , p , q$，若 $m + n = p + q$，则，

$ #box(stroke: black, inset: 3pt, [$ a_m dot.op a_n = a_p dot.op a_q $]) $

或者简化一下，

$ #box(
  stroke: black,
  inset: 3pt,
  [$ a_m dot.op a_n = a_(m - k) dot.op a_(n + k) $],

) $

据此，有，

$ #box(stroke: black, inset: 3pt, [$ a_(n - k) dot.op a_(n + k) = a_n^2 $]) $

还有一些和上面等比数列类似的操作的结论，

但是因为正负号的问题，不具体写出，可以根据上述平方的公式推导。

若 $angle.l a_n angle.r$ 为一个等比数列，则，

- $angle.l b + a_n angle.r$：为一个等比数列；
- $angle.l b times a_n angle.r$：为一个等比数列；
- $angle.l log_b a_n angle.r$：为一个等差数列（见上）；

== 求和公式 <求和公式-1>
等差数列中给出的公式依然成立，

$ S_n - S_(n - 1) = a_n $

实际上，这个对于任意数列都成立。

考虑求解出，等比数列求和公式的封闭形式，

$ S_n & = a_1 + a_1 q + a_1 q^2 + dots.h + a_1 q^(n - 1)\
    & = a_1 lr((1 + q + q^2 + dots.h + q^(n - 1))) $

注意到后面的是经典的分解因式，

#latex.render("
\\boxed{S_n=a_1\\cdot{q^n-1\\over q-1},\\,(q\\neq 1)}
")

== 求和公式 <求和公式-1>
或者，错位相减，

#latex.render("
\\begin{aligned}
qS_n-S_n=a_1q^n-a_1\\\\
S_n=a_1\\cdot{q^n-1\\over q-1},\\,(q\\neq 1)
\\end{aligned}
")

同时，若 $q = 1$，数列退化为常数列，

$ #box(stroke: black, inset: 3pt, [$ S_n = n a_1 , thin lr((q = 1)) $]) $

== 等比中项 <等比中项>
对于 $a , b$，有 $c$ 满足，

#mitex("
{b\\over c}={c\\over a}
")

即，

$ c = plus.minus sqrt(a b) $

取其中的正数，即几何平均数。

== 累乘法 <累乘法>
和累加法类似的，

$ a_n = a_(n - 1) f lr((n)) $

累乘法，即

$ a_n       & = a_(n - 1) f lr((n))\
a_(n - 1) & = a_(n - 2) f lr((n - 1))\
          & dots.h\
a_3       & = a_2 f lr((3))\
a_2       & = a_1 f lr((2)) $

上述所有式子相乘，得

$ a_n = a_1 f lr((2)) f lr((3)) dots.h f lr((n)) $

= 裂项 <裂项>
== 经典例题 <经典例题>
有性质，

#latex.render("
\\boxed{{1\\over n(n+1)}={1\\over n}-{1\\over n+1}}
")

可以求解，形如

#mitex("
S={1\\over1\\times2}+{1\\over2\\times3}+\\dots+{1\\over n(n+1)}
")

的问题。

同时，易证，

#latex.render("
\\boxed{{1\\over n(n+k)}={1\\over k}\\left({1\\over k}-{1\\over n+k}\\right)}
")

== 经典例题 <经典例题>
注意，此时裂项一定要找准剩下的。

我们可以分别写出括号内的正数、负数。

以 $k = 2$ 为例，

#mitex("
S={1\\over1\\times3}+{1\\over2\\times4}+\\dots+{1\\over n(n+2)}
")

化简，

#mitex("
2S={1\\over1}-{1\\over3}+{1\\over2}-{1\\over4}+\\dots+{1\\over n}-{1\\over n+2}
")

== 经典例题 <经典例题>
列出正负，

#mitex("
\\begin{aligned}
+&:{1\\over1},{1\\over2},{1\\over3},\\dots,{1\\over n-1},{1\\over n}\\\\
-&:{1\\over3},{1\\over4},{1\\over5},\\dots,{1\\over n+1},{1\\over n+2}
\\end{aligned}
")

容易发现，

#mitex("
2S=1+{1\\over2}-{1\\over n+1}-{1\\over n-2}
")

或者用求和符号简单的表示，下文再说。

== 整式裂项 <整式裂项>
有公式，

#latex.render("
\\boxed{n(n+1)={1\\over3}\\Big[n(n+1)(n+2)-(n-1)n(n+1)\\Big]}
")

于是，例题，

$ S = 1 times 2 + 2 times 3 + 3 times 4 + dots.h + n lr((n + 1)) $

化简，

$ 3 S = 1 times 2 times 3 - 0 times 1 times 2 + dots.h + n lr((n + 1)) lr((n + 2)) - lr((n - 1)) n lr((n + 1)) $

得，

#mitex("
S={n(n+1)(n+2)\\over3}
")

利用上述等式，注意到，

$ n^2 = n lr((n + 1)) - n $

于是，

#latex.render("
\\boxed{1^2+2^2+\\dots+n^2=S-{n(n+1)\\over2}={n(n+1)(2n+1)\\over6}}
")

或者用求和符号简单的表示，下文再说。

== 共轭根式 <共轭根式>
形如，

$ sqrt(a) + sqrt(b) , sqrt(a) - sqrt(b) $

的，称为共轭根式。

容易证明，

$ lr((sqrt(a) - sqrt(b))) dot.op lr((sqrt(a) + sqrt(b))) = a - b #h(0em) lr((a , b gt.eq 0)) $

== 共轭根式 <共轭根式>
于是，有裂项，

#mitex("
{1\\over\\sqrt a+\\sqrt b}={\\sqrt a-\\sqrt b\\over a-b}
")

以及，

#mitex("
{1\\over\\sqrt a-\\sqrt b}={\\sqrt a+\\sqrt b\\over a-b}
")

== 阶乘 <阶乘>
定义，

$ #box(
  stroke: black,
  inset: 3pt,
  [$ n ! = 1 times 2 times 3 times dots.h times lr((n - 1)) times n $],

) $

称为阶乘，有，

$ #box(stroke: black, inset: 3pt, [$ n dot.op n ! = lr((n + 1)) ! - n ! $]) $

还有组合数的，但是这里还没涉及到。

= 放缩 <放缩>
== 放缩基础 <放缩基础>
数列求和是一种精确的方法，当我们无法精确的计算的时候，就可以放缩来估计。

例如，估计

#mitex("
S={1\\over1^2}+{1\\over2^2}+\\dots+{1\\over n^2}
")

的级别。

容易发现，

#mitex("
{1\\over n}-{1\\over n-1}={1\\over n(n+1)}<{1\\over n^2}<{1\\over n(n-1)}={1\\over n-1}-{1\\over n}
")

于是，我们可以以此估计。

== 放缩基础 <放缩基础>
我们把 $1 \/ 1^2$ 保持不动，估计

$ 1.5 < S < 2 $

而为了提高精度，我们减少放缩的项数。

或者说，把 $1 \/ 2^2 , 1 \/ 3^2$ 等直接计算，而不是放缩。

这就是放缩提高精度的方法：保留更多的项。

== 放缩进阶 <放缩进阶>
引理一：

#mitex("
{\\sqrt k\\over k^2}={1\\over k^{3/2}}<2\\left({1\\over\\sqrt{k-1}}-{1\\over\\sqrt k}\\right)
")

= 通用方法 <通用方法>
例题，求解通项：

$ a_n = 2 a_(n - 1) + 1 #h(0em) lr((n gt.eq 2)) , a_1 = 1 $

下面将对于这一类的问题，总结三个通用方法。

== 方法一：数学归纳法 <方法一数学归纳法>
尝试证明，

$ a_n = 2^n - 1 $

容易发现，

$ a_1 = 2^1 - 1 = 1 $

假设对于 $n = k , k in bb(N)^(\*)$ 成立，

$ a_k = 2^k - 1 $

尝试证明对于 $n = k + 1$ 也成立，

$ a_(k + 1) = 2 a_k + 1 = 2^(k + 1) - 2 + 1 = 2^(k + 1) - 1 $

于是，该通项公式对于任意 $n in bb(N)^(\*)$ 成立。

== 方法二：变形法 <方法二变形法>
容易发现，递推公式两边同时加一，

$ a_n + 1 = 2 a_(n - 1) + 2 $

另，

$ b_n = a_n + 1 $

上式即为，

$ b_n = 2 b_(n - 1) , b_1 = 2 $

那么这是一个等比数列，易得，

$ b_n = 2^n $

于是，

$ a_n = b_n - 1 = 2^n - 1 $

== 方法二：变形法 <方法二变形法>
#strong[考虑推广这一类问题]，形如，

$ a_n = p a_(n - 1) + q $

我们两边同时加一个数，设为 $x$，

$ a_n + x = p a_(n - 1) + q + x $

记新数列，

$ b_n = a_n + x , a_n = b_n - x $

原数列，

$ b_n = p lr((b_(n - 1) - x)) + q + x = p b_(n - 1) + q - lr((p - 1)) x $

== 方法二：变形法 <方法二变形法>
另右侧常数项为零，于是，

#latex.render("
\\boxed{x={q\\over p-1}}
")

即，对于原数列，加上这个数，即可转化为普通的等比数列。

== 方法三：变形累加 <方法三变形累加>
容易得出，下面的式子不断乘二，

$ a_n = 2 a_(n - 1) + 1\
2 a_(n - 1) = 4 a_(n - 1) + 2\
4 a_(n = 2) = 8 a_(n - 2) + 4\
dots.h\
2^(n - 3) a_3 = 2^(n - 2) a_2 + 2^(n - 3)\
2^(n - 2) a_2 = 2^(n - 1) a_1 + 2^(n - 2) $

上述式子相加，

$ a_n = 2^(n - 1) a_1 + 2^(n - 2) + 2^(n - 3) + dots.h + 4 + 2 + 1 $

因为 $a_1 = 1$，

$ a_n = 2^n - 1 $

#strong[考虑推广这一类问题]，形如，

$ a_n = p a_(n - 1) + q $

我们还可以等式两边同除 $p^n$，得

#latex.render("
\\boxed{{a_n\\over p^n}={a_{n-1}\\over p^{n-1}}+{q\\over p^n}}
")

设新的数列，

#mitex("
b_n={a_n\\over p^n}
")

原数列形如，

#mitex("
b_n=b_{n-1}+{q\\over p^n}
")

对 $b$ 数列进行累加法，可以得出，

#mitex("
b_n={a_1\\over p}+{q\\over p^2}+{q\\over p^3}+\\dots+{q\\over p^n}
")

右边为等比数列，即，

#mitex("
b_n={a_1\\over p}+{q\\over p^n}\\cdot{p^n-1\\over p-1}-{q\\over p}
")

两边同时乘 $p^n$，

#latex.render("
\\boxed{a_n=(a_1-q)p^{n-1}+{q\\over p-1}(p^n-1)}
")

即通用公式。

同时，若 $q = f lr((n))$，依然可以用这个方法来做。

= 基础例题 <基础例题>
求下列数列的通项公式。

== 例题一 <例题一>
求：$a_n = 2 a_(n - 1) + 3 thin lr((n gt.eq 2)) , a_1 = 1$。

== 题解：例题一 <例题一>
因为 $q \/ lr((p - 1)) = 3$，等式两边同时加三，

#mitex("
a_n+3=2a_{n-1}+6=2^{n+1}\\\\
a_n=2^{n+1}-3
")

注意到当 $n = 1 , a_1 = 1$ 满足该式，因此， $ a_n = 2^(n + 1) - 3 $

== 例题二 <例题二>
求：$a_n = a_(n - 1) + n thin lr((n gt.eq 2)) , a_1 = 1$。

== 题解：例题二 <例题二>
注意到，

#mitex("
a_n=a_{n-1}+n\\\\
a_{n-1}=a{n-2}+n-1\\\\
\\dots\\\\
a_2=a_1+2=1+2
")

上式相加，得，

#mitex("
a_n=1+2+3+\\dots+n-1+n={n(n+1)\\over2}
")

注意到当 $n = 1 , a_1 = 1$ 满足该式，因此，

#mitex("
a_n={n(n+1)\\over2}
")

== 例题三 <例题三>
求：$a_n = 2 a_(n - 1) + n thin lr((n gt.eq 2)) , a_1 = 1$。

== 题解：例题三 <例题三>
等式两边同时除以 $2^n$，得，

#mitex("
{a_n\\over2^n}={a_{n-1}\\over2^{n-1}}+{n\\over2^n}
")

记 $b_n = a_n \/ 2^n$，

#mitex("
b_n=b_{n-1}+n/2^n\\\\
b_{n-1}=b_{n-2}+(n-1)/2^{n-1}\\\\
\\dots\\\\
b_2=b_1+1/2\\\\
b_1=1/2
")

上式相加，得，

#mitex("
b_n={n\\over2^n}+{n-1\\over2^{n-1}}+\\dots+{1\\over2}+{1\\over2}
")

注意到分母为二的幂次的形式，等式乘二，

#mitex("
2b_n={n\\over2^{n-1}}+{n-1\\over2^{n-2}}+\\dots+1+1
")

下式减上式，得，

#mitex("
\\begin{aligned}
b_n&=-{n\\over2^n}+{1\\over2^{n-1}}+{1\\over2^{n-2}}+\\dots+{1\\over2^1}+1\\\\
&={1\\over2^{n-1}}\\left(1+2+\\dots+2^{n-1}\\right)-{n\\over2^n}\\\\
&={2^n-1\\over2^{n-1}}-{n\\over2^n}=2-{2+n\\over2^n}
\\end{aligned}
")

带入原式， $ a_n = 2^n b_n = 2^(n + 1) - 2 - n $ 注意到当 $n = 1 , a_1 = 1$ 满足该式，因此， $ a_n = 2^(n + 1) - 2 - n $

== 例题四 <例题四>
求：$a_n = 2 a_(n - 1) + n^2 thin lr((n gt.eq 2)) , a_1 = 1$。

== 题解：例题四 <例题四>
等式两边同时除以 $2^n$，得，

#mitex("
{a_n\\over2^n}={a\_{n-1}\\over2^{n-1}}+{n^2\\over2^n}
")

记， $ b_n = a_n \/ 2^n , a_n = 2^n b_n $ 则，

#mitex("
b_n=b_{n-1}+{n^2\\over2^n},b_1={a\_1\\over2^1}={1\\over2}={1^2\\over2^1}
")

得，

#mitex("
b_n={1^2\\over2^1}+{2^2\\over2^2}+{3^2\\over2^3}+{4^2\\over2^4}+\\dots+{(n-1)^2\\over2^{n-1}}+{n^2\\over2^n}
")

两边同时乘二，得，

#mitex("
2b_n=1+{2^2\\over2^1}+{3^2\\over2^2}+{4^2\\over2^3}+\\dots+{(n-1)^2\\over2^{n-2}}+{n^2\\over2^{n-1}}
")

下式减上式，得，

#mitex("
b_n=1-{n^2\\over2^n}+{2^2-1^2\\over2^1}+{3^2-2^2\\over2^2}+{4^2-3^2\\over2^3}+\\dots+{(n-1)^2-(n-2)^2\\over2^{n-2}}+{n^2-(n-1)^2\\over2^{n-1}}
")

注意到， $ n^2 - lr((n - 1))^2 = n^2 - n^2 - 1 + 2 n = 2 n - 1 $ 于是，记，

#mitex("
\\begin{aligned}
c_n&={2^2-1^2\\over2^1}+{3^2-2^2\\over2^2}+{4^2-3^2\\over2^3}+\\dots+{(n-1)^2-(n-2)^2\\over2^{n-2}}+{n^2-(n-1)^2\\over2^{n-1}}\\\\
&={2\\times2-1\\over2^1}+{2\\times3-1\\over2^2}+{2\\times4-1\\over2^3}+\\dots+{2(n-1)-1\\over2^{n-2}}+{2n-1\\over2^{n-1}}
\\end{aligned}
")

即，

#mitex("
b_n=1-{n^2\\over2^n}+c_n
")

下式两边同时乘二，得，

#mitex("
2c_n=3+{2\\times3-1\\over2^1}+{2\\times4-1\\over2^2}+\\dots+{2(n-1)-1\\over2^{n-3}}+{2n-1\\over2^{n-2}}\\\\
")

与原式相减，得，

#mitex("
\\begin{aligned}
c_n&=3-{2n-1\\over2^{n-1}}+{2\\over2^1}+{2\\over2^2}+\\dots+{2\\over2^{n-3}}+{2\\over2^{n-2}}\\\\
&=3-{2n-1\\over2^{n-1}}+{1\\over2^0}+{1\\over2^1}+\\dots+{1\\over2^{n-4}}+{1\\over2^{n-3}}\\\\
&=3-{2n-1\\over2^{n-1}}+{1\\over2^{n-3}}(1+2+2^2+\\dots+2^{n-3})\\\\
&=3-{2n-1\\over2^{n-1}}+{2^{n-2}-1\\over2^{n-3}}\\\\
&=5-{2n-1\\over2^{n-1}}-{1\\over2^{n-3}}
\\end{aligned}
")

于是，

#mitex("
b_n=1-{n^2\\over2^n}+c_n=6-{n^2\\over2^n}-{2n-1\\over2^{n-1}}-{1\\over2^{n-3}}
")

于是， $ a_n = 2^n b_n = 3 times 2^(n + 1) - n^2 - 4 n - 6 $ 注意到当 $n = 1 , a_1 = 1$ 满足该式，因此， $ a_n = 3 times 2^(n + 1) - n^2 - 4 n - 6 $
