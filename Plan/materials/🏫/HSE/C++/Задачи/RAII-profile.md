## Условие
Написать класс, каждый объект которого печатает на стандартный поток вывода своё время жизни

## Решения
### 一
Проблема: если скопировать – у копии не поменяется время создания
```c++
#include <chrono>
#include <iostream>

class Lifetime {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

public:
    Lifetime() = default;

    ~Lifetime() {
        std::chrono::duration<double> elapsed =
            std::chrono::steady_clock::now() - start;

        std::cout << "Время жизни: " << elapsed.count() << " с\n";
    }
};
```
