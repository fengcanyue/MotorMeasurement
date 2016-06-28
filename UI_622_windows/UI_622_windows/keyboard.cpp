#include "keyboard.h"
#include "ui_keyboard.h"

keyBoard::keyBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyBoard)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    islocked=false;
    ui->lock->flag=1;
    ui->backspace->flag=1;

    ui->num1->neighbor.downButton=ui->lock;
    ui->num1->neighbor.upButton=0;
    ui->num1->neighbor.leftButton=0;
    ui->num1->neighbor.rightButton=ui->num2;

    ui->num2->neighbor.downButton=ui->Q;
    ui->num2->neighbor.upButton=0;
    ui->num2->neighbor.leftButton=ui->num1;
    ui->num2->neighbor.rightButton=ui->num3;


    ui->num3->neighbor.downButton=ui->W;
    ui->num3->neighbor.upButton=0;
    ui->num3->neighbor.leftButton=ui->num2;
    ui->num3->neighbor.rightButton=ui->num4;

    ui->num4->neighbor.downButton=ui->E;
    ui->num4->neighbor.upButton=0;
    ui->num4->neighbor.leftButton=ui->num3;
    ui->num4->neighbor.rightButton=ui->num5;

    ui->num5->neighbor.downButton=ui->R;
    ui->num5->neighbor.upButton=0;
    ui->num5->neighbor.leftButton=ui->num4;
    ui->num5->neighbor.rightButton=ui->num6;

    ui->num6->neighbor.downButton=ui->T;
    ui->num6->neighbor.upButton=0;
    ui->num6->neighbor.leftButton=ui->num5;
    ui->num6->neighbor.rightButton=ui->num7;

    ui->num7->neighbor.downButton=ui->Y;
    ui->num7->neighbor.upButton=0;
    ui->num7->neighbor.leftButton=ui->num6;
    ui->num7->neighbor.rightButton=ui->num8;

    ui->num8->neighbor.downButton=ui->U;
    ui->num8->neighbor.upButton=0;
    ui->num8->neighbor.leftButton=ui->num7;
    ui->num8->neighbor.rightButton=ui->num9;

    ui->num9->neighbor.downButton=ui->I;
    ui->num9->neighbor.upButton=0;
    ui->num9->neighbor.leftButton=ui->num8;
    ui->num9->neighbor.rightButton=ui->num0;

    ui->num0->neighbor.downButton=ui->O;
    ui->num0->neighbor.upButton=0;
    ui->num0->neighbor.leftButton=ui->num9;
    ui->num0->neighbor.rightButton=ui->minus;

    ui->minus->neighbor.downButton=ui->P;
    ui->minus->neighbor.upButton=0;
    ui->minus->neighbor.leftButton=ui->num0;
    ui->minus->neighbor.rightButton=ui->backspace;

    ui->backspace->neighbor.upButton=0;
    ui->backspace->neighbor.leftButton=ui->minus;
    ui->backspace->neighbor.downButton=ui->rightLine;
    ui->backspace->neighbor.rightButton=0;

    ui->Q->neighbor.upButton=ui->num2;
    ui->Q->neighbor.downButton=ui->A;
    ui->Q->neighbor.leftButton=ui->lock;
    ui->Q->neighbor.rightButton=ui->W;

    ui->A->neighbor.upButton=ui->Q;
    ui->A->neighbor.rightButton=ui->S;
    ui->A->neighbor.leftButton=ui->lock;
    ui->A->neighbor.downButton=ui->Z;

    ui->Z->neighbor.upButton=ui->A;
    ui->Z->neighbor.downButton=0;
    ui->Z->neighbor.rightButton=ui->X;
    ui->Z->neighbor.leftButton=ui->lock;

    ui->W->neighbor.upButton=ui->num3;
    ui->W->neighbor.leftButton=ui->Q;
    ui->W->neighbor.downButton=ui->S;
    ui->W->neighbor.rightButton=ui->E;

    ui->S->neighbor.upButton=ui->W;
    ui->S->neighbor.downButton=ui->X;
    ui->S->neighbor.leftButton=ui->A;
    ui->S->neighbor.rightButton=ui->D;

    ui->X->neighbor.downButton=0;
    ui->X->neighbor.upButton=ui->S;
    ui->X->neighbor.leftButton=ui->Z;
    ui->X->neighbor.rightButton=ui->C;

    ui->E->neighbor.upButton=ui->num4;
    ui->E->neighbor.downButton=ui->D;
    ui->E->neighbor.leftButton=ui->W;
    ui->E->neighbor.rightButton=ui->R;

    ui->D->neighbor.upButton=ui->E;
    ui->D->neighbor.leftButton=ui->S;
    ui->D->neighbor.downButton=ui->C;
    ui->D->neighbor.rightButton=ui->F;

    ui->C->neighbor.downButton=0;
    ui->C->neighbor.upButton=ui->D;
    ui->C->neighbor.leftButton=ui->X;
    ui->C->neighbor.rightButton=ui->V;

    ui->R->neighbor.upButton=ui->num5;
    ui->R->neighbor.downButton=ui->F;
    ui->R->neighbor.leftButton=ui->E;
    ui->R->neighbor.rightButton=ui->T;

    ui->F->neighbor.upButton=ui->R;
    ui->F->neighbor.leftButton=ui->D;
    ui->F->neighbor.downButton=ui->V;
    ui->F->neighbor.rightButton=ui->G;

    ui->V->neighbor.downButton=0;
    ui->V->neighbor.leftButton=ui->C;
    ui->V->neighbor.rightButton=ui->B;
    ui->V->neighbor.upButton=ui->F;

    ui->T->neighbor.upButton=ui->num6;
    ui->T->neighbor.downButton=ui->G;
    ui->T->neighbor.leftButton=ui->R;
    ui->T->neighbor.rightButton=ui->Y;

    ui->G->neighbor.upButton=ui->T;
    ui->G->neighbor.downButton=ui->B;
    ui->G->neighbor.leftButton=ui->F;
    ui->G->neighbor.rightButton=ui->H;

    ui->B->neighbor.downButton=0;
    ui->B->neighbor.upButton=ui->G;
    ui->B->neighbor.leftButton=ui->V;
    ui->B->neighbor.rightButton=ui->N;

    ui->Y->neighbor.upButton=ui->num7;
    ui->Y->neighbor.downButton=ui->H;
    ui->Y->neighbor.leftButton=ui->T;
    ui->Y->neighbor.rightButton=ui->U;

    ui->H->neighbor.upButton=ui->Y;
    ui->H->neighbor.leftButton=ui->G;
    ui->H->neighbor.downButton=ui->B;
    ui->H->neighbor.rightButton=ui->J;

    ui->U->neighbor.upButton=ui->num8;
    ui->U->neighbor.downButton=ui->H;
    ui->U->neighbor.leftButton=ui->Y;
    ui->U->neighbor.rightButton=ui->I;

    ui->I->neighbor.upButton=ui->num9;
    ui->I->neighbor.downButton=ui->J;
    ui->I->neighbor.leftButton=ui->U;
    ui->I->neighbor.rightButton=ui->O;

    ui->J->neighbor.upButton=ui->I;
    ui->J->neighbor.downButton=ui->N;
    ui->J->neighbor.leftButton=ui->H;
    ui->J->neighbor.rightButton=ui->K;

    ui->N->neighbor.downButton=0;
    ui->N->neighbor.upButton=ui->J;
    ui->N->neighbor.leftButton=ui->B;
    ui->N->neighbor.rightButton=ui->M;

    ui->O->neighbor.upButton=ui->num0;
    ui->O->neighbor.rightButton=ui->P;
    ui->O->neighbor.downButton=ui->K;
    ui->O->neighbor.leftButton=ui->I;

    ui->K->neighbor.upButton=ui->O;
    ui->K->neighbor.leftButton=ui->J;
    ui->K->neighbor.rightButton=ui->L;
    ui->K->neighbor.downButton=ui->M;

    ui->P->neighbor.upButton=ui->minus;
    ui->P->neighbor.rightButton=ui->rightLine;
    ui->P->neighbor.downButton=ui->L;
    ui->P->neighbor.leftButton=ui->O;

    ui->L->neighbor.downButton=ui->point;
    ui->L->neighbor.rightButton=ui->comma;
    ui->L->neighbor.leftButton=ui->K;
    ui->L->neighbor.upButton=ui->P;

    ui->M->neighbor.upButton=ui->K;
    ui->M->neighbor.rightButton=ui->point;
    ui->M->neighbor.downButton=0;
    ui->M->neighbor.leftButton=ui->N;

    ui->lock->neighbor.upButton=ui->num1;
    ui->lock->neighbor.rightButton=ui->A;
    ui->lock->neighbor.downButton=ui->Z;
    ui->lock->neighbor.leftButton=0;

    ui->rightLine->neighbor.upButton=ui->backspace;
    ui->rightLine->neighbor.downButton=ui->comma;
    ui->rightLine->neighbor.rightButton=0;
    ui->rightLine->neighbor.leftButton=ui->P;

    ui->comma->neighbor.upButton=ui->rightLine;
    ui->comma->neighbor.downButton=ui->leftLine;
    ui->comma->neighbor.leftButton=ui->L;
    ui->comma->neighbor.rightButton=ui->semicolon;

    ui->semicolon->neighbor.upButton=ui->rightLine;
    ui->semicolon->neighbor.downButton=ui->question;
    ui->semicolon->neighbor.rightButton=0;
    ui->semicolon->neighbor.leftButton=ui->comma;

    ui->point->neighbor.upButton=ui->L;
    ui->point->neighbor.leftButton=ui->M;
    ui->point->neighbor.rightButton=ui->leftLine;
    ui->point->neighbor.downButton=0;

    ui->leftLine->neighbor.downButton=0;
    ui->leftLine->neighbor.leftButton=ui->point;
    ui->leftLine->neighbor.upButton=ui->comma;
    ui->leftLine->neighbor.rightButton=ui->question;

    ui->question->neighbor.upButton=ui->semicolon;
    ui->question->neighbor.leftButton=ui->leftLine;
    ui->question->neighbor.downButton=0;
    ui->question->neighbor.rightButton=0;
}

keyBoard::~keyBoard()
{
    delete ui;
}

void keyBoard::on_lock_clicked()
{
   islocked=!islocked;
   if(islocked)
       ui->lock->setText("locked");
   else
       ui->lock->setText("unlocked");
}

void keyBoard::resizeEvent(QResizeEvent *)
{
    ui->num1->setGeometry(width()*10/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num2->setGeometry(width()*70/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num3->setGeometry(width()*130/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num4->setGeometry(width()*190/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num5->setGeometry(width()*250/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num6->setGeometry(width()*310/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num7->setGeometry(width()*370/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num8->setGeometry(width()*430/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num9->setGeometry(width()*490/740,height()*10/170,width()*51/740,height()*31/170);
    ui->num0->setGeometry(width()*550/740,height()*10/170,width()*51/740,height()*31/170);
    ui->minus->setGeometry(width()*610/740,height()*10/170,width()*51/740,height()*31/170);
    ui->backspace->setGeometry(width()*670/740,height()*10/170,width()*51/740,height()*31/170);

    ui->Q->setGeometry(width()*50/740,height()*50/170,width()*51/740,height()*31/170);
    ui->W->setGeometry(width()*110/740,height()*50/170,width()*51/740,height()*31/170);
    ui->E->setGeometry(width()*170/740,height()*50/170,width()*51/740,height()*31/170);
    ui->R->setGeometry(width()*230/740,height()*50/170,width()*51/740,height()*31/170);
    ui->T->setGeometry(width()*290/740,height()*50/170,width()*51/740,height()*31/170);
    ui->Y->setGeometry(width()*350/740,height()*50/170,width()*51/740,height()*31/170);
    ui->U->setGeometry(width()*410/740,height()*50/170,width()*51/740,height()*31/170);
    ui->I->setGeometry(width()*470/740,height()*50/170,width()*51/740,height()*31/170);
    ui->O->setGeometry(width()*530/740,height()*50/170,width()*51/740,height()*31/170);
    ui->P->setGeometry(width()*590/740,height()*50/170,width()*51/740,height()*31/170);
    ui->rightLine->setGeometry(width()*650/740,height()*50/170,width()*51/740,height()*31/170);

    ui->lock->setGeometry(width()*10/740,height()*130/170,width()*71/740,height()*31/170);
    ui->A->setGeometry(width()*80/740,height()*90/170,width()*51/740,height()*31/170);
    ui->S->setGeometry(width()*140/740,height()*90/170,width()*51/740,height()*31/170);
    ui->D->setGeometry(width()*200/740,height()*90/170,width()*51/740,height()*31/170);
    ui->F->setGeometry(width()*260/740,height()*90/170,width()*51/740,height()*31/170);
    ui->G->setGeometry(width()*320/740,height()*90/170,width()*51/740,height()*31/170);
    ui->H->setGeometry(width()*380/740,height()*90/170,width()*51/740,height()*31/170);
    ui->J->setGeometry(width()*440/740,height()*90/170,width()*51/740,height()*31/170);
    ui->K->setGeometry(width()*500/740,height()*90/170,width()*51/740,height()*31/170);
    ui->L->setGeometry(width()*560/740,height()*90/170,width()*51/740,height()*31/170);
    ui->comma->setGeometry(width()*620/740,height()*90/170,width()*51/740,height()*31/170);
    ui->semicolon->setGeometry(width()*680/740,height()*90/170,width()*51/740,height()*31/170);

    ui->Z->setGeometry(width()*90/740,height()*130/170,width()*51/740,height()*31/170);
    ui->X->setGeometry(width()*150/740,height()*130/170,width()*51/740,height()*31/170);
    ui->C->setGeometry(width()*210/740,height()*130/170,width()*51/740,height()*31/170);
    ui->V->setGeometry(width()*270/740,height()*130/170,width()*51/740,height()*31/170);
    ui->B->setGeometry(width()*330/740,height()*130/170,width()*51/740,height()*31/170);
    ui->N->setGeometry(width()*390/740,height()*130/170,width()*51/740,height()*31/170);
    ui->M->setGeometry(width()*450/740,height()*130/170,width()*51/740,height()*31/170);
    ui->point->setGeometry(width()*510/740,height()*130/170,width()*51/740,height()*31/170);
    ui->leftLine->setGeometry(width()*570/740,height()*130/170,width()*51/740,height()*31/170);
    ui->question->setGeometry(width()*630/740,height()*130/170,width()*51/740,height()*31/170);
}

void keyBoard::gainFocus()
{
    ui->Q->setFocus();
}
