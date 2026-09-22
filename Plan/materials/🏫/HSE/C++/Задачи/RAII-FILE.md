## Условие
Написать RAII-обёртку для С-шного FILE

## Решения
### 一
Проблема: если скопировать – файл дважды закроется
```c++
#include <cstdio>
#include <stdexcept>

class File {
    FILE* file;

public:
    File(const char* path, const char* mode)
        : file(std::fopen(path, mode)) {
        if (!file) {
            throw std::runtime_error("Не удалось открыть файл");
        }
    }

    ~File() {
        std::fclose(file);
    }
};
```
