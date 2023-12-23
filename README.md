# isnaujo
nd
# Parametrai
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz;
RAM: 8GB 2667Hz
SSD: Micron_1100 240GB
****
****

### Ištirti:
ar pasikeistų ir kaip pasikeistų programos sparta, jei vietoje std::vector<Studentai> naudotumėte std::list<Studentai>.

Kadangi tiek failų kūrimas, tiek ir surūšiuotų rezultatų išvedimas į failus nepriklauso nuo naudojamo konteinerio, todėl šioje užduotyje matuosim:

* studentų rūšiavimą į dvi grupes;
* duomenų įrašymas į failus;

Matuosime kiekviena konteinerį su 5 skirtingais failais po 3 kartus pagal vidurkį ir pateiksime vidurkius.
****
****

## std::vector

![image](https://github.com/GabijaF/isnaujo/assets/145053488/ae041291-22f2-4c57-aadf-743f88352f88)

Studentų rūšiavimą į dvi grupes: 0.001335233336 sekundes <br>
Grupiu įrašymas į failus: 0.0063387 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/5f0e53a0-27b0-4cd8-b0e8-5794c7469ba0)

Studentų rūšiavimą į dvi grupes: 0.0418005 sekundes <br>
Grupiu įrašymas į failus: 0.03963506666 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/34585652-e1bb-4ff7-82a8-5b7303aa7f48)

Studentų rūšiavimą į dvi grupes: 0.40813933333 sekundes <br>
Grupiu įrašymas į failus: 0.43132166666 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/1cf892c4-9062-4726-a8ce-4ad40e2e6ef8)

Studentų rūšiavimą į dvi grupes: 3.96838666667 sekundes <br>
Grupiu įrašymas į failus: 4.11383333333 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/58a82b59-2c45-4f4d-b383-cdba6638bcb9)


Studentų rūšiavimą į dvi grupes: 41.8671333333 sekundes <br>
Grupiu įrašymas į failus: 42.7793666667 sekundes
****


## std::list

![image](https://github.com/GabijaF/isnaujo/assets/145053488/813bdc28-7693-426a-a244-991b3128ed27)

Studentų rūšiavimą į dvi grupes: 0.0051837 sekundes <br>
Grupiu įrašymas į failus: 0.00904976666 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/c3da2164-c7ab-4678-b445-a332b6fd8dac)

Studentų rūšiavimą į dvi grupes: 0.0426777 sekundes <br>
Grupiu įrašymas į failus: 0.0399025 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/f197c1d4-3e1e-4ccd-9ebe-a56f9eba0c62)

Studentų rūšiavimą į dvi grupes: 0.41334333333 sekundes <br>
Grupiu įrašymas į failus: 0.42941333333 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/df332625-d459-43ed-a05a-f0e233be216f)

Studentų rūšiavimą į dvi grupes: 4.02931666667 sekundes <br>
Grupiu įrašymas į failus: 4.18043333333 sekundes

![image](https://github.com/GabijaF/isnaujo/assets/145053488/f3f24168-310f-4e58-a2e2-4043458e36c0)

Studentų rūšiavimą į dvi grupes: 42.0294333333 sekundes <br>
Grupiu įrašymas į failus: 42.9918 sekundes
****
****

# Palyginimas

| Studentu sk.  | Rusiavimas(v) | Rusiavimas(l)|
| ------------- | ------------- | ------------- |
| 1000  | 0.001335233336 | 0.0051837 |
| 10000  | 0.0418005  | 0.0426777 |
| 100000 | 0.40813933333 | 0.41334333333 |
| 1000000 | 3.96838666667 | 4.02931666667 |
| 10000000 | 41.8671333333 | 42.0294333333 |


| Studentu sk.  | Dalijimas i 2gr(v) | Dalijimas i gr(l)|
| ------------- | ------------- | ------------- |
| 1000  | 0.0063387 | 0.00904976666 |
| 10000  | 0.03963506666  | 0.0399025 |
| 100000 | 0.43132166666 | 0.42941333333 |
| 1000000 | 4.11383333333 | 4.18043333333 |
| 10000000 | 42.7793666667 | 42.9918 |

Naudojant std::List vietoj std::Vector sparta, musu atvėju, keičiasi tik dalijant i 2gr(Pvz. 100000 atvėju). Tada List veikia greiciau nei Vector. Tačiau skirtumas tarp šių konteineriu neryškus.
