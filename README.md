# Professional Skills Coursework 1 - Group 18 - BOOST Alt Version

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

### Usage

The programme takes five command-line arguments: the diffusion rates of U and V, the feed rate, the kill rate, and the threshold for counting elements in the V grid. It prints the progress of the simulation to the console and writes the state of the V grid to a VTK file every 1000 iterations.

`./gs.cpp <Du> <Dv> <F> <k> <threshold>`

## Building the Application Locally

To build this application locally, you need to follow these steps:

1. Ensure that you have a C++ compiler installed on your system. This programme requires a compiler that supports at least the C++11 standard.

2. Install the Boost library. You can download it from the Boost official website and follow their instructions for installation.

3. Clone the repository or download the source code.

4. Navigate to the directory containing the source code.

5. Compile the programme using the following command:

`g++ -std=c++11 -o gs *.cpp`

6. Run the programme with the following command:

`./gs <Du> <Dv> <F> <k> <threshold>`

## Explanation of the Verification Code

In the `checks.cpp` file, we have implemented several functions to verify the correctness of the simulation. These functions include:

1. **Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.**
This check is performed using the Boost library's type checking functions. It ensures that the types of the model parameters F and k are the same as the type of the elements in the u and v vectors. This is crucial for the calculations in the simulation to work correctly.

2. **Check that the variables u and v are the same size.**
This function ensures that the u and v vectors, which represent the concentrations of the two chemicals in the simulation, are the same size. This is necessary for the simulation to work correctly, as the calculations involve element-wise operations on the u and v vectors.

3. **Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.**
This function runs the simulation for one step after setting u and v to zero. It then checks that the resulting values of u and v are still zero. This is a basic sanity check to ensure that the simulation is working correctly. According to the Gray-Scott model equations, if u and v are both zero, they should remain zero after one simulation step.

## Explanation of the Tests
While the verification codes provide runtime checks these test perform unit tests via the Boosting framework. They check that specific functionalities of the Gray-Scott algorithm are working as intended and can be incorporated into a continuous integration. These have been split up into suitable units to make it easy to identify which part of the code has been broken.

1. **testGrayScottDiffusionZeroCase**
This test ensures that the simulation is working as intended in the case that u=0 and v=0 and is broken if the values returned are not within a small threshold around 0 as expected according to the Gray-Scott model equations.

2. **testInitialization**
This ensures that our variables are being initialized as expected that is both the types and size of our varibales match that required for the successful implementation of the algorithm.

3. **testSimulation**
testSimulation implements a loop over simulationStep() using a test case checking for type and size consistencies among the variables --still needs implementing>-- and also that the correct result is obtained.

4. **testCountElementsAboveThreshold**
Similarly testCountElementsAboveThreshold uses a test case ensuring that CountElementsAboveThreshold() gives the correct result.

## Implementation of the Tests
