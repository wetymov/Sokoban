# Sokoban in console C++

Sokoban (Soko-Ban, яп. 倉庫番, сокобан — кладовщик) — двухмерная компьютерная игра-головоломка, в которой игроку необходимо расставить ящики по обозначенным местам лабиринта. Кладовщик одновременно может двигать только один ящик, толкая вперёд.

Игра Sokoban была создана в 1981 году Хироюки Имабаяси, и издана в 1982 году японской компанией Thinking Rabbit[en]. Кроме того, компания выпустила три сиквела: Boxxle, Sokoban Perfect и Sokoban Revenge.

Игра была реализована для множества компьютерных платформ, включая практически все домашние и персональные компьютеры. Также существуют версии игры для карманных компьютеров, игровых приставок, цифровых фотоаппаратов, мобильных телефонов и телевизоров.

![GIF_SOKOBAN](https://upload.wikimedia.org/wikipedia/commons/4/4b/Sokoban_ani.gif)

Визуализированный пример решения


Больше о игре вы можете узнать на [Википедии](https://ru.wikipedia.org/wiki/Sokoban)


## О файлах
### SokobanEngine.h
-----------

В файле SokobanEngine.h реализован класс управления игроком на поле

|  Метод        |       Действие                   |
|:-------------:|:--------------------------------:|
| print_Board() |    Вывод игровой доски в консоль |
|   move_up()   | Перемещение игрока вверх         |
|  move_down()  | Перемещение игрока вниз          |
|  move_left()  | Перемещение игрока влево         |
| move_right()  | Перемещение игрока вправо        |
|  get_score()  | Получить количество очков        |
|   restart()   | Перезапустить уровень            |


### LevelGenerator.h
-----------
В файле LevelGenerator.h реализован класс создания класса уровня

Сам же уровень по своей сути представляет вектор из векторов строк
vector<vector<string\>>


|  Метод        |       Действие                   |
|:-------------:|:--------------------------------:|
|   Level(int)  | Конструктор уровня с числовым аргументом |
|   Level()     | Конструктор уровня без передачи аргумента(изначально уровень - 1)     |
|  get_level()  | Возвращает  |

### Game.h
-----------

Класс Game реализован для сбора уровня и игрового движка

|  Метод        |       Действие                   |
|:-------------:|:--------------------------------:|
|     menu()    |    Выбор уровня |
|   start_game()   | Запуск уровня         |


#### Управлевние
| Кнопка |       Действие        |
|:------:|:---------------------:|
| W      |    Движение вверх     |
| A      |    Движение влево     |
| S      |     Движение вниз     |
| D      |    Движение вправо    |
| R      | Перезагрузить уровень |


## Запуск

docker file расписывать мне было лень, поэтому здесь есть CMake
