# DOS-Clone-From-Scratch

A minimalist MS-DOS-inspired operating system built entirely in C, from first principles, with zero standard libraries, zero virtual machines, and maximum curiosity.

##  Description

This project is a handcrafted MS-DOS-style OS clone, implemented entirely using custom low-level utilities. It comes with a cross-platform `command.com` shell that runs on Windows, macOS, and Linux — no virtualization, no dependencies, just pure C.

##  Why?

Because bootstrapping your operating system from scratch is cooler than copy-pasting from gpt 💀

This project was inspired by a mix of:
- Retro-tech 
- Understanding the guts of an OS
- System architecture 

## Architecture at a Glance

- ♠ `command.com`: User-facing shell interface
- ❤ Middleware/API: Custom system call layer
- ♣ Kernel: Simulated using host OS during development

##  Development Philosophy

- Written in **pure C**, no standard libraries
- Zero reliance on **virtual machines**
- Modular Makefile-driven build system
- Custom typedefs, macro-based visibility control, and a whole lotta `<stdint>` soul

## Quick Start

Under Development
