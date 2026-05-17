# Bevprog2_v2

Mit változtattam v1-hez képest:
- JatekMester::lepesKiserlet() lehelyezi a korongot es játékost vált,
- JatekMester::nyertE() vízszintes, függőleges, es egy átló irány
- JatekMester::getNyertes() hozzáadva
- JatekMester::reset() hozzáadva
- Tabla::handle() most btn_left esetén meghívja a lepesKiserlet()-t
- A Tabla konstruktora std::function callbackot kap, amit lépés után meghív
- Az AmobaApp osszedrótozza a táblát a feliratupdatekkel
- Reset gomb hozzáadva

Ismert hiba (BUG):
- Az átlós nyerés csak az egyik átló irányt nézi (bal felső -> jobb alsó, 1,1).
  A másik atló irány (jobb felső -> bal alsó, 1,-1) kimaradt a nyertE()-ből,
  tehát ilyen irányban 5 egymást követő korong nem számít nyerésnek.
- Teli tábla eseten a játék nem áll le (nincs döntetlen direkció), tovább
  lehet kattintani mar teli táblára is.
