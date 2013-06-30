SFML - GLSL - playground
========================

inspired by http://glsl.heroku.com/
Basically an offline version of the above (also supports tinkering with vertex 
shaders!)



## 0. Table of contents
 
 1. How to compile
   1.1 Necessary libraries
   1.2 For Windows
    1.2.1 Visual Studio project
    1.2.2 umm
   1.3 For Linux
   1.4 For what is possible

 2. How to run
   2.1 Keyboard shortcuts
 
 3. How to modify shaders
   3.1 How the vertices are positioned
   3.2 Variables accessible by GLSL
 4. Credits

## 1. How to compile

### 1.2 For Windows 

#### 1.2.1 Plan A.

Use the packaged Visual Studio 2012 project to compile. Its downfall is that it 
only runs with [Visual Studio 2012](http://www.microsoft.com/visualstudio/eng/downloads#d-express-windows-desktop).

#### 1.2.2 Plan B.

1. Follow [this guide](http://sfml-dev.org/tutorials/2.0/start-vc.php) for Visual
   Studio or [that guide](http://sfml-dev.org/tutorials/2.0/start-cb.php) for 
   Code::Blocks or mingw-gcc.

### 1.3 For Linux
 
1. Follow [this guide](http://sfml-dev.org/tutorials/2.0/start-linux.php) and 
   try to make sense of the makefile. Note however the makefile most likely does
   not work!

### 1.4 For whatever else

See if [anything here](http://sfml-dev.org/tutorials/2.0/) covers your compilation
needs.

## 2. How to run

1. Make sure there's a directory called 'shaders' next to the program containing 
  two files: `shader.frag` and `shader.vert`. Those two are the vertex and fragment
  shaders that will be executed. The syntax must be correct et cetera.

2. If it's compiled non-statically, check if the required SFML dll files exist. 

3. Run the executable!

### 2.1 Keyboard shortcuts

**F11** - Fullscreen (Not yet implemented fully)  
**Space** - Pause


## 3. How to modify shaders

The program has tried to replicate the environment of glsl.heroku.com as much as 
possible. The program will look for `shaders/shader.vert` and `shaders/shader.frag` 
as the shader files.

### 3.1 The vertices

The shaders are run onto a preset VertexArray(sf::TrianglesStrip) that contains
two triangles, the end points of which are as such: 

    (1): (WIDTH, 0) ; (0, 0) ; (WIDTH, HEIGHT) 
    (2): (0,0) ; (WIDTH, HEIGHT) ; (0, HEIGHT)

    Or, rather: 
      1-0
      |\|
      3-2

As such, they cover the entire surface area of the window. The shader window is 
the only GUI that the program has. Messages and output are written to a file
(stdout.txt).

### 3.2 The variables

The program exposes four variables to the script - the vertexes' texture,  the 
mouse position, the time in seconds (with decimals) and the width/height 
"resolution" of the screen. They should be accessed as such: 

    uniform shader2D texture; 
    uniform vec2 mouse; 
    uniform float time; 
    uniform vec2 resolution; 

Credits
=======

The Simple Fast Multimedia Library (C) 2007-2013 Laurent Gomila
(see sfml-license.txt)

This program (C) 2013 boxmein (MIT license below)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.