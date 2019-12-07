#include <windows.h>
#include <stdio.h>

void Execute (char* str)
{
    for (int i=0; i<strlen (str); i++)
    {
        if (str[i] == '\t')
         printf ("___");
        else
         if (str[i] == ' ')
          printf ("_");
         else
          printf ("%c", str[i]);
    }
    printf ("\n");
}

int main(int argc, char* argv[])
{
    if (argc <=1)
    {
      printf ("Not enough parametres!");
      return 0;
    }


    // динамическая переменная под количество прочитанных байт
    PDWORD lpNumberOfBytesWritten = new DWORD;

    // создаем файл, который будет отображаться
    HANDLE MyFile=CreateFile("File-mapping.txt",
                              GENERIC_WRITE,
                              FILE_SHARE_WRITE, NULL,
                              CREATE_ALWAYS,
                              FILE_ATTRIBUTE_NORMAL,0);

    // проверка на создание файла
    if (!MyFile)
    {
       printf ("Error of opening file (write)!");
       getchar();
       return 0;
    }


    char result[1000] = "";

    for (int i=1; i<argc; i++)
    {
       strcat (result, argv[i]);
       strcat (result, " ");
    }

    // пишем в файл строку
    WriteFile(MyFile,result,strlen(result),lpNumberOfBytesWritten,NULL);

    // все закрываем
    SetEndOfFile(MyFile);
    CloseHandle(MyFile);

    // открываем файл в режиме чтения
    MyFile=CreateFile("File-mapping.txt",
                       GENERIC_READ,
                       FILE_SHARE_READ,NULL,
                       OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL,0);

    // проверка на создание файла
    if (!MyFile)
    {
       printf ("Error of opening file (read)!");
       getchar();
       return 0;
    }

    // создаем проекцию файла в память
    HANDLE MappedFile=CreateFileMapping(MyFile,NULL,
                                    PAGE_READONLY,0,0,
                                    NULL);


    // проверка на создание проекции файла
    if (!MappedFile)
    {
       printf ("Error of mapping!");

       getchar();

       return 0;
    }


    // копируем проекцию в адресное пространство основного процесса
    LPVOID Map = MapViewOfFile(MappedFile,FILE_MAP_READ, 0,0,0);

    // выводим на экран
    char* strin =(char*) Map;
    Execute (strin);

    // отменяем проецирование на адресное пространство процесса
    UnmapViewOfFile(Map);

    // закрываем проекцию
    CloseHandle(MappedFile);

    // закрываем файл
    CloseHandle(MyFile);

    system ("pause");

    return 0;
}
