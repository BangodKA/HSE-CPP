## Условие
Написать функцию popcnt, которая считает число ненулевых битов

## Решение
### 一
Прямолинейное решение за линию

### 二
Решение за O(количества единиц), где N – число битов
**Алгоритм Брайана Кернигана**
```c++
unsigned int countSetBits(int n) {
	unsigned int count = 0;
	while (n) {
		n &= (n - 1);
		count++;
	}
	return count;
}

```

**Рекурсия**
```c++
int countSetBits(int n) {
	// base case
	if (n == 0)
		return 0;
	else
		return 1 + countSetBits(n & (n - 1));
}
```

### 三
**Решение на масках**
```c++
int numberOfSetBits(uint32_t i)
{
     i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
     i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
     i *= 0x01010101;                        // horizontal sum of bytes
     return  i >> 24;               // return just that top byte (after truncating to 32-bit even when int is wider than uint32_t)
}
```
