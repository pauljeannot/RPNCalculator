#include "ltatomemanager.h"

LTAtomeManager* LTAtomeManager::instance = 0;

LTAtomeManager::LTAtomeManager()
{
    this->operatorsExisting.append("DIV");
    this->operatorsExisting.append("NUM");
    this->operatorsExisting.append("DEN");
    this->operatorsExisting.append("MOD");
    this->operatorsExisting.append("IM");
    this->operatorsExisting.append("RE");
    this->operatorsExisting.append("NEG");
    this->operatorsExisting.append("AND");
    this->operatorsExisting.append("OR");
    this->operatorsExisting.append("NOT");
    this->operatorsExisting.append("DUP");
    this->operatorsExisting.append("DROP");
    this->operatorsExisting.append("SWAP");
    this->operatorsExisting.append("LASTOP");
    this->operatorsExisting.append("LASTARGS");
    this->operatorsExisting.append("UNDO");
    this->operatorsExisting.append("REDO");
    this->operatorsExisting.append("CLEAR");
    this->operatorsExisting.append("IFT");
    this->operatorsExisting.append("EVAL");
    this->operatorsExisting.append("EDIT");
    this->operatorsExisting.append("FORGET");
    this->operatorsExisting.append("STO");
}
