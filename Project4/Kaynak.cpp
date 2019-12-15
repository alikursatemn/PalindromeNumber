#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#define SIZE 5
using namespace std;

//yýðýtýmýz
struct stack {
	int items[SIZE];
	int top;
};

//yýðýt içinden eleman çeken fonksiyon
int pop(struct stack *s) {
	int x = s->items[s->top];
	(s->top)--;
	return x;
}

//yýðýta eleman ekleyen fonksiyon
void push(struct stack *s, int a) {
	(s->top)++;
	s->items[s->top] = a;
}


//yýðýtýn boþ olup olmadýðýný sorgulayan fonksiyon
bool isEmpty(struct stack *s) {
	if (s->top == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	//number sayýsý kullanýcýdan alýnýr
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

	//basamaklar yýðýta gönderilir
	while (basamak != 0) {
		push(&n, (number / deger) % 10);
		basamak--;
		deger = deger * 10;
	}

	int carpim = 1;
	int sonuc = 0;

	//sonuç elde edilir
	while (!isEmpty(&n)) {
		sonuc = sonuc + pop(&n)*carpim;
		carpim = carpim * 10;
	}

	//palindorme luk sorgulanýr
	if (sonuc == number) {
		cout << number;
		cout << "  sayisi palindrome sayidir.";
	}
	else {
		cout << number;
		cout << " sayisi palindrome degildir.";
	}

}