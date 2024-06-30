#import "@preview/g-exam:0.3.0": *
#import "@preview/m-jaxon:0.1.1" as latex
#import "@preview/mitex:0.2.2": *

#set text(lang: "zh", region: "CN")

#show: g-exam.with(
  school: (
    name: "Sunrise Secondary School",
    logo: read("./logo.png", encoding: none),
  ),
  exam-info: (
    academic-period: "Academic year 2023/2024",
    academic-level: "1st Secondary Education",
    academic-subject: "Mathematics",
    number: "2nd Assessment 1st Exam",
    content: "Radicals and fractions",
    model: "Model A"
  ),
  show-studen-data: "first-page",
  show-grade-table: true,
  clarifications: "温馨提示：对对对。",
)

#g-question[Given the equation $x^n + y^n = z^n$ for $(x,y,z)$ and $n$ positive integers.] 
#g-subquestion(point:2)[For what values of $n$ is the statement in the previous question true?]
#v(1fr)
#g-subquestion(point:3)[For $n=2$ there's a theorem with a special name. What's that name?] 
#v(1fr)

#g-clarification[去。]

#pagebreak()

#g-subquestion[What famous mathematician had an elegant proof for this theorem but
there was not enough space in the margin to write it down?].
#v(1fr)

#g-question(point:5.5)[Prove that the real part of all non-trivial zeros of the function $zeta(z) "is" 1/2$].
#v(1fr)

