# ENFORCpp
Efficient Numerical Function Optimization for Robotics under Constraints (written in C++)

[![][badge-license]](https://creativecommons.org/licenses/by-nc/4.0/)
[![][badge-OS]](https://linuxmint.com/)
[![][badge-language]]()
[![][badge-cpu]]()

<!--[![Zenodo](https://zenodo.org/badge/doi/10.5281/zenodo.10332.png)](http://zenodo.org/record/10332)-->


Description
-------------
ENFORCpp is a C++ tool that allows you to solve nonlinear constrained optimization problems. The tool is designed with real-time considerations 
and is suitable for online trajectory and control input optimization, or any numerical problems. The proposed framework does not require any analytical representation 
of the problem and works with constrained block-box optimization functions. The method combines first-order gradient-based line search algorithms with 
constraint prioritization through nullspace projections onto constraint Jacobian space.

Usage
-------------
The usage of the library is quite straightforward. It requires users to write their own problem classes. Writing a problem class introduces many advantages, for example, 
you can define as many helper functions and parameters as you desire in a local environment. This is beneficial for complex problems and eliminates parameter name confusion in 
different scopes. A template problem description class is given inside the examples folder (examples/ProblemDescriptionTemplate.hpp) along with many different basic numerical and robotic system optimization problems.

Getting Help
------------
In case you encounter a problem or have a question, do not hesitate to open an issue. If you encounter a compilation problem, please be sure that your system satisfies the dependencies.

Feedback
------------
Feedback is always valuable. Hence, if you think some things could have been better, please open an issue and I will try to improve. 
Especially if you encounter a limitation that prevents you from implementing your optimization problem, please describe your optimization problem and the limitation that you encounter.

Installation
--------------------------------
### Dependencies
ENFORCpp uses the following tools:

 * [Git][] a source content management system
 * [Make][] a tool which controls the generation of executables and other non-source files
 * [CMake][] (>= 3.10) a build system
 * [Eigen][] (>= 3.4) C++ template library for linear algebra
 * [Gcc][] (>= 9.4)

For Ubuntu-based operating systems the dependency installation is simply:
```sh
sudo apt install git make cmake gcc g++ libeigen3-dev
```

### Install
No installation is required. Simply download the repository, include the headers, link the shared libraries, and compile for your optimization problem. Check the examples folder for the implementation examples.
You can simply edit the given examples for your problem. The library is tested in Ubuntu 20.04 and Linux Mint 21.3.

### Compile
Compiling the examples (with cmake):

```sh
git clone https://github.com/ssovukluk/ENFORCpp.git
cd ENFORCpp/examples && mkdir build && cd build
cmake ..
make
./basic        # runs the basic.cpp example that is linked with BasicProblemDescription.hpp
./rosenbrock   # runs the rosenbrock.cpp example that is linked with RosenbrockProblemDescription.hpp
./hs071        # runs the hs071.cpp example that is linked with HS071ProblemDescription.hpp
./arm          # runs the arm.cpp example that is linked with RoboticArmProblemDescription.hpp
```

Compiling the examples (without cmake):
```sh
g++ -I../include -std=C++20 -O3 -NDEBUG basic.cpp -o basic -L../lib -lNFO
g++ -I../include -std=C++20 -O3 -NDEBUG rosenbrock.cpp -o rosenbrock -L../lib -lNFO
g++ -I../include -std=C++20 -O3 -NDEBUG hs071.cpp -o hs071 -L../lib -lNFO
g++ -I../include -std=C++20 -O3 -NDEBUG arm.cpp -o arm -L../lib -lNFO
./basic        # runs the basic.cpp example that is linked with BasicProblemDescription.hpp
./rosenbrock   # runs the rosenbrock.cpp example that is linked with RosenbrockProblemDescription.hpp
./hs071        # runs the hs071.cpp example that is linked with HS071ProblemDescription.hpp
./arm          # runs the arm.cpp example that is linked with RoboticArmProblemDescription.hpp
```

Citing ENFORCpp
--------------------------------
In case you use ENFORCpp in your project, please consider citing our work and placing a star in the repository.

```bibtex
@misc{sovuklukENFORCpp,
   title={An Efficient Numerical Function Optimization Framework for Constrained Nonlinear Robotic Problems}, 
   author={Sait Sovukluk and Christian Ott},
   year={2025},
   eprint={2501.17349},
   archivePrefix={arXiv},
   primaryClass={cs.RO},
   url={https://arxiv.org/abs/2501.17349},
   doi={10.48550/arXiv.2501.17349}
}
```
And the following one for the link to the GitHub codebase:
```bibtex
@misc{ENFORCppWeb,
   author = {Sovukluk, Sait},
   title = {ENFORCpp: Efficient Numerical Function Optimization for Robotics under Constraints},
   howpublished = {https://github.com/ssovukluk/ENFORCpp},
   year = {2025}
}
```

License
--------------------------------
This project is licensed with [CC BY-NC 4.0](https://creativecommons.org/licenses/by-nc/4.0/). This license permits you to share (mirror) and adapt (borrow and alter) your mod content, providing that you give credit and don't use your work for commercial purposes.


[badge-license]: https://img.shields.io/badge/license-CC_BY--NC_4.0-green
[badge-OS]: https://img.shields.io/badge/OS-Linux-blue
[badge-language]: https://img.shields.io/badge/Language-C++-blue
[badge-cpu]: https://img.shields.io/badge/CPU-x64-blue

[CMake]: http://www.cmake.org/
[Make]: https://www.gnu.org/software/make/
[Eigen]: https://gitlab.com/libeigen/eigen/-/releases
[Git]: http://git-scm.com/
[Gcc]: https://gcc.gnu.org/
