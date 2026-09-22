## Условие
В некоторых языках, например в Go и Swift, есть ключевое слово defer. В Go не существует ни исключений (exceptions), ни деструкторов, поэтому идиома для очистки ресурсов - прямое указание языку вызвать cleanup-метод по выходу из функции.

```go
func write(fileName string, text string) error {
	file, err := os.Create(fileName)
	if err != nil {
		return err
	}
	defer file.Close() // ... сколько угодно return-ов, file.Close() всегда вызовется
}
```


## Решения
### 一
https://habr.com/ru/articles/576052/
https://www.reddit.com/r/cpp/comments/s6tzcn/golanglike_defer_operation_in_c/
https://stackoverflow.com/questions/33050620/golang-style-defer-in-c
### 二
