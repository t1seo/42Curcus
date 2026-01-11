# libasm

## Project Overview

libasm is a project to implement basic libc functions in x86-64 assembly language. It teaches assembly programming fundamentals and system call invocation methods.

## Required Functions

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_strlen` | `size_t ft_strlen(char *str)` | Return string length |
| `ft_strcpy` | `char *ft_strcpy(char *dst, const char *src)` | Copy string |
| `ft_strcmp` | `int ft_strcmp(const char *s1, const char *s2)` | Compare strings |
| `ft_write` | `ssize_t ft_write(int fd, const void *buf, size_t n)` | Write to file |
| `ft_read` | `ssize_t ft_read(int fd, void *buf, size_t n)` | Read from file |
| `ft_strdup` | `char *ft_strdup(const char *s)` | Duplicate string |

## Structure

```
libasm/
├── Makefile
├── main.c           # Test code
└── srcs/
    ├── libasm.h     # Header file
    ├── ft_strlen.s  # strlen implementation
    ├── ft_strcpy.s  # strcpy implementation
    ├── ft_strcmp.s  # strcmp implementation
    ├── ft_write.s   # write implementation
    ├── ft_read.s    # read implementation
    └── ft_strdup.s  # strdup implementation
```

## x86-64 Assembly Basics

### Registers

| Register | Purpose |
|----------|---------|
| `rax` | Return value, syscall number |
| `rdi` | First argument |
| `rsi` | Second argument |
| `rdx` | Third argument |
| `rcx` | Fourth argument / loop counter |
| `r8` | Fifth argument |
| `r9` | Sixth argument |

### System Calls (Linux)

| System Call | Number (rax) |
|-------------|--------------|
| read | 0 |
| write | 1 |

### Instruction Examples

```asm
section .text
    global ft_strlen

ft_strlen:
    xor rax, rax            ; rax = 0 (counter)
.loop:
    cmp byte [rdi + rax], 0 ; Check if current char is null
    je .done                ; If null, exit
    inc rax                 ; Increment counter
    jmp .loop               ; Continue loop
.done:
    ret                     ; Return length in rax
```

### ft_write Implementation Example

```asm
section .text
    global ft_write
    extern __errno_location

ft_write:
    mov rax, 1              ; syscall number (write)
    syscall                 ; Execute syscall
    cmp rax, 0              ; Check for error
    jl .error               ; If negative, error
    ret

.error:
    neg rax                 ; Convert error code to positive
    push rax                ; Save error code
    call __errno_location wrt ..plt  ; Get errno address
    pop qword [rax]         ; Store error code in errno
    mov rax, -1             ; Return -1
    ret
```

## Build

```bash
make        # Generate libasm.a
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild
```

## Test

```bash
# Compile
make
gcc main.c -L. -lasm -o test

# Run
./test
```

## Notes

### errno Handling
`ft_read` and `ft_write` must set errno on error.

### Calling Convention
- x86-64 System V ABI compliant
- Arguments: rdi, rsi, rdx, rcx, r8, r9 in order
- Return value: rax
- Caller-saved registers: rax, rcx, rdx, rsi, rdi, r8-r11
- Callee-saved registers: rbx, rbp, r12-r15

### NASM Syntax
```asm
section .data    ; Initialized data
section .bss     ; Uninitialized data
section .text    ; Code

global func_name ; Externally accessible
extern other_func ; Use external function
```

## References

- [x86-64 System Call Table](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
- [NASM Manual](https://www.nasm.us/doc/)
- [x86-64 ABI](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
