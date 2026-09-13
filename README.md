# Algorithms & Problem Solving Level 5

This project is a C++ practice workspace focused on data structures, queue/stack simulation, linked lists, dynamic arrays, and supporting date/string utilities.

> Note: This project is designed for Windows-based development and uses Visual Studio project files. It also relies on MSVC-specific features such as \_\_declspec(property) and functions like localtime, so it is intended to run on Windows with Visual Studio. If you want to run it on another OS or compiler, you may need to replace platform-specific calls/features and use a compatible C++ build system.

## What this project is about

It is designed to help train and improve skills in:

- Implementing generic data structures using C++ templates

- Managing dynamic memory with new and delete

- Working with doubly linked lists and dynamic arrays

- Building queue and stack ADTs using linked lists and arrays

- Simulating real-world queue systems with tickets and serving logic

- Implementing undo/redo behavior using stacks

- Using helper libraries for date/time and string manipulation

- Writing reusable, structured C++ classes and functions

## Level

This repository represents Level 5 of the learning journey.

## How to run

1. Open the solution file named Algorithms & Problem Solving Level 5.sln in Visual Studio.

2. Build the project.

3. Run the program using F5 or the Run button.

> main.cpp currently calls QueueUseCase() by default. To try other data structures, call the other test functions from main() such as TryDoubleLinkedList(), TryQueue(), TryArrQueue(), TryStack(), TryDynamicArray(), or TryArrStack().

## Topics covered in main.cpp

The code in main.cpp includes practice on:

- Doubly linked list operations:

  -- Insert at beginning, end, after value, and after index

  -- Delete by value, first node, last node, and clear

  -- Find by value/index, update value, reverse, and print

- Queue implementation using a doubly linked list

- Stack implementation using a queue/linked list

- Queue implementation using a dynamic array

- Stack implementation using an array-based queue

- Dynamic array operations:

  -- Set/get items, resize, insert, delete, reverse, clear, find, and print

- Queue line simulation:

  -- Issuing tickets

  -- Tracking total, waiting, and served clients

  -- Printing ticket lines from right-to-left and left-to-right

  -- Printing all ticket details

  -- Serving the next client

- String undo/redo example using std::stack

- Supporting date and string utilities through clsDate and clsString

## Tech Stack

- C++

- Standard Library containers used in parts of the project (std::queue, std::stack, std::string, std::vector)

## Purpose

The main goal is to practice implementing and using fundamental data structures in C++, while also building small practical use cases such as queue-line ticket simulation and undo/redo text editing. It strengthens C++ programming skills through templates, dynamic memory, linked structures, and reusable class design.
