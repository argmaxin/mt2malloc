# mt2malloc
(MT)² or MTMT stands for Multi-Threaded Maple-Tree Memory Allocator. mt2malloc is a drop-in libc's malloc replacement that comes with powerful API that makes it NUMA-native. mt2malloc is licensed under Apache License, and written in ISO C89 (ANSI C).

mt2malloc operates under POSIX-assumptions (specifically POSIX.1-1996-or-later). 
It also relies on `mmap` and `munmap`.

# Design & Inspiration

Much of the design was inspired from the [Maple Tree](https://docs.kernel.org/core-api/maple_tree.html) and [RCU](https://docs.kernel.org/RCU/index.html) of the Linux Kernel.
The core representation choice was to combine slabs and extents inside a single structure indexed by a single tree for allocations. 
