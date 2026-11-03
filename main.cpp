#include "game_dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  game_dialog w;
#ifdef Q_OS_WASM
  w.showFullScreen();
#else
  w.show();
#endif

  return a.exec();
}
