#include "ltnumerique.h"
#include "ltnombre.h"


LTNombre* LTEntier::operator+(LTNombre* p) {
std::cout << "LTEntier" << std::endl;

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        this->E1 += e->getE1();
        delete e;
        return this;
    }
    else if (re != nullptr) {
        return *(re) + this;
    }
    else if (ra != nullptr) {
        ra->setE1(ra->getE1() + this->getE1() * ra->getE2());
        delete this;
        return ra;
    }
}

LTNombre* LTReelle::operator+(LTNombre* p) {
    std::cout << "LTReelle" << std::endl;

    LTEntier* e = dynamic_cast<LTEntier*>(p);
    LTReelle* re = dynamic_cast<LTReelle*>(p);
    LTRationnelle* ra = dynamic_cast<LTRationnelle*>(p);

    if (e != nullptr) {
        this->E1 += e->getE1();
        delete e;
        return this;
    }
    else if (re != nullptr) {
        float a = this->getText().toFloat();
        float b = re->getText().toFloat();

        float res = a+b;
        QString s;
        s.setNum(res);

        QStringList list = s.split(".");
        std::cout << "a : "<< a << " - b : " << b << " - res" << res << " - s " << s.toStdString() << " - " << std::endl;
        this->E1 = list.at(0).toFloat();

        if (list.size() == 1) {
            this->E2 = 0;
        }
        else {
            this->E2 = list.at(1).toFloat();
        }

        delete re;
        return this;
    }
    else if (ra != nullptr) {
        LTReelle* r = new LTReelle(ra);
        delete ra;
        return *(this) + r;
    }

}

LTNombre* LTRationnelle::operator+(LTNombre* p) {
std::cout << "LTRationnelle" << std::endl;
}
