## Проблема
[rollbar] Unhandled exception: Failed writing to file cmake/.cmake/api/v1/query/client-vscode/query.json Error: EROFS: read-only file system, mkdir 'cmake' {}

## Возможные решения
### 一
Проблемы с разрешениями
`sudo chown -R <username> cmake`

### 二
Закончилась память

### 三
Аккуратно сделать по инструкции