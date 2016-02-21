## Chapter 03: System Programming Concepts

**Q:** When using the Linux-specific reboot() system call to reboot the system, the second
argument, magic2, must be specified as one of a set of magic numbers (e.g.,
LINUX_REBOOT_MAGIC2 ). What is the significance of these numbers? (Converting them
to hexadecimal provides a clue.)

**A:**

According with man pages:
```
This system call will fail (with EINVAL) unless magic equals
  LINUX_REBOOT_MAGIC1 (that is, 0xfee1dead) and magic2 equals
  LINUX_REBOOT_MAGIC2 (that is, 672274793).

However, since 2.1.17 also
  LINUX_REBOOT_MAGIC2A (that is, 85072278) and since 2.1.97 also
  LINUX_REBOOT_MAGIC2B (that is, 369367448) and since 2.5.71 also
  LINUX_REBOOT_MAGIC2C (that is, 537993216) are permitted as values for magic2.  (The hexadecimal values of these constants are meaningful.
```

To hex:
```
672274793 = 0x28121969
 85072278 = 0x05121996
369367448 = 0x16041998
537993216 = 0x20112000
```

```
Linus Benedict Torvalds: Born: 28-Dec-1969
Daughter: Patricia Miranda Torvalds (b. 5-Dec-1996)
Daughter: Daniela Yolanda Torvalds (b. 16-Apr-1998)
Daughter: Celeste Amanda Torvalds (b. 20-Nov-2000)
```
