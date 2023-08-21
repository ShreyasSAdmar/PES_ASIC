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

To get started with the VLSI Physical Design for ASICs workshop, follow these steps:

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



# TABLE OF CONTENTS
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

## Review ASM Function Calls
- We wrote C code in one file and your assembly code in a separate file.
- In the assembly file, we declared assembly functions with appropriate signatures that match the calling conventions of your platform.

**C Program**
`custom1to9.c`
  ``` c
  #include <stdio.h>
  
  extern int load(int x, int y);
  
  int main()
  {
    int result = 0;
    int count = 9;
    result = load(0x0, count+1);
    printf("Sum of numbers from 1 to 9 is %d\n", result);
  }
```
**Asseembly File**
`load.s`
``` s
.section .text
.global load
.type load, @function

load:

add a4, a0, zero
add a2, a0, a1
add a3, a0, zero

loop:

add a4, a3, a4
addi a3, a3, 1
blt a3, a2, loop
add a0, a4, zero
ret
```
## Simulate C Program using Function Call
**Compilation:** To compile C code and Asseembly file use the command

`riscv64-unknown-elf-gcc -O1 -mabi=lp64 -march=rv64i -o custom1to9.o custom1to9.c load.s` 

this would generate object file `custom1to9.o`.

**Execution:** To execute the object file run the command 

`spike pk custom1to9.o`

![Screenshot from 2023-08-20 20-29-14](https://github.com/Syedhasan7/pes_asic_class/assets/109273742/c32f4af0-c473-4d59-8d4a-8e7ad4bf3f41)
