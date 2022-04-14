# CPP_2GIS_Hackathon_april2022
Task and solution
# Coding Test: data search

Для быстрого запуска проекта присутствуют стадии сборки all, clean, test, timetest, example, gcov_report

В проекте реализованы 2 алгоритма поиска подстрок в соответствии с условиями задачи.

Первый алгоритм реализован алгоритмом в тремя уровнями вложенности циклов while.
Второй алгоритм ограничивается двумя уровнями.

Для храния данных в обоих алгоритмах используется контейнер Vector<int8_t>

Краткое описание алгоритмов:

## 1.  findTheSequence()

Мы получаем токен искомого слова, скопировав его от начала до позиции threshold. Затем первую букву этого слова (первый байт) ищем в векторе с использованием стандартного метода find(). После того как мы нашли букву мы копируем в отдельный токен все байты, начиная с этого До threshold.
Скопированные векторы сравниваются с помощью перегруженного оператора ==. Если совпдение нашлось, то мы делаем расширение наших токенов - искомый увеличивается на один (если есть такая возможность) и аналогично скопированный из haystack тоже расширяется, забирая поле haystackOffset + threshold + 1.
