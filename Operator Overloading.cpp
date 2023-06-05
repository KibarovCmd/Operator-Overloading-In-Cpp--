/********************************************************************
**                 COMPUTER ENGINEERING
**
**             ALEXANDER KİBAROV(İSKENDER)
********************************************************************/
#include <iostream>
#include <locale.h>
#include <string>
#include <cmath> 
#include <windows.h>
using namespace std;
int dogrulukdegeri;
int gelismisSayiKontrol(string alinan);
const double pi = 3.1415;
class KarmasikSayi
{
private:
	float gercel;
	string gercelDogrulama;
	float sanal;
	string sanalDogrulama;
public:
	void setSayiGercel()
	{
		cout << "Gerçel kısmını giriniz:\n";
		do // Kullanıcı sayı girine kadar bekliyoruz.
		{
			cout << "Lütfen sadece sayı giriniz: ";
			cin >> gercelDogrulama;
		} while (gelismisSayiKontrol(gercelDogrulama) == 1);
		gercel = stof(gercelDogrulama);
	}
	void setSayiSanal()
	{
		cout << "Sanal kısmını giriniz:\n";
		do // Kullanıcı sayı girine kadar bekliyoruz.
		{
			cout << "Lütfen sadece sayı giriniz: ";
			cin >> sanalDogrulama;
		} while (gelismisSayiKontrol(sanalDogrulama) == 1);
		sanal = stof(sanalDogrulama);
	}
	double getSayiGercel()
	{
		return gercel;
	}
	double getSayiSanal()
	{
		return sanal;
	}
	void Yazdir()
	{ //Sayıyı yazdırmak için koşul kullanıyoruz
		if (sanal > 0)
		{
			cout << "Sonuç: " << gercel << "+" << sanal << "i" << "\n";
		}
		else if (sanal < 0)
		{
			cout << "Sonuç: " << gercel << "-" << -sanal << "i" << "\n";
		}
		else
		{
			cout << "Sonuç: " << gercel << "\n";
		}
	}
	void YazdirSifiraBolunmus()
	{//Sıfıra bölünme durumu için koyuyuoruz.
		cout << "0'a bölünme yapılamaz.\n";
	}
	void KutupsalGosterim()
	{
		double modul, aci;
		modul = sqrt(pow(gercel, 2) + pow(sanal, 2));
		aci = (atan(sanal / gercel) * 180) / pi;
		cout << modul << "*cis(" << aci << ")\n";
	}
	KarmasikSayi operator+(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi toplam;
		toplam.gercel = gercel + ikincilDeger.gercel;
		toplam.sanal = sanal + ikincilDeger.sanal;
		return toplam;
	}
	KarmasikSayi operator-(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi fark;
		fark.gercel = gercel - ikincilDeger.gercel;
		fark.sanal = sanal - ikincilDeger.sanal;
		return fark;
	}
	KarmasikSayi operator*(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi carpma;
		carpma.gercel = gercel * ikincilDeger.gercel - sanal * ikincilDeger.sanal;
		carpma.sanal = gercel * ikincilDeger.sanal + ikincilDeger.gercel * sanal;
		return carpma;
	}
	KarmasikSayi operator/(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi bolme;
		bolme.gercel = (gercel * ikincilDeger.gercel + sanal * ikincilDeger.sanal) / (pow(ikincilDeger.gercel, 2) + pow(ikincilDeger.sanal, 2));
		bolme.sanal = (ikincilDeger.gercel * sanal - gercel * ikincilDeger.sanal) / (pow(ikincilDeger.gercel, 2) + pow(ikincilDeger.sanal, 2));
		return bolme;
	}
	KarmasikSayi operator+=(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi k1;
		gercel = gercel + ikincilDeger.gercel;
		sanal = sanal + ikincilDeger.sanal;
		k1.gercel = gercel;
		k1.sanal = sanal;
		return k1;
	}
	KarmasikSayi operator-=(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi k1;
		gercel = gercel - ikincilDeger.gercel;
		sanal = sanal - ikincilDeger.sanal;
		k1.gercel = gercel;
		k1.sanal = sanal;
		return k1;
	}
	KarmasikSayi operator*=(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi k;
		KarmasikSayi k2;
		k2.gercel = gercel;
		k2.sanal = sanal;
		gercel = (gercel * ikincilDeger.gercel) - (sanal * ikincilDeger.sanal);
		sanal = (k2.gercel * ikincilDeger.sanal) + (ikincilDeger.gercel * sanal);
		k.gercel = gercel;
		k.sanal = sanal;
		return k;
	}
	KarmasikSayi operator/=(KarmasikSayi ikincilDeger)
	{
		KarmasikSayi k;
		KarmasikSayi k2;
		k2.gercel = gercel;
		k2.sanal = sanal;
		gercel = ((gercel * ikincilDeger.gercel) + (sanal * ikincilDeger.sanal)) / (pow(ikincilDeger.gercel, 2) + pow(ikincilDeger.sanal, 2));
		sanal = ((ikincilDeger.gercel * k2.sanal) - (k2.gercel * ikincilDeger.sanal)) / (pow(ikincilDeger.gercel, 2) + pow(ikincilDeger.sanal, 2));
		k.gercel = gercel;
		k.sanal = sanal;
		return k;
	}
};
int main()
{
	KarmasikSayi birinciSayi, ikinciSayi, ucuncuSayi;
	string islem, sorgulama;
	setlocale(LC_ALL, "Turkish");
	cout << "###########//////////Hoşgeldiniz & byİskender\\\\\\\\\\\\\\\\\\\\###########\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	Sleep(1500);
	system("cls");
	cout << "KARMAŞIK SAYILAR İÇİN HESAP MAKİNESİ\n";
	Sleep(1500);
	system("cls");
	while (true)
	{ //Kullanıcı 7'e basana kadar programı açık tutuyoruz. Kullanıcının girdiği değere göre işlem yapıyoruz.
		cout << "1)---->>Toplama\n2)---->>Çıkarma\n3)---->>Çarpma\n4)---->>Bölme\n5)---->>Kutupsal Gösterim\n6)---->>Ekranı temizle\n7)---->>Çıkış\n";
		cout << "----Lütfen işlem seçiniz----\n";
		do
		{ // Kullanıcı sayı girine kadar bekliyoruz.
			cout << "Lütfen sadece sayı giriniz: ";
			cin >> islem;
		} while (gelismisSayiKontrol(islem) == 1);
		if (stof(islem) == 1)
		{
			cout << "1)'+'---->Aşırı yüklenmesi\n2)'+='---->Aşırı yüklenmesi(Atama operatörü sonucu girilen ilk sayıya atar.)\n";
			do
			{ // Kullanıcı sayı girine kadar bekliyoruz.
				cout << "Lütfen sadece sayı giriniz: ";
				cin >> sorgulama;
			} while (gelismisSayiKontrol(sorgulama) == 1);
			//Hangi operatör aşırı yüklemesini yapacağını soruyoruz.
			if (stof(sorgulama) == 1)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				ucuncuSayi = birinciSayi + ikinciSayi;
				ucuncuSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen birinci sayı: ";
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen ikinci sayı: ";
				ikinciSayi.Yazdir();
				cout << "--------------------------------------------\n";
			}
			if (stof(sorgulama) == 2)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				birinciSayi += ikinciSayi;
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen birinci sayı: ";
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen ikinci sayı: ";
				ikinciSayi.Yazdir();
				cout << "--------------------------------------------\n";
			}
		}
		else if (stof(islem) == 2)
		{
			cout << "1)'-'---->Aşırı yüklenmesi\n2)'-='---->Aşırı yüklenmesi(Atama operatörü sonucu girilen ilk sayıya atar.)\n";
			do
			{ // Kullanıcı sayı girine kadar bekliyoruz.
				cout << "Lütfen sadece sayı giriniz: ";
				cin >> sorgulama;
			} while (gelismisSayiKontrol(sorgulama) == 1);
			//Hangi operatör aşırı yüklemesini yapacağını soruyoruz.
			if (stof(sorgulama) == 1)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				ucuncuSayi = birinciSayi - ikinciSayi;
				ucuncuSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen birinci sayı: ";
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen ikinci sayı: ";
				ikinciSayi.Yazdir();
				cout << "--------------------------------------------\n";
			}
			if (stof(sorgulama) == 2)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				birinciSayi -= ikinciSayi;
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen birinci sayı: ";
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen ikinci sayı: ";
				ikinciSayi.Yazdir();
				cout << "--------------------------------------------\n";
			}
		}
		else if (stof(islem) == 3)
		{
			cout << "1)'*'---->Aşırı yüklenmesi\n2)'*='---->Aşırı yüklenmesi(Atama operatörü sonucu girilen ilk sayıya atar.)\n";
			do
			{ // Kullanıcı sayı girine kadar bekliyoruz.
				cout << "Lütfen sadece sayı giriniz: ";
				cin >> sorgulama;
			} while (gelismisSayiKontrol(sorgulama) == 1);
			//Hangi operatör aşırı yüklemesini yapacağını soruyoruz.
			if (stof(sorgulama) == 1)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				ucuncuSayi = birinciSayi * ikinciSayi;
				ucuncuSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen birinci sayı: ";
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen ikinci sayı: ";
				ikinciSayi.Yazdir();
				cout << "--------------------------------------------\n";
			}
			if (stof(sorgulama) == 2)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				birinciSayi *= ikinciSayi;
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen birinci sayı: ";
				birinciSayi.Yazdir();
				cout << "--------------------------------------------\nGirilen ikinci sayı: ";
				ikinciSayi.Yazdir();
				cout << "--------------------------------------------\n";
			}
		}
		else if (stof(islem) == 4)
		{
			cout << "1)'/'---->Aşırı yüklenmesi\n2)'/='---->Aşırı yüklenmesi(Atama operatörü sonucu girilen ilk sayıya atar.)\n";
			do
			{ // Kullanıcı sayı girine kadar bekliyoruz.
				cout << "Lütfen sadece sayı giriniz: ";
				cin >> sorgulama;
			} while (gelismisSayiKontrol(sorgulama) == 1);
			//Hangi operatör aşırı yüklemesini yapacağını soruyoruz.
			if (stof(sorgulama) == 1)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				ucuncuSayi = birinciSayi / ikinciSayi;
				//Sıfıra bölünme durumunu kontrol ediyoruz.
				if (ikinciSayi.getSayiGercel() == 0 && ikinciSayi.getSayiSanal() == 0)
				{
					cout << "--------------------------------------------\n";
					ucuncuSayi.YazdirSifiraBolunmus();
					cout << "--------------------------------------------\n";
				}
				else
				{
					ucuncuSayi.Yazdir();
					cout << "--------------------------------------------\nGirilen birinci sayı: ";
					birinciSayi.Yazdir();
					cout << "--------------------------------------------\nGirilen ikinci sayı: ";
					ikinciSayi.Yazdir();
					cout << "--------------------------------------------\n";
				}
			}
			if (stof(sorgulama) == 2)
			{
				cout << "İlk sayı:\n";
				birinciSayi.setSayiGercel();
				birinciSayi.setSayiSanal();
				cout << "İkinci sayı:\n";
				ikinciSayi.setSayiGercel();
				ikinciSayi.setSayiSanal();
				birinciSayi /= ikinciSayi;
				//Sıfıra bölünme durumunu kontrol ediyoruz.
				if (ikinciSayi.getSayiGercel() == 0 && ikinciSayi.getSayiSanal() == 0)
				{
					cout << "--------------------------------------------\n";
					birinciSayi.YazdirSifiraBolunmus();
					cout << "--------------------------------------------\n";
				}
				else
				{
					birinciSayi.Yazdir();
					cout << "--------------------------------------------\nGirilen birinci sayı: ";
					birinciSayi.Yazdir();
					cout << "--------------------------------------------\nGirilen ikinci sayı: ";
					ikinciSayi.Yazdir();
					cout << "--------------------------------------------\n";
				}
			}
		}
		else if (stof(islem) == 5)
		{//Kutupsal gösterim için yazdırıyoruz.
			cout << "Sayı giriniz\n";
			birinciSayi.setSayiGercel();
			birinciSayi.setSayiSanal();
			birinciSayi.KutupsalGosterim();
		}
		else if (stof(islem) == 6)
		{//Ekranı temizliyoruz.
			cout << "Ekran temizleniyor\n";
			system("cls");
		}
		else if (stof(islem) == 7)
		{//Uygulamayı sonlandırıyoruz.
			break;
		}
		else
		{//Aksi durum için.
			cout << "Bulunamadı\n";
		}
	}
	cout << "&byİskender'i tercih ettiğiniz için teşekkürler\n";
	return 0;
}
int gelismisSayiKontrol(string alinan)
{
	string yeni;
	string yeni2;
	string simdilikYeni;
	string simdilikYeni2;
	string kontrolYeni;
	int kontrol = 0;
	int i;
	//noktayı görene kadar kontrol edip nokta olmayanları yeni bir stringe ekliyoruz.
	for (i = 0; i < alinan.length(); )
	{
		if (alinan[i] == '.')
		{
			kontrol = 1;
			break;
		}
		else
		{
			yeni2 = alinan[i];
			yeni.append(yeni2);
			i++;
		}
	}
	//noktadan sonraki karekterleri yeni stringe ekliyoruz.
	for (int j = i + 1; j < alinan.length(); j++)
	{
		simdilikYeni2 = alinan[j];
		simdilikYeni.append(simdilikYeni2);
	}
	//Bu ifade(karekter katarlarını) yeni bir string de birleştiriyoruz.
	kontrolYeni.append(yeni);
	kontrolYeni.append(simdilikYeni);
	//İlk karekter - ise bunun negatif olduğunu anlatıyoruz.
	if (kontrolYeni[0] == '-')
	{
		//Bunun dışında olanlarda sayı dışında karekter varsa 1 yoksa sıfır döndürüyoruz.
		for (int i = 1; i < kontrolYeni.length(); i++)
		{
			if (isalnum(kontrolYeni[i]) == 0)
			{
				dogrulukdegeri = 1;
				break;
			}
			else
			{
				if (isalpha(kontrolYeni[i]) == 0)
				{
					dogrulukdegeri = 0;
					continue;
				}
				else
				{
					dogrulukdegeri = 1;
					break;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < kontrolYeni.length(); i++)
		{
			//İlk karekter - değilse direkilk ifadeden başlıyoruz kontrole.
			if (isalnum(kontrolYeni[i]) == 0)
			{
				dogrulukdegeri = 1;
				break;
			}
			else
			{
				if (isalpha(kontrolYeni[i]) == 0)
				{
					dogrulukdegeri = 0;
					continue;
				}
				else
				{
					dogrulukdegeri = 1;
					break;
				}
			}
		}
		//Kontrolümüz sonuucu sayıdan başka ifade varsa 1 yoksa 0 döndürüyoruz.
		if (dogrulukdegeri == 1)
		{
			return 1;
		}
		else if (dogrulukdegeri == 0)
		{
			return 0;
		}
	}
	//Kontrolümüz sonuucu sayıdan başka ifade varsa 1 yoksa 0 döndürüyoruz.
	if (dogrulukdegeri == 1)
	{
		return 1;
	}
	else if (dogrulukdegeri == 0)
	{
		return 0;
	}
}
