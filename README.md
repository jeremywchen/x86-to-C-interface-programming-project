x86-to-C interface programming project
Chen, Jeremy Wertheim and Ortiz, Ma China

 For the kernels, vector A and vector B are arrays of sizes 20, 24, and 28 where all elements are 1.<br />
 i.) 
 As seen from the results for debug mode, the run time in assembly is faster than C and this is more apparent in larger sample sizes. When the vector size becomes larger, the time complexity between both languages become more apparent. When the vector size is 20, C runs at an average of 0.004800 seconds in our machine while ASM runs at an average of 0.001800 seconds. This result doesn't show a significant difference between the languages but when the vector size is 28, the difference is much more apparent as the runtime in C is 1.026000 seconds while ASM runtime was 0.358867 seconds. Likewise, the language's runtime as the vector size grows is much greater in C than ASM. One of the reasons for this is C still goes through a compiler and other processes to translate the C code into machine language. Assembly doesn't need a compiler but instead is directly mapped from between assembly language and machine language by the assembler. So the arithmetic operations in the calculation would be "translated" faster in assembly language.

 In release mode, the results differ greatly. For all vector sizes, ASM runs slower than C however not by significant margins. When the vector size is 2^20, the average runtime in C is 0.001733 seconds while in ASM it is 0.001800 seconds. When the vector size is 2^28, the average C runtime us 0.348800 seconds while in ASM it's 0.367733 seconds. As mentioned, the difference in runtime between languages aren't significant and one of the most possible reason for this is release mode is more optimized as the compiler runs the code faster and uses less memory.
 
 ii & iii.)
 For testing, we used 2^28 as the max because 2^29 and 2^30 were too large for the machine to complete running.

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
