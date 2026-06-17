[![License Apache--2.0](https://img.shields.io/badge/License-Apache--2.0-green?label=License)](https://github.com/Arm-Examples/AVH_CI_Template/blob/main/LICENSE)
[![Run Example](https://img.shields.io/github/actions/workflow/status/Arm-Examples/AVH_CI_Template/basic.yml?logo=arm&logoColor=0091bd&label=Run%20Example)](./.github/workflows/basic.yml)
[![Run Example and Report](https://img.shields.io/github/actions/workflow/status/Arm-Examples/AVH_CI_Template/basic_w_report.yml?logo=arm&logoColor=0091bd&label=Run%20Example%20and%20Report)](./.github/workflows/basic_w_report.yml)

# AVH CI Template

[<img src="https://github.com/Arm-Examples/.github/blob/main/profile/cicd_intro.png" alt="Introduction to CI/CD test automation" width="317" height="193" align="left">](https://developer.arm.com/-/media/arm%20developer%20community/videos/tools%20and%20software/keil%20mdk/cicd_webinar.mp4?#t=04:15
 "Introduction to CI/CD test automation")

This repository contains a **CI template for unit test automation** that uses [GitHub Actions](https://github.com/features/actions) on [GitHub-hosted runners](https://docs.github.com/en/actions/using-github-hosted-runners/about-github-hosted-runners/about-github-hosted-runners) with Ubuntu Linux. A report can optionally be generated using the [Unity test framework](https://github.com/MDK-Packs/Unity).

The tests run on [**Fixed Virtual Platforms (FVP) simulation models**](https://arm-software.github.io/AVH/main/simulation/html/index.html), which implement Cortex-M, Corstone, or Cortex-M/Ethos-U device subsystems. These simulation models are designed for software verification and testing. They enable simulation-based test automation for various software workloads, including unit tests, integration tests, and fault injection.

The tools used in this **CI template** are part of [Keil MDK Version 6](https://www.keil.arm.com/keil-mdk/). For evaluation purposes, the *MDK - Community Edition* can be used, but commercial usage requires a license for the *MDK - Professional Edition*.
Tool installation is managed with [vcpkg](https://www.keil.arm.com/artifacts/) using a [configuration file](./vcpkg-configuration.json), which helps ensure a consistent setup on desktop computers and in CI.

<br clear="left"/>

![CI Workflow explained: Create, debug, and test](https://github.com/Arm-Examples/.github/blob/main/profile/CICD_Overview.png "CI Workflow explained: Create, debug, and test")

## Usage

This template repository can be used as a starting point for validation projects. Click **Use this template - Create a new repository** to start your own CI test project.
> [!IMPORTANT]
> Log in with your GitHub account to enable the **Use this template - Create a new repository** button.

The [Project](Project) tests a single function (*my_sum*) using the [Unity test framework](https://github.com/MDK-Packs/Unity), which is available as a [CMSIS software pack](https://www.keil.arm.com/packs/unity-arm-packs). Users can modify the test cases to simulate an error and observe Unity test reporting.

> [!TIP]
> This video demonstrates the workflow: [Using CMSIS-Toolbox and Keil MDK v6 in CI/CD Workflows](https://developer.arm.com/-/media/arm%20developer%20community/videos/tools%20and%20software/keil%20mdk/cicd_webinar.mp4?#t=04:15 "Using CMSIS-Toolbox and Keil MDK v6 in CI/CD Workflows")

### Repository Structure

Directory                     | Content
:-----------------------------|----------
[.github/workflows](.github/workflows) | Workflow YML files that get you started with GitHub Actions for CMSIS projects.
[Project](Project)                     | A simple unit test application in [*csolution project format*](https://github.com/Open-CMSIS-Pack/cmsis-toolbox).

### GitHub

With GitHub Actions, two workflows are available:

- [basic.yml](.github/workflows/basic.yml) compiles and runs the application.
- [basic_w_report.yml](.github/workflows/basic_w_report.yml) compiles and runs the application; then generates a test report using [phoenix-actions/test-reporting](https://github.com/phoenix-actions/test-reporting).

Use the [*Actions*](/../../actions) view in the GitHub web interface to execute the *CI test run* and review *test results*.

### Desktop

**Prerequisite:**

- Install VS Code with [Arm Keil Studio Pack extensions](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack).
- Click **Use this template - Create a new repository** to create your own CI test flow in your GitHub account.

**Build:**

In VS Code:

- Open the *Source Control Activity Bar* and use *Clone Repository* to get the application on your local computer.
- Open *CMSIS Activity Bar* and *Build* the application.

> [!NOTE]
>
> When you open the project for the first time, the *Arm Tools Environment* managed with [vcpkg](https://www.keil.arm.com/artifacts/) is installed, which may take a few minutes.

**Run:**

In VS Code, open the *CMSIS Activity Bar* and *Run* the application.

**Debug:**

In VS Code, open the *CMSIS Activity Bar* and *Debug* the application.

## More CI Examples

Arm uses CI validation tests like this for many projects. Most CMSIS software components are validated with FVP simulation, as shown in the table below. You can explore [other projects with topic "cicd"](https://github.com/search?q=topic%3Acicd+org%3AArm-Examples+fork%3Atrue&type=repositories) or read **[CI/CD](https://github.com/Arm-Examples/.github/blob/main/profile/CICD.md)** to learn more. While this test uses [FVP simulation models](https://arm-software.github.io/AVH/main/simulation/html/index.html), you can also run tests on [hardware targets using a self-hosted runner](https://github.com/Arm-Examples/.github/blob/main/profile/RPI_GH_Runner.md).

Resource           | Description
:------------------|:------------------
[CMSIS Version 6](https://github.com/ARM-software/CMSIS_6/actions) | Runs a CMSIS-Core validation test across the supported processors using multiple compilers.
[RTOS2 Validation](https://github.com/ARM-software/CMSIS-RTX/actions) | Runs the CMSIS-RTOS2 validation across Keil RTX using source and library variants.
[STM32H743I-EVAL_BSP](https://github.com/Open-CMSIS-Pack/STM32H743I-EVAL_BSP) | Build test of a Board Support Pack (BSP) with MDK-Middleware [Reference Applications](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/ReferenceApplications.md) using Arm Compiler or GCC. The artifacts store the various example projects for testing on the hardware board.

## Other Developer Resources

Resource           | Description
:------------------|:------------------
[Documentation](https://arm-software.github.io/AVH/main/overview/html/index.html) | Comprehensive documentation for FVP simulation models.
[Support Forum](https://community.arm.com/support-forums/f/arm-virtual-hardware-targets-forum) | Arm Virtual Hardware is supported via a forum. Your feedback will influence future roadmap.
[AVH-MLOps](https://github.com/ARM-software/AVH-MLOps) | Shows the setup of a Docker container with foundation tools for CI and MLOps systems.

