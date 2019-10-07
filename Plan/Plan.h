0  BEGIN PGM Plan MM 
1  ;Zyklus zum Planfraesen mit spiralfoermiger Zustellung
2  ;Copyright (C) 2019 Jonas Gappert <jonas@gappert.de>
3  ;This program is free software: you can redistribute it and/or modify it~
 under the terms of the GNU General Public License as published by the Free~
 Software Foundation, either version 3 of the License, or any later~
 version.
4  ;This program is distributed in the hope that it will be useful, but~
 WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY~
 or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License~
 for more details.
5  ;You should have received a copy of the GNU General Public License along~
 with this program. If not, see <https://www.gnu.org/licenses/>.
6  * - interne Parameter
7  *   - Ueberpruefung
8  FN 12: IF +Q1840 LT +1 GOTO LBL "1042"
9  FN 11: IF +Q1840 GT +4 GOTO LBL "1042"
10 FN 11: IF +Q1800 GT +Q1801 GOTO LBL "1005"
11 FN 11: IF +Q1802 GT +Q1803 GOTO LBL "1005"
12 FN 12: IF +Q1804 LT +Q1805 GOTO LBL "1077"
13 FN 12: IF +Q1810 LT +0 GOTO LBL "1011"
14 FN 9: IF +Q1810 EQU +0 GOTO LBL "1011"
15 FN 12: IF +Q1812 LT +0 GOTO LBL "1011"
16 FN 9: IF +Q1812 EQU +0 GOTO LBL "1011"
17 FN 11: IF +Q1812 GT +1 GOTO LBL "1011"
18 FN 12: IF +Q1813 LT +0 GOTO LBL "1011"
19 FN 9: IF +Q1813 EQU +0 GOTO LBL "1011"
20 FN 11: IF +Q1813 GT +1 GOTO LBL "1011"
21 FN 12: IF +Q1820 LT +0 GOTO LBL "1010"
22 FN 9: IF +Q1820 EQU +0 GOTO LBL "1010"
23 FN 12: IF +Q1822 LT +0 GOTO LBL "1010"
24 FN 9: IF +Q1822 EQU +0 GOTO LBL "1010"
25 FN 12: IF +Q1830 LT +0 GOTO LBL "1082"
26 FN 12: IF +Q1831 LT +0 GOTO LBL "1082"
27 FN 12: IF +Q1832 LT +0 GOTO LBL "1011"
28 *   - Berechnung Zustelltiefe
29 Q1950 = Q1804 - Q1805 ;relative Tiefe
30 Q1951 = INT ( ( Q1950 / Q1810 ) + 0.99999999 ) ;Anzahl Zustellungen
31 Q1952 = Q1950 / Q1951 ;Zustelltiefe
32 *   - Berechnung seitliche Zustellung
33 Q1963 = Q1812 * Q108 * 2 ;max seitliche Zustellung
34 Q1964 = Q1813 * Q108 * 2 ;Ueberlappung Mitte
35 Q1965 = Q1801 - Q1800 ;Seitenlaenge X
36 Q1966 = Q1803 - Q1802 ;Seitenlaenge Y
37 FN 12: IF +Q1966 LT +Q1965 GOTO LBL "yKleiner"
38 Q1960 = Q1965 ;kleinere Seitenlaenge
39 FN 9: IF +0 EQU +0 GOTO LBL "BerSeitZust"
40 LBL "yKleiner"
41 Q1960 = Q1966 ;kleinere Seitenlaenge
42 LBL "BerSeitZust"
43 Q1960 = Q1960 + Q1964 ;Seitenlaenge + Ueberlappung Mitte
44 Q1961 = INT ( ( Q1960 / Q1963 ) + 0.999 ) ;Anzahl seitlicher Zustellungen
45 Q1962 = Q1960 / Q1961 ;seitliche Zustellung
46 *   - sichere Hoehe
47 Q1907 = Q1804 + Q1830 ;sichere Hoehe
48 Q1908 = Q1804 + Q1831 ;2. sichere Hoehe
49 Q1909 = Q1908 ;akt sichere Hoehe
50 *   - Koordinaten Anfang
51 Q1900 = Q1800 ;X minus
52 Q1901 = Q1801 ;X plus
53 Q1902 = Q1802 ;Y minus
54 Q1903 = Q1803 ;Y plus
55 Q1904 = Q1804 ;Z plus
56 Q1905 = Q1805 ;Z minus
57 Q1914 = Q1904 ;Z
58 *   - LBL Koordinaten akt Zustellung
59 LBL "KoordAktZust"
60 *   - Koordinaten aktuelle Zustellung
61 Q1910 = Q1900 + ( Q1962 - Q108 ) ;X minus
62 Q1911 = Q1901 - ( Q1962 - Q108 ) ;X plus
63 Q1912 = Q1902 + ( Q1962 - Q108 ) ;Y minus
64 Q1913 = Q1903 - ( Q1962 - Q108 ) ;Y plus
65 *   - Koordinaten akt Zustellung - Radius
66 Q1920 = 0 ;X minus
67 Q1921 = 0 ;X plus
68 Q1922 = 0 ;Y minus
69 Q1923 = 0 ;Y plus
70 * - Labels
71 *   - LBL Zustellung
72 Q1951 = Q1951 - 1
73 Q1914 = Q1914 - Q1952
74 FN 9: IF +Q1840 EQU +1 GOTO LBL "StartSeite1"
75 FN 9: IF +Q1840 EQU +2 GOTO LBL "StartSeite2"
76 FN 9: IF +Q1840 EQU +3 GOTO LBL "StartSeite3"
77 FN 9: IF +Q1840 EQU +4 GOTO LBL "StartSeite4"
78 LBL "Zustellung"
79 Q1909 = Q1907
80 FN 9: IF +Q1951 EQU +0 GOTO LBL "EndPgm"
81 FN 9: IF +0 EQU +0 GOTO LBL "KoordAktZust"
82 *   - LBL StartSeite1
83 LBL "StartSeite1"
84 *     - Anfahr Positionen berechnen
85 Q1930 = Q1900 - Q108
86 Q1931 = Q1913 - Q108 - Q1832
87 Q1932 = Q1930 - Q1832
88 *     - Anfahren
89 L  X+Q1932  Y+Q1931 R0 FMAX
90 L  Z+Q1909 R0 FMAX
91 L  Z+Q1914 R0 FQ1822
92 L  X+Q1930  Y+Q1931 R0 FQ1820
93 RND RQ1832
94 L  X+Q1930  Y+Q1913 R0 FQ1820
95 RND RQ108
96 FN 9: IF +0 EQU +0 GOTO LBL "Spirale1"
97 *   - LBL StartSeite2
98 LBL "StartSeite2"
99 *     - Anfahr Positionen berechnen
100 Q1930 = Q1902 - Q108
101 Q1931 = Q1910 + Q108 + Q1832
102 Q1932 = Q1930 - Q1832
103 *     - Anfahren
104 L  X+Q1931  Y+Q1932 R0 FMAX
105 L  Z+Q1909 R0 FMAX
106 L  Z+Q1914 R0 FQ1822
107 L  X+Q1931  Y+Q1930 R0 FQ1820
108 RND RQ1832
109 L  X+Q1910  Y+Q1930 R0 FQ1820
110 RND RQ108
111 FN 9: IF +0 EQU +0 GOTO LBL "Spirale2"
112 *   - LBL StartSeite3
113 LBL "StartSeite3"
114 *     - Anfahr Positionen berechnen
115 Q1930 = Q1901 + Q108
116 Q1931 = Q1912 + Q108 + Q1832
117 Q1932 = Q1930 + Q1832
118 *     - Anfahren
119 L  X+Q1932  Y+Q1931 R0 FMAX
120 L  Z+Q1909 R0 FMAX
121 L  Z+Q1914 R0 FQ1822
122 L  X+Q1930  Y+Q1931 R0 FQ1820
123 RND RQ1832
124 L  X+Q1930  Y+Q1912 R0 FQ1820
125 RND RQ108
126 FN 9: IF +0 EQU +0 GOTO LBL "Spirale3"
127 *   - LBL StartSeite4
128 LBL "StartSeite4"
129 *     - Anfahr Positionen berechnen
130 Q1930 = Q1903 + Q108
131 Q1931 = Q1911 - Q108 - Q1832
132 Q1932 = Q1930 + Q1832
133 *     - Anfahren
134 L  X+Q1931  Y+Q1932 R0 FMAX
135 L  Z+Q1909 R0 FMAX
136 L  Z+Q1914 R0 FQ1822
137 L  X+Q1931  Y+Q1930 R0 FQ1820
138 RND RQ1832
139 L  X+Q1911  Y+Q1930 R0 FQ1820
140 RND RQ108
141 FN 9: IF +0 EQU +0 GOTO LBL "Spirale4"
142 *   - LBL Spirale
143 LBL "Spirale2"
144 Q1923 = Q1913 - Q108
145 L  X+Q1910  Y+Q1923 R0 FQ1820
146 Q1940 = Q1911 - Q1910 - ( Q108 * 2 )
147 FN 12: IF +Q1940 LT +0 GOTO LBL "EndeRichtung4"
148 FN 9: IF +Q1940 EQU +0 GOTO LBL "EndeRichtung4"
149 Q1910 = Q1910 + Q1962
150 CT IX+Q108 IY+Q108
151 LBL "Spirale1"
152 Q1921 = Q1911 - Q108
153 L  X+Q1921  Y+Q1913 R0 FQ1820
154 Q1940 = Q1913 - Q1912 - ( Q108 * 2 )
155 FN 12: IF +Q1940 LT +0 GOTO LBL "EndeRichtung3"
156 FN 9: IF +Q1940 EQU +0 GOTO LBL "EndeRichtung3"
157 Q1913 = Q1913 - Q1962
158 CT IX+Q108 IY-Q108
159 LBL "Spirale4"
160 Q1922 = Q1912 + Q108
161 L  X+Q1911  Y+Q1922 R0 FQ1820
162 Q1940 = Q1911 - Q1910 - ( Q108 * 2 )
163 FN 12: IF +Q1940 LT +0 GOTO LBL "EndeRichtung2"
164 FN 9: IF +Q1940 EQU +0 GOTO LBL "EndeRichtung2"
165 Q1911 = Q1911 - Q1962
166 CT IX-Q108 IY-Q108
167 LBL "Spirale3"
168 Q1920 = Q1910 + Q108
169 L  X+Q1920  Y+Q1912 R0 FQ1820
170 Q1940 = Q1913 - Q1912 - ( Q108 * 2 )
171 FN 12: IF +Q1940 LT +0 GOTO LBL "EndeRichtung1"
172 FN 9: IF +Q1940 EQU +0 GOTO LBL "EndeRichtung1"
173 Q1912 = Q1912 + Q1962
174 CT IX-Q108 IY+Q108
175 FN 9: IF +0 EQU +0 GOTO LBL "Spirale2"
176 *   - LBL EndeRichtung3
177 LBL "EndeRichtung3"
178 CT  X+Q1921  Y+Q1912
179 L  X+Q1910  Y+Q1912
180 L  Z+Q1909 R0 FMAX
181 FN 9: IF +0 EQU +0 GOTO LBL "Zustellung"
182 *   - LBL EndeRichtung4
183 LBL "EndeRichtung4"
184 CT  X+Q1911  Y+Q1923
185 L  X+Q1911  Y+Q1912
186 L  Z+Q1909 R0 FMAX
187 FN 9: IF +0 EQU +0 GOTO LBL "Zustellung"
188 *   - LBL EndeRichtung1
189 LBL "EndeRichtung1"
190 CT  X+Q1920  Y+Q1913
191 L  X+Q1911  Y+Q1913
192 L  Z+Q1909 R0 FMAX
193 FN 9: IF +0 EQU +0 GOTO LBL "Zustellung"
194 *   - LBL EndeRichtung2
195 LBL "EndeRichtung2"
196 CT  X+Q1910  Y+Q1922
197 L  X+Q1910  Y+Q1913
198 L  Z+Q1909 R0 FMAX
199 FN 9: IF +0 EQU +0 GOTO LBL "Zustellung"
200 * - Error
201 LBL "1005"
202 FN 14: ERROR= 1005
203 LBL "1010"
204 FN 14: ERROR= 1010
205 LBL "1011"
206 FN 14: ERROR= 1011
207 LBL "1042"
208 FN 14: ERROR= 1042
209 LBL "1077"
210 FN 14: ERROR= 1077
211 LBL "1082"
212 FN 14: ERROR= 1082
213 * - LBL EndPgm
214 LBL "EndPgm"
215 END PGM Plan MM 
