## Условие

### UniquePtrInt
Сделать класс UniquePtrInt
`explicit unique_ptr( pointer p ) noexcept;`
### Rule-of-3
- Удаление конструктора и присвоения
- Добавление `operator->`
	- Тут посмотреть, что можем обращаться к полям внутренней структуры
### Rule-of-5
- Добавление move-конструктора и присвоения