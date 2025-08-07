# DOS-Clone-From-Scratch

A minimalist MS-DOS-inspired operating system built entirely in C, from first principles, with zero standard libraries, zero virtual machines, and curiosity.

##  What even is this?

This project is a handcrafted MS-DOS-style OS clone, implemented entirely using custom low-level utilities. It comes with a cross-platform `command.com` shell that runs on Windows, macOS, and Linux — no virtualization, no dependencies, just pure C.

##  Why tho?

Because bootstrapping your OS from scratch is better than copy-pasting from gpt 💀

This project was inspired by a mix of:
- Retro-tech
- OS dev
- Understanding the guts of an OS
- System architecture 

## Architecture at a Glance

- `command.com`: User-facing shell interface
- Middleware/API: Custom system call layer (still gotta work on)
- Kernel: Simulated using the host OS during development (still gotta work on)

##  Development Philosophy

- Written in **pure C**, no standard libraries
- Zero reliance on **virtual machines**
- Modular Makefile-driven build system
- Custom typedefs and macro-based visibility control

## Quick Start

still under development

