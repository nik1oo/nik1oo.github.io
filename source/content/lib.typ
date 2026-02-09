#let template(doc) = [
	#import "@preview/algo:0.3.6": algo, i, d, comment, code
	#set align(start)
	#set par(justify:true,leading:5pt,spacing:0.8em,first-line-indent:2em)
	#show math.equation: set text(font: "Cambria Math",size: 10pt)
	#show math.equation.where(block: true): set align(center)
	#set math.mat(delim: "[")
	#set text(fill:rgb("#303030"))
	#set text(font: "Book Antiqua", size: 10pt, spacing:150%)
	#show raw: set text(spacing:100%)
	#show heading: set align(left)
	#show heading: set text(font: "Book Antiqua")
	#show heading.where(level: 1): set text(size:24pt)
	#show heading.where(level: 2): set text(size:18pt)
	#show link: underline
	#set quote(block: true)
	#show quote: set text(style: "italic")
	#set table(inset: 2pt, stroke: stroke(paint: gray, thickness: 0.5pt), align: left)
	#counter(heading).update(0)
	#set list(indent: 16pt)
	#set enum(numbering: "(1)", indent: 16pt)
	#set terms(indent: 0pt)
	#set footnote.entry(indent: 0pt)
	#set image(scaling: "pixelated", width: 75%)
	#doc ]

