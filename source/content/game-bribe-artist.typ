#import "lib.typ": *
#show: template

= Bribe Artist

#figure(caption: [Drawing by _Defixient_.], image(width: 100%, "bribe-artist-image.jpg"))

#figure(caption: [Drawing by _m0rgamma_.], image(width: 100%, "bribe-artist-image-2.png"))

_Bribe Artist_ is a funny browser game where you have 20 seconds to draw a fake dollar. It was made for a 7-day game jam.

/*
- I combined path-traced SDF geometry---used for effects---with rasterized triangular geometry---used for rigid objects.
- For physics I generate SDF representation of meshes.
- Instead of Phong, I implemented a modified version of the EON BRDF formula, which gives much better results.
- Everything is multi-threaded using a custom job scheduling system.

[itch](https://nik1oo.itch.io/the-blue-break)

---
## Wanda

![image](../../wanda.gif)
![image](../../wiggler.gif)

Enter-the-gungeon-inspired Bullet-hell game.
- High-quality ray-traced pre-rendered backgrounds.
- Point lights.
- Real geometric displacement mapping.
- Ray-traced reflections.
- Collision map generated from the geometry.
- Local co-op with mouse-and-keyboard versus controller.
- Custom SDF primitives for architectural elements.
- Screen-space effects: curvature-based outline, bloom, image-based glare.
- Skeletal animation.

---
## Bribe Artist

![image](../../bribe-artist.gif)

[itch](https://nik1oo.itch.io/bribe-artist)

---
## Bogwalker

![image](../../bogwalker.gif)

Logic puzzle game. It's like Minesweeper, but you can sense the mines from further away. I made this in 2 weeks.
- Randomly-generated levels.
- 4 difficulty settings.
- A beautiful water shader.

[itch](https://nik1oo.itch.io/bogwalker)
[github](https://github.com/nik1oo/bogwalker)

---
## Blade & Eye

![image](../../blade-and-eye.gif)

First-person golf-themed fantasy adventure game I made for a game jam. Iconoclastic controls. Hit watermelons to score points. It's a simple demo for a greater idea.

- Used Blender as a level editor.

[itch](https://nik1oo.itch.io/blade-and-eye)
*/