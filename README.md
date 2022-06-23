# MegaHanasenai
このリポジトリは[ハックツハッカソン イクチオカップ](https://cup.hackz.team/ichthyo)でチーム「俺のC++がこんなに可愛いわけがない」が開発した「メガ話せない」のリポジトリのコピーになります。
## Requirement
- gcc
- make
- [Siv3D](https://siv3d.github.io/ja-jp/)
- [Boost C++ Libraries](https://www.boost.org/)
- [Visual Studio](https://visualstudio.microsoft.com/ja/)
## Install
### backend
事前にBoostをインストールしておく  
Linux  
```
MegaHanasenai/backend$ ./make
```

### frontend
Windows
```
Siv3D, Boostをインストールしておく  
MegaHanasenai/frontend 内のslnファイルをVisual Studioで開く
(Siv3D, boostがあればgccでコンパイルも可だと思われる(未確認))  
実行  
```

### Usage
#### 基本的な使い方
backend, frontendを実行  
frontend(クライアント)で大きな声を出すと、他の、サーバに接続したことのあるクライアントに音声が送信される
