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
  title: [数学归纳法],
  subtitle: [Mathematical Induction],
  author: [RainPPR],
  date: datetime.today(),
)

#let (init, slides, touying-outline, alert) = utils.methods(s)
#show: init

#show strong: alert

#let (slide, title-slide, focus-slide) = utils.slides(s)
#show: slides

数学归纳法是证明某个命题对于所有满足 $n gt.eq n_0$ 的整数 $n$ 都成立的一般方法。首先我们在 $n$ 取 最小值 $n_0$ 时证明该命题，这一步骤成为#strong[基础]。然后对 $n > n_0$，假设该命题对 $n_0 tilde.op n - 1$ 之间的所有值已经被证明，再证明该命题对 $n$ 成立，这一步骤成为#strong[归纳]。

这样一种证明方法仅用有限步就得到无限多个结果。

= 皮亚诺公理
==
一个最简单的例子，皮亚诺公理的自然数定义：

+ $0$ 是自然数；
+ 每一个确定的自然数 $a$，都有一个确定的后继 $a prime$，$a prime$ 也是自然数；
+ 对于每个自然数 $b , c$，$b = c$ 当且仅当 $b prime = c prime$；
+ $0$ 不是任何自然数的后继；
+ 任意关于自然数的命题，如果证明：
  - 它对 $0$ 成立，且假定它对自然数 $a prime$ 为真时，
  - 可以证明它对 $a prime$ 也成立。
  - 那么该命题对所有自然数都成立。

公理 $5$ 保证了数学归纳法的正确性，从而被称为归纳法原理。

==
PS：在集合论和计算机科学领域中，认为 $0$ 属于自然数。

但在数论领域中，认为 $0$ 不属于自然数，因而按数论描述，自然数会同义于正整数。

因此，如果定义 $0$ 不属于自然数，把上面的 $0$ 改成 $1$ 即可。

= 戴德金-皮亚诺结构

戴德金-皮亚诺结构可以描述为满足所有以下条件的三元组 $lr((S , f , e))$：

+ $lr((e in S))$
+ $lr((forall a in S)) lr((f lr((a)) in S))$
+ $lr((forall b in S)) lr((forall c in S)) lr((lr((f lr((b)) = f lr((c)))) arrow.r.double lr((b = c))))$
+ $lr((forall a in S)) lr((f lr((a)) eq.not e))$
+ $lr((forall A subset.eq S)) lr(
    (lr((lr((e in A)) and lr((forall a in A)) lr((f lr((a)) in A)))) arrow.r.double lr((A = S)))
  )$

一个形象化的例子就是最上面的，即三元组 $lr(
  (bb(N) , lr((f : bb(N) arrow.r bb(N)^(*) ; #h(0em) x arrow.r.bar lr((x + 1)))) , 0)
)$。

= 例子

==

证明，

#mitex("
S_n=1+2+\\dots+n={n(n+1)\\over2}
")

==

由于，

#mitex("
1={1\\times2\\over2}
")

假设我们已经证明，

#mitex("
S_{n-1}={n(n-1)\\over2}
")

那么，

#mitex("
S_n=S_{n-1}+n={n(n-1)\\over2}+n={n(n+1)\\over2}
")

则，其对于任意自然数成立。

= 应用

==

解递归式，

#mitex("
Q_0=\\alpha,Q_1=\\beta\\\\
Q_n={1+Q_{n-1}\\over Q_{n-2}},n>1
")

==

容易发现，

#mitex("
\\begin{aligned}
Q_0&=\\alpha\\\\
Q_1&=\\beta\\\\
Q_2&={1+\\beta\\over\\alpha}\\\\
Q_3&={1+\\alpha+\\beta\\over\\alpha\\beta}\\\\
Q_4&={1+\\alpha\\over\\beta}
\\end{aligned}
\\begin{aligned}
Q_5&=\\alpha\\\\
Q_6&=\\beta\\\\
\\dots\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\end{aligned}
")

==

是一个周期函数，结论：

#mitex("
Q_n=\\left\\{\\begin{aligned}
&\\alpha&\quad\\operatorname{if}n\\equiv0\\pmod5\\\\
&\\beta&\quad\\operatorname{if}n\\equiv1\\pmod5\\\\
&{1+\\beta\\over\\alpha}&\quad\\operatorname{if}n\\equiv2\\pmod5\\\\
&{1+\\alpha+\\beta\\over\\alpha\\beta}&\quad\\operatorname{if}n\\equiv3\\pmod5\\\\
&{1+\\alpha\\over\\beta}&\quad\\operatorname{if}n\\equiv4\\pmod5\\\\
\\end{aligned}\\right.
")

==

证明：

对于 $n in \[ 0 , 5 \)$，易证。

假设对于 $n = 5 k + q , k lt.eq t , k in bb(Z) , q in \[ 0 , 5 \)$ 成立。

证明对于 $n = 5 lr((k + 1)) + q$ 也成立，以 $n = 5 lr((k + 1))$ 为例，

#mitex("
Q_{5(k+1)}={1+Q_{5(k+1)-1}\\over Q_{5(k+1)-2}}={1+Q_{5k+4}\\over Q_{5k+3}}=\\alpha
")

对于 $q = 2 , 3 , 4$，同理，略。

= 反向数学归纳法

==

反向数学归纳法，是从 $n$ 到 $n - 1$ 来证明命题，而不是相反。

例如，证明：

#mitex("
\\prod_{i=1}^nx_i\\le\\left({\\sum_{i=1}^nx_i\\over n}\\right)^n
")

对于 $x_1 , x_2 dots.h x_n gt.eq 0$。

==

证明：

记命题，

#mitex("
P(n):x_1\\dots x_n\\le\\left({x_1+\\dots+x_n\\over n}\\right)^n
")

则，

$ P lr((1)) : x_1 lt.eq x_1 $

显然成立。

#mitex("
P(2):x_1x_2\\le\\left({x_1+x_2\\over2}\\right)^2
")

==

即，

#mitex("
4x_1x_2\\le x_1^2+2x_1x_2+x_2^2\\\\
x_1^2-2x_1x_2+x_2^2\\ge0
")

显然成立。

即，$P lr((1)) , P lr((2))$ 成立。

== 性质一

若 $P lr((n))$ 成立，则 $P lr((n - 1))$ 也成立。

记，

#mitex("
x_n={x_1+\\dots+x_{n-1}\\over n-1}
")

则 $P lr((n))$ 为，

#mitex("
x_1\\dots x_{n-1}\\cdot{x_1+\\dots+x_{n-1}\\over n-1}\\le\\left({x_1+\\dots+x_{n-1}\\over n-1}\\right)^n
")

即 $P lr((n - 1))$，

#mitex("
x_1\\dots x_{n-1}\\le\\left({x_1+\\dots+x_{n-1}\\over n-1}\\right)^{n-1}
")

Q.E.D.

== 性质二

若 $P lr((n))$ 成立，则 $P lr((2 n))$ 成立。

我们记第一个 $P lr((n))$ 为，

#mitex("
x_1\\dots x_n\\le\\left({x_1+\\dots+x_n\\over n}\\right)^n
")

同样的，记第二个 $P lr((n))$ 为，

#mitex("
x_{n+1}\\dots x_{2n}\\le\\left({x_{n+1}+\\dots+x_{2n}\\over n}\\right)^n
")

== 性质二

我们知道 $P lr((2))$ 是成立的，记

#mitex("
y_1=x_1\\dots x_n\\\\
y_2=x_{n+1}\\dots x_{2n}
")

对 $y_1 , y_2$ 应用 $P lr((2))$，

== 性质二

#mitex("
\\begin{aligned}
y_1y_2&\\le\\left({y_1+y_2\\over2}\\right)^2\\\\
x_1\\dots x_{2n}&\\le\\left(x_1\\dots x_n+x_{n+1}\\dots x_{2n}\\over2\\right)^2\\\\
&={(x_1\\dots x_n)^2+(x_{n+1}+x_{2n})^2+2x_1\\dots x_{2n}\\over4}\\\\
&={(x_1\\dots x_n)^2+(x_{n+1}+x_{2n})^2\\over2}\\\\
&\\le{(x_1+\\dots+x_n)^{2n}+(x_{n+1}+\\dots+x_{2n})^{2n}\\over(2n)^{2n}}\\\\
&\\le\\left({x_1+\\dots+x_{2n}\\over2n}\\right)^{2n}
\\end{aligned}
")

== 性质二

即，$P lr((2 n))$。

Q.E.D.

== 整理

根据，

#mitex("
P(1),P(2)\\\\
P(n)\\Rightarrow P(2n)\\\\
P(n)\\Rightarrow P(n-1)
")

我们可以知道，对于 $forall n in bb(N)^(\*)$，$P lr((n))$ 成立。

END.
