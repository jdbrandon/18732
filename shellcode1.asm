Section   .text
     global _start

;_start:
;     jmp short GotoCall
;shellcode:
;     pop esi
;     xor eax, eax
;     mov byte [esi + 7], al
;     mov byte [esi + 10], al
;     mov byte [esi + 23], al
;     mov byte [esi + 24], al
;     lea ebx, [esi]
;     mov long [esi + 25], ebx
;     mov long [esi + 29], eax
;     mov byte al, 0x0b
;     mov ebx, esi
;     lea ecx, [esi + 25]
;     lea edx, [esi + 29]
;     int 0x80
;
;GotoCall:
;     Call shellcode
;     db '/bin/shJ-cJ"echo Hello"JJAAAAKKKK'

_start:
     jmp short arg3
align 4
shellcode:
     pop esi
     xor eax, eax
     mov byte [esi + 7], al
     lea ebx, [esi]
     mov long [esi + 8], ebx
     mov long [esi + 12], eax
     mov byte al, 0x0b
     mov ebx, esi
     ;lea ecx, [esi + 8]
     lea ecx, [esi]
     lea edx, [esi + 12]
     int 0x80
arg3:
     xor eax, eax
     sub long esp, 0x4
     mov long [esp], eax
arg2:
     Call arg1
     db 'echo HelloJ'
arg1:
     pop esi
     push esi
     mov byte [esi + 0xa], al
     Call arg0
     db '-cJ'
arg0:
     pop esi
     push esi
     mov byte [esi + 0x2], al
     Call shellcode
     db '/bin/shJAAAAKKKK'
