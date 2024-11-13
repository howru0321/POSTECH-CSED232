#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int timer_int;//실시간 시간
    int score_int;//실시간 점수

    QLabel *words[6];//화면에 존재하는 단어 목록. 6단어가 최대이다.
    int words_int;//화면에 존재하는 단어의 개수
    int x[6];//화면에 존재하는 단어의 x좌표. 랜덤하게 적용된다.
    int y[6];//화면에 존재하는 단어의 y좌표. 동일한 지점에서 시작하며, 시간이 지나면 내려온다.
    bool e_or_c[6];//단어가 어려운 단어인지 쉬운 단어인지 를 판별하는 정보가 담긴 배열

    QTimer*timer;

public slots:
    void increase_time();//시간을 감소시키는 함수
    void GameOver();//게임이 종료된 후 게임을 다시 시작할지 게임을 종료할지 정보를 받는 창을 ㄸㅢ우는 함수
    void spawn_word();//단어를 생성하는 함수
    void word_rain();//단어의 위치를 밖ㅜ는 함수
    void add_score();//점수를 올리는 함수

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
