<<<<<<< HEAD
# mt2malloc
(MT)² or MTMT stands for Multi-Threaded Maple-Tree Memory Allocator.

mt2malloc is a drop-in libc's malloc replacement that comes with a powerful API that makes it NUMA-native.

mt2malloc is licensed under LGPLv2.1-or-later License, and written in ISO C11.
mt2malloc operates under POSIX-assumptions (specifically POSIX.1-2008-or-later).
||||||| parent of 985fda3 (commit: add working tree)
# mt2malloc
(MT)² or MTMT stands for Multi-Threaded Maple-Tree Memory Allocator. mt2malloc is a drop-in libc's malloc replacement that comes with powerful API that makes it NUMA-native. mt2malloc is licensed under Apache License, and written in ISO C89 (ANSI C).
=======
#mt2malloc
(MT)² or MTMT stands for Multi-Threaded Maple-Tree Memory Allocator. mt2malloc is a drop-in libc's malloc replacement that comes with powerful API that makes it NUMA-native. mt2malloc is licensed under Apache License, and written in ISO C89 (ANSI C).
>>>>>>> 985fda3 (commit: add working tree)

<<<<<<< HEAD
It also relies on `mmap` and `munmap` exclusively as of now (Windows ports are WIP). 
||||||| parent of 985fda3 (commit: add working tree)
mt2malloc operates under POSIX-assumptions (specifically POSIX.1-1996-or-later). 
It also relies on `mmap` and `munmap` exclusively as of now (Windows ports are WIP). 
=======
mt2malloc operates under POSIX-assumptions (specifically POSIX.1-1996-or-later). 
It also relies on `mmap` and `munmap` exclusively as of now (Windows ports are WIP).
>>>>>>> 985fda3 (commit: add working tree)

#Design& Inspiration

Much of the design was inspired from the [Maple Tree](https://docs.kernel.org/core-api/maple_tree.html) and [RCU](https://docs.kernel.org/RCU/index.html) of the Linux Kernel.
<<<<<<< HEAD

The core representation choice was to combine slabs and extents inside a single structure indexed by a single tree for allocations. This is allows circumvention of multiple complex data-structures, and a better mechanism in terms of correctness. 

It naturally provides isolation of metadata from user-data, and keeps metadata-induced fragmentation negligible at the user level. It also allows interesting properties, such as the ability to free interior pointers and so on.

mt2malloc is designed to be bounded and incremental in terms of cost. It also hopes of formal modelling in the near future!
||||||| parent of 985fda3 (commit: add working tree)
The core representation choice was to combine slabs and extents inside a single structure indexed by a single tree for allocations. 
=======
The core representation choice was to combine slabs and extents inside a single structure indexed by a single tree for allocations.
>>>>>>> 985fda3 (commit: add working tree)
