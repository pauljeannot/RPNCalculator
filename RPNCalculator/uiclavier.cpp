#include "uiclavier.h"

void UIKeyboardLayout::constructDefaultKeyboardLayout() {

    UIButton *bt7 = new UIButton("7");
    UIButton *bt8 = new UIButton("8");
    UIButton *bt9 = new UIButton("9");
    UIButton *btparentheseG = new UIButton("(");
    UIButton *btparentheseD = new UIButton(")");

    UIButton *opPlus = new UIButton("+");
    UIButton *opMoins = new UIButton("-");
    UIButton *opMult = new UIButton("*");

    UIButtonsLine *line1 = new UIButtonsLine();
    line1->addButton(bt7);
    line1->addButton(bt8);
    line1->addButton(bt9);
    line1->addButton(btparentheseG);
    line1->addButton(btparentheseD);

    line1->addSpace();
    line1->addButton(opPlus);
    line1->addButton(opMoins);
    line1->addButton(opMult);

    //----------------------------
    //      2ème ligne
    //----------------------------
    UIButton *bt4 = new UIButton("4");
    UIButton *bt5 = new UIButton("5");
    UIButton *bt6 = new UIButton("6");
    UIButton *btcrochetG = new UIButton("[");
    UIButton *btcrochetD = new UIButton("]");

    UIButton *opDiviser = new UIButton("/");
    UIButton *opDivise = new UIButton("DIV");
    UIButton *opMod = new UIButton("MOD");

    UIButtonsLine *line2 = new UIButtonsLine();
    line2->addButton(bt4);
    line2->addButton(bt5);
    line2->addButton(bt6);
    line2->addButton(btcrochetG);
    line2->addButton(btcrochetD);

    line2->addSpace();
    line2->addButton(opDiviser);
    line2->addButton(opDivise);
    line2->addButton(opMod);

    //----------------------------
    //      3ème ligne
    //----------------------------
    UIButton *bt1 = new UIButton("1");
    UIButton *bt2 = new UIButton("2");
    UIButton *bt3 = new UIButton("3");
    UIButton *quote = new UIButton("'", 0.6);
    UIButton *backspace = new UIButton("BACK", 1.4);

    UIButton *neg = new UIButton("NEG");
    UIButton *num = new UIButton("NUM");
    UIButton *den = new UIButton("DEN");

    UIButtonsLine *line3 = new UIButtonsLine();
    line3->addButton(bt1);
    line3->addButton(bt2);
    line3->addButton(bt3);
    line3->addButton(quote);
    line3->addButton(backspace);

    line3->addSpace();
    line3->addButton(neg);
    line3->addButton(num);
    line3->addButton(den);

    //----------------------------
    //      4ème ligne
    //----------------------------
    UIButton *bt0 = new UIButton("0");
    UIButton *space = new UIButton("SPACE", 2, " ");
    UIButton *dot = new UIButton(".", 0.6);
    UIButton *enter = new UIButton("ENTER", 1.4);

    UIButton *complex = new UIButton("$");
    UIButton *im = new UIButton("IM");
    UIButton *re = new UIButton("RE");

    UIButtonsLine *line4 = new UIButtonsLine();
    line4->addButton(bt0);
    line4->addButton(space);
    line4->addButton(dot);
    line4->addButton(enter);

    line4->addSpace();
    line4->addButton(complex);
    line4->addButton(im);
    line4->addButton(re);

    //----------------------------
    //      5ème ligne (Manips pile et Opérateurs logiques)
    //----------------------------
    UIButton *undo = new UIButton("UNDO", 1.7);
    UIButton *dup = new UIButton("DUP", 1.7);
    UIButton *drop = new UIButton("DROP", 1.99);

    UIButton *egal = new UIButton("=");
    UIButton *diff = new UIButton("!=");
    UIButton *AND = new UIButton("AND");

    UIButtonsLine *line5 = new UIButtonsLine();
    line5->addButton(undo);
    line5->addButton(dup);
    line5->addButton(drop);

    line5->addSpace();
    line5->addButton(egal);
    line5->addButton(diff);
    line5->addButton(AND);

    //----------------------------
    //      6ème ligne
    //----------------------------
    UIButton *REDO = new UIButton("REDO", 1.7);
    UIButton *SWAP = new UIButton("SWAP", 1.7);
    UIButton *Lastop = new UIButton("LASTOP", 1.99);

    UIButton *inf = new UIButton("<");
    UIButton *sup = new UIButton(">");
    UIButton *Opor = new UIButton("OR");

    UIButtonsLine *line6 = new UIButtonsLine();
    line6->addButton(REDO);
    line6->addButton(SWAP);
    line6->addButton(Lastop);

    line6->addSpace();
    line6->addButton(inf);
    line6->addButton(sup);
    line6->addButton(Opor);

    //----------------------------
    //      7ème ligne
    //----------------------------
    UIButton *Clear = new UIButton("CLEAR", 3.2);
    UIButton *Lastarg = new UIButton("LASTARGS", 1.99);

    UIButton *infeg = new UIButton("<=");
    UIButton *supeg = new UIButton(">=");
    UIButton *Not = new UIButton("NOT");

    UIButtonsLine *line7 = new UIButtonsLine();
    line7->addButton(Clear);
    line7->addButton(Lastarg);


    line7->addSpace();
    line7->addButton(infeg);
    line7->addButton(supeg);
    line7->addButton(Not);

    //----------------------------
    //      8ème ligne
    //----------------------------
    UIButton *eval = new UIButton("EVAL", 1.2);
    UIButton *edit = new UIButton("EDIT", 1.2);
    UIButton *sto = new UIButton("STO", 1.2);
    UIButton *forget = new UIButton("FORGET", 1.59);

    UIButton *ift = new UIButton("IFT", 3);

    UIButtonsLine *line8 = new UIButtonsLine();
    line8->addButton(eval);
    line8->addButton(edit);
    line8->addButton(sto);
    line8->addButton(forget);

    line8->addSpace();
    line8->addButton(ift);

    //----------------------------
    //      Assemblage des lignes en un clavier
    //----------------------------
    this->addLine(line1);
    this->addLine(line2);
    this->addLine(line3);
    this->addLine(line4);
    this->addSpace();
    this->addLine(line5);
    this->addLine(line6);
    this->addLine(line7);
    this->addSpace();
    this->addLine(line8);

}
