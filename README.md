# objektinio-uzduotis


### Įdiegimo instrukcija:<br>
- Atsisiųsti failus
- Konsolėje suvesti komandą: make
- Konsolėje suvesti komanda: .\run

### Paleidus programa jums reikeiės:<br>
- Pasirinkti ar norite generuoti failus ar ne
- Su kokiu konteineriu norite rezultatų
- Iš kokio failo norite imti duomenis

## v1.1 Programoje implementuota Studentas klase
### veikimo sparta lyginant optimizavimo lygius:<br>
- o1 19.285 s
- o2 18.321 s
- o3 18.125 s
### veikimo sparta lyginant su struktura:<br>
- 10000000 įrašų su struktūra
  - 3.58194s
- 10000000 įrašų su klase
  - 19.285 s
- 1000000 su struktūra
  - 0.73451 s  
- 1000000 su klase
  - 1.91364 s  
## v1.0 Programa skirta palyginti skirtingų c++ konteinerių veikimo bei skirtingų strategijų spartą beiu pridėtas makefile
### Programos veikimo metu matome skirtingų strategijų rezultatus:<br>
- Pirmoji strategija kuria du naujus konteinerius
- Antroji kuria vieną naują konteinerį, o iš pradinio trina nereikalingus elementus
### Testavimo rezultatai:<br>
- 10000000 įrašu su vector
  - Kuriant du naujus konteinerius laikas: 3.58194s atminties naudojimas padidėjo 8% daugiau
  - Kuriant vieną naują konteinerį laikas: 3.97554s atminties naudojimas padidėjo 5% daugiau
- 10000000 įrašu su list
  - Kuriant du naujus konteinerius laikas: 3.49514s atminties naudojimas padidėjo 7% daugiau
  - Kuriant vieną naują konteinerį laikas: 4.47392s atminties naudojimas padidėjo 4% daugiau
- 10000000 įrašu su deque
  - Kuriant du naujus konteinerius laikas: 2.8237s atminties naudojimas padidėjo 10% daugiau
  - Kuriant vieną naują konteinerį laikas: 4.26029s atminties naudojimas padidėjo 6% daugiau 

## v0.5 Programa skirta palyginti skirtingų c++ konteinerių veikimo spartą

### Rezultate matysite failo nuskaitymo laiką, failo paruosimo darbui laiką ir duomenų skirstymo į dvi grupes laiką

### Testavimo rezultatai:<br>
- 10000000 įrašu su vector
  - Nuskaitymo laikas 0,66s
  - Paruosimo laikas 17,45s
  - Dalinimo į dvi grupes laikas 1,33s
  - Bendras laikas 19,45s
  - Ram sparta padidėjo 5%, ssd 1%, cpu 10%
- 10000000 įrašu su list
  - Nuskaitymo laikas  0,64s
  - Paruosimo laikas 18,78s
  - Dalinimo į dvi grupes laikas 5,14s
  - Bendras laikas 24,57s
  - Ram sparta padidėjo 9%, ssd 1%, cpu 12%
- 10000000 įrašu su deque
  - Nuskaitymo laikas  0,65s
  - Paruosimo laikas 12,92s
  - Dalinimo į dvi grupes laikas 1,61s
  - Bendras laikas 15,18s
  - Ram sparta padidėjo 6%, ssd 1%, cpu 10%
