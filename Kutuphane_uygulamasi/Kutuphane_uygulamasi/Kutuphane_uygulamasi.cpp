#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
struct book {
	string ad;
	string atandigiogrenci = {};
};
book kitap[10000];

int n;
bool Admin;

void KitapListesiNoPause();
void Saver();
int Nfinder();
int Admin_Login();
string Student_Login();
int ShowScreen(string);
void Kitap_Listesi();
void Kitap_Atama();
void Kitap_Ekleme();
void Txt_Struct();
void Kitap_Silme();
void Kitap_Iade(string);

int main()
{
	while (1)
	{
		string no;
		n = Nfinder();
		Saver();
		int secim;
		system("cls");
		cout << "1-Admin Login" << endl << "2-Student Login" << endl << "3-Uygulamayi Kapat" << endl;
		cout << "Seciniz:";
		while (1)
		{

			cin >> secim;
			if (secim > 3 || secim < 1)
			{
				system("cls");
				cout << "1 ve 3 arasinda bir sayi seciniz." << endl << "seciminiz:";
			}
			else
				break;
		}
		if (secim == 3)
		{
			return 0;
		}
		switch (secim)
		{
		case 1:
		{

			Admin = Admin_Login();
			break;
		}
		case 2:
		{
			no = Student_Login();
			break;
		}
		}

		ShowScreen(no);
	}
}

int Nfinder()
{
	int i = 0;
	string satir;
	ifstream Kitaplar;
	Kitaplar.open("Books.txt");
	while (getline(Kitaplar, satir))
	{
		i++;
	}
	Kitaplar.close();
	return i;
}
int Admin_Login()
{
	system("cls");
	string admin_sifre;
	string satir;
	ifstream PASS;
	PASS.open("AdminSifre.txt");
	PASS >> satir;
	PASS.close();

	while (1)
	{
		cout << "Admin Password:";
		cin >> admin_sifre;
		if (satir == admin_sifre)
		{
			return true;
		}
		else
		{
			cout << "password is incorrect" << endl;
		}
	}
}
string Student_Login()
{
	int i = 0, j = 0;
	string studentNo;
	string studentPass;
	string satir;
	string satir2;
	while (1)
	{
		system("cls");
		cout << "Student No:";
		cin >> studentNo;
		cout << "Student Password:";
		cin >> studentPass;
		ifstream StudentNo;
		StudentNo.open("StudentNo.txt");
		while (getline(StudentNo, satir))
		{
			i++;
			if (studentNo == satir)
			{
				break;
			}
		}
		StudentNo.close();
		ifstream StudentPass;
		StudentPass.open("StudentPass.txt");
		while (j < i)
		{
			j++;
			getline(StudentPass, satir2);
		}
		if (studentPass == satir2)
		{
			Admin = false;
			break;
		}
		else
		{
			system("cls");
			cout << "password or student no is incorrect" << endl;
		}
	}
	return studentNo;
}
int ShowScreen(string no)
{
	int secim;

	if (Admin == true)
	{
		while (1)
		{
			while (1)
			{
				system("cls");
				cout << "Hosgeldiniz Elham Hanim" << endl;
				cout << "islemler:" << endl << "1-Kitap listesi  " << "2- Kitap ekleme " << "3-Kitap silme  " << "4-Kitap atama " << "5-Cikis yap" << endl << "Isleminiz:";
				Txt_Struct();

				cin >> secim;
				if (secim > 5 || secim < 1)
				{
					cout << "Lutfen 1 ve 4 arasinda bir sayi giriniz!";
				}
				else if (secim == 5)
				{
					return 0;
				}
				else
				{

					switch (secim)
					{
					case 1:
					{
						Kitap_Listesi();
						break;
					}
					case 2:
					{	Kitap_Ekleme();
					break;
					}
					case 3:
					{
						Kitap_Silme();
						break;
					}
					case 4:
					{
						Kitap_Atama();
						break;
					}
					}
					break;
				}
			}
		}
	}
	else
	{
		while (1)
		{
			while (1)
			{
				system("cls");
				cout << "Iyi Gunler" << endl;
				cout << "No:" << no << endl << "islemler:" << "1-Kitap Listesi " << "2-Kitap Iade " << "3-Cikis yap " << endl;
				cout << "isleminiz:";
				cin >> secim;
				if (secim > 3 || secim < 1)
				{
					cout << "Lutfen 1 ve 3 arasinda bir sayi giriniz!";
				}
				else if (secim == 3)
				{
					return 0;
				}
				else
				{

					switch (secim)
					{
					case 1:
					{
						Kitap_Listesi();
						break;
					}
					case 2:
					{
						Kitap_Iade(no);
						break;
					}
					}
					break;
				}
			}
		}
	}
}
void Kitap_Listesi()
{

	int i = 1;
	cout << endl << endl;
	ifstream Kitaplar;
	string satir;
	Kitaplar.open("Books.txt");
	while (getline(Kitaplar, satir))
	{
		cout << i << "-" << satir;
		if (kitap[i].atandigiogrenci.length() == 9)
		{
			cout << " [Bu kitap bir ogrenciye atanmistir.]";
		}
		cout << endl;
		i++;

	}
	Kitaplar.close();

	system("pause");
}
void Kitap_Ekleme()
{
	cout << "Eklenilecek kitabin adini giriniz:";
	cin.ignore();
	getline(cin, kitap[n + 1].ad);

	ofstream Kitap;
	Kitap.open("Books.txt", ios_base::app);
	Kitap << endl << kitap[n + 1].ad;
	Kitap.close();
	n++;
}
void Txt_Struct()
{
	int i = 1;
	ifstream Kitap;
	string satir;
	Kitap.open("Books.txt");
	while (getline(Kitap, kitap[i].ad))
	{
		i++;
	}
	Kitap.close();
}
void Kitap_Silme()
{
	system("cls");
	int secim, i;

	KitapListesiNoPause();
	cout << endl << "Silmek istediginiz kitabi giriniz:";
	cin >> secim;
	cout << endl << endl;
	for (secim; secim < n; secim++)
	{
		kitap[secim].ad = kitap[secim + 1].ad;
		kitap[secim].atandigiogrenci = kitap[secim + 1].atandigiogrenci;

	}
	kitap[n].ad = "";
	n--;
	ofstream Kitap;

	Kitap.open("Books.txt");
	for (i = 1; i <= n; i++)
	{
		Kitap << kitap[i].ad << endl;
	}
	Kitap.close();

}
void Kitap_Atama()
{
	bool D = false;
	int secim;

	string ogrencino, satir;
	ifstream Ogrencino;
	Ogrencino.open("StudentNo.txt");
	while (1)
	{
		system("cls");
		KitapListesiNoPause();
		cout << endl << " Atamak istediginiz kitabi seciniz:";
		cin >> secim;
		if (secim<0 || secim > n)
		{
			cout << "0 ile " << n << " arasi bir sayi giriniz.";
			system("pause");
		}
		else if (kitap[secim].atandigiogrenci.length() == 9)
		{
			cout << "Zaten atanmis bir kitabi baska ogrenciye atayamazsiniz" << endl;
			system("pause");
		}
		else
			break;
	}
	cout << " Atamak istediginiz ogrencinin numarasi:";
	cin >> ogrencino;
	while (getline(Ogrencino, satir))
	{
		if (satir == ogrencino)
		{

			ofstream Atanan;

			Atanan.open("Atanan.txt", ios_base::app);
			kitap[secim].atandigiogrenci = ogrencino;
			Atanan << ogrencino << endl << kitap[secim].ad << endl;
			D = true;
			break;
			Atanan.close();
			Saver();
		}
		else
		{
		}
	}
	if (D != true)
	{
		cout << "Girdiginiz ogrenci numarasi sistemde bulunmamaktadir." << endl;
		system("pause");
	}
	Ogrencino.close();
}
void Kitap_Iade(string no)
{
	Saver();
	int secim;
	string atama_no, satir;
	int arr[10000];
	int i, j = 1, k, x;
	cout << "Uzerinize atanmis kitaplar:" << endl;
	for (i = 1; i <= n; i++)
	{
		atama_no = kitap[i].atandigiogrenci;
		if (atama_no.compare(no) == 0)
		{
			cout << j << "-" << kitap[i].ad << endl;
			arr[j] = i;
			j++;
		}
	}
	x = j;
	if (j == 1)
	{

	}
	else
	{
		while (1)
		{
			cout << "Iade etmek istediginiz kitabi giriniz:";
			cin >> secim;
			if (secim <= 0 || secim > x - 1)
			{
				cout << "lutfen 0 ile " << x << " arasinda bir deger giriniz" << endl;
			}
			else
			{
				kitap[arr[secim]].atandigiogrenci = {};
				ofstream Atanan;
				Atanan.open("Atanan.txt");
				for (k = 1; k <= n; k++)
				{
					if (kitap[k].atandigiogrenci.length() == 9)
					{
						Atanan << kitap[k].atandigiogrenci << endl << kitap[k].ad;
					}
				}
				Atanan.close();
				break;
				ShowScreen(no);
			}
		}
	}

	cout << " Uzerinize atanmis kitap bulunmamaktadir" << endl;
	system("pause");
	ShowScreen(no);

}
void Saver()
{
	Txt_Struct();
	int i;
	string satir, satir2, tempsatir;
	ifstream Kitap;
	ifstream Atanan;
	Atanan.open("Atanan.txt");

	while (getline(Atanan, satir))
	{
		Kitap.open("Books.txt");
		i = 1;
		while (getline(Kitap, satir2))
		{
			if (satir.compare(satir2) == 0)
			{
				kitap[i].atandigiogrenci = tempsatir;
				break;
			}
			i++;

		}
		Kitap.close();
		tempsatir = satir;
	}
	Atanan.close();
}
void KitapListesiNoPause()
{
	int i = 1;
	cout << endl << endl;
	ifstream Kitaplar;
	string satir;
	Kitaplar.open("Books.txt");
	while (getline(Kitaplar, satir))
	{
		cout << i << "-" << satir;
		if (kitap[i].atandigiogrenci.length() == 9)
		{
			cout << "\tBu kitap bir ogrenciye atanmistir.";
		}
		cout << endl;
		i++;
	}
	Kitaplar.close();
}