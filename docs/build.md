# Building

Requires Qt 6.

- Desktop: requires Qt Multimedia, for the music.
  Run `qmake6` and `make`
- WebAssembly: use the `qmake` from a single-threaded Qt for WebAssembly
  installation, with the matching
  [Emscripten](https://doc.qt.io/qt-6/wasm.html) version

[GitHub Actions](https://github.com/richelbilderbeek/carnaval_tic_tac_toe/blob/main/.github/workflows/build.yml)
builds the Linux, Windows and
WebAssembly versions and stores them as artifacts of each workflow run.
