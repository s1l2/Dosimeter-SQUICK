#pragma once
#include <avr/pgmspace.h>

#define en 0
#define ru 1

//Выбор языка, en - английский, ru -  русский
//Русский язык занимает RAM: 92 байт Flash: 118 байт
#define LANGUAGE ru
#ifndef LANGUAGE
#define LANGUAGE en
#endif

#if LANGUAGE == ru
#define RUS
#else
#define EN
#endif

//Вывод логотипа при включении
//Занимает RAM: 0 байт Flash: 386 байт
//Раскоментировать чтобы выводить логотип
#define SHOW_LOGO

//Время показа логотипа в мс
#if defined(SHOW_LOGO)
#define LOGO_TIME 1000
#endif

//Продвинутый алгоритм расчёта погрешности
//Занимает RAM: 12 байт Flash: 1390 байт
//Раскомментировать, чтобы включить улучшеный алгоритм расчёта погрешности
#define ADVANCED_ERROR          

//Режим сна. Заснуть можно в меню. Выход из сна долгое удержание кнопки set
//Занимает RAM: 42 байт Flash: 456 байт
//Раскоментировать чтобы включить
#define CAN_SLEEP

//Отрисовка графика, раскоментировать чтобы включить
//Занимает RAM: 85 байт Flash: 146 байт
#define DRAW_GRAPH

#if defined(DRAW_GRAPH)
//Константа для графика
#define RAD_MIN 0
#endif

//Универсальная плата. Позволяет выбрать счётчик гейгера из пресетов, или настроить свой
//Имеет некоторые ограничения, т.к. занимает много памяти и может вызвать ошибки при
//выставлении большого значения времени счёта
//Занимает RAM: 49 байт Flash: 1988 байт
//Раскомментировать чтобы включить
#define UNIVERSAL_COUNTER

//Если прибор не универсален, то устанавливаем время счёта вручную
#if !defined(UNIVERSAL_COUNTER)
#define GEIGER_TIME 37
#endif

#if defined(UNIVERSAL_COUNTER) && defined(CAN_SLEEP)
#define PAGES 8
#elif defined(UNIVERSAL_COUNTER) && !defined(CAN_SLEEP)
#define PAGES 7
#elif !defined(UNIVERSAL_COUNTER) && defined(CAN_SLEEP)
#define PAGES 6
#else
#define PAGES 5
#endif


#define TIMER1_PRELOAD 64910 //65535-64910=625, 15625/625=25Гц
#define TIME_FACT 25 // 25Гц/25=1Гц секундные интервалы

#if defined(SHOW_LOGO)
static const unsigned char PROGMEM logo_Bitmap[] = { 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x80, 0x88, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x80, 0x1e, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x0f, 0xc0, 0x78, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x0c, 0x7f, 
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x0c, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x7f, 0xf0, 0x88, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0xf8, 
	0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf8, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xfc, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfc, 
	0x03, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xfe, 0x07, 0xff, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 
	0xf8, 0xf1, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x20, 0xff, 0xfc, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x20, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
	0xff, 0xf0, 0x20, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x3c, 0x00, 0x20, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x00, 0x20, 0x09, 
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x00, 0xf0, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xc1, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x01, 0xfc, 
	0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x03, 0xfc, 0x0a, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x43, 0x07, 0xfe, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x07, 
	0x07, 0x09, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x0e, 0x67, 0x08, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x1c, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 
	0x1c, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xff, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x7c, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x67, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif

static const unsigned char PROGMEM battery_Bitmap[] = {
	0x7f, 0xfe, 0xc0, 0x02, 0x80, 0x02, 0x80, 0x02, 0x80, 0x02, 0xc0, 0x02, 0x7f, 0xfe
};