// ConsoleApplication29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<conio.h>
#include<cmath>
#include<ctime>
#define MAX 100
using namespace std;


class Arac {
public:
	string plaka;
	string kisi_ad, kisi_soyad, kisi_tel;
	time_t giris;

}araba[MAX];

class Otopark {
public:
	string gorevli_id, gorevli_sifre;
	int i, gelir;
	Otopark(string id, string s) {
		gorevli_id = id;
		gorevli_sifre = s;
		gelir = 0;
		i = -1;

	}
	void menu() {
		int secim;
		cout << "OTOPARK PROGRAMI" << endl;
		cout << "........" << endl;
		cout << "1.Yeni Arac" << endl;
		cout << "2.Arac Cikis" << endl;
		cout << "3.Arac Listele" << endl;
		cout << "4.Rapor" << endl;
		cout << "5.Cikis" << endl;
		secim = _getch();
		switch (secim) 
		{
		case '1':yeni();
			break;
		case '2':cikar();
			break;
		case'3':listele();
			break;
		case'4':rapor();
			break;
		case'5':exit(0);
		default:cout << "Hatali secim!" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		}
	}

	void yeni() {
		system("cls");
		i++;
		cout << "Aracin Sahibinin Adi:";
		cin >> araba[i].kisi_ad;
		cout << "Aracin Sahibinin Soyadi:";
		cin >> araba[i].kisi_soyad;
		cout << "Aracin Sahibinin Telefonu:";
		cin >> araba[i].kisi_tel;
		cout << "Aracin Plakasi:";
		cin >> araba[i].plaka;
		cout << "Islem Basarili." << endl;
		time(&araba[i].giris);
		system("pause");
		system("cls");
		menu();
	}

	void cikar() {
		system("cls");
		bool buldu = false;
		int j = 0, k, saat;
		double sure;
		time_t cikis;
		string plka;
		time(&cikis);

		cout << "Plaka Girin:";
		cin >> plka;
		while (j <= i) {
			if (araba[j].plaka == plka) {
				sure = difftime(cikis, araba[j].giris);
				for (k = j; k <= i; k++) {
					araba[k] = araba[k + 1];
				}
				i--;
				buldu = true;
				break;
			}
			j++;
		}

		if (buldu == false) {
			cout << "Plaka Bulunamadi!" << endl;
			system("pause");
			system("cls");
			menu();
		}

		sure = sure / 3600;
		saat = ceil(sure);
		cout << "Ucret=" << saat * 5 << "TL" << endl;
		gelir += saat * 5;
		system("pause");
		system("cls");
		menu();
	}

	void listele() {
		system("cls");
		for (int j = 0; j <= i; j++) {
			cout << araba[j].plaka << endl;
		}

		system("pause");
		system("cls");
		menu();
	}

	void rapor() {
		system("cls");
		cout << "Suanki gelir=" << gelir << "TL" << endl;

		system("pause");
		system("cls");
		menu();
	}
};


int main()
{
	Otopark calisan("hilalkocan", "1414");
	string ad, sifre;
	int i = 0;
	cout << "OTOPARK PROGRAMI" << endl;
	while (1) {
		cout << "Kullanici Adini Girin:" << endl;
		cin >> ad;
		cout << "Sifreyi Girin:" << endl;
		cin >> sifre;

		if (calisan.gorevli_id == ad)
			if (calisan.gorevli_sifre == sifre) {
				cout << "Sifre Dogru" << endl;
				system("pause");
				break;
			}

		cout << "Tekrar Deneyin!" << endl;
		system("pause");
	}

	system("cls");
	calisan.menu();

	system("pause");
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
