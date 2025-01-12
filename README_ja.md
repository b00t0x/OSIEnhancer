# OSIEnhancer
DSDT や SSDT で OS 判定に使われる `_OSI` 関数で利用可能な文字列を拡張する Lilu プラグインです。

`_OSI("Darwin 21")` や `_OSI("Monterey")` といった文字列を利用することができ、macOS バージョンごとに異なる ACPI パッチを適用できるようになります。

## 利用可能な文字列
### `_OSI("macOS")`
マルチブート環境で macOS のみにパッチを適用するには `_OSI("Darwin")` を利用することが推奨されていますが、実際には Linux も `_OSI("Darwin")` に[反応する](https://www.kernel.org/doc/html/v6.0/firmware-guide/acpi/osi.html#apple-mac-and-osi-darwin)ため、不都合を起こす可能性があります。そのため macOS 全般を判定する別の方法として、`"macOS"` を定義しています。

### `_OSI("Darwin XX")`
`"Darwin 21"` などの文字列により、カーネルバージョンで macOS バージョンを判別することができます。

`"Darwin 25"` など、将来の macOS リリースにも対応しています（`-osibeta` ブート引数が必要です）。

### `_OSI("macOS XX")` / `_OSI("OS X 10.XX")`
`"macOS 12"` などの文字列で macOS バージョンを判別することができます。実際に設定されている文字列は [interfaces.hpp](./OSIEnhancer/interfaces.hpp) を参照してください。

また、`"macOS 15"` など、命名規則が変わらない限り将来の macOS リリースにも対応しています（`-osibeta` ブート引数が必要です）。

### `_OSI("Yosemite")` ... `_OSI("Sequoia")`
各 macOS バージョンの名前を利用することもできます。実際に設定されている文字列は [interfaces.hpp](./OSIEnhancer/interfaces.hpp) を参照してください。

### Intel Framebuffer
個人的な用途として、利用可能な Intel iGPU の Framebuffer を判別するために下記の文字列を導入しています。
- `"Skylake Framebuffer"`
- `"Kaby Lake Framebuffer"`
- `"Coffee Lake Framebuffer"`

これらの用途については[ここ](https://github.com/b00t0x/opencore-macos-version-specific-dp)を参照してください。

## SSDT
`MinKernel` / `MaxKernel` の機能を実現するため、この kext と組み合わせて使う [SSDT とサンプル](./SSDT)を用意しています。

## メモ
### Mavericks (10.9) 以前
`AcpiInstallInterface` は Yosemite (10.10) 以降にしか実装されていないため、Mavericks 以前でこの kext を利用することはできません。Leopard (10.5) から Mavericks では `AcpiOsValidateInterface` を置換することで対応できるかもしれませんが、確認できていません。
