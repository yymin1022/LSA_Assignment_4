#include <linux/syscalls.h>

SYSCALL_DEFINE0(mycall)
{
	printk("20194094 Yongmin Yoo System Call\n");
	return 0;
}
