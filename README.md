# _printf

A custom implementation of the C `printf` function built from scratch for Holberton School.

---

## 📚 Description

The `_printf` function is a simplified re-creation of the standard C `printf` function.  
It formats and prints data according to a format string and a variable number of arguments.

---

## 🧠 Features

This implementation handles the following format specifiers:

| Specifier | Description                      |
|-----------|----------------------------------|
| `%c`      | Character                        |
| `%s`      | String                           |
| `%%`      | Percent sign                     |
| `%d`, `%i`| Signed decimal integer           |
| `%u`      | Unsigned decimal integer         |
| `%o`      | Unsigned octal                   |
| `%x`      | Unsigned hexadecimal (lowercase) |
| `%X`      | Unsigned hexadecimal (uppercase) |
| `%b`      | Binary (custom specifier)        |

---

## 📁 Project Structure

```
.
├── _printf.c
├── call_handler.c
├── handlers.c
├── helpers.c
├── main.h
├── main.c       (for testing)
├── README.md
```

---

## 🛠️ Compilation

Compile all files using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

---

## 🧪 Example Usage

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    _printf("Character: %c\n", 'H');
    _printf("Percent: %%\n");
    _printf("Decimal: %d\n", 123);
    _printf("Unsigned: %u\n", 456);
    _printf("Octal: %o\n", 100);
    _printf("Hex (lower): %x\n", 255);
    _printf("Hex (upper): %X\n", 255);
    _printf("Binary: %b\n", 98);
    return (0);
}
```

---

## ✅ Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Compilation: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- No global variables
- Max 5 functions per file
- Max 40 lines per function
- Betty coding style

---

## ✍️ Authors

- **Joseph Gleason Lopez** – [@JosephGleason](https://github.com/JosephGleason)
- **Kevin Santos** – [@HISvessel](https://github.com/HISvessel)

---

## 📜 License

This project is open-source baby.

