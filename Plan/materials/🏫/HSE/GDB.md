### Установка
- `brew install gdb`
- `sudo apt install gdb`
### Сборка и запуск
- `-g`, `-O0`
- `clang -std=c17 -Wall -Wextra -g -O0 average.c -o average`
- `gdb ./average`, `gdb ./char_sum`

### Программа и точки останова
- `file ./average`
- `list main`
- `break main`
- Точка останова внутри цикла

### Выполнение
- `run`
- `next` / `n`, `step` / `s`
- `continue` / `c`
- `quit` / `q`

### Переменные и выражения
- `print a`, `print b`, `print a + b`
- `print result`
- `print c`, `print /c c`, `print /x c`
- `print sum`
- `display c`, `display /x c`, `display sum`
- <span style="color: #808080;"><code style="color: inherit;">watch result</code>, <code style="color: inherit;">watch sum</code></span>

### Ввод с терминала
- `run < /dev/tty`
- Enter, Ctrl+D, Ctrl+C
