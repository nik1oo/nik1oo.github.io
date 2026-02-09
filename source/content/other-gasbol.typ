#import "lib.typ": *
#show: template

= Live Coding in Odin

#figure(caption: [Demo.], html.video(controls: true, width: 1280, height: 720, src: "gasbol-video.mp4"))

This is a prototype of a live coding environment for the _Odin_ programming language. It uses _Jupyter_ as front-end. It compiles cells on demand and loads them dynamically. It has custom directives that allow you to execute cells simultaneously.
