#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <linux/seccomp.h>
#include <linux/filter.h>
#include <linux/audit.h>
#include <sys/ptrace.h>
#include <fcntl.h>

void say_hello()
{
   printf("Can you drive with a blindfold?\n");
}

char* get_flag()
{
   char* flag = (char*)malloc(0x100);
   int i = 0;
   int fd = open("/flag", O_RDONLY);
   while (1)
   {
	  int result = read(fd, flag+i, 1);
	  if (result != 1)
	  {
		 break;
	  }
	  i += 1;
   }
   flag[i] = '\0';
   close(fd);
   return flag;
}

void shellcode_it(char* buf, unsigned int size)
{

   char* flag = get_flag();

   void *ptr = mmap(0, size, PROT_EXEC | PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
   void (*shell)(char*);
   memcpy(ptr, buf, size);


   // Close all possible communication channels
   close(0);
   close(1);
   close(2);

   if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT) != 0)
   {
	  exit(-1);
   }

   shell = (void (*)(char*)) ptr;
   shell(flag);

   return;
}

void get_that_shellcode()
{
   char buf[513];
   int num;
   int i;
   printf("Send me your vehicle\n");
   num = read(0, buf, 512);
   buf[512] = '\0';
   for (i = 0; i < num; i++)
   {
	  if (buf[i] == '\0')
	  {
		 printf("Failed smog inspection.\n");
		 return;
	  }
   }

   shellcode_it(buf, num);
}


int main(int argc, char** argv)
{
   setvbuf(stdout, NULL, _IONBF, 0);

   if (getenv("DEBUG") == NULL)
   {
	  alarm(5);
   }

   say_hello();
   get_that_shellcode();
   exit(0);
}
