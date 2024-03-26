%include "io64.inc"
section .data
    prompt1 db "[VECTOR 1] Element %d: ", 0
    prompt2 db "[VECTOR 2] Element %d: ", 0
    prompt3 db "Result: %lf"
    var1 dq 0.0
    var2 dq 0.0  
    scanfp db "%lf",0
    

section .text
global main


extern printf, scanf

main:
    sub rsp, 8*7
    
    PRINT_STRING "Enter vector length n: "
    GET_DEC 8, r13
    PRINT_DEC 8, r13
    inc r13
    mov rbx, 1            ; Initialize rbx to 0
    pxor xmm15, xmm15
    NEWLINE
    
L1:
    GET_FLOAT:
        ; scan first element
        lea rcx, [prompt1]
        mov rdx, rbx
        call printf
        
        lea rcx, [scanfp]
        lea rdx, [var1]
        call scanf
        
        movsd xmm14, [var1]
  

        ; scan second element
        lea rcx, [prompt2]
        mov rdx, rbx
        call printf
        
        
        lea rcx, [scanfp]
        lea rdx, [var2]
        call scanf
        
        movsd xmm13, [var2]
        
        ; vevctor operation
        mulsd xmm14, xmm13
        addsd xmm15, xmm14
        
        
        ; loop logic
        NEWLINE
        inc rbx         
        cmp rbx, r13    
        jl L1         
    
    
    lea rcx, [prompt3]
    movq rdx, xmm15
    call printf
        
    add rsp, 8*7     
    xor rax, rax
    ret
