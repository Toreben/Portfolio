# RTv1
#### by mhervet and bnoyer

RTv1 is a raytracing project made at Le-101 school.

This are the rules for a correct RTv1 scene file, as we defined it.

## Rules of a correct RTv1 file :

 1. A valid scene must have at least a camera and a viewport, defined in this order.
 2.  All infos for an element of the scene must be present.
 3. Colors can either be formated as `#RRGGBBAA` or `0xRRGGBBAA`.
 4. No additionnal whitespaces are allowed, neither at the beginning nor at the end of a line.
 5. Comments are lines starting with a `#` character. Those lines are skipped. 
 6. Everything after the last `}` is ignored and considered as comments.
 7. Lines begins with tabulations, not spaces, take care of it if you copy/past the sample.
 
### /!\ NO ERROR ALLOWED, PLEASE CORRECT YOUR FILE TO HAVE A RESULT /!\

## Correct syntax for Rtv1 scene file :
N.B : Sphere direction is useless for RTv1, just leave its components at 0.
Viewport datas are the size of the window, in pixels.
Angles must be entered ind degres.

	scene :
	{
		view :
		{
			camera :
			{
				position = (double double double)
				angle on x = double
				angle on y = double
				distance = positive double
			}
			viewport :
			{
				height = positive integer
				width = positive integer
			}
			spot :
			{
				position = (double double double)
				intensity = positive double
				color = #RRGGBBAA
			}
		}
		objects :
		{
			sphere :
			{
				origin = (double double double)
				direction = (0 0 0)
				radius = positive double
				color = #RRGGBBAA
			}
			cone :
			{
				origin = (double double double)
				direction = (double double double)
				angle = double
				color = #RRGGBBAA
			}
			cylinder :
			{
				origin = (double double double)
				direction = (double double double)
				radius = positive double
				color = #RRGGBBAA
			}
			plane :
			{
				origin = (double double double)
				direction = (double double double)
				color = #RRGGBBAA
			}
		}
	}
### Important
#### /!\ IMPORTANT : EXPECT ERROR ON CASCADE IF A TYPE OF OBJECT IS INVALID /!\
Some errors are not clearly identified, whitespaces amongst others.
Unlike gcc, the program does not give advices to correct the errors.

## Run the project
To compile the project and run the project (only on MacOs)

	$> make
	$> ./rtv1 scene_path/scene_name

## Want a preview ?

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
*... or this...*

![...or this !](./screens/fun3?raw=true "Shadding 3")
*... or this !*
