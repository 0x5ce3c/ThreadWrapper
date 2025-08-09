<p align="left">Данная обертка над потоками позволяет быстро использовать функции с аргументами и без них в отдельных потоках, всё ограничивается только лимитом до 5 аргументов.</p>

###

<p align="left">Подключение:</p>

###

<p align="left">1) добавьте файлы:<br>ThreadWrapper.hpp и ThreadWrapper.cpp к вашему проекту.<br>2) подключите заголовочный файл ThreadWrapper.hpp.</p>

###

<p align="left">Использование(примерчики):</p>

###

<p align="left">Перед использованием в начале процедуры или функции необходимо добавить создание уникального поинтера, а затем использовать функции:<br><br>void func1()<br>{<br>//your code<br>}<br><br>void func2(int a, char b, string c, float d, double e)<br>{<br>   //your code<br>}<br><br>void any_func()<br>{<br>  auto thw = ThreadWrapper::create();<br>  thw->beginThread(func1);<br>  thw->beginThreadex(func2, a, b, c, d, e);<br>}</p>

###
