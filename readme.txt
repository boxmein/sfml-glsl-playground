SFML - GLSL - playground, inspired by http://glsl.heroku.com/
=============================================================

Basically an offline version of the above (also supports tinkering with vertex 
shaders!)



Table of contents
=================
 
 * How to compile
 * How to run
 * How to modify shaders
 * Credits

How to compile
==============

For Windows 
-----------

### Plan A. ###

Use the packaged Visual Studio 2012 project to compile. Its downfall is that it 
only runs with [Visual Studio 2012](http://www.microsoft.com/visualstudio/eng/downloads#d-express-windows-desktop).

### Plan B. ###

1. Follow [this guide](http://sfml-dev.org/tutorials/2.0/start-vc.php) for Visual
   Studio or [that guide](http://sfml-dev.org/tutorials/2.0/start-cb.php) for 
   Code::Blocks or mingw-gcc.

For Linux
---------
 
1. Follow [this guide](http://sfml-dev.org/tutorials/2.0/start-linux.php) and 
   try to make sense of the makefile.

For whatever else
-----------------

See if [anything here](http://sfml-dev.org/tutorials/2.0/) covers your compilation
needs.

How to run
==========

1. Make sure there's a directory called 'shaders' next to the program containing 
  two files: `shader.frag` and `shader.vert`. Those two are the vertex and fragment
  shaders that will be executed. The syntax must be correct et cetera.

2. If it's compiled non-statically, check if the required SFML dll files exist. 

3. Run the executable!

How to modify shaders
=====================

The vertices
------------

The program will look for `shaders/shader.vert` and `shaders/shader.frag` as the
shader files.

The shaders are run onto a preset VertexArray that contains two triangles, the 
end points of which are as such: 

    (1): (WIDTH, 0) ; (0, 0) ; (WIDTH, HEIGHT) 
    (2): (0,0) ; (WIDTH, HEIGHT) ; (0, HEIGHT)

As such, they cover the entire surface area of the window. The shader window is 
the only GUI that the program has. Messages and output are written to a file
(stdout.txt).

The variables
-------------

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