#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMessageBox>
#include <qstring.h>
#include <cstdlib>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    score_int=0;
    timer_int=30;
    words_int=0;

    ui->setupUi(this);


    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(increase_time()));//1초마다 increase_time() 함수를 실행시켜 QLcd에 표현되는 시간을 1초 줄인다.
    connect(timer,SIGNAL(timeout()),this,SLOT(spawn_word()));//1초마다 spawn_word() 함수를 실행시켜 단어를 하나 생성한다.
    connect(timer,SIGNAL(timeout()),this,SLOT(word_rain()));//1초마다 word_rain() 함수를 실행시켜 단어의 위치를 일괄적으로 밖ㅝ준다.
    timer->start(1000);//위에 있는 3개의 connect 함수에게 1초마다 신호를 SIGNAL에 준다
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(add_score()));//qlineedit에 enter키가 들어오면 qlineedit의 맴버함수인 returnPress()함수에서 SIGNAL을 받아 이 connect함수를 작동시켜 add_score()함수를 작동하도록 한다.


}

MainWindow::~MainWindow()//동적할당한 모든 객체나 포인터를 동적할당 해제시켜준다
{
    delete timer;
    for(int i=0;i<words_int;i++){
        delete words[i];
    }
    delete ui;
}

void MainWindow::increase_time()//시간을 감소시키는 함수
{
    //if(timer_int==31){
        //timer_int=30;
       // return;
    //}
    timer_int-=1;//1초 시간을 줄인다

    if(timer_int<0){//음수인 경우를 예외처리 시켜준다.
        timer_int=0;
    }
    ui->timer_->display(timer_int);//lcd에 시간을 표현한다.


    if(timer_int<=0){
        ui->timer_->display(0);//음수인 경우 예외처리 시켜준다
        ui->score_->display(score_int);
        this->GameOver();
    }
}

void MainWindow::GameOver()//게임이 종료된 후 게임을 다시 시작할지 게임을 종료할지 정보를 받는 창을 ㄸㅢ우는 함수
{
    QMessageBox*mes=new QMessageBox(QMessageBox::Question,tr("Time Out"),"Your Score is "+QString::number(this->score_int)+"\nDo you want to try again?",QMessageBox::Yes|QMessageBox::No);


    switch(mes->exec()){
    case QMessageBox::Yes:
        timer_int=30;
        score_int=0;
        for(int i=0;i<words_int;i++){
            words[i]->clear();
            delete words[i];
        }
        words_int=-2;//timer_int=0일ㄸㅐ 한번, 그 다음턴 단어생성을 한번 더 쉬어줘야 초기 화면에 단어가 생성되지 않으므로, -2로 설정 해 두었다.
        ui->timer_->display(timer_int);
        ui->score_->display(score_int);

        timer_int=31;//timer를 통해 1초뒤에 increase_time()함수가 실행됐을ㄸㅐ timer_int는 1 줄어듦으로 31로 설정해야 한다.
        delete mes;//동적할당 해제
        break;
    case QMessageBox::No:
        exit(0);
        delete mes;//동적할당 해제

        break;
    }
}

void MainWindow::spawn_word()//단어를 생성하는 함수
{
    QString easy_words[30]= {"명징", "직조", "갈증", "비행기", "나흗날", "비둘기", "옹달샘", "줄이다", "거울", "집오리", "물리학", "토마토", "올리브", "은박지", "문지방", "물병", "양치질", "어린이", "집무실", "달빛", "다르다", "부고", "낫", "서당", "참외", "사다리", "천지", "인바디", "어금니", "추격"};
    QString crazy_words[10]= {"숨마쿰라우데", "우거지다", "토지소유권", "하염없다", "도톰하다", "넓적부리", "타란티노", "방울토마토", "객체지향수업", "컴퓨터공학과"};


    int easy_int=rand()%30;//easy_words에 있는 총 30개의 단어중 랜덤으로 하나를 선택하기 위해 random number을 30으로 나눈 나머지를 계산해 단어를 선택하였다.
    int crazy_int=rand()%10;//crazy_words에 있는 총 10개의 단어중 랜덤으로 하나를 선택하기 위해 random number을 10으로 나눈 나머지를 계산해 단어를 선택하였다.


    int rand_e_c=rand()%10;//easy_words를 생성할지, crazy_word를 생성할지 선택하기 위해 0-9ㄲㅏ지 숫자중 랜덤으로 선택하기 위해 random number을 10으로 나눈 나머지를 계산하였다.


    if(words_int>=6){//총 단어수가 6이면 더이상 단어를 생성하지 않기 위해 함수를 종료한다.
        return;
    }

    if(words_int<0){//게임 재시작후 총 2번 쉬기위해 생긴 알고리즘. words_int가 -2,-1일ㄸㅐ 총 2번 쉬게 된다.
        words_int++;
        return;
    }

    if(rand_e_c<8){//rand_e_c가 0-7 숫자 중 하나면 이 알고리즘을 시행시킨다. 0-9숫자 중 0-7이 나올 확률은 80퍼센트이므로 총 80퍼센트의 확률로 easy_words가 생성된다.
        words[words_int]= new QLabel(easy_words[easy_int],this);
        e_or_c[words_int]=true;
    }
    else{//rand_e_c가 8-9 숫자 중 하나면 이 알고리즘을 시행시킨다. 0-9숫자 중 8-9이 나올 확률은 20퍼센트이므로 총 20퍼센트의 확률로 crazy_words가 생성된다.
        words[words_int]= new QLabel(crazy_words[crazy_int],this);
        words[words_int]->setStyleSheet("QLabel {color : red }");
        e_or_c[words_int]=false;
    }

    int width_int=rand()%600;
    width_int+=100;//단어 생성시 x축 좌표를 랜덤하게 설정한다.

    x[words_int]=width_int;
    y[words_int]=100;//초기 y 좌표는 일정하게 100에서 시작한다.
    words_int++;
}

void MainWindow::word_rain()//단어의 위치를 밖ㅜ는 함수
{
    if(words_int<0){
        return;
    }
    for(int i=0;i<words_int;i++){
        words[i]->move(x[i],y[i]);
        words[i]->show();

        if(e_or_c[i]==true){
            y[i]+=30;
        }
        else{
            if(y[i]<280){//중간 지점오기 전 ㄲㅏ지는 easy_words보다 1.5배 더 ㅃㅏ르게 ㄸㅓㄹ어진다.
                y[i]+=45;
            }
            else{
                y[i]+=30;
            }
        }

        if(y[i]>=480){//단어가 범위 밖으로 벗어나면 단어는 삭제된다.
            timer_int-=3;
            if(timer_int<0){
                timer_int=0;
            }
            ui->timer_->display(timer_int);
            words[i]->clear();
            delete words[i];
            words_int--;
            for(int j=i;j<words_int;j++){
                x[j]=x[j+1];
                y[j]=y[j+1];
                e_or_c[j]=e_or_c[j+1];
                words[j]=words[j+1];
            }
            i--;//배열을 ㄸㅐㅇ긴 후에 다시 그 자리에서 반복문을 돌려야 한다.
        }
    }
}

void MainWindow::add_score()//점수를 올리는 함수
{
    int pos=-1;
    for(int i=0;i<words_int;i++){
        if(words[i]->text()==ui->lineEdit->text()){
            pos=i;
            break;
        }
    }

    if(pos!=-1){

        if(e_or_c[pos]==true){//쉬운 단어인 경우
            score_int+=10;
        }
        else{//어려운 단어인 경우
            score_int+=15;
        }
        words[pos]->clear();
        delete words[pos];
        words_int--;
        for(int j=pos;j<words_int;j++){
            x[j]=x[j+1];
            y[j]=y[j+1];
            e_or_c[j]=e_or_c[j+1];
            words[j]=words[j+1];
        }
    }

    ui->lineEdit->clear();
    ui->score_->display(score_int);

}


