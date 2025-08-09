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

//���������� ���� � ��� �� ������ ������� ��������
void thprint()
{    
    std::thread::id threadId = std::this_thread::get_id();    
    static int i = 0;    
    printf("SkyNet:\t>  �� ������_0:   [  %i  ]  �� ��������_0  [  %i  ] ������_0 >  [  %s  ]\n", threadId, i++, gen_random(18).c_str());
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
    for (size_t i = 0; i < 100; i++) //1000 �����
    {
        //�������� �� �� ������� �� 10%        
        //thw->beginThread(thprint);//����������� �������
        thw->beginThread(thprint);
        /*thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);
        thw->beginThread(thprint);*/

        //���� � �����������
        std::thread::id threadId = std::this_thread::get_id();
        static int d = 0;
        
        //�������� �� �� ������� �� 10%
        thw->beginThreadex(printf, "SkyNet:\t>  �� ������_0:   [  %i  ]  �� ��������_0  [  %i  ] ������_0 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        /*thw->beginThreadex(printf,"����� ������� �� ������� ������_1\t>  �� ������_1:   [  %i  ]  �� ��������_1  [  %i  ] ������_1 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_2\t>  �� ������_2:   [  %i  ]  �� ��������_2  [  %i  ] ������_2 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_3\t>  �� ������_3:   [  %i  ]  �� ��������_3  [  %i  ] ������_3 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_4\t>  �� ������_4:   [  %i  ]  �� ��������_4  [  %i  ] ������_4 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_5\t>  �� ������_5:   [  %i  ]  �� ��������_5  [  %i  ] ������_5 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_6\t>  �� ������_6:   [  %i  ]  �� ��������_6  [  %i  ] ������_6 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_7\t>  �� ������_7:   [  %i  ]  �� ��������_7  [  %i  ] ������_7 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_8\t>  �� ������_8:   [  %i  ]  �� ��������_8  [  %i  ] ������_8 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());
        thw->beginThreadex(printf, "����� ������� �� ������� ������_9\t>  �� ������_9:   [  %i  ]  �� ��������_9  [  %i  ] ������_9 >  [  %s  ]\n", threadId, d++, gen_random(18).c_str());*/
     
        exec(7);

        string title;

        title.resize(256);
        sprintf(&title[0], "��� ���������� > %s | ����� ��������� > %i | ������ > %i", gen_random(18).c_str(),d++, thw->GetCountErrors());
        
        //thw->beginThreadex(SetConsoleTitleA,title.c_str());// �������� �� ������� ��������� � �� ��������� - ��������� �����      
        //sleep(1000);//�������� 10 �����������, ��� � ������ Anomaly ��� ��������� ������� �������
    }
    printf("��������� ����� ���������! �������� ������ %i", thw->GetCountErrors());
    for (;;);
    //system("pause");
    return 0;   // Program successfully completed.
}