# Gotham Night – Computer Graphics Project

A 2D Gotham City skyline drawn with OpenGL/GLUT in C++, with an animated police blimp sweeping its spotlight across the city.

### ▶ [Live demo](https://azwad-islam.github.io/Computer-Graphics-Project/)

The same `main.cpp` runs in the browser: it is compiled to WebAssembly with [Emscripten](https://emscripten.org/) and deployed to GitHub Pages on every push (see [`.github/workflows/pages.yml`](.github/workflows/pages.yml)).

## Features
- Buildings drawn from OpenGL polygons, quads and triangles with per-vertex color gradients
- Animated police blimp that moves back and forth using `glutTimerFunc` (~60 FPS)
- Spotlight that fades out using alpha blending
- Ellipse and circle drawing with trigonometric vertex generation

## Run on desktop (Windows)
1. Open `final Project.cbp` in Code::Blocks (MinGW + freeglut).
2. Build and run.

Linked libraries: `freeglut`, `opengl32`, `glu32`, `winmm`, `gdi32`.

## Build for the web
With the [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) installed:

```bash
emcc main.cpp -O2 -o dist/index.html --shell-file web/shell.html -sLEGACY_GL_EMULATION -sGL_UNSAFE_OPTS=0 -lglut -lGL -lGLU
```

Then serve the `dist` folder, for example with `python -m http.server -d dist`.
