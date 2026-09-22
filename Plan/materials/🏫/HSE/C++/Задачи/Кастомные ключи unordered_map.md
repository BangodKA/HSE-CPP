## Условие

Создать тип `Key` с двумя строковыми полями и одним целочисленным полем. Реализовать для него
сравнение на равенство и хэш, чтобы `Key` можно было использовать как ключ
`std::unordered_map<Key, int>`.

Добавить функцию:

```cpp
std::optional<int> FindValue(
    const std::unordered_map<Key, int>& values,
    const Key& key);
```

Функция должна:

- искать элемент через `find`, не используя `operator[]`;
- возвращать найденное значение;
- возвращать `std::nullopt`, если ключ отсутствует;
- не изменять контейнер.


## Решения
### 一
```x++
```cpp
template <>
struct std::hash<Key>
{
  std::size_t operator()(const Key& k) const
  {
    using std::size_t;
    using std::hash;
    using std::string;

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return ((hash<string>()(k.first)
             ^ (hash<string>()(k.second) << 1)) >> 1)
             ^ (hash<int>()(k.third) << 1);
  }
};
```

### 二
