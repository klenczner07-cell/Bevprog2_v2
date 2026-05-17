#include "application.hpp"
#include "button.hpp"
#include "felirat.hpp"
#include "tabla.hpp"
#include "jatekmaster.hpp"
#include <string>

class AmobaApp : public Application {
public:
    AmobaApp() : Application(720, 530), _jm() {
        _allapotSor = new Felirat(this, 530, 10, 175, 40, "");
        _tabla = new Tabla(this, 10, 10, &_jm, [this]() { allapotFrissit(); });
        _resetGomb = new Button(this, 530, 60, 175, 38, "Uj jatek", [this]() {
            _jm.reset();
            allapotFrissit();
        });
        allapotFrissit();
    }

private:
    void allapotFrissit() {
        int ny = _jm.getNyertes();
        if (ny == 1)
            _allapotSor->frissit("Fekete nyert!");
        else if (ny == 2)
            _allapotSor->frissit("Feher nyert!");
        else
            _allapotSor->frissit(std::to_string(_jm.getAktualisJatekos()) + ". jatekos lep");
    }

    JatekMester _jm;
    Tabla* _tabla;
    Felirat* _allapotSor;
    Button* _resetGomb;
};

int main() {
    AmobaApp app;
    app.event_loop();
    return 0;
}
