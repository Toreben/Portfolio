

# Le 101 projects by bnoyer 
_This repo is a part of my work at Le-101 School._

All of those projects where made on a MacOs computer, but also most of them work on Ubuntu distributions.
Subjects of those four projects are in the [***subjects***](./subjects) directory, both in french and english for your convenience.

Summary :
- [Structure](#structure)
- [Projects](#projects)
	- [00 libft](#00-libft)
	- [01 fillit](#01-fillit)
	- [02 fdf](#02-fdf)
	- [03 fractol](#03-fractol)
	- [04 RTv1](#04-rtv1)
	- [06 Wolf3D](#06-wolf3d)

## Structure
All those projects have the same structure :
 - an autor file
 - a Makefile
 - includes folder
 - source folder
 - library folders if needed

Graphical projects **fdf** and  **fractol** are using the Minilibx graphical library (aka MLX), developed by Ol for 42 schools. MLX exists under two versions : a MacOs only, using AppKit and OpenGL frameworks, and an other one for Linux, using X11 library. Both projects have both sources, making them runnable on both OS (but work best on MacOs).
MLX for Linux is broken, so you might need to work the command twice to compile the project.

I added easter eggs  in the graphical projects, but they only work under MacOs, because of the use of the *afplay* command, only available on MacOs.

## Projects
In order to compile the projects, simply run the _make_ command at the  root of each of them.

### 00 libft
The *libft* project consists of reproducing some of the Standard C library. I added some function later.

### 01 fillit
The *fillit* project consists of filling the smallest square possible with tetriminos described in a file given in parameter of the program. Every tetrimonos are define by four sharps (*#*), and are included in a square of 4x4 characters. All the remaining characters must be dots (.).
To run the program, use ```./fillit file```

### 02 fdf
The *fdf* projects consists of graphically recreating the schematic representation of a raised ground. The height map is given in parameter. Each number on the map represents the height of this precise point. You can find already made maps in the **maps** folder.
To run the program, use ```./fdf map_to_draw [colorscheme]``` (ex : *./fdf maps/le-101.v1 "kouign amann"*)

Available colorschemes :
- **notum terram** -> classic map colors
- **le 101** -> le-101-school colorscheme (Default)
- **fire** -> fire-like color
- **paon pan pan** -> peacock-blue
- **rafletnaug** -> pink-orange colorscheme
- **kouign amann** -> butter-like colorscheme
 - **mars** ->	Mars inspired colorscheme

![Le-101-v1 map, with default colorscheme (Le-101)](./screen/fdf/01.png?raw=true "Le-101-v1 map, with default colorscheme (Le-101)")
*Le-101-v1 map, with default colorscheme (Le-101)*

![Mars map, with mars colorscheme](./screen/fdf/02.png?raw=true "Mars map, with mars colorscheme")
*Mars map, with mars colorscheme*

![France S map, with Notum Terram colorscheme](./screen/fdf/03.png?raw=true "France S map, with Notum Terram colorscheme")
*France S map, with Notum Terram colorscheme*

![France XXL map, with Notum Terram colorscheme](./screen/fdf/04.png?raw=true "France XXL map, with Notum Terram colorscheme")
*France XXL map, with Notum Terram colorscheme*

### 03 fractol
The *fractol* project consists of representing fractals on screen. My programs allows to draw Mandelbrot, Burning ship, and Mandelbrot's version of Julia fractals.
To run the program, use ```./fractol fractal``` (ex : *./fractol 1* or *./fractol Mandelbrot*)

Available fractals :
- **1 Mandelbrot**
- **2 Burning Ship**
- **3 Julia**

![Mandelbrot fractal, black to white color scheme, 50 iterations](./screen/fractol/01.png?raw=true "Mandelbrot fractal, black to white color scheme, 50 iterations")
*Mandelbrot fractal, black to white color scheme, 50 iterations*

![Mandelbrot fractal, mainly green colorscheme, 440 iterations](./screen/fractol/02.png?raw=true "Mandelbrot fractal, mainly green colorscheme, 440 iterations")
*Mandelbrot fractal, mainly green colorscheme, 440 iterations*

![Zoom on Mandelbrot fractal, mainly red colorscheme, 120 iterations](./screen/fractol/03.png?raw=true "Zoom on Mandelbrot fractal, mainly red colorscheme, 120 iterations")
*Zoom on Mandelbrot fractal, mainly red colorscheme, 120 iterations*

![Julia fractal, black to purple colorscheme, 140 iterations](./screen/fractol/04.png?raw=true "Julia fractal, black to purple colorscheme, 140 iterations")
*Julia fractal, black to purple colorscheme, 140 iterations*

![Julia fractal, black to purple colorscheme, 140 iterations (different parameter from the previous screenshot)](./screen/fractol/05.png?raw=true "Julia fractal, black to purple colorscheme, 140 iterations (different parameter from the previous screenshot)")
*Julia fractal, black to purple colorscheme, 140 iterations (different parameter from the previous screenshot)*

![Julia fractal, mainly cyan colorscheme, 1230 iteration (same center as the previous Julia screenshot)](./screen/fractol/06.png?raw=true "Julia fractal, mainly cyan colorscheme, 1230 iteration (same center as the previous Julia screenshot)")
*Julia fractal, mainly cyan colorscheme, 1230 iteration (same center as the previous Julia screenshot)*

![Zoom on the Burning Ship fractal, black to cyan colorscheme, 50 iterations](./screen/fractol/07.png?raw=true "Zoom on the Burning Ship fractal, black to cyan colorscheme, 50 iterations")
*Zoom on the Burning Ship fractal, black to cyan colorscheme, 50 iterations*

### 04 RTv1
RTv1, for _Raytracer version 1_, is a basic ray tracing program taking a scene in parameter, and renders the resulting ray-traced image. The program runs with the SDL2 framework, the sources for MacOS are at the root of the directory.
The file discribes the content of the scene, such as the camera position and orientation ; the window size ; point lights positions,  colors and intensities ; objects positions, directions, colors and size.
All the rules are discribed in the README of the project.
To run the program, use```./rtv1 scene_path/scene_file``` (ex : ***./rtv1 scn/pilliers***)

#### Want a preview ?

![One sphere and one cone](./screens/pap?raw=true "One sphere and one cone")
*One scene with two objects*

![The same scene as in the subject (almost)](./screens/sujet?raw=true "Same scene as in subject")
*The same scene as in the subject*

![Some pillars](./screens/pilliers?raw=true "Pillars")
*Some pillars*

![Same scene from a different point of view](./screens/pilliers2?raw=true "Pillars2")
*Same scene from a different point of view*

![Some cones](./screens/cones?raw=true "Cones")
*Some cones*

![Some cylinders](./screens/cylindres?raw=true "Cylinders")
*Some cylinders*

![Some spheres](./screens/spheres?raw=true "Spheres")
*Some spheres*

#### What append if we mess with the shadding operations ?
![This...](./screens/fun1?raw=true "Shadding 1")
*This...*

![...or this...](./screens/fun2?raw=true "Shadding 2")
*... ot this...

![...or this !](./screens/fun3?raw=true "Shadding 3")
*... ot this !*

### 05 RT
The logical continuity of the previous project, with more options, more objects...
Work in progress, my project is not available yet, put you can read the subject anyway.

### 06 Wolf3D
Work in progress, my project is not available yet, put you can read the subject anyway.
