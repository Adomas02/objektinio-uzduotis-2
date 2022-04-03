# objektinio-uzduotis

## Programa skirta palyginti skirtingų c++ konteinerių veikimo spartą

### Paleidus programa jums reikeiės:<br>
- Pasirinkti ar norite generuoti failus ar ne
- Su kokiu konteineriu norite rezultatų
- Iš kokio failo norite imti duomenis

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
