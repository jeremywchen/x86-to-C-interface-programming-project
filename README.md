# x86-to-C interface programming project
By Chen, Jeremy Wertheim and Ortiz, Ma China

This program is designed to evaluate the performance of both x86_64 assembly language and C programming in computing the dot product of two single-precision float vectors. The program accepts an integer n as input, which specifies the length of the vectors. Additionally, it requires two single-precision float vectors A and B, each of length n, and a single-precision float variable sdot. The assembly function for calculating the dot product is contained within sdot.asm, while the C function for the same operation, along with the mechanism for measuring the execution time of both the C and assembly functions, is implemented in main.c.

# Average Execution Times after 30 Runs



# Comparative Analysis of the Results
 For the kernels, vector A and vector B are arrays of sizes 20, 24, and 28 where all entries are 1.<br />

 ## Debug Mode
 As seen from the results for debug mode, the run time in assembly is faster than C and this is more apparent in larger sample sizes. When the vector size becomes larger, the time complexity between both languages becomes more apparent. When the vector size is 20, C runs at an average of 0.004800 seconds (4.8 milliseconds) in our machine while ASM runs at an average of 0.001800 seconds (1.8 milliseconds). This result does not show a significant difference between the languages but when the vector size is 28, the difference is much more apparent as the runtime in C is 1.026000 seconds while ASM runtime was 0.358867 seconds. Likewise, the language's runtime as the vector size grows is much greater in C than in Assembly. One of the reasons for this is C still goes through a compiler and other processes to translate the C code into machine language. This advantage can be attributed to the direct mapping between assembly language and machine language, which bypasses the need for a compiler to translate C code into machine instructions. The ability to directly manipulate the machine code allows for more efficient use of resources, such as registers, which can significantly impact performance. Additionally, C code includes overhead for features like memory management, type checking, and function calls, which can slow down execution. In contrast, assembly code is more streamlined and executes more efficiently without these overheads.

### Release Mode
 In release mode, the results differ greatly. For all vector sizes, ASM runs slower than C however not by significant margins. When the vector size is 2^20, the average runtime in C is 0.001733 seconds while in ASM it is 0.001800 seconds. When the vector size is 2^28, the average C runtime is 0.348800 seconds while in ASM it's 0.367733 seconds. As mentioned, the difference in runtime between languages is not significant. This is attributed to compiler optimizations. Release mode enables compiler optimizations that are not present in debug mode. These optimizations can include loop unrolling, function inlining, and more aggressive dead code elimination, which can significantly reduce the execution time of C code. Assembly code, being directly translated to machine code without such optimizations, may not benefit from these improvements

To conclude, in debug mode, compilers often include additional checks and debugging information that can slow down execution. Assembly code, being directly translated to machine code without overhead, can execute more efficiently in debug mode compared to C.  However, modern C compilers have made significant strides in optimizing code, reducing the performance gap between C and assembly in release mode. 

 <br />
 For testing, we used 2^28 as the max because 2^29 and 2^30 were too large for the machine to complete running. This includes the correctness check of the output. As the vectors are only filled with 1s the expected output is 2^n.

# Screenshots of the program output including the correctness check
 Vector size: 2^20<br />
  Debug mode<br />
  ![20vector debug](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/defa8a22-6fce-4036-b98a-2d71af077434)

  Release mode<br />
  ![20 vector release](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/16d81906-82d6-4874-a697-494360f59301)
  
 Vector size: 2^24<br />
  Debug mode<br />
  ![24vector debug](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/d474cb4d-4669-4b8b-b686-95c2505d324d)
  
  Release mode<br />
  ![24 vector release](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/c5bc7ebc-8562-43ff-9402-91a7a5c63b2f)

 Vector size: 2^28<br />
  Debug mode<br />
  ![28vector debug](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/ef03b3b8-587a-4e99-baa7-8b74e38c8319)

  Release mode<br />
  ![28 vector release](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/22f92c19-e796-431b-9d66-10f5798c1556)
