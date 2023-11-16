# Professional Skills Coursework 1 - Group 18 - Acutest Version

This repository contains the first coursework for the Professional Skills course. The main file in this coursework is `gs.cpp`, a C++ programme that simulates the Gray-Scott model, a reaction-diffusion system.

## File Analysis: `gs.cpp`

The `gs.cpp` file is a C++ programme that simulates a reaction-diffusion system using the Gray-Scott model. The Gray-Scott model is a mathematical model that simulates the interaction of two chemical substances, U and V, under specific conditions.

### programme Structure

The programme is structured into several parts:

1. **Global Variables and Constants**: The programme starts by defining several global variables and constants that control the simulation parameters, such as the grid size, diffusion rates, feed rate, kill rate, and time step.

2. **Grid Initialization**: The `init()` function initializes the U and V grids. The U grid is initialized to 1.0 everywhere but the border, while the V grid is initialized to 0.0 everywhere except for a rectangular region in the middle, where it is initialized to a random value between 0.0 and 1.0.

3. **VTK File Writing**: The `writeVTKFile()` function writes the current state of the V grid to a VTK file. This allows the simulation results to be visualized using a VTK viewer.

4. **Simulation Step**: The `simulateStep()` function performs one time step of the simulation. It calculates the next state of the U and V grids based on the current state and the Gray-Scott model equations.

5. **Threshold Counting**: The `countElementsAboveThreshold()` function counts the number of elements in the V grid that are above a certain threshold. This is used to measure the progress of the reaction.

6. **Main Function**: The `main()` function controls the overall flow of the programme. It initializes the grids, then enters a loop where it performs a simulation step and periodically writes the V grid to a VTK file. After the simulation is complete, it counts the number of elements in the V grid that are above a certain threshold and prints this value.
