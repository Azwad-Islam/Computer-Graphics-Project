# Gotham City – Computer Graphics Project

A 2D Gotham City night scene drawn with OpenGL/GLUT in C++, with Batman, the Bat-Signal and an animated police blimp sweeping its searchlight across the city.

### ▶ [Live demo](https://azwad-islam.github.io/Computer-Graphics-Project/)

The same `main.cpp` runs in the browser: it is compiled to WebAssembly with [Emscripten](https://emscripten.org/) and deployed to GitHub Pages on every push (see [`.github/workflows/pages.yml`](.github/workflows/pages.yml)).

## Features
- Gotham City at night: Wayne Tower, GCPD, the police building and a skyline of lit windows, drawn from OpenGL polygons, quads, triangles, lines and points
- Batman on a rooftop with the Bat-Signal in the sky
- Animated police blimp with a searchlight, moved with `glTranslatef` on a `glutTimerFunc` timer (~60 FPS)
- Keyboard and mouse controls
- Ellipse and circle drawing with trigonometric vertex generation

## Controls
| Input | Action |
| --- | --- |
| `B` | Toggle Batman, the Bat-Signal and the police blimp |
| `S` / `A` | Stop / start the blimp |
| `Z` / `X` | Move the blimp backward / forward |
| Left / right click | Speed up / slow down the blimp |

In the browser, click the scene first so it receives key presses.

## Run on desktop (Windows)
1. Open `final Project.cbp` in Code::Blocks (MinGW + freeglut).
2. Build and run.

Linked libraries: `freeglut`, `opengl32`, `glu32`, `winmm`, `gdi32`.

## Build for the web
With the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) installed:

```bash
emcc main.cpp -O2 -o dist/index.html --shell-file web/shell.html -DGL_GLEXT_PROTOTYPES -lglut -lGL -lGLU
```

Then serve the `dist` folder, for example with `python -m http.server -d dist`.
