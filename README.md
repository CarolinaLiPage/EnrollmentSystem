# UWBCSS342Project5Group
Carolina Li and Nour Toblany
CSS 342
Project 5
enrollmentsystem.cpp implements an application that processes enrollments


This program has successfully implemented all the required functions and
passed all the tests.

When creating an output.txt produces:

=====================================================
1. Compilation warnings are in the section below
=====================================================
=====================================================
2. Program output are in the section below
=====================================================
Done.
=====================================================
3. clang-tidy warnings are in the section below
=====================================================
Resource filename: /usr/local/lib64/python3.6/site-packages/clang_tidy/data/bin/clang-tidy 
49170 warnings generated.
86455 warnings generated.
135980 warnings generated.
178477 warnings generated.
.....
Suppressed 285544 warnings (285544 in non-user code).
Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
25 warnings treated as errors
=====================================================
4. clang-format warnings are in the section below
=====================================================
Running clang-format on ./course.cpp
Running clang-format on ./enrollmentsystem.cpp
Running clang-format on ./main.cpp
Running clang-format on ./student.cpp
Running clang-format on ./university.cpp
=====================================================
5. Memory leak issues are in the section below
=====================================================
=====================================================
6. valgrind memory test is in the section below. Look for "definitely lost" 
=====================================================
==5940== Memcheck, a memory error detector
==5940== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==5940== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==5940== Command: ./a.out
==5940== Parent PID: 4943
==5940== 
==5940== 
==5940== HEAP SUMMARY:
==5940==     in use at exit: 0 bytes in 0 blocks
==5940==   total heap usage: 1,991 allocs, 1,991 frees, 237,201 bytes allocated
==5940== 
==5940== All heap blocks were freed -- no leaks are possible
==5940== 
==5940== For lists of detected and suppressed errors, rerun with: -s
==5940== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
=====================================================
7. Code coverage information is in the section below
=====================================================

The warnings this program gets from clang-tidy are:
1. error: 2 adjacent parameters ... are easily swapped by mistake [bugprone-easily-swappable-parameters,-warnings-as-errors]

2. error: kernel performance could be improved by unrolling this loop with a '#pragma unroll' directive [altera-unroll-loops,-warnings-as-errors]

3. error: backward branch (for loop) is ID-dependent due to variable reference to ... and may cause performance degradation [altera-id-dependent-backward-branch,-warnings-as-errors]

4. error: class 'EnrollmentSystem' and class 'University' defines a non-default destructor but does not define a copy constructor, a copy assignment operator, a move constructor or a move assignment operator [cppcoreguidelines-special-member-functions,hicpp-special-member-functions,-warnings-as-errors]

Reasons why:
1. I tried fixing this error, but it's really hard to find anything on this error online. It seems like a relatively new error
   and leaving it doesn't seem to effect how the program runs.
2. #parag unroll usually only works for a data structure of a fixed size. I used a Map which did not have a fixed size.
3. I tried fixing this error also, but again it's really hard to find anything on this error online. It seems like I needed
   to not depend on a variable on the loop which I couldn't do for these loops
4. I didn't define a copy constructor, assignment operator, move constructor, or move assignment operator for the EnrollmentSystem
   class or the University class. I didn't see much of a relevance in creating these for this specific application  becuase they're
   not used and it would give me errors if I didn't use them if I created them.