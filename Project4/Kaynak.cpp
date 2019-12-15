#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#define SIZE 5
using namespace std;

//y���t�m�z
struct stack {
	int items[SIZE];
	int top;
};

//y���t i�inden eleman �eken fonksiyon
int pop(struct stack *s) {
	int x = s->items[s->top];
	(s->top)--;
	return x;
}

//y���ta eleman ekleyen fonksiyon
void push(struct stack *s, int a) {
	(s->top)++;
	s->items[s->top] = a;
}


//y���t�n bo� olup olmad���n� sorgulayan fonksiyon
bool isEmpty(struct stack *s) {
	if (s->top == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	//number say�s� kullan�c�dan al�n�r
	cout << "Bir sayi giriniz: ";
	int number;
	cin >> number;

	int sayi = number;
	int basamak = 1;

	//basamak sayisi bulunur
	while (sayi >= 10) {
		sayi = sayi / 10;
		basamak++;
	}


	struct stack n;
	int deger = 1;

	//basamaklar y���ta g�nderilir
	while (basamak != 0) {
		push(&n, (number / deger) % 10);
		basamak--;
		deger = deger * 10;
	}

	int carpim = 1;
	int sonuc = 0;

	//sonu� elde edilir
	while (!isEmpty(&n)) {
		sonuc = sonuc + pop(&n)*carpim;
		carpim = carpim * 10;
	}

	//palindorme luk sorgulan�r
	if (sonuc == number) {
		cout << number;
		cout << "  sayisi palindrome sayidir.";
	}
	else {
		cout << number;
		cout << " sayisi palindrome degildir.";
	}

}