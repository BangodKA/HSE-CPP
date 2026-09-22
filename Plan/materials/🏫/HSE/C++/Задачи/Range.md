## Условие
### 一

Добиться того, чтобы компилировался и работал ожидаемым образом следующий код:

```c++
for (int x : Range(10)) {
    std::cout << x << std::endl;
}
```

Из чего состоит:
```c++
const range = Range{10};
for (auto it = range.begin(); it [</!=] range.end(); ++it) {
	std::cout << *it << std::endl;
}
```

**Важно: нельзя хранить весь диапазон в памяти**
### 二
Поддержать Range(start, stop, step) с вещественным счётчиком и диапазоном. Возникает проблема: в вещественных числах сложно гарантировать, где остановится счетчик 

Как решение, можно использовать begin и end разных типов, и показать, что operator!= может содержать произвольную логику.**
### 三
Добавить поддержку `operator++(int)` и `operator->`

## Решение

### 一
```c++
class It {
public:
	explicit It(const int current): current_(current) {}
	
	It& operator++() {
		++current_;
		return *this;
	}

	int operator*() const { return current_; }

	bool operator==(const It other) { return current_ == other.current_; }

private:
	int current_;
};

class Range {
public:
	explicit Range(const int end): end_(end) {}
	
	It begin() const { return It{0}; }
	It end() const { return It{end_}; }

private:
	int end_;
};

```

### 三
```c++
It operator++(int) {
	int prev = current_;
	++current_;
	return It{prev};
}

// особо смысла не имеет
const int* operator->() const {
    return &current_;
}

```
