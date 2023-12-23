# isnaujo
nd

# Paleidimas
1. Parsisiunčiame [visas](https://github.com/GabijaF/isnaujo/tree/f9d4ac6c593da81b30665539baefc57d98618c1b/visas) aplanka is v1.0.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/df9c5f34-da87-4d06-a8a4-a080da43b587)
2.  Paleidžiame PowerShell
![image](https://github.com/GabijaF/isnaujo/assets/145053488/c2988d91-7b9e-44fb-a3d4-abd08fb10937)
3. Ir jame parašome RUNMME.bat paeiliui esantį tekstą.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/6f47ae50-46c9-42d7-a4cf-410b9109bebe)
![image](https://github.com/GabijaF/isnaujo/assets/145053488/f6bb0220-dd43-4240-939e-12ec0f664069)
4. Mūsų failas 'visas' prisipildė aplankais kurie reikalingi programos paleidimui. Atidarome Debug aplanka ir paleidžiame programa.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/9ffd81a8-81d2-44fe-8234-5a7af39509cc)
![image](https://github.com/GabijaF/isnaujo/assets/145053488/d503ed03-22ad-420f-895c-a5d2c0d94efb)
5. Programai baigusji užsidaro.
![image](https://github.com/GabijaF/isnaujo/assets/145053488/39e93764-7253-44f3-b6aa-a6a9824e76c6)

# v.pradine
v.pradinė. generuoja.cpp paleidus koda klausia studento vardo ir pavardes. Poto klausia ar nd pazymius ir egzamino nori ivesti pats ar juos sugeneruoti atsitiktinai. parasius visu studentu duomenis programa paklausia koki galutini rezultata nori matyti vartotojas ar pagal vidurki ar mediana.

# v0.1
v0.1. tas pats kodas i .h ir .cpp failus ir panaudotas minimalus išimčių valdymas.

# v0.2

kodas nuskaito faila, ir isveda 2 failus: surusiuotus vargsiukai ir galvociai.

![image](https://github.com/GabijaF/isnaujo/assets/145053488/71e70385-afad-44e5-9b22-8174f87a9419)


1bandymas: 0.011086 sekundes
2bandymas: 0.0149357 sekundes
3bandymas: 0.0089862 sekundes
bandymu vidurkis: 0.0116693 sekundes



![image](https://github.com/GabijaF/isnaujo/assets/145053488/ad588561-0792-405e-a3af-2c569d4e61ba)


1bandymas: 0.1624448 sekundes
2bandymas: 0.1600233 sekundes
3bandymas: 0.1597411 sekundes
bandymu vidurkis: 0.1607364 sekundes


![image](https://github.com/GabijaF/isnaujo/assets/145053488/ac835221-9415-4c34-b6a1-b666c9549161)


1bandymas: 1.3445191 sekundes
2bandymas: 1.3602037 sekundes
3bandymas: 1.3804005 sekundes
bandymu vidurkis: 1.36170776667 sekundes


![image](https://github.com/GabijaF/isnaujo/assets/145053488/39f4934e-6867-4ab7-9d78-3c916f9dbc69)


1bandymas: 8.52987 sekundes
2bandymas: 9.06612 sekundes
3bandymas: 8.902099 sekundes
bandymu vidurkis: 8.83269633333 sekundes


![image](https://github.com/GabijaF/isnaujo/assets/145053488/3cc7bb5e-87a2-4114-adeb-8250b544bf12)


1bandymas: 86.90333 sekundes
2bandymas: 165.64522 sekundes
3bandymas: 163.65959 sekundes
bandymu vidurkis: 138.736046667 sekundes

# v0.3
## Parametrai
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

# v0.1 
## 1 strategija
Bendro studentai konteinerio (vector ir list tipų) skaidymas į du naujus to paties tipo konteinerius: "vargšiukų" ir "galvociu". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba galvociu).

Nesunku pastebėti, kad tokia strategija yra neefektyvi užimamos atminties atžvilgiu:

### vector atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

![v1](https://github.com/GabijaF/isnaujo/assets/145053488/d277058c-118b-4818-876c-8f94c95f281f)

### list atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

![l1](https://github.com/GabijaF/isnaujo/assets/145053488/0db2feba-5eae-410b-9172-1860910a5072)


Programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

### vector:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |  0.0030413| 0.0040084 |  0.0030096| 0 |
| 10000  | 0.0780444 | 0.0080004 |0.0356217 |0.0462288|
| 100000 | 1.57536 | 0.138789 | 0.16402 | 0.239093 |
| 1000000 | 3.93834 | 0.492667 | 0.71094| 1.02808|
| 10000000 | 33.473  | 7.35889 |  8.27889 |9.24557  | 

### list:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |   0.0040745 |0.0039971  | 0.0039847| 0.0040013 |
| 10000  |0.129829 |  0.0119939  |0.016233 |0.0199896|
| 100000 | 1.58593 | 0.126619 |  0.162997  |0.226659 |
| 1000000 | 4.17133 | 0.49107 | 0.831084|  1.16655 |
| 10000000 | 71.1717  | 9.39051 | 16.5541 |23.466  | 

### Išvada: 
naudojant 1 strategija vector tipas veikia greičiau už list.
***
## 2 strategija
Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik galvociai. 

Atminties atveju si strategija efektyvesne, tačiau dažni trynimai gali būti "skausmingi", vector tipo konteineriams.

### vector atveju:
pateikta atmintis paleidus kodą su 100 000 studentų turinčiu failu:

![image](https://github.com/GabijaF/isnaujo/assets/145053488/15dd976e-c8d4-41a3-997c-1d194448d0f9)

### list atveju:
pateikta atmintis paleidus kodą su 10 000 000 studentų turinčiu failu:

Programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

### vector:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |  0.0055643| 0.0302857  |   0.001001| 0.0015278 |
| 10000  | 0.0736229 |2.034884 |0.0095045 |0.0064997 |
| 100000 | 0.697874 | 221.699 |  0.0922078 |0.0691245 |

### list:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |  0.0038108| 0.0025442  | 0.0150123| 0.0360239 |
| 10000  | 0.101188 |0.01624 | 0.0095302  |0.0164752  |
| 100000 | 2.36938 | 0.380681 |  0.184752 |0.271983|
| 1000000  |  4.79024| 0.728885 | 0.792867| 1.06198 |
| 10000000  | 37.775 |7.8761  |8.46732 |10.7526  |

### Išvada: 
naudojant 2 strategija list tipas veikia greičiau už vector.
***
## 3 strategija
Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant greičiausiai veikiancia 1 strategiją, įtraukiant į ją "efektyvius" darbo su konteineriais metodus (naudosime copy_if, remove_copy_if, stable_partition).

Visus 3 algoritmus pritaikysim vector tipui, ir issirinksime greiciausiai veikianti, kuri pritaikysim ir list tipui.

Programos veikimo sparta su list ir vector konteineriais(laikas pateiktas sekundėmis): 

### vector copy_if:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  |   0.0060114 | 0.0010008  | 0.0020004| 0 |
| 10000  |0.0560198  |0.0080422 | 0.0069968  |0.0100863  |
| 100000 | 0.673109  | 0.0806257 | 0.0662875 |0.0910801|
| 1000000  | 3.63352| 0.566676 | 0.588548| 0.883478 |
| 10000000  | 29.162 |5.5803 |6.39421 |8.1343  |

### vector remove_copy_if:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  | 0.0030174  |0.0049813  | 0.0019977 | 0.0010005  |
| 10000  |0.0645132   |0.0090003 | 0.0059997  |0.0099959  |
| 100000 | 0.671475   | 0.0806397 |0.0655182 |0.0826068|
| 1000000  |  3.62926 | 0.581576  | 0.600415| 0.864768|
| 10000000  | 28.8801  |5.61558 |6.407  |8.09974  |

### vector stable_partition:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  | 0.0050357   |0.0010046  | 0.0020014 | 0.0010036  |
| 10000  |0.06951   |0.007  |0.0069991 |0.0110247 |
| 100000 | 0.687185    | 0.0715817 |0.0656571 |0.0936633|
| 1000000  |  3.65286| 0.554817  | 0.612013 | 0.869332|
| 10000000  | 28.9634   |5.60472 |6.38962   |8.08078  |

pastebime, kad stable_partition veikia greiciausiai todel ji pritaikysime ir list tipui:

### list stable_partition:
| Studentu sk.  |Nuskaitymas | Dalijimas| Išvėdimas į vargšiukus| Išvėdimas į galvočius|
| ------------- | ------------- | ------------- |-----------------|--------------------|
| 1000  | 0.0030001  |0.0010006  | 0.0020002 | 0.0009913  |
| 10000  |0.0945954  |0.0255504 |0.0069999 |0.0110295 |
| 100000 | 1.11831  | 0.330492 |0.0740337 | 0.104791|
| 1000000  | 4.37306| 1.49957  | 0.622037 |  0.927994|
| 10000000  | 34.2783   |36.5723 |16.304  |11.792 |

### isvada:
Programos efektyvumas stipriai gali priklausyti ne tik nuo naudojamo konteinerio tipo, tačiau ir nuo naudojamų algoritmų.
***
