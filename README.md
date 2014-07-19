c-separate-compilation
======================

C言語の分割コンパイルのチュートリアル

# includeの役割
まず分割コンパイルの前に、includeの役割を知ろう。

## 00 return 数字 するだけのプログラム
ディレクトリ`00`の`main.c`を実行すると、ステータスコード120が得られます。

```shell
$ cd 00
$ gcc main.c && ./a.out ; echo $?
```

ここまでは何の変哲もないC言語のプログラムです。

## 01 include 命令のはたらきを確認しよう

次に、ディレクトリ`01`の`main.c`の中身を見てから、実行してみてください。
`00`のときと同じ結果になるはずです。


```shell
$ cd 01
$ gcc main.c && ./a.out ; echo $?
```

さて、includeがファイルを単純に挿入しているだけであることが予想できますが、
これを実際に確認してみましょう。

```shell
$ gcc -E main.c
```

どうですか？
プリプロセッサがinclude命令をファイルの中身に置き換えた結果を見ることができましたね。

