# Solar-System-Simlation-in-C
A graphical C program simulating the solar system with planets orbiting the Sun, including planet sizes, colors, and orbit paths, using the graphics.h library.
## Features
- Visual representation of the solar system with 2D orbits.  
- Planets colored distinctly and labeled.  
- Planetary motion using simple elliptical orbit calculations.  
- Background stars for a realistic space effect.  
- Adjustable planet sizes and speeds.  

## Limitations
- Uses `graphics.h` and `conio.h`, which are outdated and mostly supported in Turbo C/C++ environments, not modern compilers.  
- Simulation is 2D and does not reflect accurate 3D positions or planetary distances.  
- Orbits are simple ellipses, not scaled to real astronomical units.  
- No interactivity (e.g., zoom, pan, or info on planets).  
- Limited to pre-calculated orbits; cannot dynamically simulate gravity or physics.  

## Installation / Usage
1. Install Turbo C/C++ or any compatible compiler supporting `graphics.h`.  
2. Place the code in your project folder.  
3. Compile and run. Make sure the BGI graphics path is correctly set.  
