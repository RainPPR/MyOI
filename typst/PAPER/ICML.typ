#import "@preview/lucky-icml:0.2.1": *
#import "@preview/m-jaxon:0.1.1" as latex
#import "@preview/mitex:0.2.2": *

#let affls = (
  airi: ("AIRI", "Moscow", "Russia"),
  skoltech: (
    department: "AI Center",
    institution: "Skoltech",
    location: "Moscow",
    country: "Russia",
    ),
)

#let authors = (
  (name: "Firstname1 Lastname1",
   affl: ("skoltech"),
   email: "author@example.org",
   equal: true),
  (name: "Firstname1 Lastname1", affl: ("airi", "skoltech"), equal: true),
)

#show: icml2024.with(
  title: [
    Submission and Formatting Instructions for \
    International Conference on Machine Learning (ICML 2024)
  ],
  authors: (authors, affls),
  keywords: ("Machine Learning", "ICML"),
  abstract: [
    This document provides a basic paper template and submission guidelines.
    Abstracts must be a single paragraph, ideally between 4–6 sentences long.
    Gross violations will trigger corrections at the camera-ready phase.
  ],
  bibliography: bibliography("refs.bib"),
  header: [Submission and Formatting Instructions for ICML 2024],
  appendix: include "appendix.typ",
  accepted: false,
)

#vruler(offset: -1.7in)

= Introduction
Scientific writing is a crucial part of the research process, allowing researchers to share their findings with the wider scientific community. However, the process of typesetting scientific documents can often be a frustrating and time-consuming affair, particularly when using outdated tools such as LaTeX. Despite being over 30 years old, it remains a popular choice for scientific writing due to its power and flexibility. However, it also comes with a steep learning curve, complex syntax, and long compile times, leading to frustration and despair for many researchers. @netwok2020

== Paper overview
In this paper we introduce Typst, a new typesetting system designed to streamline the scientific writing process and provide researchers with a fast, efficient, and easy-to-use alternative to existing systems. Our goal is to shake up the status quo and offer researchers a better way to approach scientific writing.

By leveraging advanced algorithms and a user-friendly interface, Typst offers several advantages over existing typesetting systems, including faster document creation, simplified syntax, and increased ease-of-use.

To demonstrate the potential of Typst, we conducted a series of experiments comparing it to other popular typesetting systems, including LaTeX. Our findings suggest that Typst offers several benefits for scientific writing, particularly for novice users who may struggle with the complexities of LaTeX. Additionally, we demonstrate that Typst offers advanced features for experienced users, allowing for greater customization and flexibility in document creation.

Overall, we believe that Typst represents a significant step forward in the field of scientific writing and typesetting, providing researchers with a valuable tool to streamline their workflow and focus on what really matters: their research. In the following sections, we will introduce Typst in more detail and provide evidence for its superiority over other typesetting systems in a variety of scenarios.

= Methods
#lorem(90)

$ a + b = gamma $

#lorem(200)
