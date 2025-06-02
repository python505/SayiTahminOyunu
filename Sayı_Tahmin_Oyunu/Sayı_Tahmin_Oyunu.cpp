#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

void ekrantemizleme() {
#ifdef _WIN32
    system("cls");  
#else
    system("clear"); 
#endif
}

int main() {
    std::srand(std::time(0)); 

    char tekrarOyna;
    int enIyiSkor = 9999; 

    do {
        ekrantemizleme(); 
        auto baslangicZamani = std::time(0); 

        int maxSayi;
        int maxDeneme = 9999; 
        int gizliSayi;
        int denemeSayisi = 0;
        int zorluk;

        std::cout << "Zorluk seviyesi sec:\n";
        std::cout << "1. Kolay (1-50)\n";
        std::cout << "2. Orta (1-100)\n";
        std::cout << "3. Zor (1-500, 5 hak)\n";
        std::cout << "Secimin (1/2/3): ";
        std::cin >> zorluk;

        if (zorluk == 1) {
            maxSayi = 50;
        }
        else if (zorluk == 2) {
            maxSayi = 100;
        }
        else if (zorluk == 3) {
            maxSayi = 500;
            maxDeneme = 5; 
        }
        else {
            std::cout << "Gecersiz secim! Orta mod secildi.\n";
            maxSayi = 100;
        }

        gizliSayi = std::rand() % maxSayi + 1;

        std::cout << "1-" << maxSayi << " arasinda bir sayi tuttum. Basla bakalim!\n";
        std::cin.ignore(); 

        bool bildiMi = false;

        while (denemeSayisi < maxDeneme) {
            std::cout << "Tahminini gir (veya 'skor' ya da 'quit' yaz): ";
            std::string girdi;
            std::getline(std::cin, girdi);

            if (girdi == "quit") {
                std::cout << "Oyundan cikiliyor...\n";
                return 0; 
            }

            if (girdi == "skor") {
                std::cout << "Su ana kadarki en iyi skorun: " << enIyiSkor << " deneme\n";
                continue; 
            }

            int tahmin;
            try {
                tahmin = std::stoi(girdi); 
            }
            catch (...) {
                std::cout << "Gecersiz giris! Lutfen bir sayi yaz.\n";
                continue;
            }

            denemeSayisi++;

            if (tahmin < gizliSayi) {
                std::cout << "Daha buyuk bir sayi gir.\n";
            }
            else if (tahmin > gizliSayi) {
                std::cout << "Daha kucuk bir sayi gir.\n";
            }
            else {
                std::cout << "Tebrikler! " << denemeSayisi << " denemede bildin!\n";
                bildiMi = true;
                if (denemeSayisi < enIyiSkor) {
                    enIyiSkor = denemeSayisi;
                    std::cout << "Yeni en iyi skor!\n";
                }
                break;
            }

            if (zorluk == 3 && denemeSayisi == maxDeneme) {
                std::cout << "Uzgunum, hakkin bitti! Dogru cevap: " << gizliSayi << "\n";
            }
        }

        auto bitisZamani = std::time(0); 
        std::cout << "Oyun suresi: " << (bitisZamani - baslangicZamani) << " saniyede bildiniz\n";
        std::cout << "Su ana kadarki en iyi skorun: " << enIyiSkor << " deneme\n";

        std::cout << "Tekrar oynamak ister misin? (e/h): ";
        std::cin >> tekrarOyna;
        std::cin.ignore(); 

    } while (tekrarOyna == 'e' || tekrarOyna == 'E');

    std::cout << "Gorusuruz! Oyun bitti.\n";

    return 0;
}
