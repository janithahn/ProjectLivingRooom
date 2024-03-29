# 3D Living Room with OpenGL
### Computer Graphics Project
This is a Visual Studio 2019 OpenGL project written in C++ with the help of the following libraries and references. The project demonstrates a 3D living room with all the following features.
* 3D objects created with `glu` and `glut` functions as well as with using Blender(`.obj` files for the **couch**, **ceiling fan**, and the **table**).
* Lighting.
* Animation for the ceiling fan with two separate speed controls.
* Texture mapping.
* Geometrics Transformations.
* Camera and the projections.
* Keyboard functions to view the scene.

## Used Libraries
* [freeglut](http://prdownloads.sourceforge.net/freeglut/freeglut-3.0.0.tar.gz?download)
* [glew](https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0-win32.zip/download)
* [SOIL2](https://github.com/SpartanJ/SOIL2)
* [dirent](https://github.com/tronkko/dirent)

## Library Paths
* Linker:
$(SolutionDir)vendor\glew\lib;$(SolutionDir)vendor\freeglut\lib;$(SolutionDir)vendor\SOIL2\lib;$(SolutionDir)vendor\GL_files\lib;%(AdditionalLibraryDirectories)

* C/C++: $(SolutionDir)vendor\additional\Library\include;$(SolutionDir)vendor\glew\include;$(SolutionDir)vendor\freeglut\include;$(SolutionDir)vendor\SOIL2\include;$(SolutionDir)vendor\dirent\include;$(SolutionDir)vendor\GL_files\include;%(AdditionalIncludeDirectories)

* Change `Solution Platform` to `x86`, not `x64`.

## References 
* https://learnopengl.com/Getting-started/Textures
* [Loading 3D objects into OpenGL C++](https://github.com/WHKnightZ/OpenGL-Load-Model)

## Screenshots
![Living Room Screenshot](https://github.com/s16417/ProjectLivingRooom/blob/master/screenshots/Capture.PNG)




https://user-images.githubusercontent.com/64242868/152974897-3205afb8-ffc4-4000-945e-63043c9c0bf8.mp4

