Robot Project – Graphic Programming
Overview

This project is a 3D robot visualization and graphics programming assignment developed in C++ using OpenGL and Win32 APIs. The application demonstrates hierarchical modeling, transformations, lighting, texturing, camera controls, and interactive object manipulation within a custom-rendered 3D environment.

The robot is constructed from multiple independent components such as the head, body, arms, legs, shield, sword, and jetpack. These components are assembled using hierarchical transformations to create a complete articulated character.

In addition to the robot model, the project includes an Experimentation Station scene featuring textured structures, environmental objects, lighting effects, and user-controlled interactions.

Features
Robot Modeling
Hierarchical robot construction
Modular body part system
Head, body, arms, and legs modeled separately
Additional accessories:
Shield
Sword
Jetpack
Graphics Techniques
OpenGL immediate mode rendering
Hierarchical transformations
Translation, rotation, and scaling
Perspective and orthographic projection modes
Dynamic lighting
Shadow rendering
Texture mapping using BMP textures
Interactive Controls
Camera movement controls
Camera rotation controls
Object transformations
Keyboard input through DirectInput
Scene switching and object manipulation
Experimentation Station
Textured environment
Bridge and tower structures
Ship and sea elements
Lighting demonstrations
Interactive transformation testing
Technologies Used
Technology	Purpose
C++	Core application development
OpenGL	3D rendering
GLU	Utility rendering functions
Win32 API	Window creation and event handling
DirectInput	Keyboard and input management
Visual Studio	Development environment
Project Structure
RobotProjectGraphicProgramming/
│
├── Main.cpp
├── InputManager.cpp
├── InputManager.h
│
├── Robot.cpp
├── Robot.h
│
├── RobotPart.cpp
├── RobotPart.h
│
├── Head.cpp
├── Head.h
│
├── Body.cpp
├── Body.h
│
├── LeftArm.cpp
├── LeftArm.h
│
├── LeftLeg.cpp
├── LeftLeg.h
│
├── Shield.cpp
├── Shield.h
│
├── Sword.cpp
├── Sword.h
│
├── Jetpack.cpp
├── Jetpack.h
│
├── ExperimentationStation.cpp
├── ExperimentationStation.h
│
└── Texture Files (*.bmp)
Controls
Camera Controls
Key	Action
Numpad 8	Move Camera Up
Numpad 5	Move Camera Down
Numpad 4	Move Camera Left
Numpad 6	Move Camera Right
Numpad 7	Move Camera Forward
Numpad 1	Move Camera Backward
Scene Selection
Key	Action
1	Display Robot Scene
3	Display Experimentation Scene
Experimentation Station Controls
Key	Action
W / S	Move Up / Down
A / D	Move Left / Right
Q / E	Move Forward / Backward
T / G	Rotate Y Axis
F / H	Rotate X Axis
R / Y	Rotate Z Axis
I / K	Elbow Rotation Y
J / L	Elbow Rotation X
Graphics Concepts Demonstrated
Hierarchical Modeling

The robot is built using parent-child relationships. Transformations applied to parent components affect their children, allowing complex articulated movement.

Lighting

The project utilizes OpenGL lighting to simulate realistic illumination using:

Ambient light
Diffuse light
Light positioning
Texture Mapping

BMP textures are applied to robot components and environment objects to improve visual quality and realism.

Projection Modes

The application supports:

Perspective Projection
Orthographic Projection
Shadow Rendering

Shadow calculations are performed using projection matrices to create planar shadows on the scene.

Building the Project
Requirements
Microsoft Visual Studio
Windows Operating System
OpenGL
GLU
DirectX SDK (DirectInput)
Steps
Clone the repository:
git clone https://github.com/yourusername/RobotProjectGraphicProgramming.git
Open:
RobotProjectGraphicProgramming.sln
Build the solution in Visual Studio.
Run the project.
Learning Objectives

This project was developed to practice and demonstrate:

OpenGL rendering fundamentals
3D transformations
Hierarchical object modeling
Texture mapping
Lighting techniques
Shadow projection
Interactive graphics programming
Input handling using DirectInput
Author

Developed as part of a Graphics Programming / Computer Graphics coursework project using C++, OpenGL, and Win32 APIs.
