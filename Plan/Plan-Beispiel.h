0  BEGIN PGM Plan-Beispiel MM 
1  BLK FORM 0.1 Z  X-200  Y-100  Z-30
2  BLK FORM 0.2  X+200  Y+100  Z+0
3  TOOL CALL 1 Z S800
4  L  X+0  Y+0  Z+50 R0 FMAX M3
5  ;----- Zyklus Planfraesen Parameter -----
6  Q1840 = 1 ;Start-Richtung
7  Q1800 = - 200 ;Startpunkt X
8  Q1801 = 200 ;Endpunkt X
9  Q1802 = - 100 ;Startpunkt Y
10 Q1803 = 100 ;Endpunkt Y
11 Q1804 = 0 ;Startpunkt Z
12 Q1805 = - 3 ;Endpunkt Z
13 Q1810 = 1 ;Maximale Zustell-Tiefe
14 Q1812 = 0.7 ;Bahnueberlappung Faktor D
15 Q1813 = 0.05 ;Ueberlappung Mitte Faktor D
16 Q1820 = 600 ;Vorschub Fraesen
17 Q1822 = 2000 ;Vorschub Vorpositionieren
18 Q1830 = 5 ;Sicherheits-Abstand
19 Q1831 = 50 ;2. Sicherheits-Abstand
20 Q1832 = 5 ;Sicherheits-Abstand Seite
21 ;----- Zyklus Planfraesen Aufruf -----
22 CALL PGM TNC:\Plan.h
23 L  X+0  Y+200  Z+300 R0 FMAX M5
24 L M30
25 END PGM Plan-Beispiel MM 
