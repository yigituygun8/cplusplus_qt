#include <iostream>

using namespace std;

int main()
{
    std::string metin = "ş";

    std::cout << metin << std::endl; // Ekranda "ş" harfi görünecektir.

    // Ekranda 1 harf görmenize rağmen çıktı 2 olacaktır!
    std::cout << "Boyut: " << metin.length() << std::endl;

    // İlk baytı ekrana basmaya çalışır ve anlammsız bir karakter üretir
    std::cout << "İlk Karakter: " << metin[0] << std::endl;

    std::string name = "Osman";
    for(std::string::iterator it = name.begin(); it != name.end(); ++it) {
        std::cout << *it; // Her karakteri ayrı ayrı ekrana basar.
    }
    std::cout << "\n";

    // or range for
    for(char c : name) {
        std::cout << c;
    }
    std::cout << "\n";

    std::cout << name.size() << std::endl; // name.length() ile aynı sonucu verir, stringin uzunluğunu döndürür.

    std::cout << (name.empty() ? "Empty" : "Not Empty" )<< std::endl;

    name.resize(3);
    std::cout << name << std::endl; // "Osm" olarak güncellenir, çünkü resize() fonksiyonu stringin boyutunu 3'e düşürür ve fazla karakterleri keser.

    name = "Osman";
    std::cout << name.substr(1, 4) << std::endl; // "sman"

    std::cout << name.replace(0, 5, "Yiğit") << std::endl;

    name.append(" Uygun");
    std::cout << name << std::endl;
    // tabii bunların farklı overloadları da var, örneğin replace fonksiyonunun farklı parametrelerle kullanımı gibi (fill, range, substringler vs)

    // Refer: https://cplusplus.com/reference/string/string/
    return 0;
}
