# La Piscine

## Project Overview

La Piscine (The Pool) is a 4-week intensive programming bootcamp for admission to 42 Seoul. It teaches C language and shell scripting basics while adapting to 42's educational approach.

## Structure

```
la_piscine/
├── Shell00/     # Shell basics
└── Shell01/     # Advanced shell
```

## Shell00 - Shell Basics

### Topics
- Basic shell commands
- File permissions
- I/O redirection
- Pipes

### Key Commands

| Command | Description |
|---------|-------------|
| `ls` | List files |
| `cd` | Change directory |
| `pwd` | Print working directory |
| `chmod` | Change file permissions |
| `cat` | Display file contents |
| `touch` | Create empty file/update timestamp |
| `mkdir` | Create directory |
| `rm` | Remove files/directories |
| `cp` | Copy files |
| `mv` | Move/rename files |

### File Permissions

```bash
# Format: rwxrwxrwx (owner/group/others)
chmod 755 file  # rwxr-xr-x
chmod 644 file  # rw-r--r--
chmod u+x file  # Add execute permission for owner
```

## Shell01 - Advanced Shell

### Topics
- Regular expressions
- sed, awk
- Environment variables
- Shell scripting

### Key Commands

| Command | Description |
|---------|-------------|
| `grep` | Pattern search |
| `sed` | Stream editor |
| `awk` | Text processing |
| `find` | File search |
| `wc` | Word/line count |
| `sort` | Sort |
| `uniq` | Remove duplicates |
| `cut` | Cut text |
| `tr` | Character translation |
| `head/tail` | Display beginning/end |

### grep Examples

```bash
grep "pattern" file         # Basic search
grep -r "pattern" dir/      # Recursive search
grep -i "pattern" file      # Case insensitive
grep -n "pattern" file      # Show line numbers
grep -v "pattern" file      # Inverse match
```

### sed Examples

```bash
sed 's/old/new/' file       # Replace first match only
sed 's/old/new/g' file      # Replace all matches
sed -n '5p' file            # Print only line 5
sed '1d' file               # Delete first line
```

### awk Examples

```bash
awk '{print $1}' file       # Print first field
awk -F: '{print $1}' file   # Specify delimiter
awk 'NR==5' file            # Print line 5
awk '{sum+=$1} END {print sum}' file  # Sum
```

## Piscine Schedule (4 weeks)

### Week 1
- C00: C basics (variables, conditionals, loops)
- Shell00: Shell basics

### Week 2
- C01: Pointer basics
- C02: String handling
- Shell01: Advanced shell

### Week 3
- C03: String functions
- C04: Number handling functions
- C05: Recursive functions

### Week 4
- C06: argc, argv
- C07: Dynamic memory allocation
- C08: Header files, macros
- Rush: Team project

## Evaluation System

- **Peer Evaluation**: Code review with other students
- **Moulinette**: Automated grading system
- **Exams**: Weekly exams

## Required Tools

- **Git**: Version control and assignment submission
- **Vim/Emacs**: Text editor (IDE prohibited)
- **gcc**: C compiler

## Norminette

42's coding style rules:
- Maximum 25 lines per function
- Maximum 80 characters per line
- Maximum 4 parameters per function
- No global variables (in most assignments)
- Use tabs for indentation

```bash
norminette file.c
```

## Tips

1. **Master the Basics**: Thoroughly learn pointers and memory management
2. **Collaborate**: Learn by teaching each other
3. **Use Man Pages**: Check documentation with `man function_name`
4. **Test Thoroughly**: Consider edge cases
5. **Time Management**: 4 weeks is shorter than you think
