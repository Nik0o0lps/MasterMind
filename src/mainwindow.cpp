#include "mainwindow.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include "graphicsview.h"
#include "coloritem.h"

MainWindow::MainWindow()
{
    createActions();
    createMenus();
        QPixmap bkgnd("/home/nikolas5/Desktop/Mastermind-master/foto.png");
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
}

void MainWindow::createActions()
{
    //funcao QAction

    newGameAction = new QAction(tr("New Game"), this);
    newGameAction->setShortcut(QKeySequence(tr("F2")));
    QObject::connect(newGameAction, SIGNAL(triggered()), this, SLOT(newGame()));

    statisticsAction = new QAction(tr("Statistics"), this);
    statisticsAction->setShortcut(QKeySequence(tr("F4")));
    QObject::connect(statisticsAction, SIGNAL(triggered()), this, SLOT(statistics()));

    optionsAction = new QAction(tr("Options"), this);
    optionsAction->setShortcut(tr("F5"));
    QObject::connect(optionsAction, SIGNAL(triggered()), this, SLOT(options()));

    instructionsAction = new QAction(tr("Instructions"), this);
    instructionsAction->setShortcut(QKeySequence(tr("F6")));
    QObject::connect(instructionsAction, SIGNAL(triggered()), this, SLOT(instructions()));

    rulesAction = new QAction(tr("Rules"), this);
    rulesAction->setShortcut(QKeySequence(tr("F7")));
    QObject::connect(rulesAction, SIGNAL(triggered()), this, SLOT(rules()));

    exitAction = new QAction(tr("Exit"), this);
    exitAction->setShortcut(QKeySequence::Close);
    QObject::connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));


    aboutAction = new QAction(tr("About Mastermind"), this);
    aboutAction->setShortcut(QKeySequence(tr("F1")));
    QObject::connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    tipsAction = new QAction(tr("Tips"), this);
    tipsAction->setShortcut(QKeySequence(tr("F12")));
    QObject::connect(tipsAction, SIGNAL(triggered()), this, SLOT(tips()));
}

void MainWindow::createMenus()
{
    game = menuBar()->addMenu(tr("Game"));
    game->addAction(newGameAction);
    game->addAction(statisticsAction);
    game->addAction(optionsAction);
    game->addAction(instructionsAction);
    game->addAction(rulesAction);
    game->addAction(exitAction);

    help = menuBar()->addMenu(tr("Help"));
    help->addAction(aboutAction);
    help->addAction(tipsAction);
}


void MainWindow::newGame()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(QRectF(-140, -50, 500, 774));

    for(int i = 0 ; i < 8; i++)
    {
        ColorItem *item = new ColorItem;
        item->setPos(-100, 50 * i + 25 );

        scene->addItem(item);
    }


    board = new Board();
    scene->addItem(board);

    board->setI(0);
    QHBoxLayout *layout = new QHBoxLayout;
    view = new GraphicsView(scene);
    layout->addWidget(view);

    QWidget * widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("MasterMind"
""));
    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::statistics()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setText(tr("Statisticas nao disponiveis"));
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->exec();
}

void MainWindow::options()
{
    int answer = QMessageBox::warning(this, tr("Options"), tr("Ainda estamos na faze beta"), QMessageBox::Ok);
    if( answer == QMessageBox::Ok )
    {
        QMessageBox::information(this, tr("Desculpe"), tr("Desculpe o incoveniente"));
    }
}

void MainWindow::instructions()
{
    QMessageBox *msgBox = new QMessageBox;

    msgBox->setText(tr("<h1>Mastermind: Instruções</h1> \
                       <section> \
                       <p><strong>Como Jogar?</strong><p> \
                       <p>Arraste a cor do canto esquerdo da tela até os espaços vazios. Clique em validar caso ache que a combinação está correta.</p> \
                       </section>"));
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}

void MainWindow::rules()
{
    QMessageBox *msgBox = new QMessageBox;

    msgBox->setText(tr("<h1>Mastermind: Regras</h1> \
                       <section> \
                       <p><strong>Objetivo</strong><p> \
                       <p>Voce é o Codebreaker. Voce tem 10 chances para achar a combinação de cores corretas em seus respectivos lugares.<p> \
                       </section> \
                       <section> \
                       <p><strong>O Tabuleiro</strong><p> \
                       O tabuleiro possui 4 espaços vazios a cada tentativa, totalizando no total 40 tentivas de combinacoes possiveis a cada jogo \
                       </section>"));
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}

void MainWindow::exit()
{
    MainWindow::close();
}

void MainWindow::about()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setText(tr("versao 1.0"));
    msgBox->setIcon(QMessageBox::Warning);
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->exec();
}

void MainWindow::tips()
{
    QMessageBox *msgBox = new QMessageBox;
    msgBox->setText(tr("<h3>Dicas Para Voce.</h3><ul><li>Tenha atencao e se mantenha calmo, pense a cada jogada.</li></ul>"));
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setStandardButtons(QMessageBox::Close);
    msgBox->exec();
}
