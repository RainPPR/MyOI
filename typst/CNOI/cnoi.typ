#import "./cnoi-template.typ": *
#import "@preview/m-jaxon:0.1.1" as latex
#import "@preview/mitex:0.2.2": *

#let prob-list = (
  (
    name: "A + B Problem",
    name-en: "add",
    time-limit: "1000 ms",
    memory-limit: "512 MiB",
    test-case-count: "20",
  ),
  (
    name: "A × B Problem",
    name-en: "mul",
    type: "提交答案型",
    time-limit: "500 ms",
    memory-limit: "512 MiB",
    test-case-equal: "否",
    submit-file-name: "test.out",
  )
)

#let contest-info = (
  name: "某某某竞赛",
  name-en: "PPR CSP-J 2024",
  author: "RainPPR",
  time: "时间：2023 年 7 月 24 日 08:00 ~ 13:00"
)

#let (init, title, problem-table, next-problem, filename, current-filename, current-sample-filename, data-constraints-table-args) = document-class(contest-info, prob-list)

#show: init

#title()

#problem-table(
  extra-rows:(
    year: (
      name: "年份",
      wrap: text,
      always-display: true,
      default: "2023"
    ),
    contest: (
      name: "赛事",
      default: "NOI"
    ),
    setter: (
      name: "出题人",
      default: p => { p.name-en + "的出题人" }
    )
  ),
  languages:(
    ("C++", "cpp"),
    ("Python", "py"),
  ),
  compile-options: (
    ("C++", "-O2 -std=c++14 -DOFFLINE_JUDGE"),
  )
)

*注意事项（请仔细阅读）*

+ 文件名（程序名和输入输出文件名）必须使用英文小写。
+ `C++` 中函数 `main()` 的返回值类型必须是 int，程序正常结束时的返回值必须是 0。
+ 若无特殊说明，结果的比较方式为全文比较（过滤行末空格及文末回车）。
+ 程序可使用的栈空间内存限制与题目的内存限制一致。
+ 选手不得使用内嵌汇编，`#pragma` 等指令。

#next-problem()

== 题目描述

输入两个*整数* $a,b$，输出他们的和。

== 输入格式

从文件 #current-filename("in") 中读入数据。

两个以空格分开的整数。

== 输出格式

输出到文件 #filename("add.out") 中。

一个整数，表示 #mi("a+b")。

== 样例 1 输入

#raw(read("add1.in"), block: true)

== 样例 1 输出

```text
50
```

== 样例 1 解释

#mitex("
20+30=50
")

== 数据范围

对于所有测试数据保证：$|a|,|b|<=10^9$。

#figure(
  table(
    columns: 4,
    ..data-constraints-table-args,
    table.header( "测试点编号", $a,b <=$, $a+b <=$, "特殊性质" ),
    $1 tilde 5$, $300$, $300$, table.cell(rowspan:2)[无],
    $6 tilde 9$, table.cell(rowspan:4)[$10^5$], $2000$,
    $10 tilde 13$,  table.cell(rowspan:4)[$10^9$], [A],
    $14 tilde 17$, [B],
    $18 tilde 19$, table.cell(rowspan:2)[无],
    $20$, $10^9$,
  )
)

特殊性质 A: 你可以像上面这样创建复杂的表格。

#next-problem()

== 题目背景

*这是一道提交答案题。*

== 题目描述

#lorem(50)

== 评分标准

#lorem(50)

#lorem(100)

== 数据范围

#lorem(50)
