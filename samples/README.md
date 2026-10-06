# Примеры

Чтобы собрать конкретный пример из корня репозитория, укажи имя его подпапки:

```sh
make -C samples interface
```

Из папки `samples` команда та же, без `-C`:

```sh
make interface
```

Можно собрать и запустить пример прямо из его папки:

```sh
cd samples/interface
make
make run
```

Исполняемый файл появится в корневой папке `.executables` под именем примера, например `.executables/interface`.
