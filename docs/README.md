# carnaval_tic_tac_toe

Carnaval game of tic-tac-toe.

![Screenshot](carnaval_tic_tac_toe.png)

- [Windows executable](http://richelbilderbeek.nl/carnaval_tic_tac_toe.exe)
- [YouTube video](https://youtu.be/wOc8YE24DHw)

## Building

Requires Qt 6.

- Desktop: run `qmake6` and `make`
- WebAssembly: use the `qmake` from a single-threaded Qt for WebAssembly
   installation, with the matching [Emscripten](https://doc.qt.io/qt-6/wasm.html) version

[GitHub Actions](https://github.com/richelbilderbeek/carnaval_tic_tac_toe/blob/main/.github/workflows/build.yml) builds the Linux, Windows and
WebAssembly versions and stores them as artifacts of each workflow run.

## Playing on a website

The WebAssembly artifact is a set of static files, which any web host can serve.
For example, put them in a folder on a website, then embed the game:

```html
<iframe src="game/carnaval_tic_tac_toe.html" width="400" height="500"></iframe>
```

## Actually playing it

<!-- markdownlint-disable MD033 --><!-- Need HTML here -->

<iframe src="game/carnaval_tic_tac_toe.html" width="400" height="500"></iframe>

<!-- markdownlint-enable MD033 -->
