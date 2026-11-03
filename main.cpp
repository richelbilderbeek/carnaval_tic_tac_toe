#include "game_dialog.h"
#include <QApplication>

#ifndef Q_OS_WASM
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QUrl>
#endif

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  game_dialog w;
#ifdef Q_OS_WASM
  w.showFullScreen();
#else
  w.show();

  QAudioOutput audio_output;
  QMediaPlayer music_player;
  music_player.setAudioOutput(&audio_output);
  music_player.setSource(QUrl("qrc:/carnaval_tic_tac_toe.ogg"));
  music_player.setLoops(QMediaPlayer::Infinite);
  music_player.play();
#endif

  return a.exec();
}
