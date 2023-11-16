# Professional Skills Coursework 1 - Group 18 - GTest Version

This repository contains the first coursework for the Professional Skills course. The main file in this coursework is `gs.cpp`, a C++ programme that simulates the Gray-Scott model, a reaction-diffusion system.

# Brief Command Line to Build System and Run the Test

```bash
cmake -S . -B build
cmake --build build
cd build
ctest --verbose
```

## File Analysis: `gs.cpp`

The `gs.cpp` file is a C++ programme that simulates a reaction-diffusion system using the Gray-Scott model. The Gray-Scott model is a mathematical model that simulates the interaction of two chemical substances, U and V, under specific conditions.

### programme Structure

The programme is structured into several parts:

1. **Global Variables and Constants**: The programme starts by defining several global variables and constants that control the simulation parameters, such as the grid size, diffusion rates, feed rate, kill rate, and time step.

2. **Grid Initialization**: The `init()` function initializes the U and V grids. The U grid is initialized to 1.0 everywhere but the border, while the V grid is initialized to 0.0 everywhere except for a rectangular region in the middle, where it is initialized to a random value between 0.0 and 1.0. If the 'testFlag' has been activated, init function will also be the place where the three tests take place.

3. **VTK File Writing**: The `writeVTKFile()` function writes the current state of the V grid to a VTK file. This allows the simulation results to be visualized using a VTK viewer.

4. **Simulation Step**: The `simulateStep()` function performs one time step of the simulation. It calculates the next state of the U and V grids based on the current state and the Gray-Scott model equations.

5. **Threshold Counting**: The `countElementsAboveThreshold()` function counts the number of elements in the V grid that are above a certain threshold. This is used to measure the progress of the reaction.

6. **Main Function**: The `main()` function controls the overall flow of the programme. It initializes the grids, then enters a loop where it performs a simulation step and periodically writes the V grid to a VTK file. After the simulation is complete, it counts the number of elements in the V grid that are above a certain threshold and prints this value.

### Usage

The programme takes five (or six possibly) command-line arguments: the diffusion rates of U and V, the feed rate, the kill rate, and the threshold for counting elements in the V grid. It prints the progress of the simulation to the console and writes the state of the V grid to a VTK file every 1000 iterations. If user is not intended to perform a real simulation but instead want to test the sanity of input parameters and check if the building process works well, they can simply add a '-t' command before all input parameters, which will run the three tests in init function.

`./gs [-t test] <Du> <Dv> <F> <k> <threshold>`

## Building the Application Locally

To build this application locally, you need to follow these steps:

1. Ensure that you have CMake installed on your system. This programme requires CMake at least above version 3.14.

2. In the main directory input the command `cmake -S . -B build`. 
   *'-S' indicates the path to root directory of the CMake project to build. '-B' indicates the path to directory which CMake will use as the root of build directory.
    If the directory doesn't already exist CMake will make it.*

3. In the main directory input the command `cmake --build build`.
  *'--build <dir>' build a CMake-generated project binary tree.*

4. Navigate to the build directory. Input command like `cd build`.

5. Run the programme with the following command:
    `./gs <Du> <Dv> <F> <k> <threshold>`
   Or run a test with output. The former command will default the params with 0.14, 0.07, 0.03, 0.0648, 0.1 while the latter provides you with customization:
   `ctest --verbose` / `./gs -t <Du> <Dv> <F> <k> <threshold>`

## Explanation of the Verification Code

In the init function of `gs.cpp` file, we have implemented several tests to verify the correctness of the simulation. These functions include:

1. **Check that the type of the model parameters (F, k) matches that of the element type of the u and v vectors.**
This check is performed using the Googletest's ASSERT_TRUE. It ensures the statement that typeids of the model parameters F and k are the same as the type of the elements in the u and v vectors is true. This is crucial for the calculations in the simulation to work correctly.

2. **Check that the variables u and v are the same size.**
This check ensures that the u and v vectors, which represent the concentrations of the two chemicals in the simulation, are the same size using ASSERT_EQ. This is necessary for the simulation to work correctly, as the calculations involve element-wise operations on the u and v vectors.

3. **Check that the simulation produces the mathematically correct answer when u = 0 and v = 0.**
Directory 'test' includes two correct results of initial all-zero u and v after simulate 9999 times with Du=0.14, F=0.03, dt=0.06. This check runs the simulation for 9999 steps with the same params after setting u and v to zero. It then checks that the resulting values of u and v are the same as the two result files. This is a basic sanity check to ensure that the simulation is working correctly.
