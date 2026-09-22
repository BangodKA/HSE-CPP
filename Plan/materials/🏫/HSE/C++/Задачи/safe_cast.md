## Условие
### 一
Выбрать два произвольных целых типа, используя `numeric_limits`, написать кусок кода, приводящий значение одного из этих типов к другому, если это возможно без потери данных и переполнения в противном случае позвать `abort`/`exit`/что-нибудь ещё
### ニ
Сделать функцию safe_cast, которая безопасно кастует один интегральный тип в другой

Для проверки интегральности можно посмотреть [концепты](https://en.cppreference.com/w/cpp/language/constraints) (`is_integral` https://en.cppreference.com/w/cpp/concepts/integral)

```c++
template<typename T>
concept integral=std::is_integral_v<T>
```
## Решение
### 一
### ニ
```c++
template <std::integral Source, std::integral Destination>

Destination safe_cast(Source val) {

	if (std::numeric_limits<Source>::is_signed != std::numeric_limits<Destination>::is_signed) {
	
		if (!std::numeric_limits<Destination>::is_signed) {
			if (val != static_cast<Destination>(val)) {
				exit(1);
			}
		}
	}
	
	if (val > std::numeric_limits<Destination>::max()
		|| val < std::numeric_limits<Destination>::min()) {
		exit(1);
	}
	
	return static_cast<Destination>(val);
}
```
