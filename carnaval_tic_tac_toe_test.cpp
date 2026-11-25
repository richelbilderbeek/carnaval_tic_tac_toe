// Tests for Carnaval Tic-Tac-Toe
//
// The tests play the game for a short while,
// so that the code coverage is measured.
// Run with: ./carnaval_tic_tac_toe_test
#include <QtTest>

#include "game_dialog.h"

class carnaval_tic_tac_toe_test : public QObject
{
  Q_OBJECT

private slots:

  void window_can_be_shown()
  {
    game_dialog w;
    w.show();
    QVERIFY(QTest::qWaitForWindowExposed(&w));
  }

  void window_responds_to_clicks()
  {
    game_dialog w;
    w.show();
    QVERIFY(QTest::qWaitForWindowExposed(&w));
    const int n{8};
    for (int x = 0; x != n; ++x)
    {
      for (int y = 0; y != n; ++y)
      {
        const QPoint p(
          (x * w.width()) / n + w.width() / (2 * n),
          (y * w.height()) / n + w.height() / (2 * n)
        );
        QTest::mouseClick(&w, Qt::LeftButton, Qt::NoModifier, p);
      }
    }
    QTest::qWait(100);
    QVERIFY(w.isVisible());
  }

  void window_responds_to_keys()
  {
    game_dialog w;
    w.show();
    QVERIFY(QTest::qWaitForWindowExposed(&w));
    const std::vector<Qt::Key> keys = {
      Qt::Key_Left,
      Qt::Key_Right,
      Qt::Key_Up,
      Qt::Key_Down,
      Qt::Key_Space,
      Qt::Key_Return,
      Qt::Key_W,
      Qt::Key_A,
      Qt::Key_S,
      Qt::Key_D
    };
    for (int i = 0; i != 3; ++i)
    {
      for (const auto key: keys)
      {
        QTest::keyClick(&w, key);
        QTest::qWait(10);
      }
    }
    QVERIFY(w.isVisible());
  }

  void game_runs_for_a_while()
  {
    game_dialog w;
    w.show();
    QVERIFY(QTest::qWaitForWindowExposed(&w));
    QTest::qWait(2000);
    QVERIFY(w.isVisible());
  }
};

QTEST_MAIN(carnaval_tic_tac_toe_test)
#include "carnaval_tic_tac_toe_test.moc"
