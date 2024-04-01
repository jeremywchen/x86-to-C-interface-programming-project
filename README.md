x86-to-C interface programming project
Chen, Jeremy Wertheim and Ortiz, Ma China

 i.) 
 As seen from the results, the run time in assembly is faster than C and this is more apparent in larger sample sizes. When the vector size becomes larger, the time complexity between both languages become more apparent. As seen in the pictures of the results, As the vector size grows, the difference in runtime between the C program and asm program is more apparent. Likewise, the runtime as the vector size grows is much greater in C than asm. One of the reasons for this is C still goes through a compiler and other processes to translate the C code into machine language. Assembly doesn't need a compiler  but instead is directly mapped from between assembly language and machine language by the assembler. So the arithmetic operations in the calculation would be "translated" faster in assembly language.
 
 ii & iii.)
 For testing, we used 2^28 as the max because 2^29 and 2^30 were too large for the machine to complete running.
 
 Equation for sum of squares: (n(n + 1)(2n + 1)) / 6 <br />
 ![sum of squares](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/97a46f67-f6a0-4de7-b282-f171498ac2c8)

 Vector size: 2^20<br />
  ![20vector](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/949e19b7-0165-4cc1-8945-1170fc894aa3)

 
 Vector size: 2^24<br />
  ![24vector](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/c02c3313-de79-4ddc-bbae-38c5e4d23160)


 Vector size: 2^28<br />
  ![28vector](https://github.com/jeremywchen/x86-to-C-interface-programming-project/assets/92730916/f27734d8-1872-47b2-8dde-8dd291b01619)
