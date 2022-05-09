#include <stdlib.h>
#include <iostream>
using namespace std;
struct Node       //Структура являющаяся звеном списка
 {
     int x;     //Значение x будет передаваться в список
     Node *Next,*Prev; //Указатели на адреса следующего и предыдущего элементов списка
 };

 class List   //Создаем тип данных Список
 {
     Node *Head,*Tail; //Указатели на адреса начала списка и его конца
 public:
     List():Head(NULL),Tail(NULL){}; //Инициализируем адреса как пустые
     ~List(); //Деструктор
     void Show(); //Функция отображения списка на экране
     void Add(int x); //Функция добавления элементов в список
 };

List::~List() //Деструктор
 {    

     while (Head) //Пока по адресу на начало списка что-то есть
     {
         Tail=Head->Next; //Резервная копия адреса следующего звена списка 
         delete Head; //Очистка памяти от первого звена 
         Head=Tail; //Смена адреса начала на адрес следующего элемента 
     }
 }
 void List::Add(int x){
   Node *temp=new Node; //Выделение памяти под новый элемент структуры
   temp->Next=NULL;  //Указываем, что изначально по следующему адресу пусто
   temp->x=x;//Записываем значение в структуру
  
   if (Head!=NULL) //Если список не пуст
   {
       temp->Prev=Tail; //Указываем адрес на предыдущий элемент в соотв. поле
       Tail->Next=temp; //Указываем адрес следующего за хвостом элемента
       Tail=temp; //Меняем адрес хвоста
   }
   else //Если список пустой
   {
       temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
       Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
   }
 }

 void List::Show()
 {
//ВЫВОДИМ СПИСОК С КОНЦА
     Node *temp=Tail; //Временный указатель на адрес последнего элемента
     while (temp!=NULL) //Пока не встретится пустое значение
     {
         cout<<temp->x<<" "; //Выводить значение на экран
         temp=temp->Prev; //Указываем, что нужен адрес предыдущего элемента
     }
     cout << endl;

 //ВЫВОДИМ СПИСОК С НАЧАЛА
     temp=Head; //Временно указываем на адрес первого элемента
      while (temp!=NULL) //Пока не встретим пустое значение
     {
         cout<<temp->x<<" "; //Выводим каждое считанное значение на экран
         temp=temp->Next; //Смена адреса на адрес следующего элемента
     }
 }

int main ()
{
 List lst; //Объявляем переменную, тип которой есть список
 lst.Add(100); //Добавляем в список элементы
 lst.Add(200);
 lst.Add(900);
 lst.Add(888);

 lst.Show(); //Отображаем список на экране
}