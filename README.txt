My "base" library
-----------------

This is my base library that provides utilities that I find very useful and use
in at least one of my projects (hopefully more than one as re-use is the
purpose). Below is a description of each file. For more information see each
file.

* pool

This is a pool-type memory allocator, which allocates memory from a block of
memory retrieved from the OS. Once initialized its memory can be consumed and
reset almost instantly, ready for re-use.

* str

A simple string object that is just a pointer and a length.
