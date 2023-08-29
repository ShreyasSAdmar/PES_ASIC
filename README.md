# VLSI Physical Design for ASICs

## Objective
The objective of VLSI (Very Large Scale Integration) physical design for ASICs (Application-Specific Integrated Circuits) is to transform a logical design description (RTL - Register Transfer Level) into a physical layout that can be fabricated as an integrated circuit. This involves translating the high-level functional representation of the circuit into a physical implementation that meets design constraints, performance targets, and manufacturability requirements.This process ensures the circuit's functionality aligns with design constraints, performance goals and manufacturing standards.

## SKILL OUTCOMES


+ Architectural Design
+ RTL Design / Behavioral Modeling
+ Floorplanning
+ Placement
+ Clock Tree Synthesis
+ Routing

## INSTALLATION

To get started with the VLSI Physical Design for ASICs workshop, follow these steps for the installation of required tools:

<details>
<summary> Riscv_toolchain Installation </summary>
	
1. Download the `run.sh` script from the [GitHub repository](https://github.com/kunalg123/riscv_workshop_collaterals/blob/master/run.sh).

2. Open a terminal on your system.

3. Navigate to the directory where you downloaded the `run.sh` script. For example, if it's in your Downloads folder, use the following command:

    ```sh
    cd Downloads
    ```

4. Execute the script by running the following command:

    ```sh
    ./run.sh
    ```

This will initiate the installation process and set up the necessary environment for the workshop.
</details>
<details>
<summary> Yosys with GTKwave Installation </summary>
	
+ `cd`
+ `git clone https://github.com/YosysHQ/yosys.git`
+ `cd yosys`
+ `sudo apt install make`
+ `sudo apt-get update`
+ `sudo apt-get install build-essential clang bison flex  libreadline-dev gawk tcl-dev libffi-dev git  graphviz xdot pkg-config python3 libboost-system-dev libboost-python-dev libboost-filesystem-dev zlib1g-dev`
+ `make config-gcc`
+ `make`
+ `sudo make install`
+ `sudo apt install gtkwave`
+ Type `yosys`
  
  <img width="358" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/40f2b0a2-e37a-4a25-bd30-d24f1f41dbb5">
  
  If received as shown above, installation is successful.

    ### End of installation
</details>

# TABLE OF CONTENTS

<details>
<summary>DAY 1 </summary>
<br>

	
## DAY 1 
**Introduction to RISCV ISA and GNU Compiler Toolchain**
+ Introduction to Basic Keywords
  - [Introduction](#introduction)
  - [From Apps to Hardware](#from-apps-to-hardware)
  - [Detail Description of Course Content](#detail-description-of-course-content)

+ Labwork for RISCV Toolchain
  - [C Program](#c-program)
  - [RISCV GCC Compiler and Dissemble](#riscv-gcc-compiler-and-dissemble)
  - [Spike Simulation and Debug](#spike-simulation-and-debug)

+ Integer Number Representation  
  - [64-bit Unsigned Numbers](#64-bit-unsigned-numbers)
  - [64-bit Signed Numbers](#64-bit-signed-numbers)
  - [Labwork For Signed and Unsigned Numbers](#labwork-for-signed-and-unsigned-numbers)

# Introduction to Basic Keywords
## Introduction
- **ISA (Instruction Set Archhitecture)**
  - ISA defines the interface between a computer's hardware and its software, specifically how the processor and its components interact with the software instructions that drive the execution of tasks.
  - It encompasses a set of instructions, addressing modes, data types, registers, memory organization, and the mechanisms for executing and managing instructions.

- **RISC-V (Reduced Instruction Set Computing - Five)(https://www.riscv.org/)**.
  - It is an open-source Instruction Set Architecture (ISA) that has gained significant attention and adoption in the world of computer architecture and semiconductor design.
  - RISC architectures simplify the instruction set by focusing on a smaller set of instructions, each of which can be executed in a single clock cycle. This approach usually leads to faster execution of individual instructions. 

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/a8915f6d-38e4-4339-8729-8b407817ddde)


## From Apps to Hardware
1. **Apps:** Application software, often referred to simply as "applications" or "apps," is a type of computer software that is designed to perform specific tasks or functions for end-users.
   
2. **System software:** System software refers to a category of computer software that acts as an intermediary between the hardware components of a computer system and the user-facing application software. It provides essential services, manages hardware resources, and enables the execution of application programs. System software plays a critical role in maintaining the overall functionality, security, and performance of a computer system.'

3. **Operating System:** The operating system is a fundamental piece of software that manages hardware resources and provides various services for both users and application programs. It controls tasks such as memory management, process scheduling, file system management, and user interface interaction. Examples of operating systems include Microsoft Windows, macOS, Linux, and Android.

4. **Compiler:** A compiler is a type of software tool that translates high-level programming code written by developers into assembly-level language.

5. **Assembler:** An assembler is a software tool that translates assembly language code into machine code or binary code that can be directly executed by a computer's processor.

6. **RTL:** RTL serves as an abstraction level in the design process that represents the behavior of a digital circuit in terms of registers and the operations that transfer data between them.

7. **Hardware:** Hardware refers to the physical components of a computer system or any electronic device. It encompasses all the tangible parts that make up a computing or electronic device and enable it to perform various tasks.

## Detail Description of Course Content

**Pseudo Instructions:** Pseudo-instructions are used to simplify programming, improve code readability, and reduce the number of explicit instructions a programmer needs to write. They are especially useful for common programming patterns that involve multiple instructions.
`Ex: li, mv`.

**Base Integer Instructions:** The term "base integer instructions" refers to the fundamental set of instructions that form the foundation for performing basic arithmetic, logical, and data movement operations.
`Ex: add, sub, and, or, xor, sll`.

**Multiply Extension Intructions:** The RISC-V architecture includes a set of multiply and multiply-accumulate (MAC) extension instructions that enhance the instruction set to perform efficient multiplication and multiplication-accumulate operations.
`Ex: mul, mulh, mulhu, mulhsu`.

**Single and Double Precision Floating Point Extension:** The RISC-V architecture includes floating-point extensions that provide support for both single-precision (32-bit) and double-precision (64-bit) floating-point arithmetic operations. These extensions are often referred to as the "F" and "D" extensions, respectively. Floating-point arithmetic is essential for handling real numbers with fractional parts and for performing accurate calculations involving decimal values.

**Application Binary Interface:** ABI stands for "Application Binary Interface." It is a set of rules and conventions that govern how software components interact with each other at the binary level. The ABI defines various aspects of program execution, including how function calls are made, how parameters are passed and returned, how memory is allocated and managed, and more.

**Memory Allocation and Stack Pointer** 
- Memory allocation refers to the process of assigning and managing memory segments for various data structures, variables, and objects used by a program. It involves allocating memory space from the system's memory pool and releasing it when it is no longer needed to prevent memory leaks.
- The stack pointer is a register used by a program to keep track of the current position of the program's execution on the call stack. 

# Labwork for RISCV Toolchain
## C Program
+ C program to compute sum of first n numbers using leafpad text editor.

`leafpad sum1ton.c`
``` c
#include<stdio.h>

int main()
{
        int i,sum =0, n;
	printf("Enter value of n = \t");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		sum = sum + i;
	}
	printf("Sum of numbers from 1 to %d is %d \n",n,sum);
	return 0;
}
```

 + The program is compiled using the following commands.
     ```sh
       gcc sumton.c
    ```
     ``` sh
   .\a.out
     ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/8b129102-4e2b-49dd-97d9-d280df397cac)

## RISCV GCC Compiler and Dissemble

+ To compile the C program using the riscv compiler, the following command is used.

  ```sh
  riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
  ```

+ Using the following command
  ```sh
  ls -ltr sum1ton.c
  ```
   we can check that the object file is created.

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/708b149d-35f3-49c7-9437-69da6d298fe6)


+ To get the dissembled ALP code for the C program, the following command is used.

  ```sh
   riscv64-unknown-elf-objdump -d sum1ton.o | less
  ```

+ In order to view the main section, type
  ```sh
  /main
  ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/f53759e7-e001-4167-9d6d-139b4004a4cf)

+ To count the number of instructions, subtract the next address (0x1ec) from main adress(0x184) and divide by four (byte addressed).

Here, since we used -O1 optimisation, the number of instructions are 26.

When we use -Ofast optimisation, the number of instructions have been reduced to 24.

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/56990654-3710-4d3c-968a-814ba229d316)

- -Onumber : level of optimisation required
- -mabi : specifies the ABI (Application Binary Interface) to be used during code generation according to the requirements
- -march : specifies target architecture

In order to view the different options available for these fields, use the following commands

go to the directory where riscv64-unkonwn-elf is present

- -O1 : ``` riscv64-unkonwn-elf --help=optimizer```
- -mabi : ```riscv64-unknown-elf-gcc --target-help```
- -march : ```riscv64-unknown-elf-gcc --target-help```

For different instances,
- use the command ```riscv64-unknown-elf-objdump -d 1_to_N.o | less```
- use ``` /instance``` to search for an instance 
- press ENTER
- press ```n``` to search next occurance
- press ```N``` to search for previous occurance. 
- use ```esc :q``` to quit


## Spike Simulation and Debug

+ ```sh
  spike pk sum1ton.o
  ```
  is used to run the assembly code, tocheck whether the instructions produced are right to give the correct output.

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/74178c2d-c14c-443b-af6a-9dec4a5f276f)


+ ```sh
  spike -d pk sum1ton.o
  ```
  is used for debugging.

+ Some commands for debugging:

- `until pc 0 100b0` is used to run all the instructions till the instruction at 100b0 , here main.
- press ENTER to run the instructions line by line.
- `reg 0 a2`  to check content of register a2 0th core
- q : to quit the debug process

# Integer Number Representation 

## 64-Bit Unsigned Numbers
- Unsigned numbers, also known as non-negative numbers, are numerical values that represent magnitudes without indicating direction or sign.
- Range: [0, (2^n)-1 ]

## 64-Bit Signed Numbers
- Signed numbers are numerical values that can represent both positive and negative magnitudes, along with zero.
- Range : Positive : [0 , 2^(n-1)-1]
          Negative : [-1 to 2^(n-1)]
 
## Labwork For Signed and Unsigned Numbers

+ C program to return the maximum and minimum values of 64bit unsigned numbers.

`unsigned.c`

``` c
#include <stdio.h>
#include <math.h>

int main(){
	unsigned long long int max = (unsigned long long int) (pow(2,64) -1);
	unsigned long long int min = (unsigned long long int) (pow(2,64) *(-1));
	printf("Smallest number represented by unsigned 64-bit integer = %llu\n",min);
	printf("Biggest number represented by unsigned 64-bit integer = %llu\n",max);
	return 0;
}
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/f309500b-e718-42e0-b422-637a2d4d0405)



+ C program to return the maximum and minimum values of 64bit signed numbers.
  
`signed.c`

``` c
#include <stdio.h>
#include <math.h>

int main(){
	long long int max = (long long int) (pow(2,63) -1);
	long long int min = (long long int) (pow(2,63) *(-1));
	printf("Smallest number represented by signed 64-bit integer is %lld\n",min);
	printf("Largest number represented by signed 64-bit integer is %lld\n",max);
	return 0;
}
}
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/eb0403ad-4b3c-4bd0-a84f-beb5d1467c46)
</details>

<details>
<summary>DAY 2 </summary>
<br>
	
## DAY 2 
**Introduction to ABI and Basic Verification Flow**
+ Application Binary Interface
  - [Introduction to ABI](#introduction-to-abi)
  - [Memory Allocation for Double Words](#memory-allocation-for-double-words)
  - [Load Add and Store Instructions](#load-add-and-store-instructions)
  - [32-Registers and their ABI Names](#32-registers-and-their-abi-names)

+ Labwork using ABI Function Calls
  - [Algorithm for C Program using ASM](#algorithm-for-c-program-using-asm)
  - [Review ASM Function Calls](#review-asm-function-calls)
  - [Simulate C Program using Function Call](#simulate-c-program-using-function-call)

+ Basic Verification Flow using iverilog
  - [Lab to run C Program on RISC-V CPU](#lab-to-run-c-program-on-risc-v-cpu) 

# Application Binary Interface

## Introduction to ABI

+ An Application Binary Interface (ABI) is a set of rules and conventions that dictate how binary code interacts with and communicates with other binary code, typically at the level of machine code or compiled code. In simpler terms, it defines the interface between two software components or systems that are written in different programming languages, compiled by different compilers, or running on different hardware architectures.
+ The ABI is crucial for enabling interoperability between different software components, such as different libraries, object files, or even entire programs. It allows components compiled independently and potentially on different platforms to work seamlessly together by adhering to a common set of rules for communication and data representation.
  
## Memory Allocation for Double Words

64-bit number (or any multi-byte value) can be loaded into memory in little-endian or big-endian. It involves understanding the byte order and arranging the bytes accordingly
1. **Little-Endian:**
In little-endian representation, you store the least significant byte (LSB) at the lowest memory address and the most significant byte (MSB) at the highest memory address.

2. **Big-Endian:**
In big-endian representation, you store the most significant byte (MSB) at the lowest memory address and the least significant byte (LSB) at the highest memory address.

#### For example, consider the 64-bit hexadecimal value 0x0123456789ABCDEF. 
+ In Little-Endian representation, it would be stored as follows in memory:

<img width="454" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/03377ed7-b513-4573-9eac-947e761b7fec">

+ In Big-Endian representation, it would be stored as follows in memory:

<img width="454" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9a88bbcd-1a1d-465d-89da-33eeefcf397c">

+ Comparision:
  
<img width="454" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/a8230e0f-86ef-4674-a4a3-0ac16a9275a9">


## Load Add and Store Instructions

Load, Add, and Store instructions are fundamental operations in computer architecture and assembly programming. They are often used to manipulate data within a computer's memory and registers.
1. **Load Instructions:**
Load instructions are used to transfer data from memory to registers. They allow you to fetch data from a specified memory address and place it into a register for further processing.

Example `ld x6, 8(x5)`

In this Example
- `ld` is the load double-word instruction.
- `x6` is the destination register.
- `8(x5)` is the memory address pointed to by register `x5` (base address + offset).
  
2. **Store Instructions:**
Store instructions are used to write data from registers into memory.They store values from registers into memory addresses

Example `sd x8, 8(x9)`

In this Example
- `sd` is the store double-word instruction.
- `x8` is the source register.
- `8(x9)` is the memory address pointed to by register `x9` (base address + offset).

3. Add Instructions:
  Add instructions are used to perform addition operations on registers. They add the values of two source registers and store the result in a destination register.

Example `add x9, x10, x11`

In this Example
- `add` is the add instruction.
- `x9` is the destination register.
- `x10` and `x11` are the source registers.

<img width="430" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ca248b1e-2374-4b3d-8db2-81c55949671a">
  

## 32-Registers and their ABI Names

The choice of the number of registers in a processor's architecture, such as the RISC-V RV64 architecture with its 32 general-purpose registers, involves a trade-off between various factors. While modern processors can have more registers but increasing the number of registers could lead to larger instructions, which would take up more memory and potentially slow down instruction fetch and decode.
#### ABI Names
ABI names for registers serve as a standardized way to designate the purpose and usage of specific registers within a software ecosystem. These names play a critical role in maintaining compatibility, optimizing code generation, and facilitating communication between different software components. 

<img width="430" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/7cacd6c6-c1c6-40a4-a1af-1c686662bc34">

# Labwork using ABI Function Calls

## Algorithm for C Program using ASM

- Incorporating assembly language code into a C program can be done using inline assembly or by linking separate assembly files with your C code.
- When you call an assembly function from your C code, the C calling convention is followed, including pushing arguments onto the stack or passing them in registers as required.
- The program executes the assembly function, following the assembly instructions you've provided.

  <img width="430" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/60608708-b7b9-4e50-a265-d7cf1151d85d">

## Review ASM Function Calls
- We wrote C code in one file and your assembly code in a separate file.
- In the assembly file, we declared assembly functions with appropriate signatures that match the calling conventions of your platform.

**C Program**
`1tonmod.c`
  ``` c
  #include <stdio.h>
  
extern int load(int x, int y);
  
int main()
{
	int count,result = 0;
	printf("Enter value of  n : \t");
	scanf("%d",&count);
    	result = load(0x0, count+1);
	printf("Sum of numbers from 1 to %d is %d\n",count, result);
}
```
**Asseembly File**
`load.s`
``` s
.section .text
.global load
.type load, @function

load:	add a4, a0, zero
	add a2, a0, a1
	add a3, a0, zero

loop:	add a4, a3, a4
	addi a3, a3, 1
	blt a3, a2, loop
	add a0, a4, zero
	ret
```
<img width="430" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/d13a3a8c-096c-42a5-afef-d2e148559a40">

## Simulate C Program using Function Call

**Compilation and Execution:** 
+ To compile C code and Asseembly file use the command
```sh
`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o 1tonmod.o 1tonmod.c load.s` 
```

+this would generate object file `1tonmod.o`.

+ To execute the object file run the command 

```sh
spike pk 1tonmod.o
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/f19cd29c-f487-4cb8-acd6-6434884ce923)

+ For the assembly code, use the command 
```sh
riscv64-unknown-elf-objdump -d 1tonmod.o |less
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/e76f4e4e-f35c-4bac-a6ca-f269b90b5c36)

# Basic Verification Flow using iverilog

## Lab to run C Program on RISC-V CPU

 - RISC-V CPU is written in verilog
 - C Program is converted to hex file and loaded in memoery
 - Memory is read by the CPU and processes its contents
 - Output is displayed by CPU

 <img width="454" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/7a457416-45d3-4812-b397-1eec2cc289f8">
   

+ Type the following command in the terminal to download some basic labs
```sh
git clone https://github.com/kunalg123/riscv_workshop_collaterals.git
```

+ Move to risv_workshop_collaterals directory using `cd riscv_workshop_collaterals`
+ The command `ls -ltr` lists the files in the directory.
+ Move to labs using `cd labs`
+ "picorv32.v" is one of the risc-v CPU's. Use `vim picorv32.v` or `less picorv32.v` to open it to see the verilog codes. Press q to quit.

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9aada571-356d-4cea-841e-c7ff2eb6361c)

+ Use `vim testbench.v` to look at the testbench
+ To run use the following command
  ```sh
  chmod 777 rv32im.sh
  ./rv32im.sh
  ```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6ef87618-6a71-433d-8de2-38c51a9976e7)

+ Type `ls -ltr` and then `vim firmware.hex` command to see the hex file created.
+ `vim firmware32.hex` to look at the bitstream.
  
</details>


<details>
<summary>DAY 3 </summary>
<br>

	
## DAY 3
 **Introduction to Verilog RTL design and Synthesis**
+ Introduction to Open-Source Simulator iVerilog
   - [Introduction to iVerilog Design Testbench](#introduction-to-iverilog-design-testbench)
+ Labs using iVerilog and GTKwave
   - [Introduction to Lab](#introduction-to-lab)
   - [Introduction to iVerilog GTKwave](#introduction-to-iverilog-gtkwave)
+ Introduction to Yosys and Logic synthesis
   - [Introduction to Yosys](#introduction-to-yosys)
   - [Introduction to Logic Synthesis](#introduction-to-logic-synthesis)
+ Labs using Yosys and Sky130 PDKs
   - [Yosys good_mux](#yosys-good_mux)

# Introduction to Open-Source Simulator iVerilog
## Introduction to iVerilog Design Testbench 

- **Simulator**
   - It is a tool used for checking/simulating the design. It looks for the changes in the value of input.
   - Upon a change to the input  the output is evaluated.No change in the inputs => no change in the outputs.
   - The tool used here is **iverilog** .

- **iVerilog**
  -  It is an open-source Verilog simulator used for testing and simulating digital circuit designs described in the Verilog hardware description language (HDL).
  -  Both the design and the testbench are fed to the simulator and it produces a vcd (value change dump) file.
  -  In order to view the vcd file, we use the GTKwave tool to see the output wave forms.
    
   <img width="526" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/7cebeb4b-13c6-47e0-99b0-cf0b74a6df55">

- **Design**
  - It is the verilog code or set of verilog codes having functions for the required specifications.
  - May have 1/more primary inputs and 1/more primary outputs.
  - Verilog is used to describe the behavior and structure of digital circuits at different levels of abstraction, from high-level system descriptions  down to low-level gate-level representations. 

- **Testbench**
  - A testbench is a verilog program used to check the functionality of the Design. Testbenches are required for testing and simulating digital designs.
  - It has a stimulus generator and stimulus observer to generate inputs and check the outputs of the design.
  - TB has no primary inputs or outputs.

    <img width="526" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/cba0ff11-2877-4113-965e-575f6ec16804">
     
# Labs using iVerilog and GTKwave
## Introduction to Lab 

+ Make a directory named vsd `mkdir vsd`.
+ Go to the folder using`cd vsd`.
+ Type this command `git clone https://github.com/kunalg123/sky130RTLDesignAndSynthesisWorkshop.git`
+ A folder called `sky130RTLDesignAndSynthesisWorkshop` is created in the `vsd` directory.

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/253c1f2f-3f14-4f82-aaf1-a27b7a8efdf5)

  - my_lib : contains all the library files

  - lib : contains sky130 standard cell library used for our synthesis

  - verilog_model : contains all the standard cell verilog modules of the standard cells contained in the .lib

  - verilog_files : contains all the verilog source files and testbench files which are required for labs


## Introduction to iVerilog GTKwave

+ `cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/175effec-06f3-4ada-b172-eae0cd76362d)

+ The design file(good_mux.v) along with the testbench(tb_good_mux.v) can be loaded into the iverilog simulator using

```sh
iverilog good_mux.v tb_good_mux.v
```

+ When `./a.out` is entered an output file gets created.

+ The output of the iverilog, a vcd file, which is created  is loaded into the simualtor gtkwave using 

  ```sh
   gtkwave tb_good_mux.vcd 


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9d140892-bbe5-459a-b1c5-1eec8b8cfa48)

+ The simulator output
  
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9cb344cb-9b5a-4ccb-917f-130e945c958e)

+ Tips to analyse the outputs easily
  
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6659af4b-0d8b-47ba-ac88-3a0cc84f557f)


+ In order to view the contents of the files use

```sh 
gvim tb_good_mux.v -o good_mux.v
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/d240cf99-6a92-402f-bc3e-f37b6b16036d)

# Introduction to Yosys and Logic Synthesis

## Introduction to Yosys 

+ **Synthesizer**
  - It is a tool used for converting RTL design to netlist.
  - Here, the synthesizer used is **Yosys**.

+ **Yosys**
  - It is an open-source framework for Verilog RTL synthesis and formal verification.
  - Yosys provides a collection of tools and algorithms that enable designers to transform high-level RTL (Register Transfer Level) descriptions of digital circuits into optimized gate-level representations suitable for physical implementation on hardware.

 <img width="561" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c0b71614-ef4d-4646-9005-00bbd4a6bf43">

   - Design and .lib files are fed to the synthesizer to get a netlist file.
   - **Netlist** is the representation of the design in the form of standard cells in the .lib
     
+ Commands used to perform different opertions:
  - `read_verilog` to read the design
  - `read_liberty` to read the .lib file
  - `write_verilog` to write out the netlist file
 
+ To verify the synthesis

<img width="566" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9ca85f67-137a-499d-a5e6-28b038f82d58">

   - Netlist along with the tesbench is fed to the iverilog simulator.
   - The vcd file generated is fed to the gtkwave simulator.
   - The output on the simulator must be same as the output observed during RTL simulation.
   - Same RTL testbench can be used as the primary inputs and primary outputs remain same between the RTL design and synthesised netlist.

## Introduction to Logic Synthesis 

+ **Logic Synthesis**
  - Logic synthesis is a process in digital design that transforms a high-level hardware description of a digital circuit, typically in a hardware description language (HDL) like Verilog or VHDL, into a lower-level representation composed of logic gates and flip-flops.
  - The goal of logic synthesis is to optimize the design for various criteria such as performance, area, power consumption, and timing.

 + **.lib**
   - It is a collection of logical modules like AND, OR, NOT etc.
   - It has different flavors of same gate like 2 input AND gate, 3 input AND gate etc with different performace speed.
  
+ **Why different flavors  of gate?**
  - In order to make a circuit faster, the clock frequency should be high.
  - For that, the time period of the clock should be as low as possible.
  
<img width="400" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/210d9f8f-3320-4165-a60a-96de607a17ac">

+ In a sequential circuit, clock period depends on:
  - Clock to Q of flip-flop A.
  - Propagation delay of combinational circuit.
  - Setup time of flip-flop B.

<img width="400" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/18e3937a-b9d4-4ec6-b329-e143856d1a2f">

+ **Why need fast and slow cells?**
  - To ensure that there are no HOLD issues at flip-flop B, we require slow cells.
  - For a smaller propagation time, we need faster cells.
  - The collection forms the .lib

+ **Faster Cells vs Slower Cells**
  - Load in digital circuit is of Capacitence.
  - Faster the charging or dicharging of capacitance, lesser is the cell delay.
  - However, for a quick charge/ discharge of capacitor, we need transistors capable of sourcing more current i.e, we need **wide transistors**.
  - Wider transistors have lesser delay but consume more area and power.
  - Narrow transistors have more delay but consume less area and performance.
  - Faster cells come with a cost of area and power.
 
+ **Selection of the Cells**
  - We have to guide the Synthesizer to choose the flavour of cells that is optimum for implementation of logic circuit.
  - More use of faster cells leads to bad circuit in terms of power and area and also hold time violations.
  - More use of slower cells leads to sluggish circuits amd may not meet the performance needs.
  - Hence the guidance is offered to the synthesiser in the form of **constraints**.


# Labs using Yosys and Sky130 PDKs

## Yosys good_mux  

+ ```sh
  cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
  ```
  
+ To invoke **yosys** , use the command `yosys`.

  <img width="358" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/40f2b0a2-e37a-4a25-bd30-d24f1f41dbb5">

+ To read the library
    
     ```sh
     read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
     ```    
+ To read the design

    ```sh
  read_verilog good_mux.v
    ```

 + To syntheis the module

      ```sh
   synth -top good_mux
      ```

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/538b5f64-fe80-45a6-b1d2-4716a16ca30a)

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/5eeba289-ec22-4b54-b20d-cbdde5c1c36b)
 
 
+ To generate the netlist

  ```sh
  abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  ```
  
  <img width="287" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/78d150ae-b427-4ab8-9fdb-5c7c87862b69">
  <img width="287" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/f2344b45-84db-478d-a773-f418720db48a">

It gives a report of what cells are used and the number of input and output signals.Comparision of number of inputs and outputs with the verilog code.

+ To see the logic realised

  `show`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/dec66ebc-853c-44d6-ad82-cf7c1c1b5d64)

  The mux is completely realised in the form of sky130 library cells.

+ To write the netlist

  - ```sh
    write_verilog good_mux_netlist.v
    ```
   - ```sh
     !gvim good_mux_netlist.v
     ```
     
   - To view a simplified code
     
     ```sh
      write_verilog -noattr good_mux_netlist.v
     ```
     
     ```sh
     !gvim good_mux_netlist.v
     ```
  
  
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9257ad92-d701-4a0a-af79-623eb12d5a81)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/2fc1c778-95f5-46af-b97c-4cddcda90e02)



</details>


<details>
<summary>DAY 4 </summary>
<br>

## DAY 4
**Timing Libs, Hierarchical vs Flat Synthesis and Efficient Flop Coding Styles**
+ Introduction to Timing Dot Libs
  - [Introduction to Dot Lib](#introduction-to-dot-lib)
+ Hierarchical vs Flat Synthesis
  - [Hierarchical Synthesis Flat Synthesis](#hierarchical-synthesis-flat-synthesis) 
+ Various Flop Coding Styles and Optimization
  - [Why Flops and Flop Coding Styles](#why-flops-and-flop-coding-styles)
  - [Lab Flop Synthesis Simulations](#lab-flop-synthesis-simulations)
  - [Interesting Optimisations](#interesting-optimisations)

# Introduction to Timing Dot Libs
## Introduction to Dot Lib 

+ To view the contents in the .lib

  ```sh
  gvim ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  ```

  <img width="443" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/019e635b-6afe-432c-87f8-63ba20211436">

  + The first line in the file `library ("sky130_fd_sc_hd__tt_025C_1v80") ` :
    
    - tt   : indicates **Typical Process**.
    - 025C : indicates the  temperatures.
    - 1v80 : indicates the  voltage.
+ It also displays the units of various parameters.

  <img width="284" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/068a2434-321a-4d6b-924c-52f2093f69a5">
  <img width="229" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/064988f5-7a63-4645-9e04-b16f992a7abf">

+ It gives the features of the cells
+ To enable line number `:se nu`
+ To view all the cells `:g//`
+ To view any instance `:/instance`
+ Since there are 5 inputs, for all the 32 possible combinations, it gives the delay, power and all the other parameters for each cell.
+ The below image shows the power consumption and area comparision.
  
<img width="911" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/5f18e9bb-2265-4fbe-87d2-3a262e0f22de)">


# Hierarchical vs Flat Synthesis
## Hierarchical Synthesis Flat Synthesis 

**Hierarchical Synthesis**
  Hierarchical synthesis is an approach in digital design and logic synthesis where complex designs are broken down into smaller, more manageable modules or sub-circuits, and each module is synthesized individually. These synthesized modules are then integrated back into the overall design hierarchy. This approach helps manage the complexity of large designs and allows designers to work on different parts of the design independently.
  
+ The file we used in this lab is `multiple_modules.v`

  - `cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files`
  -  `gvim multiple_modules.v`

<img width="321" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/4bc3c105-9467-43c1-8736-5085e6875448">

+  `multiple_modules` instantiates `sub_module1` and `sub_module2`

+  Launch `yosys`
+  To read the library file
  ```sh
  read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  ```
+  To read the verilog file
  ```sh
  read_verilog multiple_modules.v
 ```
+  To set it as top module
  ```sh
 synth -top multiple_modules
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/359e77ae-788e-435e-86cd-d3e6b726bb01)

  <img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ead196b7-6d2b-43cc-899b-9f2e515e9200">
  <img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/a89f369d-1bb0-428e-a4f8-d13989763836">
  <img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/5543c0a2-2c1e-4e10-8bed-1bac36024acf">
  
  
+  To create netlist
  ```sh
  abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  ```
+  To view the netlist
  ```sh
 show multiple_modules
 ```

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/2cc04b44-98f6-4e55-9c9a-4fe146b6f0f4)


- Here it shows `sub_module1` and `sub_module2` instead of AND gate and OR gate.

+ ```sh
  write_verilog -noattr multiple_modules_hier.v
  ```
+ ```sh
  !gvim multiple_modules_hier.v
  ```
  
  <img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9371813a-df5d-400c-9c3a-559e56d1e3bc">
  <img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6076240d-4288-4cd9-9144-d52b9a11d4bf">
  <img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/30857f64-761b-4ead-bce5-59c8166cec1a">

 **Flattened Synthesis**
 
Flattened synthesis is the opposite of hierarchical synthesis. Instead of maintaining the hierarchical structure of the design during synthesis, flattened synthesis combines all modules and sub-modules into a single, flat representation. This means that the entire design is synthesized as a single unit, without preserving the modular organization present in the original high-level description.

+  Launch `yosys`
+  +  To read the library file
  ```sh
  read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  ```
+  To read the verilog file
  ```sh
  read_verilog multiple_modules.v
 ```
+  To set it as top module
  ```sh
 synth -top multiple_modules
```
  
+  To create netlist
  ```sh
  abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  ```
+ To write out a flattened netlist
  ```sh
   flatten
  ```
+  To view the netlist
  ```sh
 show 
 ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/e16acceb-507f-4363-b656-b0235f7a30ee)

+ ```sh
  write_verilog -noattr multiple_modules_flat.v
  ```
+ ```sh
  !gvim multiple_modules_flat.v
  ```

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/3e758df8-5337-437b-99e7-3c9c0e6c8c6d)

  
<img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ab3f1019-2dda-444f-8f2f-42600482cff1">
<img width="304" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/d5417f3e-4580-4c56-83dd-20d62f5f80bf">


# Various Flop Coding Styles and Optimization
## Why Flops and Flop Coding Styles

**Why do we need a Flop?**

+ A flip-flop (often abbreviated as "flop") is a fundamental building block in digital circuit design.
+ It's a type of sequential logic element that stores binary information (0 or 1) and can change its output based on clock signals and input values.
+ In a combinational circuit, the output changes after the propagation delay of the circuit once inputs are changed.
+ During the propagation of data, if there are different paths with different propagation delays, then a glitch might occur.
+ There will be multiple glitches for multiple combinational circuits.
+ Hence, we need flops to store the data from the combinational circuits.
+ When a flop is used, the output of combinational circuit is stored in it and it is propagated only at the posedge or negedge of the clock so that the next combinational circuit gets a glitch free input thereby stabilising the output.
+ We use control pins like **set** and **reset** to initialise the flops.
+ They can be synchronous and asynchronous.

**D Flip-Flop with Asynchronous Reset**
+ When the reset is high, the output of the flip-flop is forced to 0, irrespective of the clock signal.
+ Else, on the positive edge of the clock, the stored value is updated at the output.

 ```sh
 gvim dff_asyncres.v
```

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/fc1d6645-4448-479f-8a95-c12658676b41)


**D Flip_Flop with Asynchronous Set**
+ When the set is high, the output of the flip-flop is forced to 1, irrespective of the clock signal.
+ Else, on positive edge of the clock, the stored value is updated at the output.

```sh
gvim dff_async_set.v
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/4a3905e6-90fb-4989-bfb4-e3fcc4386521)

**D Flip-Flop with Synchronous Reset**
+ When the reset is high on the positive edge of the clock, the output of the flip-flop is forced to 0.
+ Else, on the positive edge of the clock, the stored value is updated at the output.

  ```sh
  gvim dff_syncres.v
  ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/4ebbce21-a474-4078-8713-68befe906c34)


**D Flip-Flop with Asynchronous Reset and Synchronous Reset**
+ When the asynchronous resest is high, the output is forced to 0.
+ When the synchronous reset is high at the positive edge of the clock, the output is forced to 0.
+ Else, on the positive edge of the clock, the stored value is updated at the output.
+ Here, it is a combination of both synchronous and asynchronous reset DFF.

```sh
gvim dff_asyncres_syncres.v
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9b3d5eb1-f845-4544-b7ee-04fc934c8640)

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/59c0a19e-d76c-4e54-b197-94d22177546b)

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/06d04cda-615d-4cd7-ba18-af81fd4cb5da)


## Lab Flop Synthesis Simulations 

**D Flip-Flop with Asynchronous Reset**
+ **Simulation**
  ```sh
    cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
    iverilog dff_asyncres.v tb_dff_asyncres.v
    ./a.out
    gtkwave tb_dff_asyncres.vcd
  ```
  
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ae93bfc8-6278-417a-870f-33fa82f04987)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/841ee7d7-f19b-45c7-8d81-d53c3e45982e)


+ **Synthesis**
  ```sh
  cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
  yosys
  read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  read_verilog dff_asyncres.v
  synth -top dff_asyncres
  dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
  show
  ```

    ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/57fb2646-2fe2-4989-8343-c091b9236b1d)


 **D Flip_Flop with Asynchronous Set**
 + **Simulation**

   
  ```sh
  cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
iverilog dff_async_set.v tb_dff_async_set.v
./a.out
gtkwave tb_dff_async_set.vcd
  ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6366bc71-c699-4c21-b792-84e9e0f06565)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/1e727477-faa7-4909-a5b2-52603a99a294)


+ **Synthesis**

```sh
 cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_async_set.v
synth -top dff_async_set
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
  ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/56df9f39-91d8-4b42-bfed-45794fadda53)


**D Flip-Flop with Synchronous Reset**

+ **Simulation**
  ```sh
  cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
  iverilog dff_syncres.v tb_dff_syncres.v
  ./a.out
  gtkwave tb_dff_syncres.vcd
  ```
 
     
   ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/3e8b1870-c6a7-493e-b858-1ba97ca62483)

   

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/20ffac93-0bf4-44cb-a512-a922e9b5b1fd)

  

+ **Synthesis**
```sh
cd vsd/sky130RTLDesignAndSynthesisWorkshop/verilog_files
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_syncres.v
synth -top dff_syncres
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/79098c20-6676-41a8-8851-6d275f4de7f3)


## Interesting Optimisations </summary>	

+ ```sh
  gvim mult_2.v
  ```
 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/af09564b-ab4c-4606-9ce1-c18e6525e992)

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/05545a37-c20f-4f17-8b47-7a06adc294b4)


```sh
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog mult_2.v
synth -top mul2
```

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ae5051bb-4cff-4692-ad3a-b54017bfca19)


```sh
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6a7fc18a-99bd-4004-83c8-6e7744c1c46d)


```sh
write_verilog -noattr mul2_netlist.v
!gvim mul2_netlist.v
```
  
 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/4bbf3398-4e7c-4e61-a380-983a45897330)

```sh
gvim mult_8.v
```
  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ce669f45-c451-4fb0-abfb-96aa8bf6800a)

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c9b1e11c-332c-4b8d-9846-d6f1f4b29213)


```sh
yosys
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog mult_8.v
synth -top mult8
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/daa0c201-25e8-4969-8d05-b3059d933ccc)


```sh
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/36593762-4c2d-4522-a6a7-52033321051b)


```sh
write_verilog -noattr mult8_netlist.v
gvim mult8_netlist.v
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c0c25019-8b3f-4555-8a25-cfd15d0dc563)

</details>

<details>
<summary>DAY 5 </summary>
<br>
	
## DAY 5
**Combinational and Sequential Optmizations**
+ [Introduction to Optimisations](#introduction-to-optimisations)
+ [Combinational Logic Optimisations](#combinational-logic-optimisations)
+ [Sequential Logic Optimisations](#sequential-logic-optimisations)
+ [Sequential Optimisations for Unused Outputs](#sequential-optimisations-for-unused-outputs)


# Introduction to Optimisations 
## Combinational Optimisation 
	
+ Combinational logic refers to logic circuits where the outputs depend only on the current inputs and not on any previous states.
+ Combinational optimization is a field of study in computer science and operations research that focuses on finding the best possible solution from a finite set of options for problems that involve discrete variables and have no inherent notion of time.
+ Optimising the combinational logic circuit is squeezing the logic to get the most optimized digital design so that the circuit finally is area and power efficient.
+ Techniques for Optimisations:
  - **Constant propagation** is an optimization technique used in compiler design and digital circuit synthesis to improve the efficiency of code and circuit implementations by replacing variables or expressions with their constant values where applicable.
  - **Boolean logic optimization**, also known as logic minimization or Boolean function simplification, is a process in digital design that aims to simplify Boolean expressions or logic circuits by reducing the number of terms, literals, and gates required to implement a given logical function.

## Sequential Logic Optimisations 

+ Sequential logic optimizations involve improving the efficiency, performance, and resource utilization of digital circuits that include memory elements like flip-flops and latches.
+ Optimizing sequential logic is crucial in ensuring that digital circuits meet timing requirements, consume minimal power, and occupy the least possible area while maintaining correct functionality.
+ Optimisation methods:
  - **Sequential constant propagation**, also known as constant propagation across sequential elements, is an optimization technique used in digital design to identify and propagate constant values through sequential logic elements like flip-flops and registers. This technique aims to replace variable values with their known constant values at various stages of the logic circuit, optimizing the design for better performance and resource utilization.
  - **State optimization**, also known as state minimization or state reduction, is an optimization technique used in digital design to reduce the number of states in finite state machines (FSMs) while preserving the original functionality.
  - **Sequential logic cloning**, also known as retiming-based cloning or register cloning, is a technique used in digital design to improve the performance of a circuit by duplicating or cloning existing registers (flip-flops) and introducing additional pipeline stages. This technique aims to balance the critical paths within a circuit and reduce its overall clock period, leading to improved timing performance and better overall efficiency.
  - **Retiming** is an optimization technique used in digital design to improve the performance of a circuit by repositioning registers (flip-flops) along its paths to balance the timing and reduce the critical path delay. The primary goal of retiming is to achieve a shorter clock period without changing the functionality of the circuit.
 

# Combinational Logic Optimisations

## opt_check

+ `gvim opt_check.v`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/2e6c4f6d-b7b7-49a0-a4e4-394f49b96a73)
 

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check.v
synth -top opt_check
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/f24fdf34-5f35-4c60-810a-6e745b5be9f8)


  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/29439fc7-945e-4ae1-9763-3da5846825b4)


## opt_check2 

+ `gvim opt_check2.v`

  ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/efdd3dd8-845c-4e00-8588-099b297c8c5f)

  
```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check2.v
synth -top opt_check2
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/5f90cd99-7df1-4584-ba7e-bc5266a24be9)

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/8cf75ebc-c4ff-416e-940f-faac6a4cf8a1)

## opt_check3 

+ `gvim opt_check3.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/708e80c7-933a-4aef-bb21-0ae4a8529255)


```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check3.v
synth -top opt_check3
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/b9f2fd77-430a-4b65-9989-9ab9a70570d3)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/d28c7200-5910-499c-b604-f0b22cfba9b8)


## opt_check4 

+ `gvim opt_check4.v`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ea7a9d11-0364-4a0b-8370-5e3bed0daeea)


```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog opt_check4.v
synth -top opt_check4
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c330b995-16c2-4272-a6b4-bc76b124bf2a)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/a68f4c7e-5755-4538-86d5-401b556dae58)


## multiple_module_opt
	
+ `gvim multiple_module_opt.v`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c4382bdb-8f3c-4246-8233-fb5799c5a5a7)


```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog multiple_module_opt.v
synth -top multiple_module_opt
opt_clean -purge
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
 
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/b3a4892b-40b4-4eec-98ba-b98387a24f2a)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6ec1093e-8a32-4576-ac42-6f7cdd35c730)


# Sequential Logic Optimisations
## dff_const1 </summary>	

+ `gvim dff_const1.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/478d8085-b541-469b-a26e-d3f4644cb456)


**Simulation**

```sh
iverilog dff_const1.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const1.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/2e668976-6499-48bf-9abb-0ddfc40e8445)


**Synthesis**

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const1.v
synth -top dff_const1
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/05e960a0-baf4-4f11-9aa9-137672ce13b8)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/588092c8-8a35-4bfc-9490-809378fc9d80)


## dff_const2 

+ `gvim dff_const2.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/bc95b4ab-21c3-45cc-bffb-8b220091fbc6)


**Simulation**

```sh
iverilog dff_const2.v tb_dff_const2.v
./a.out
gtkwave tb_dff_const2.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/acd1b024-c707-48b0-98b4-60cc53782acb)


 **Synthesis**
 
```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const2.v
synth -top dff_const2
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/79f9f33b-d940-4844-9f85-0be93f9075c6)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/bfc24cf7-8605-4761-b846-05fae8a80c2a)


## dff_const3 

+ `gvim dff_const3.v`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/576eda65-2789-402d-90ca-bc24a0a9ee9b)


**Simulation**

```sh
iverilog dff_const3.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const3.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ad4b80c9-60cc-4d70-bac0-f69b78c1862e)


**Synthesis**

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const3.v
synth -top dff_const3
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ee07994c-cff8-4d8a-a518-edf605235fb2)

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/f625bd1e-70d9-403d-a809-7cb74f40f14d)


## dff_const4 

+ `gvim dff_const4.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/47318043-d60e-45a6-894a-482db94c1d7e)


**Simulation**

```sh
iverilog dff_const4.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const4.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ff0f0bce-673f-443d-8759-7680b9faf010)


**Synthesis**

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const4.v
synth -top dff_const4
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c34fde83-75fb-4d2f-ab5c-51adbb1d82c5)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/97a0f9e0-ca18-48c0-b1f0-25118f9c6588)


## dff_const5 

+ `gvim dff_const5.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/ad9d5b32-366c-409c-90aa-b9d09e65653f)


**Simulation**

```sh
iverilog dff_const5.v tb_dff_const1.v
./a.out
gtkwave tb_dff_const5.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/7eeb6f0f-434b-4091-b846-f8fb790fa11f)


**Synthesis**

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog dff_const5.v
synth -top dff_const5
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/8f268f49-51d1-43b7-a9a7-0a8b2bdcbe99)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c402aaa1-d1d6-40df-931a-7ed0911ef27e)


# Sequential Optimisations for Unused Outputs
## counter_opt 

 + `gvim counter_opt.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/34e7ce96-0ab2-4519-9951-3b1947382f59)


```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog counter_opt.v
synth -top counter_opt
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/70d9a2de-9765-47d3-a247-0b055d0bb5d3)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/18ef600e-3f38-4102-8d76-dceb9932f576)


## counter_opt2 

+ `gvim counter_opt2.v`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/9d4c583b-ed6f-4351-8a2d-a7920c02201d)


```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog counter_opt2.v
synth -top counter_opt2
dfflibmap -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib 
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/57bc0821-b7c6-442d-8778-cabd996ea0c3)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/a35aed3d-33bf-47da-8b2e-a2368566620f)


</details>

<details>
<summary>DAY 6 </summary>
<br>
	
## DAY 6
**GLS, Blocking vs Non-Blocking and Synthesis-Simulation Mismatch**

+ GLS Synthesis-Simulation Mismatch and Blocking Non-Blocking Statements
  - [GLS Concepts And Flow Using Iverilog](#gls-concepts-and-flow-using-iverilog)
  - [Synthesis Simulation Mismatch](#synthesis-simulation-mismatch)
  - [Blocking And Non Blocking Statements In Verilog](#blocking-and-non-blocking-statements-in-verilog)
  - [Caveats With Blocking Statements](#caveats-with-blocking-statements)
+ [Labs on GLS and Synthesis-Simulation Mismatch](#labs-on-gls-and-synthesis-simulation-mismatch)
+ [Labs on Synth-Sim Mismatch for Blocking Statement](#labs-on-synth-sim-mismatch-for-blocking-statement)

# GLS Synthesis-Simulation Mismatch and Blocking Non-blocking Statements
## GLS Concepts And Flow Using Iverilog

 + **Gate Level Simualtion**
   - Gate-level simulation is a technique used in digital design and verification to validate the functionality of a digital circuit at the gate-level implementation.
   - It involves simulating the circuit using the actual logic gates and flip-flops that make up the design, as opposed to higher-level abstractions like RTL (Register Transfer Level) descriptions.
   - This type of simulation is typically performed after the logic synthesis process, where a high-level description of the design is transformed into a netlist of gates and flip-flops.
   - We perform this to verify logical correctness of the design after synthesizing it. Also ensuring the timing of the design is met.
  
<img width="608" alt="image" src="https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c0581d3c-98c0-492f-b00c-7e370867189f">

+ **Synthesis-Simulation Mismatch**
+ 
  - A synthesis-simulation mismatch refers to a situation in digital design where the behavior of a circuit, as observed during simulation, doesn't match the expected or desired behavior of the circuit after it has been synthesized.
  - This discrepancy can occur due to various reasons, such as timing issues, optimization conflicts, and differences in modeling between the simulation and synthesis tools.
  - This mismatch is a critical concern in digital design because it indicates that the actual hardware implementation might not perform as expected, potentially leading to functional or timing failures in the fabricated chip.

+ **Blocking Statements**
  - Blocking statements are executed sequentially in the order they appear in the code and have an immediate effect on signal assignments.
  - Example:

  ``` v
   module BlockingExample(input A, input B, input C, output Y, output Z);
    wire temp;

    // Blocking assignment
    assign temp = A & B;

    always @(posedge C) begin
        // Blocking assignment
        Y = temp;
        Z = ~temp;
    end
   endmodule
  ```

+ **Non-Blocking Statements**
  - Non-blocking assignments are used to model concurrent signal updates, where all assignments are evaluated simultaneously and then scheduled to be updated at the end of the time step.
  - Example:
  - 
   ``` v
    module NonBlockingExample(input clock, input D, input reset, output reg Q);

    always @(posedge clock or posedge reset) begin
        if (reset)
            Q <= 0;  // Reset the flip-flop
        else
            Q <= D;  // Non-blocking assignment to update Q with D on clock edge
    end
  endmodule
   ```

+ **Caveats with Blocking Statements**
  
  + Blocking statements in hardware description languages like Verilog have their uses, but there are certain caveats and considerations to be aware of when working with them. Here are some important caveats associated with using blocking statements:
    - Procedural Execution: Blocking statements are executed sequentially in the order they appear within a procedural block (such as an always block). This can lead to unexpected behavior if the order of execution matters and is not well understood.
    - Lack of Parallelism: Blocking statements do not accurately represent the parallel nature of hardware. In hardware, multiple signals can update concurrently, but blocking statements model sequential behavior. As a result, using blocking statements for modeling complex concurrent logic can lead to incorrect simulations.
    - Race Conditions: When multiple blocking assignments operate on the same signal within the same procedural block, a race condition can occur. The outcome of such assignments depends on their order of execution, which might lead to inconsistent or unpredictable behavior.
    - Limited Representation of Hardware: Hardware systems are inherently concurrent and parallel, but blocking statements do not capture this aspect effectively. Using blocking assignments to model complex combinational or sequential logic can lead to models that are difficult to understand, maintain, and debug.
    - Combinatorial Loops: Incorrect use of blocking statements can lead to unintentional combinational logic loops, which can result in simulation or synthesis errors.
    - Debugging Challenges: Debugging code with many blocking assignments can be challenging, especially when trying to track down timing-related issues.
    - Not Suitable for Flip-Flops: Blocking assignments are not suitable for modeling flip-flop behavior. Non-blocking assignments (<=) are generally preferred for modeling flip-flop updates to ensure accurate representation of concurrent behavior.
    - Sequential Logic Misrepresentation: Using blocking assignments to model sequential logic might not capture the intended behavior accurately. Sequential elements like registers and flip-flops are better represented using non-blocking assignments.
    - Synthesis Implications: The behavior of blocking assignments might not translate well during synthesis, leading to potential mismatches between simulation and synthesis results.



# Labs on GLS and Synthesis-Simulation Mismatch
## ternary_operator_mux 

+ `gvim ternary_operator_mux.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/6cc6b509-42f2-44db-8485-117df3a43e93)


**Simulation**
  ```sh
iverilog ternary_operator_mux.v tb_ternary_operator_mux
./a.out
gtkwave tb_ternary_operator_mux.vcd
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/fec6b23e-9a09-4540-8e28-9f07a056ad07)


**Synthesis**

  ```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog ternary_operator_mux.v
synth -top ternary_operator_mux
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/703b6a44-e68b-4009-bb8f-be6632208141)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/b0ec5c2c-e2a5-4a60-a2af-5df28194c941)


**GLS to Gate-Level Simulation**

```sh
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v ternary_operator_mux_net.v tb_ternary_operator_mux.v
./a.out
gtkwave tb_ternary_operator_mux.vcd
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c142d5cf-ffca-4c7f-854d-bbc1af2f35eb)


## bad_mux 

 + `gvim bad_mux.v`

 ![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/8f89fbce-933c-4c1f-bf3e-d112131d92aa)


**Simualtion**

  ```sh
iverilog bad_mux.v tb_bad_mux.v
./a.out
gtkwave tb_bad_mux.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/d36f0f4a-774b-4c28-bd6a-c4d3d48c34a2)


**Synthesis**

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog bad_mux.v
synth -top bad_mux
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```
![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/13c81d8d-2898-4f47-affd-2f4c3be56b9c)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/c649c45b-587f-4955-81d8-c57578e693a0)


**GLS to Gate-Level Simulation**

```sh
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v bad_mux_net.v tb_bad_mux.v
./a.out
gtkwave tb_bad_mux.vcd
  ```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/954277e0-3e6c-42bd-9a8c-97c472fab3ed)


# Labs on Synth-Sim Mismatch for Blocking Statement

## blocking_caveat 

+ `gvim blocking_caveat.v`

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/a185f644-bb29-4a51-893d-9fcc2feab9c1)


**Simualtion**

 ```sh
iverilog blocking_caveat.v tb_blocking_caveat.v
./a.out
gtkwave tb_blocking_caveat.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/633d011f-0d57-408e-a9b7-2362bfd5268a)


**Synthesis**

```sh
read_liberty -lib ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
read_verilog blocking_caveat.v
synth -top blocking_caveat
abc -liberty ../lib/sky130_fd_sc_hd__tt_025C_1v80.lib
show
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/2fec1d2b-674d-40b7-8365-bcc6c43ea0ef)


![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/cc9911ea-1690-48ad-8948-893821b29810)


**GLS to Gate-Level Simulation**

```sh
iverilog ../my_lib/verilog_model/primitives.v ../my_lib/verilog_model/sky130_fd_sc_hd.v blocking_caveat_net.v tb_blocking_caveat.v
./a.out
gtkwave tb_blocking_caveat.vcd
```

![image](https://github.com/ShreyasSAdmar/PES_ASIC/assets/85454575/fef1977e-2897-4fa4-af48-3f795c6974c6)


</details>

  


  
