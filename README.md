x86-to-C interface programming project
Chen, Jeremy Wertheim and Ortiz, Ma China

 i.) 
 As seen from the results, the run time in assembly is faster than C and this is more apparent in larger sample sizes. When the vector size becomes larger, the time complexity between both languages become more apparent. As seen in the pictures of the results, As the vector size grows, the difference in runtime between the C program and asm program is more apparent. Likewise, the runtime as the vector size grows is much greater in C than asm. One of the reasons for this is C still goes through a compiler and other processes to translate the C code into machine language. Assembly doesn't need a compiler  but instead is directly mapped from between assembly language and machine language by the assembler. So the arithmetic operations in the calculation would be "translated" faster in assembly language.
 
 ii & iii.)
 For testing, we used 2^28 as the max because 2^29 and 2^30 were too large for the machine to complete running.

 Vector size: 2^20<br />
  ![20vector](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/5e12ac04-3f7d-404d-8aae-e098811138d2)
 
 Vector size: 2^24<br />
  ![24vector](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/9d5ab46b-c029-4d29-bc19-6eea4e1b0316)


 Vector size: 2^28<br />
  ![28vector](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/1519cb33-75f9-4282-98aa-2f3279ba8430)
