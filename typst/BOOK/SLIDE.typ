#import "@preview/touying:0.3.2": *
#import "@preview/m-jaxon:0.1.1" as latex
#import "@preview/mitex:0.2.2": *

// Themes: default, simple, metropolis, dewdrop, university, aqua
#let s = themes.metropolis.register(aspect-ratio: "16-9")
#let s = (s.methods.info)(
  self: s,
  title: [Start Your Writing in Touying],
  subtitle: [Subtitle],
  author: [Author],
  date: datetime.today(),
  institution: [Institution],
)

#let (init, slides, touying-outline, alert) = utils.methods(s)
#show: init

#show strong: alert

#let (slide, title-slide, focus-slide) = utils.slides(s)
#show: slides

= The Section

== Slide Title

Slide content.

#mitex("
a+b=\sum\\nolimits_{a}^b
")

#latex.render("
a+b=\sum\\nolimits_{a}^b
")

可以使用 LaTeX 或者 MathJax 渲染。

== 下一周

没有啊

= 很好的

== 好好好

钉钉。

= 尾声

打扫卫生。