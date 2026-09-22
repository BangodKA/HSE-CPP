- Move семантика
    - Copy elision
        - RVO, NRVO (оптимизация копии return<->возвращаемый тип)
        - Инициализация временным объектом и передача временного объекта в качестве аргумента функции (оптимизации копии вызов функции<->куда его кладем)
	*  r-value vs l-value vs x-value
		* https://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues
		* ![[cpp-fall-20260922/materials/🏫/HSE/C++/Images/Pasted image 20260314230744.png|Pasted image 20260314230744.png]]
	* `std::move`
	    - Рассмотреть, пример имплементации move (ниже) и объяснить, что move просто говорит: этот объект не нужен, его можно использовать, как угодо. move участвует только на этапе компиляции
	    - Передается всегда lvalue-ссылка (внутри функции все параметры – lvalue), поэтому даже && нужно move (либо всегда move, либо временный объект) (and implicit conversion from lvalue to rvalue reference is forbidden by standard).
		* https://stackoverflow.com/questions/7510182/how-does-stdmove-convert-expressions-to-rvalues
```cpp
template <typename T>
typename remove_reference<T>::type&& move(T&& arg)
{
  return static_cast<typename remove_reference<T>::type&&>(arg);
}
```

* [Rule of five, rule of zero](https://en.cppreference.com/w/cpp/language/rule_of_three)
- Move конструкторы и move операторы присваивания
- Перемещаемые, но не копируемые объекты на примере `std::unique_ptr`
