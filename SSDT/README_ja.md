# SSDT
## SSDT-Darwin
[SSDT-Darwin.aml](./SSDT-Darwin.aml) では `DARW` メソッドを定義し、パッチの適用範囲を `If(OSDW(16,21))` のようにカーネルバージョンによって指定することができます。

## サンプル
### SSDT-UHD620
[SSDT-UHD620](./SSDT-UHD620.dsl) は `OSDW` や他の `_OSI` の使い方を示すサンプルです。SSDT-Darwin と組み合わせて使います。

この例では、10.11 に Skylake の Framebuffer を適用し、10.12 - 12 では Kaby Lake のものを、13 以降では Coffee Lake のものを適用しています。

`_DSM` が衝突する場合には、[config.plist](./config.plist) に記載されている `XDSM` パッチが必要です。

### SSDT-UHD620-Alt
[SSDT-UHD620-Alt](./SSDT-UHD620-Alt.dsl) は SSDT-UHD620 と同じ機能の異なる表現です。Kaby Lake の Framebuffer を優先し、存在しない場合は Skylake / Coffee Lake のものを適用します。
