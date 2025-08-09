#include "main.h"

using namespace std;

string gen_random(const int len)
{
    string s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];

    s[len] = 0;

    return s;
}

//используем один и тот же ресурс разными потоками
void thprint()
{    
    std::thread::id threadId = std::this_thread::get_id();    
    static int i = 0;    
    printf("SkyNet:\t>  ид потока_0:   [  %i  ]  ид операции_0  [  %i  ] строка_0 >  [  %s  ]\n", threadId, i++, gen_random(18).c_str());
}

void sleep(int timeout)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
}

int main()
{    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    auto thw = ThreadWrapper::create();
    for (size_t i = 0; i < 100; i++) //1000 задач
    {
        //нагрузка на ЦП спадает на 10%        
        //thw->beginThread(thprint);//оптимальный вариант
        thw->beginThread(thprint);
        /*thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);*/

        //тест с аргументами
        std::thread::id threadId = std::this_thread::get_id();
        static int d = 0;
        
        //нагрузка на ЦП спадает на 10%
        thw->beginThreadex(printf, "SkyNet:\t>  ид потока_0:   [  %i  ]  ид операции_0  [  %i  ] строка_0 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        /*thw->beginThreadex(printf,"битва потоков за ресурсы памяти_1\t>  ид потока_1:   [  %i  ]  ид операции_1  [  %i  ] строка_1 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_2\t>  ид потока_2:   [  %i  ]  ид операции_2  [  %i  ] строка_2 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_3\t>  ид потока_3:   [  %i  ]  ид операции_3  [  %i  ] строка_3 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_4\t>  ид потока_4:   [  %i  ]  ид операции_4  [  %i  ] строка_4 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_5\t>  ид потока_5:   [  %i  ]  ид операции_5  [  %i  ] строка_5 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_6\t>  ид потока_6:   [  %i  ]  ид операции_6  [  %i  ] строка_6 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_7\t>  ид потока_7:   [  %i  ]  ид операции_7  [  %i  ] строка_7 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_8\t>  ид потока_8:   [  %i  ]  ид операции_8  [  %i  ] строка_8 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "битва потоков за ресурсы памяти_9\t>  ид потока_9:   [  %i  ]  ид операции_9  [  %i  ] строка_9 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());*/
     
        exec(7);

        string title;

        title.resize(256);
        sprintf(&title[0], "имя приложения > %s | задач выполнено > %i | ошибок > %i", gen_random(18).c_str(),d++, thw->GetCountErrors());
        
        //thw->beginThreadex(SetConsoleTitleA,title.c_str());// нагрузка на процесс программы и на процессор - отдельный поток      
        //sleep(1000);//задержка 10 миллисекунд, как в движке Anomaly при обработке игровых событий
    }
    printf("Обработка задач завершена! Выявлено ошибок %i", thw->GetCountErrors());
    for (;;);
    //system("pause");
    return 0;   // Program successfully completed.
}